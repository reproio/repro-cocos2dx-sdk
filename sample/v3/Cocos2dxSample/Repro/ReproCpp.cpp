//
//  ReproCpp.cpp
//
//  Created by woshidan on 2017/03/30.
//  Copyright (c) 2017 Repro Inc. All rights reserved.
//

#include "ReproCpp.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>

#include "ReproConverterAndroid.h"

#define CLASS_NAME_REPRO_SDK "io.repro.android.Repro"
#define CLASS_NAME_REPRO_SDK_BRIDGE "io.repro.android.Cocos2dxBridge"

// Setup

void ReproCpp::setup(const char* token) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK_BRIDGE, "startSession",  "(Ljava/lang/String;)V"))
    {
        jstring jToken = methodInfo.env->NewStringUTF(token);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jToken);
        methodInfo.env->DeleteLocalRef(jToken);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

// OptIn / OptOut

void ReproCpp::optIn(bool endUserOptedIn) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "optIn", "(Z)V"))
    {
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, endUserOptedIn);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

// Log Level

void ReproCpp::setLogLevel(const char* logLevel) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK_BRIDGE, "setLogLevel", "(Ljava/lang/String;)V"))
    {
        jstring jLogLevel = methodInfo.env->NewStringUTF(logLevel);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jLogLevel);
        methodInfo.env->DeleteLocalRef(jLogLevel);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

// User Profile

void ReproCpp::setUserID(const char* userId)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "setUserID", "(Ljava/lang/String;)V")){
        jstring juserId = methodInfo.env->NewStringUTF(userId);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, juserId);
        methodInfo.env->DeleteLocalRef(juserId);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

const char* ReproCpp::getUserID()
{
    cocos2d::JniMethodInfo methodInfo;
    const char* userId;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "getUserID", "()Ljava/lang/String;")){
        jstring jUserId = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
        userId = methodInfo.env->GetStringUTFChars(jUserId, NULL);
        methodInfo.env->DeleteLocalRef(jUserId);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return userId;
    }
    return userId;
}

const char* ReproCpp::getDeviceID()
{
    cocos2d::JniMethodInfo methodInfo;
    const char* deviceId;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "getDeviceID", "()Ljava/lang/String;")){
        jstring jDeviceId = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
        deviceId = methodInfo.env->GetStringUTFChars(jDeviceId, NULL);
        methodInfo.env->DeleteLocalRef(jDeviceId);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return deviceId;
    }
    return deviceId;
}

void ReproCpp::setStringUserProfile(const char* key, const char* value) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "setStringUserProfile", "(Ljava/lang/String;Ljava/lang/String;)V")){
        jstring jKey = methodInfo.env->NewStringUTF(key);
        jstring jValue = methodInfo.env->NewStringUTF(value);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey, jValue);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(jValue);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::setIntUserProfile(const char* key, int value) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "setIntUserProfile", "(Ljava/lang/String;I)V")){
        jstring jKey = methodInfo.env->NewStringUTF(key);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey, value);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::setDoubleUserProfile(const char* key, double value) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "setDoubleUserProfile", "(Ljava/lang/String;D)V")){
        jstring jKey = methodInfo.env->NewStringUTF(key);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey, value);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::setDateUserProfile(const char* key, std::time_t value) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK_BRIDGE, "setDateUserProfile", "(Ljava/lang/String;J)V")){
        jstring jKey = methodInfo.env->NewStringUTF(key);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey, (jlong)value);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::setUserGender(enum UserProfileGender gender) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "setUserGender", "(Lio/repro/android/user/UserProfileGender;)V")){
        jclass jUserProfileGenderClass = methodInfo.env->FindClass("io/repro/android/user/UserProfileGender");
        const char *fieldSignature = "Lio/repro/android/user/UserProfileGender;";
        jfieldID jGenderField;
        jobject jGender;

        switch (gender) {
            case UserProfileGenderMale:
                jGenderField = methodInfo.env->GetStaticFieldID(jUserProfileGenderClass, "MALE", fieldSignature);
                jGender = methodInfo.env->GetStaticObjectField(jUserProfileGenderClass, jGenderField);
                break;
            case UserProfileGenderFemale:
                jGenderField = methodInfo.env->GetStaticFieldID(jUserProfileGenderClass, "FEMALE", fieldSignature);
                jGender = methodInfo.env->GetStaticObjectField(jUserProfileGenderClass, jGenderField);
                break;
            default:
                jGenderField = methodInfo.env->GetStaticFieldID(jUserProfileGenderClass, "OTHER", fieldSignature);
                jGender = methodInfo.env->GetStaticObjectField(jUserProfileGenderClass, jGenderField);
        }

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jGender);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        methodInfo.env->DeleteLocalRef(jGender);
        methodInfo.env->DeleteLocalRef(jUserProfileGenderClass);
    }
}

void ReproCpp::setUserEmailAddress(const char* value) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "setUserEmailAddress", "(Ljava/lang/String;)V")){
        jstring jValue = methodInfo.env->NewStringUTF(value);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jValue);
        methodInfo.env->DeleteLocalRef(jValue);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

