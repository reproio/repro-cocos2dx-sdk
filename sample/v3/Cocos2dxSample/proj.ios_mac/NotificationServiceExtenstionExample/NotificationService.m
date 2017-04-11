//
//  NotificationService.m
//  NotificationServiceExample
//
//  Created by woshidan on 2017/03/31.
//
//

#import "NotificationService.h"
#import <UserNotifications/UserNotifications.h>

@interface NotificationService ()

@property (nonatomic, strong) void (^contentHandler)(UNNotificationContent *contentToDeliver);
@property (nonatomic, strong) UNMutableNotificationContent *bestAttemptContent;

@end

@implementation NotificationService

- (void)didReceiveNotificationRequest:(UNNotificationRequest *)request withContentHandler:(void (^)(UNNotificationContent * _Nonnull))contentHandler {
    self.contentHandler = contentHandler;
    self.bestAttemptContent = [request.content mutableCopy];
    
    NSDictionary *attachment = request.content.userInfo[@"rpr_attachment"];
    if (!attachment) {
        contentHandler(self.bestAttemptContent);
        return;
    }
    
    NSString *urlStr = attachment[@"url"];
    NSString *type = attachment[@"type"];
    NSURL *url = [NSURL URLWithString:urlStr];
    
    [[[NSURLSession sharedSession] downloadTaskWithURL:url
                                     completionHandler:^(NSURL * _Nullable location,
                                                         NSURLResponse * _Nullable response,
                                                         NSError * _Nullable error) {
                                         
                                         if (error) {
                                             contentHandler(self.bestAttemptContent);
                                             return;
                                         }
                                         
                                         NSString *fileName = [NSString stringWithFormat:@"%@.%@", [[NSUUID UUID]UUIDString], type];
                                         NSURL *fileURL = [NSURL fileURLWithPath:[NSTemporaryDirectory() stringByAppendingPathComponent:fileName]];
                                         [[NSFileManager defaultManager] moveItemAtURL:location toURL:fileURL error:nil];
                                         
                                         NSError *attachError;
                                         UNNotificationAttachment *attachment = [UNNotificationAttachment attachmentWithIdentifier:@"IDENTIFIER" URL:fileURL options:nil error:&attachError];
                                         if (!attachError) {
                                             self.bestAttemptContent.attachments = @[attachment];
                                         }
                                         
                                         contentHandler(self.bestAttemptContent);
                                     }] resume];
}

- (void)serviceExtensionTimeWillExpire {
    // Called just before the extension will be terminated by the system.
    // Use this as an opportunity to deliver your "best attempt" at modified content, otherwise the original push payload will be used.
    self.contentHandler(self.bestAttemptContent);
}

@end
