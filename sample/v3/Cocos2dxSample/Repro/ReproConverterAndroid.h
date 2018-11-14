
#ifndef ReproConverterAndroid_h
#define ReproConverterAndroid_h

#include <jni.h>
#include "ReproEventProperties.h"

namespace repro {
    class ReproConverterAndroid {

    public:

        static jobject convertToViewContentProperties(JNIEnv* env, const ViewContentProperties* properties);

        static jobject convertToSearchProperties(JNIEnv* env, const SearchProperties* properties);

        static jobject convertToAddToCartProperties(JNIEnv* env, const AddToCartProperties* properties);

        static jobject convertToAddToWishlistProperties(JNIEnv* env, const AddToWishlistProperties* properties);

        static jobject convertToInitiateCheckoutProperties(JNIEnv* env, const InitiateCheckoutProperties* properties);

        static jobject convertToAddPaymentInfoProperties(JNIEnv* env, const AddPaymentInfoProperties* properties);

        static jobject convertToPurchaseProperties(JNIEnv* env, const PurchaseProperties* properties);

        static jobject convertToShareProperties(JNIEnv* env, const ShareProperties* properties);

        static jobject convertToLeadProperties(JNIEnv* env, const LeadProperties* properties);

        static jobject convertToCompleteRegistrationProperties(JNIEnv* env, const CompleteRegistrationProperties* properties);


    private:
        static void setJsonStringAsMapObject(JNIEnv* env, jclass clazz, jobject object, const char* method, const char* value);

        static void setDoubleValueToObject(JNIEnv* env, jclass clazz, jobject object, const char* method, const double value);

        static void setStringValueToObject(JNIEnv* env, jclass clazz, jobject object, const char* method, const char* value);
        
        static void setIntValueToObject(JNIEnv* env, jclass clazz, jobject object, const char* method, const int value);
    };
}

#endif /* ReproConverterAndroid_h */