// Standard Event Tracking

void ReproCpp::trackViewContent(const char *contentId, repro::ViewContentProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackViewContent", "(Ljava/lang/String;Lio/repro/android/tracking/ViewContentProperties;)V")){
        jstring jContentId = methodInfo.env->NewStringUTF(contentId);
        jobject jProperties = repro::ReproConverterAndroid::convertToViewContentProperties(methodInfo.env, properties);
        
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jContentId, jProperties);
        methodInfo.env->DeleteLocalRef(jContentId);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackSearch(repro::SearchProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackSearch", "(Lio/repro/android/tracking/SearchProperties;)V")){
        jobject jProperties = repro::ReproConverterAndroid::convertToSearchProperties(methodInfo.env, properties);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jProperties);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackAddToCart(const char *contentId, repro::AddToCartProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackAddToCart", "(Ljava/lang/String;Lio/repro/android/tracking/AddToCartProperties;)V")){
        jstring jContentId = methodInfo.env->NewStringUTF(contentId);
        jobject jProperties = repro::ReproConverterAndroid::convertToAddToCartProperties(methodInfo.env, properties);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jContentId, jProperties);
        methodInfo.env->DeleteLocalRef(jContentId);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackAddToWishlist(repro::AddToWishlistProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackAddToWishlist", "(Lio/repro/android/tracking/AddToWishlistProperties;)V")){
        jobject jProperties = repro::ReproConverterAndroid::convertToAddToWishlistProperties(methodInfo.env, properties);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jProperties);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackInitiateCheckout(repro::InitiateCheckoutProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackInitiateCheckout", "(Lio/repro/android/tracking/InitiateCheckoutProperties;)V")){
        jobject jProperties = repro::ReproConverterAndroid::convertToInitiateCheckoutProperties(methodInfo.env, properties);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jProperties);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackPurchase(const char *contentId, double value, const char *currency,
                             repro::PurchaseProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackPurchase", "(Ljava/lang/String;DLjava/lang/String;Lio/repro/android/tracking/PurchaseProperties;)V")){
        jstring jContentId = methodInfo.env->NewStringUTF(contentId);
        jstring jCurrency = methodInfo.env->NewStringUTF(currency);
        jobject jProperties = repro::ReproConverterAndroid::convertToPurchaseProperties(methodInfo.env, properties);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jContentId, value, jCurrency, jProperties);
        methodInfo.env->DeleteLocalRef(jContentId);
        methodInfo.env->DeleteLocalRef(jCurrency);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackAddPaymentInfo(repro::AddPaymentInfoProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackAddPaymentInfo", "(Lio/repro/android/tracking/AddPaymentInfoProperties;)V")){
        jobject jProperties = repro::ReproConverterAndroid::convertToAddPaymentInfoProperties(methodInfo.env, properties);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jProperties);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackShare(repro::ShareProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackShare", "(Lio/repro/android/tracking/ShareProperties;)V")){
        jobject jProperties = repro::ReproConverterAndroid::convertToShareProperties(methodInfo.env, properties);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jProperties);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackLead(repro::LeadProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackLead", "(Lio/repro/android/tracking/LeadProperties;)V")){
        jobject jProperties = repro::ReproConverterAndroid::convertToLeadProperties(methodInfo.env, properties);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jProperties);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackCompleteRegistration(repro::CompleteRegistrationProperties *properties) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "trackCompleteRegistration", "(Lio/repro/android/tracking/CompleteRegistrationProperties;)V")){
        jobject jProperties = repro::ReproConverterAndroid::convertToCompleteRegistrationProperties(methodInfo.env, properties);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jProperties);
        methodInfo.env->DeleteLocalRef(jProperties);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

// Event Tracking

void ReproCpp::track(const char* eventName) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "track", "(Ljava/lang/String;)V")){
        jstring jEventName = methodInfo.env->NewStringUTF(eventName);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventName);
        methodInfo.env->DeleteLocalRef(jEventName);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

void ReproCpp::trackWithProperties(const char* eventName, const char* jsonDictionary) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK_BRIDGE, "trackWithProperties", "(Ljava/lang/String;Ljava/lang/String;)V")){
        jstring jEventName = methodInfo.env->NewStringUTF(eventName);
        jstring jJsonDictionary = methodInfo.env->NewStringUTF(jsonDictionary);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventName, jJsonDictionary);
        methodInfo.env->DeleteLocalRef(jEventName);
        methodInfo.env->DeleteLocalRef(jJsonDictionary);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

// In App Message

