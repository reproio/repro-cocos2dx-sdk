//
//  ReproCpp.mm
//
//  Created by jollyjoester_pro on 10/31/14.
//  Copyright (c) 2014 Repro Inc. All rights reserved.
//

#import <sys/utsname.h>
#include "ReproCpp.h"
#import <Repro/Repro.h>
#include "ReproConverterIOS.h"

// helper methods to check OS Version and Device Type

float osVersion()
{
    return UIDevice.currentDevice.systemVersion.floatValue;
}

NSString* device()
{
    struct utsname systemInfo;
    uname(&systemInfo);
    return [NSString stringWithCString:systemInfo.machine encoding:NSUTF8StringEncoding];
}

NSInteger majorIndexOfDeviceIdentifierFor(NSString* devicePrefix)
{
    NSString *deviceId = device(); // e.g. "iPhone9,1"

    if (![deviceId hasPrefix:devicePrefix]) {
        return 0;
    }

    return [[deviceId substringFromIndex:[devicePrefix length]] integerValue];
}


// Setup

void ReproCpp::setup(const char* token) {
    [Repro setup: repro::ReproConverterIOS::convertCStringToNSString(token) ?: @""];
}

// OptIn / OptOut

void ReproCpp::optIn(bool endUserOptedIn) {
    [Repro optIn:endUserOptedIn];
}

// Log Level

void ReproCpp::setLogLevel(const char* logLevel) {
    if ([repro::ReproConverterIOS::convertCStringToNSString(logLevel) ?: @"" isEqualToString:@"Debug"]) {
        [Repro setLogLevel:RPRLogLevelDebug];
    } else if ([repro::ReproConverterIOS::convertCStringToNSString(logLevel) ?: @"" isEqualToString:@"Info"]) {
        [Repro setLogLevel:RPRLogLevelInfo];
    } else if ([repro::ReproConverterIOS::convertCStringToNSString(logLevel) ?: @"" isEqualToString:@"Warn"]) {
        [Repro setLogLevel:RPRLogLevelWarn];
    } else if ([repro::ReproConverterIOS::convertCStringToNSString(logLevel) ?: @"" isEqualToString:@"Error"]) {
        [Repro setLogLevel:RPRLogLevelError];
    } else if ([repro::ReproConverterIOS::convertCStringToNSString(logLevel) ?: @"" isEqualToString:@"None"]) {
        [Repro setLogLevel:RPRLogLevelNone];
    }
}

// User Profile

void ReproCpp::setUserID(const char* userId) {
    [Repro setUserID: repro::ReproConverterIOS::convertCStringToNSString(userId) ?: @""];
}

const char* ReproCpp::getUserID() {
  return repro::ReproConverterIOS::convertNSStringToCString([Repro getUserID]);
}

const char* ReproCpp::getDeviceID() {
  return repro::ReproConverterIOS::convertNSStringToCString([Repro getDeviceID]);
}

void ReproCpp::setStringUserProfile(const char* key, const char* value) {
  [Repro setStringUserProfile: repro::ReproConverterIOS::convertCStringToNSString(value) ?: @""
                       forKey: repro::ReproConverterIOS::convertCStringToNSString(key) ?: @""];
}

void ReproCpp::setIntUserProfile(const char* key, int value) {
  [Repro setIntUserProfile:value forKey: repro::ReproConverterIOS::convertCStringToNSString(key) ?: @""];
}

void ReproCpp::setDoubleUserProfile(const char* key, double value) {
  [Repro setDoubleUserProfile:value forKey: repro::ReproConverterIOS::convertCStringToNSString(key) ?: @""];
}

void ReproCpp::setDateUserProfile(const char* key, std::time_t value) {
  [Repro setDateUserProfile:[NSDate dateWithTimeIntervalSince1970:value]
                     forKey: repro::ReproConverterIOS::convertCStringToNSString(key) ?: @""];
}

// Standard Event Tracking

void ReproCpp::trackViewContent(const char* contentId, repro::ViewContentProperties* properties) {
    [Repro trackViewContent: repro::ReproConverterIOS::convertCStringToNSString(contentId) ?: @""
                 properties: repro::ReproConverterIOS::convertToViewContentProperties(properties)];
}

void ReproCpp::trackSearch(repro::SearchProperties* properties) {
    [Repro trackSearch: repro::ReproConverterIOS::convertToSearchProperties(properties)];
}

void ReproCpp::trackAddToCart(const char* contentId, repro::AddToCartProperties* properties) {
    [Repro trackAddToCart: repro::ReproConverterIOS::convertCStringToNSString(contentId) ?: @""
               properties: repro::ReproConverterIOS::convertToAddToCartProperties(properties)];
}

void ReproCpp::trackAddToWishlist(repro::AddToWishlistProperties* properties) {
    [Repro trackAddToWishlist: repro::ReproConverterIOS::convertToAddToWishlistProperties(properties)];
}

void ReproCpp::trackInitiateCheckout(repro::InitiateCheckoutProperties* properties) {
    [Repro trackInitiateCheckout: repro::ReproConverterIOS::convertToInitiateCheckoutProperties(properties)];
}

void ReproCpp::trackAddPaymentInfo(repro::AddPaymentInfoProperties* properties) {
    [Repro trackAddPaymentInfo: repro::ReproConverterIOS::convertToAddPaymentInfoProperties(properties)];
}

void ReproCpp::trackPurchase(const char* contentId, double value, const char* currency, repro::PurchaseProperties* properties) {
    [Repro trackPurchase: repro::ReproConverterIOS::convertCStringToNSString(contentId) ?: @""
                   value: value
                currency: repro::ReproConverterIOS::convertCStringToNSString(currency) ?: @""
              properties: repro::ReproConverterIOS::convertToPurchaseProperties(properties)];
}

void ReproCpp::trackShare(repro::ShareProperties* properties) {
    [Repro trackShare: repro::ReproConverterIOS::convertToShareProperties(properties)];
}

void ReproCpp::trackLead(repro::LeadProperties* properties) {
    [Repro trackLead: repro::ReproConverterIOS::convertToLeadProperties(properties)];
}

void ReproCpp::trackCompleteRegistration(repro::CompleteRegistrationProperties *properties) {
    [Repro trackCompleteRegistration: repro::ReproConverterIOS::convertToCompleteRegistrationProperties(properties)];
}

// Event Tracking

void ReproCpp::track(const char* eventName) {
    [Repro track: repro::ReproConverterIOS::convertCStringToNSString(eventName) ?: @"" properties:nil];
}

void ReproCpp::trackWithProperties(const char* eventName, const char* jsonDictionary) {
    [Repro track: repro::ReproConverterIOS::convertCStringToNSString(eventName) ?: @""
      properties: repro::ReproConverterIOS::convertCStringJSONToNSDictionary(jsonDictionary)];
}

// In App Message

void ReproCpp::disableInAppMessageOnActive() {
    [Repro disableInAppMessageOnActive];
}

void ReproCpp::showInAppMessage() {
    [Repro showInAppMessage];
}

// Push Notification

void ReproCpp::setPushRegistrationID(const char* registrationID) {
    // not supported in iOS
}
