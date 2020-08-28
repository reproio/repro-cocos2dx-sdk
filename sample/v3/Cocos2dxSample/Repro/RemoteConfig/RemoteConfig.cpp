#include <android/log.h>
#include "platform/android/jni/JniHelper.h"
#include "ReproConverterAndroid.h"
#include "ReproCpp.h"

#define CLASS_REMOTECONFIG_VALUE "io.repro.android.remoteconfig.RemoteConfigValue"
#define CLASS_REMOTECONFIG       "io.repro.android.remoteconfig.RemoteConfig"

// RemoteConfigValue

ReproCpp::RemoteConfigValue::RemoteConfigValue(NativeRemoteConfigValue remoteConfigValue)
{
    this->remoteConfigValue = remoteConfigValue;
}

const char* ReproCpp::RemoteConfigValue::getStringValue()
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG_VALUE, "asString", "()Ljava/lang/String;")) {
        jstring string = (jstring)methodInfo.env->CallObjectMethod(this->remoteConfigValue, methodInfo.methodID);
        if (!string) {
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
            return NULL;
        }

        const char *str = methodInfo.env->GetStringUTFChars(string, NULL);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return str;
    }
    return NULL;
}

// RemoteConfig

ReproCpp::RemoteConfig::RemoteConfig(NativeRemoteConfig remoteConfig)
{
    this->remoteConfig = remoteConfig;
}

static std::function<void(ReproCpp::RemoteConfig::FetchStatus error)> g_completion;

extern "C" {

    DECL_JNI_CALLBACK(JNI_REPRO_CLIENT_BRIDGE, nativeListenerHandler, jobject status)
    {
        if (g_completion) {
            JNIEnv *env = cocos2d::JniHelper::getEnv();
            if (!env) {
                return;
            }

            jclass classRemoteConfigListener = env->FindClass("io/repro/android/remoteconfig/RemoteConfigListener$FetchStatus");
            jmethodID getValueMethod = env->GetMethodID(classRemoteConfigListener, "ordinal", "()I");
            jint value = env->CallIntMethod(status, getValueMethod);

            ReproCpp::RemoteConfig::FetchStatus fetchStatus;
            switch (value) {
                case 0:
                    fetchStatus = ReproCpp::RemoteConfig::FetchStatusSuccess;
                    break;
                case 1:
                    fetchStatus = ReproCpp::RemoteConfig::FetchStatusTimeoutReached;
                    break;
                case 2:
                    fetchStatus = ReproCpp::RemoteConfig::FetchStatusAlreadyFetched;
                    break;
            }
            g_completion(fetchStatus);
            g_completion = nullptr;
        }
    }

};

void ReproCpp::RemoteConfig::fetch(double timeout, std::function<void(ReproCpp::RemoteConfig::FetchStatus error)> completion)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME_REPRO_CLIENT_BRIDGE, "fetchRemoteConfig", "(J)V")) {
        g_completion = completion;
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, (jlong)(timeout * 1000));

        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

bool ReproCpp::RemoteConfig::activateFetched()
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG, "activateFetched", "()Z")) {
        jboolean result = methodInfo.env->CallBooleanMethod(this->remoteConfig, methodInfo.methodID);

        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return (bool)result;
    }
    return false;
}

bool ReproCpp::RemoteConfig::setDefaultsFromMap(std::map<std::string, std::string> values)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG, "setDefaultsFromMap", "(Ljava/util/Map;)V")) {
        jclass classHashMap = methodInfo.env->FindClass("java/util/HashMap");
        jmethodID methodHashMapNew = methodInfo.env->GetMethodID(classHashMap, "<init>", "(I)V");
        jmethodID methodHashMapPut = methodInfo.env->GetMethodID(classHashMap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
        jobject defaults = methodInfo.env->NewObject(classHashMap, methodHashMapNew, values.size());

        for (auto iter = values.begin(); iter != values.end(); iter++) {
            jstring key   = methodInfo.env->NewStringUTF(iter->first.c_str());
            jstring value = methodInfo.env->NewStringUTF(iter->second.c_str());
            methodInfo.env->CallObjectMethod(defaults, methodHashMapPut, key, value);
        }

        methodInfo.env->CallVoidMethod(this->remoteConfig, methodInfo.methodID, defaults);

        methodInfo.env->DeleteLocalRef(defaults);
        methodInfo.env->DeleteLocalRef(classHashMap);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return true;
    }
    return false;
}

bool ReproCpp::RemoteConfig::setDefaultsFromJsonFile(const char *filePath)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG, "setDefaultsFromJsonFile", "(Ljava/lang/String;)Z")) {
        jstring stringPath = methodInfo.env->NewStringUTF(filePath);
        jboolean result = methodInfo.env->CallBooleanMethod(this->remoteConfig, methodInfo.methodID, stringPath);

        methodInfo.env->DeleteLocalRef(stringPath);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return result;
    }
    return false;
}

