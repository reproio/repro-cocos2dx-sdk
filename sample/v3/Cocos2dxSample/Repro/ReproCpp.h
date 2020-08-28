//
//  ReproCpp.h
//
//  Created by jollyjoester_pro on 10/31/14.
//  Copyright (c) 2014 Repro Inc. All rights reserved.
//

#ifndef __REPRO_CPP_H__
#define __REPRO_CPP_H__

#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <functional>
#include "ReproEventProperties.h"
#include "ReproCppConfig.h"

#if defined(__ANDROID__)
#include <jni.h>
#define NativeNewsFeedEntry     jobject
#define NativeRemoteConfigValue jobject
#define NativeRemoteConfig      jobject
#elif defined(__OBJC__)
#import <Repro/Repro.h>
@class RPRNewsFeedEntry;
#define NativeNewsFeedEntry     RPRNewsFeedEntry*
#define NativeRemoteConfigValue RPRRemoteConfigValue*
#define NativeRemoteConfig      RPRRemoteConfig*
#else
#define NativeNewsFeedEntry     void*
#define NativeRemoteConfigValue void*
#define NativeRemoteConfig      void*
#endif

class ReproCpp {

public:

    class NewsFeedEntry {

    private:
        NativeNewsFeedEntry newsFeedEntry;

    public:
        NewsFeedEntry(NativeNewsFeedEntry newsFeedEntry);

        NativeNewsFeedEntry getNativeNewsFeedEntry();

        uint64_t getID();
        const char * getDeviceID();
        const char * getTitle();
        const char * getSummary();
        const char * getBody();
        const char * getLinkUrl();
        const char * getImageUrl();
        time_t getDeliveredAt();
        bool getShown();
        bool getRead();
        void setShown(bool value);
        void setRead(bool value);
    };

    class RemoteConfigValue {

    private:
        NativeRemoteConfigValue remoteConfigValue;

    public:
        RemoteConfigValue(NativeRemoteConfigValue remoteConfigValue);

        const char* getStringValue();
    };
    class RemoteConfig {

    public:

        enum FetchStatus : int {
            FetchStatusSuccess = 0,
            FetchStatusTimeoutReached,
            FetchStatusAlreadyFetched
        };

    private:
        NativeRemoteConfig remoteConfig;
        std::function<void(FetchStatus status)> completion;

    public:
        RemoteConfig(NativeRemoteConfig remoteConfig);

        void fetch(double timeout, std::function<void(FetchStatus status)> completion);
        bool activateFetched();
        bool setDefaultsFromMap(std::map<std::string, std::string> values);
        bool setDefaultsFromJsonFile(const char *filePath);
        bool setDefaultsFromJsonString(const char *jsonString);

        RemoteConfigValue get(const char *key);
        RemoteConfigValue getLocalDefaultValue(const char *key);
        std::map<std::string, RemoteConfigValue*> getAllValues();
        std::map<std::string, RemoteConfigValue*> getAllValuesWithPrefix(const char *prefix);

        void forceReset();
    };

    enum UserProfileGender : int {
        UserProfileGenderOther = 0,
        UserProfileGenderMale,
        UserProfileGenderFemale
    };

    // Setup
    static void setup(const char* token);

    // OptIn / OptOut
    static void optIn(bool endUserOptedIn);

    // Log Level
    static void setLogLevel(const char* logLevel);

    // User Profile
    static void setUserID(const char* userId);
    static const char* getUserID();
    static const char* getDeviceID();
    static void setStringUserProfile(const char* key, const char* value);
    static void setIntUserProfile(const char* key, int value);
    static void setDoubleUserProfile(const char* key, double value);
    static void setDateUserProfile(const char* key, std::time_t value);
    static void setUserGender(enum UserProfileGender gender);
    static void setUserEmailAddress(const char* value);

    // Standard Event Tracking
    static void trackViewContent(const char* contentId, repro::ViewContentProperties* properties);
    static void trackSearch(repro::SearchProperties* properties);
    static void trackAddToCart(const char* contentId, repro::AddToCartProperties* properties);
    static void trackAddToWishlist(repro::AddToWishlistProperties* properties);
    static void trackInitiateCheckout(repro::InitiateCheckoutProperties* properties);
    static void trackAddPaymentInfo(repro::AddPaymentInfoProperties* properties);
    static void trackPurchase(const char* contentId, double value, const char* currency, repro::PurchaseProperties* properties);
    static void trackShare(repro::ShareProperties* properties);
    static void trackLead(repro::LeadProperties* properties);
    static void trackCompleteRegistration(repro::CompleteRegistrationProperties* properties);

    // Event Tracking
    static void track(const char*eventName);
    static void trackWithProperties(const char* eventName, const char* jsonDictionary);

    // In App Message
    static void disableInAppMessagesOnForegroundTransition();
    static void enableInAppMessagesOnForegroundTransition();

    // Push Notification
    static void setPushRegistrationID(const char* registrationID);

    // SilverEgg
    static void setSilverEggCookie(const char* cookie);
    static void setSilverEggProdKey(const char* key);

    // NewsFeed
    static std::vector<ReproCpp::NewsFeedEntry> getNewsFeeds(uint64_t limit, bool *error);
    static std::vector<ReproCpp::NewsFeedEntry> getNewsFeeds(uint64_t limit, uint64_t offsetID, bool *error);
    static bool updateNewsFeeds(std::vector<ReproCpp::NewsFeedEntry> newsFeeds, bool *error);

    // RemoteConfig
    static ReproCpp::RemoteConfig getRemoteConfig();
};

#if defined(__ANDROID__)
extern "C" {

    // To ensure expand className, it needs two steps.
    #define DECL_JNI_CALLBACK(className, methodName, arg)  DECL_JNI_CALLBACK_2(className, methodName, arg)
    #define DECL_JNI_CALLBACK_2(className, methodName, arg)  JNIEXPORT void JNICALL Java_ ## className ## _ ## methodName (JNIEnv* env, jobject thiz, arg)

    DECL_JNI_CALLBACK(JNI_REPRO_CLIENT_BRIDGE, nativeListenerHandler, jobject status);

};
#endif


#endif
