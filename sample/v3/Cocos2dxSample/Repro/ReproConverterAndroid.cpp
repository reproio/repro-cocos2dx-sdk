#include "ReproConverterAndroid.h"
using namespace repro;

jobject ReproConverterAndroid::convertToViewContentProperties(JNIEnv* env, const ViewContentProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/ViewContentProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(VALUE)) setDoubleValueToObject(env, jClass, jProperties, "setValue", properties->getValue());
    if (properties->has(CURRENCY)) setStringValueToObject(env, jClass, jProperties, "setCurrency", properties->getCurrency());
    if (properties->has(CONTENT_NAME)) setStringValueToObject(env, jClass, jProperties, "setContentName", properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) setStringValueToObject(env, jClass, jProperties, "setContentCategory", properties->getContentCategory());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

jobject ReproConverterAndroid::convertToSearchProperties(JNIEnv* env, const SearchProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/SearchProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(VALUE)) setDoubleValueToObject(env, jClass, jProperties, "setValue", properties->getValue());
    if (properties->has(CURRENCY)) setStringValueToObject(env, jClass, jProperties, "setCurrency", properties->getCurrency());
    if (properties->has(CONTENT_CATEGORY)) setStringValueToObject(env, jClass, jProperties, "setContentCategory", properties->getContentCategory());
    if (properties->has(SEARCH_STRING)) setStringValueToObject(env, jClass, jProperties, "setSearchString", properties->getSearchString());
    if (properties->has(CONTENT_ID)) setStringValueToObject(env, jClass, jProperties, "setContentId", properties->getContentId());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

jobject ReproConverterAndroid::convertToAddToCartProperties(JNIEnv* env, const AddToCartProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/AddToCartProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(VALUE)) setDoubleValueToObject(env, jClass, jProperties, "setValue", properties->getValue());
    if (properties->has(CURRENCY)) setStringValueToObject(env, jClass, jProperties, "setCurrency", properties->getCurrency());
    if (properties->has(CONTENT_NAME)) setStringValueToObject(env, jClass, jProperties, "setContentName", properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) setStringValueToObject(env, jClass, jProperties, "setContentCategory", properties->getContentCategory());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

jobject ReproConverterAndroid::convertToAddToWishlistProperties(JNIEnv* env, const AddToWishlistProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/AddToWishlistProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(VALUE)) setDoubleValueToObject(env, jClass, jProperties, "setValue", properties->getValue());
    if (properties->has(CURRENCY)) setStringValueToObject(env, jClass, jProperties, "setCurrency", properties->getCurrency());
    if (properties->has(CONTENT_NAME)) setStringValueToObject(env, jClass, jProperties, "setContentName", properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) setStringValueToObject(env, jClass, jProperties, "setContentCategory", properties->getContentCategory());
    if (properties->has(CONTENT_ID)) setStringValueToObject(env, jClass, jProperties, "setContentId", properties->getContentId());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

jobject ReproConverterAndroid::convertToInitiateCheckoutProperties(JNIEnv* env, const InitiateCheckoutProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/InitiateCheckoutProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(VALUE)) setDoubleValueToObject(env, jClass, jProperties, "setValue", properties->getValue());
    if (properties->has(CURRENCY)) setStringValueToObject(env, jClass, jProperties, "setCurrency", properties->getCurrency());
    if (properties->has(CONTENT_NAME)) setStringValueToObject(env, jClass, jProperties, "setContentName", properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) setStringValueToObject(env, jClass, jProperties, "setContentCategory", properties->getContentCategory());
    if (properties->has(CONTENT_ID)) setStringValueToObject(env, jClass, jProperties, "setContentId", properties->getContentId());
    if (properties->has(NUM_ITEMS)) setIntValueToObject(env, jClass, jProperties, "setNumItems", properties->getNumItems());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

jobject ReproConverterAndroid::convertToAddPaymentInfoProperties(JNIEnv* env, const AddPaymentInfoProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/AddPaymentInfoProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(VALUE)) setDoubleValueToObject(env, jClass, jProperties, "setValue", properties->getValue());
    if (properties->has(CURRENCY)) setStringValueToObject(env, jClass, jProperties, "setCurrency", properties->getCurrency());
    if (properties->has(CONTENT_CATEGORY)) setStringValueToObject(env, jClass, jProperties, "setContentCategory", properties->getContentCategory());
    if (properties->has(CONTENT_ID)) setStringValueToObject(env, jClass, jProperties, "setContentId", properties->getContentId());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