bool ReproCpp::RemoteConfig::setDefaultsFromJsonString(const char *jsonString)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG, "setDefaultsFromJsonString", "(Ljava/lang/String;)Z")) {
        jstring stringJson = methodInfo.env->NewStringUTF(jsonString);
        jboolean result = methodInfo.env->CallBooleanMethod(this->remoteConfig, methodInfo.methodID, stringJson);

        methodInfo.env->DeleteLocalRef(stringJson);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return result;
    }
    return false;
}

ReproCpp::RemoteConfigValue ReproCpp::RemoteConfig::get(const char *key)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG, "get", "(Ljava/lang/String;)Lio/repro/android/remoteconfig/RemoteConfigValue;")) {
        jstring stringKey = methodInfo.env->NewStringUTF(key);
        jobject value = methodInfo.env->CallObjectMethod(this->remoteConfig, methodInfo.methodID, stringKey);

        methodInfo.env->DeleteLocalRef(stringKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return ReproCpp::RemoteConfigValue(value);
    }
    return nullptr;
}

ReproCpp::RemoteConfigValue ReproCpp::RemoteConfig::getLocalDefaultValue(const char *key)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG, "getLocalDefaultValue", "(Ljava/lang/String;)Lio/repro/android/remoteconfig/RemoteConfigValue;")) {
        jstring stringKey = methodInfo.env->NewStringUTF(key);
        jobject value = methodInfo.env->CallObjectMethod(this->remoteConfig, methodInfo.methodID, stringKey);

        methodInfo.env->DeleteLocalRef(stringKey);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return ReproCpp::RemoteConfigValue(value);
    }
    return nullptr;
}


static std::map<std::string, ReproCpp::RemoteConfigValue*> convertValues(JNIEnv *env, jobject nativeValues)
{
    jclass classMap = env->FindClass("java/util/Map");
    jmethodID methodEntrySet = env->GetMethodID(classMap, "entrySet", "()Ljava/util/Set;");
    jobject set = env->CallObjectMethod(nativeValues, methodEntrySet);

    jclass classSet = env->FindClass("java/util/Set");
    jmethodID methodIterator = env->GetMethodID(classSet, "iterator", "()Ljava/util/Iterator;");
    jobject iter = env->CallObjectMethod(set, methodIterator);

    jclass classIterator = env->FindClass("java/util/Iterator");
    jmethodID methodHasNext = env->GetMethodID(classIterator, "hasNext", "()Z");
    jmethodID methodNext = env->GetMethodID(classIterator, "next", "()Ljava/lang/Object;");

    jclass classEntry = env->FindClass("java/util/Map$Entry");
    jmethodID methodGetKey = env->GetMethodID(classEntry, "getKey", "()Ljava/lang/Object;");
    jmethodID methodGetValue = env->GetMethodID(classEntry, "getValue", "()Ljava/lang/Object;");

    std::map<std::string, ReproCpp::RemoteConfigValue*> values;
    while (env->CallBooleanMethod(iter, methodHasNext)) {
        jobject hashEntry = env->CallObjectMethod(iter, methodNext);
        jstring hashKey = (jstring)env->CallObjectMethod(hashEntry, methodGetKey);
        jobject hashValue = env->CallObjectMethod(hashEntry, methodGetValue);

        const char* key = env->GetStringUTFChars(hashKey, NULL);
        ReproCpp::RemoteConfigValue value = ReproCpp::RemoteConfigValue(hashValue);

        values[key] = &value;


        env->DeleteLocalRef(hashKey);
        env->DeleteLocalRef(hashEntry);
    }

    env->DeleteLocalRef(classEntry);
    env->DeleteLocalRef(classIterator);
    env->DeleteLocalRef(classSet);
    env->DeleteLocalRef(classMap);
    return std::move(values);
}

std::map<std::string, ReproCpp::RemoteConfigValue*> ReproCpp::RemoteConfig::getAllValues()
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG, "getAllValues", "()Ljava/util/Map;")) {
        jobject nativeValues = methodInfo.env->CallObjectMethod(this->remoteConfig, methodInfo.methodID);

        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return convertValues(methodInfo.env, nativeValues);
    }

    std::map<std::string, ReproCpp::RemoteConfigValue*> values;
    return std::move(values);
}

std::map<std::string, ReproCpp::RemoteConfigValue*> ReproCpp::RemoteConfig::getAllValuesWithPrefix(const char *prefix)
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG, "getAllValuesWithPrefix", "(Ljava/lang/String;)Ljava/util/Map;")) {
        jstring stringPrefix = methodInfo.env->NewStringUTF(prefix);
        jobject nativeValues = methodInfo.env->CallObjectMethod(this->remoteConfig, methodInfo.methodID, stringPrefix);

        methodInfo.env->DeleteLocalRef(stringPrefix);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        return convertValues(methodInfo.env, nativeValues);
    }

    std::map<std::string, ReproCpp::RemoteConfigValue*> values;
    return std::move(values);
}

void ReproCpp::RemoteConfig::forceReset()
{
    cocos2d::JniMethodInfo methodInfo;
    if (cocos2d::JniHelper::getMethodInfo(methodInfo, CLASS_REMOTECONFIG, "forceReset", "()V")) {
        methodInfo.env->CallVoidMethod(this->remoteConfig, methodInfo.methodID);

        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}
