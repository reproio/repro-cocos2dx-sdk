#include <android/log.h>
#include "platform/android/jni/JniHelper.h"
#include "ReproConverterAndroid.h"
#include "ReproCpp.h"

ReproCpp::NewsFeedEntry::NewsFeedEntry(NativeNewsFeedEntry newsFeedEntry)
{
    this->newsFeedEntry = newsFeedEntry;
}

NativeNewsFeedEntry ReproCpp::NewsFeedEntry::getNativeNewsFeedEntry()
{
    return this->newsFeedEntry;
}

static jclass getNewsFeedEntryClass(JNIEnv *env)
{
    return env->FindClass("io/repro/android/newsfeed/NewsFeedEntry");
}

uint64_t ReproCpp::NewsFeedEntry::getID()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return 0;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "id", "J");
    jlong jID = env->GetLongField(this->newsFeedEntry, fieldID);

    env->DeleteLocalRef(classNewsFeedEntry);
    return (uint64_t)jID;
}

const char * ReproCpp::NewsFeedEntry::getDeviceID()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return nullptr;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "deviceID", "Ljava/lang/String;");
    jstring stringDeviceID = (jstring)env->GetObjectField(this->newsFeedEntry, fieldID);
    const char *deviceId = env->GetStringUTFChars(stringDeviceID, NULL);

    env->DeleteLocalRef(stringDeviceID);
    env->DeleteLocalRef(classNewsFeedEntry);
    return deviceId;
}

const char * ReproCpp::NewsFeedEntry::getTitle()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return nullptr;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "title", "Ljava/lang/String;");
    jstring stringTitle = (jstring)env->GetObjectField(this->newsFeedEntry, fieldID);
    const char *title = env->GetStringUTFChars(stringTitle, NULL);

    env->DeleteLocalRef(stringTitle);
    env->DeleteLocalRef(classNewsFeedEntry);
    return title;
}

const char * ReproCpp::NewsFeedEntry::getSummary()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return nullptr;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "summary", "Ljava/lang/String;");
    jstring stringSummary = (jstring)env->GetObjectField(this->newsFeedEntry, fieldID);
    const char *summary = env->GetStringUTFChars(stringSummary, NULL);

    env->DeleteLocalRef(stringSummary);
    env->DeleteLocalRef(classNewsFeedEntry);
    return summary;
}

const char * ReproCpp::NewsFeedEntry::getBody()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return nullptr;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "body", "Ljava/lang/String;");
    jstring stringBody = (jstring)env->GetObjectField(this->newsFeedEntry, fieldID);
    const char *body = env->GetStringUTFChars(stringBody, NULL);

    env->DeleteLocalRef(stringBody);
    env->DeleteLocalRef(classNewsFeedEntry);
    return body;
}

const char * ReproCpp::NewsFeedEntry::getLinkUrl()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return nullptr;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "linkUrl", "Landroid/net/Uri;");
    jobject linkUrl = env->GetObjectField(this->newsFeedEntry, fieldID);

    jclass classUrl = env->FindClass("android/net/Uri");
    jmethodID methodToString = env->GetMethodID(classUrl, "toString", "()Ljava/lang/String;");
    jstring stringLinkUrl = (jstring)env->CallObjectMethod(linkUrl, methodToString);

    const char *url = env->GetStringUTFChars(stringLinkUrl, NULL);

    env->DeleteLocalRef(linkUrl);
    env->DeleteLocalRef(stringLinkUrl);
    env->DeleteLocalRef(classUrl);
    env->DeleteLocalRef(classNewsFeedEntry);
    return url;
}

const char * ReproCpp::NewsFeedEntry::getImageUrl()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return nullptr;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "imageUrl", "Landroid/net/Uri;");
    jobject imageUrl = env->GetObjectField(this->newsFeedEntry, fieldID);

    jclass classUrl = env->FindClass("android/net/Uri");
    jmethodID methodToString = env->GetMethodID(classUrl, "toString", "()Ljava/lang/String;");
    jstring stringImageUrl = (jstring)env->CallObjectMethod(imageUrl, methodToString);

    const char *url = env->GetStringUTFChars(stringImageUrl, NULL);

    env->DeleteLocalRef(imageUrl);
    env->DeleteLocalRef(stringImageUrl);
    env->DeleteLocalRef(classUrl);
    env->DeleteLocalRef(classNewsFeedEntry);
    return url;
}

time_t ReproCpp::NewsFeedEntry::getDeliveredAt()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return 0;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "deliveredAt", "Ljava/util/Date;");
    jobject deliveredAt = env->GetObjectField(this->newsFeedEntry, fieldID);

	jclass classDate = env->FindClass("java/util/Date");
	jmethodID methodGetTime = env->GetMethodID(classDate, "getTime", "()J");
    jlong jTime = env->CallLongMethod(deliveredAt, methodGetTime);

    env->DeleteLocalRef(deliveredAt);
    env->DeleteLocalRef(classDate);
    env->DeleteLocalRef(classNewsFeedEntry);
    return (time_t)(jTime / 1000);
}

bool ReproCpp::NewsFeedEntry::getShown()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return false;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "shown", "Z");
    jboolean shown = env->GetBooleanField(this->newsFeedEntry, fieldID);

    env->DeleteLocalRef(classNewsFeedEntry);
    return (bool)shown;
}

bool ReproCpp::NewsFeedEntry::getRead()
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return false;
    }
    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "read", "Z");
    jboolean read = env->GetBooleanField(this->newsFeedEntry, fieldID);

    env->DeleteLocalRef(classNewsFeedEntry);
    return (bool)read;
}

void ReproCpp::NewsFeedEntry::setShown(bool value)
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return;
    }

    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "shown", "Z");
    env->SetBooleanField(this->newsFeedEntry, fieldID, (jboolean)value);

    env->DeleteLocalRef(classNewsFeedEntry);
}

void ReproCpp::NewsFeedEntry::setRead(bool value)
{
    JNIEnv *env = cocos2d::JniHelper::getEnv();
    if (!env) {
        return;
    }

    jclass classNewsFeedEntry = getNewsFeedEntryClass(env);
    jfieldID fieldID = env->GetFieldID(classNewsFeedEntry, "read", "Z");
    env->SetBooleanField(this->newsFeedEntry, fieldID, (jboolean)value);

    env->DeleteLocalRef(classNewsFeedEntry);
}