void ReproCpp::disableInAppMessagesOnForegroundTransition() {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "disableInAppMessagesOnForegroundTransition", "()V")){
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

void ReproCpp::enableInAppMessagesOnForegroundTransition() {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_CLIENT_BRIDGE, "enableInAppMessagesOnForegroundTransition", "()V")){
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

// Push Notification

void ReproCpp::setPushRegistrationID(const char* registrationID) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "setPushRegistrationID", "(Ljava/lang/String;)V")){
        jstring jRegistrationID = methodInfo.env->NewStringUTF(registrationID);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jRegistrationID);
        methodInfo.env->DeleteLocalRef(jRegistrationID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

// SilverEgg

void ReproCpp::setSilverEggCookie(const char* cookie) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "setSilverEggCookie", "(Ljava/lang/String;)V")){
        jstring jCookie = methodInfo.env->NewStringUTF(cookie);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jCookie);
        methodInfo.env->DeleteLocalRef(jCookie);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

void ReproCpp::setSilverEggProdKey(const char* key) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "setSilverEggProdKey", "(Ljava/lang/String;)V")){
        jstring jKey = methodInfo.env->NewStringUTF(key);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jKey);
        methodInfo.env->DeleteLocalRef(jKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

// NewsFeed

#define SET_SUCCESS() if (error) { *error = false; }
#define SET_ERROR() if (error) { *error = true; }

static std::vector<ReproCpp::NewsFeedEntry> convertNewsFeed(JNIEnv *env, jobject nativeNewsFeeds)
{
    std::vector<ReproCpp::NewsFeedEntry> newsFeeds;

    jclass clsList = env->FindClass("java/util/List");
    jmethodID methodSize = env->GetMethodID(clsList, "size", "()I");
    jmethodID methodGet = env->GetMethodID(clsList, "get", "(I)Ljava/lang/Object;");
    if (clsList == NULL || methodSize == NULL || methodGet == NULL) {
        return std::move(newsFeeds);
    }

    jint count = env->CallIntMethod(nativeNewsFeeds, methodSize);
    for (jint i = 0; i < count; i++) {
        jobject jEntry = env->CallObjectMethod(nativeNewsFeeds, methodGet, i);
        newsFeeds.push_back(ReproCpp::NewsFeedEntry(jEntry));
    }

    return std::move(newsFeeds);
}

std::vector<ReproCpp::NewsFeedEntry> ReproCpp::getNewsFeeds(uint64_t limit, bool *error) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "getNewsFeeds", "(I)Ljava/util/List;")){
        jobject jNewsFeeds = methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, (jint)limit);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        if (methodInfo.env->ExceptionCheck()) {
            SET_ERROR();

            std::vector<ReproCpp::NewsFeedEntry> newsFeeds;
            return std::move(newsFeeds);
        }

        SET_SUCCESS();
        return convertNewsFeed(methodInfo.env, jNewsFeeds);
    }

    SET_ERROR();
    std::vector<ReproCpp::NewsFeedEntry> newsFeeds;
    return std::move(newsFeeds);
}

std::vector<ReproCpp::NewsFeedEntry> ReproCpp::getNewsFeeds(uint64_t limit, uint64_t offsetID, bool *error) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "getNewsFeeds", "(IJ)Ljava/util/List;")){
        jobject jNewsFeeds = methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, (jint)limit, (jlong)offsetID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        if (methodInfo.env->ExceptionCheck()) {
            SET_ERROR();
            std::vector<ReproCpp::NewsFeedEntry> newsFeeds;
            return std::move(newsFeeds);
        }

        SET_SUCCESS();
        return convertNewsFeed(methodInfo.env, jNewsFeeds);
    }

    SET_ERROR();
    std::vector<ReproCpp::NewsFeedEntry> newsFeeds;
    return std::move(newsFeeds);
}

bool ReproCpp::updateNewsFeeds(std::vector<ReproCpp::NewsFeedEntry> newsFeeds, bool *error) {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "updateNewsFeeds", "(Ljava/util/List;)V")){
        jclass classArrayList = methodInfo.env->FindClass("java/util/ArrayList");
        jmethodID methodArrayListNew = methodInfo.env->GetMethodID(classArrayList, "<init>", "(I)V");
        jmethodID methodArrayListAdd = methodInfo.env->GetMethodID(classArrayList, "add", "(Ljava/lang/Object;)Z");

        jobject list = methodInfo.env->NewObject(classArrayList, methodArrayListNew, newsFeeds.size());
        for (auto iter = newsFeeds.begin(); iter != newsFeeds.end(); iter++) {
            ReproCpp::NewsFeedEntry entry = *iter;
            methodInfo.env->CallBooleanMethod(list, methodArrayListAdd, entry.getNativeNewsFeedEntry());
        }
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, list);

        methodInfo.env->DeleteLocalRef(classArrayList);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        if (methodInfo.env->ExceptionCheck()) {
            SET_ERROR();
            return false;
        }

        SET_SUCCESS();
        return true;
    }

    SET_ERROR();
    return false;
}

// RemoteConfig

ReproCpp::RemoteConfig ReproCpp::getRemoteConfig()
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "getRemoteConfig", "()Lio/repro/android/remoteconfig/RemoteConfig;")){
        jobject remoteConfig = methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);

        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return ReproCpp::RemoteConfig(remoteConfig);
    }
    return nullptr;
}
