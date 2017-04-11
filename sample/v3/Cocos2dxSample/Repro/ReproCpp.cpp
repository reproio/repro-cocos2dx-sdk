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

#define CLASS_NAME_REPRO_SDK "io.repro.android.Repro"
#define CLASS_NAME_REPRO_SDK_BRIDGE "io.repro.android.Cocos2dxBridge"
#define CLASS_NAME_REPRO_CLIENT_BRIDGE "io.repro.cocos2dx.v3.sample.ReproBridge"

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

void ReproCpp::startRecording() {
    // startRecording is not supported for Android. No operation is executed.
}

void ReproCpp::stopRecording() {
    // stopRecording is not supported for Android. No operation is executed.
}

void ReproCpp::pauseRecording() {
    // pauseRecording is not supported for Android. No operation is executed.
}

void ReproCpp::resumeRecording() {
    // resumeRecording is not supported for Android. No operation is executed.
}

void ReproCpp::maskWithRect(float x, float y, float width, float height, const char* key) {
    // maskWithRect is not supported for Android. No operation is executed.
}

void ReproCpp::unmaskWithRect(const char* key) {
    // unmaskWithRect is not supported for Android. No operation is executed.
}

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

void ReproCpp::disableInAppMessageOnActive() {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_SDK, "disableInAppMessageOnActive", "()V")){
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}

void ReproCpp::showInAppMessage() {
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_CLIENT_BRIDGE, "showInAppMessage", "()V")){
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return;
    }
}