jobject ReproConverterAndroid::convertToPurchaseProperties(JNIEnv* env, const PurchaseProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/PurchaseProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(CONTENT_NAME)) setStringValueToObject(env, jClass, jProperties, "setContentName", properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) setStringValueToObject(env, jClass, jProperties, "setContentCategory", properties->getContentCategory());
    if (properties->has(NUM_ITEMS)) setIntValueToObject(env, jClass, jProperties, "setNumItems", properties->getNumItems());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

jobject ReproConverterAndroid::convertToShareProperties(JNIEnv* env, const ShareProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/ShareProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(CONTENT_NAME)) setStringValueToObject(env, jClass, jProperties, "setContentName", properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) setStringValueToObject(env, jClass, jProperties, "setContentCategory", properties->getContentCategory());
    if (properties->has(CONTENT_ID)) setStringValueToObject(env, jClass, jProperties, "setContentId", properties->getContentId());
    if (properties->has(SERVICE_NAME)) setStringValueToObject(env, jClass, jProperties, "setServiceName", properties->getServiceName());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

jobject ReproConverterAndroid::convertToLeadProperties(JNIEnv* env, const LeadProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/LeadProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(VALUE)) setDoubleValueToObject(env, jClass, jProperties, "setValue", properties->getValue());
    if (properties->has(CURRENCY)) setStringValueToObject(env, jClass, jProperties, "setCurrency", properties->getCurrency());
    if (properties->has(CONTENT_NAME)) setStringValueToObject(env, jClass, jProperties, "setContentName", properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) setStringValueToObject(env, jClass, jProperties, "setContentCategory", properties->getContentCategory());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

jobject ReproConverterAndroid::convertToCompleteRegistrationProperties(JNIEnv* env, const CompleteRegistrationProperties* properties) {
    jclass jClass = env->FindClass("io/repro/android/tracking/CompleteRegistrationProperties");
    jmethodID jMethodID = env->GetMethodID(jClass, "<init>", "()V");
    jobject jProperties = env->NewObject(jClass, jMethodID);

    if (properties->has(VALUE)) setDoubleValueToObject(env, jClass, jProperties, "setValue", properties->getValue());
    if (properties->has(CURRENCY)) setStringValueToObject(env, jClass, jProperties, "setCurrency", properties->getCurrency());
    if (properties->has(CONTENT_NAME)) setStringValueToObject(env, jClass, jProperties, "setContentName", properties->getContentName());
    if (properties->has(STATUS)) setStringValueToObject(env, jClass, jProperties, "setStatus", properties->getStatus());
    if (properties->has(EXTRAS)) setJsonStringAsMapObject(env, jClass, jProperties, "setExtras", properties->getExtras());

    env->DeleteLocalRef(jClass);
    return jProperties;
}

void ReproConverterAndroid::setDoubleValueToObject(JNIEnv* env, jclass clazz, jobject object, const char* method, const double value) {
    jmethodID jMethodID = env->GetMethodID(clazz, method, "(D)V");
    env->CallVoidMethod(object, jMethodID, value);
}

void ReproConverterAndroid::setJsonStringAsMapObject(JNIEnv* env, jclass clazz, jobject object, const char* method, const char* value) {
    // Generate Java Map object from json string
    jstring jJson = env->NewStringUTF(value);
    jclass jUitlClass = env->FindClass("io/repro/android/Cocos2dxBridge");
    jmethodID jToMapMethodID = env->GetStaticMethodID(jUitlClass, "convertJsonStringToMap", "(Ljava/lang/String;)Ljava/util/Map;");
    jobject jValue = env->CallStaticObjectMethod(jUitlClass, jToMapMethodID, jJson);

    // Set Map object to extras
    jmethodID jMethodID = env->GetMethodID(clazz, method, "(Ljava/util/Map;)V");
    env->CallVoidMethod(object, jMethodID, jValue);

    env->DeleteLocalRef(jJson);
    env->DeleteLocalRef(jUitlClass);
    env->DeleteLocalRef(jValue);
}

void ReproConverterAndroid::setStringValueToObject(JNIEnv* env, jclass clazz, jobject object, const char* method, const char* value) {
     jstring jValue = env->NewStringUTF(value);
     jmethodID jMethodID = env->GetMethodID(clazz, method, "(Ljava/lang/String;)V");
     env->CallVoidMethod(object, jMethodID, jValue);

     env->DeleteLocalRef(jValue);
}

void ReproConverterAndroid::setIntValueToObject(JNIEnv* env, jclass clazz, jobject object, const char* method, const int value) {
     jmethodID jMethodID = env->GetMethodID(clazz, method, "(I)V");
     env->CallVoidMethod(object, jMethodID, value);
}