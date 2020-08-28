LOCAL_PATH := $(call my-dir)

FIREBASE_CPP_SDK_DIR := ../../../firebase_cpp_sdk

APP_ABI := armeabi-v7a x86
STL := $(firstword $(subst _, ,$(APP_STL)))
FIREBASE_LIBRARY_PATH := $(FIREBASE_CPP_SDK_DIR)/libs/android/$(TARGET_ARCH_ABI)/$(STL)

include $(CLEAR_VARS)
LOCAL_MODULE := firebase_app
LOCAL_SRC_FILES := $(FIREBASE_LIBRARY_PATH)/libfirebase_app.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/$(FIREBASE_CPP_SDK_DIR)/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := firebase_feature
LOCAL_SRC_FILES := $(FIREBASE_LIBRARY_PATH)/libfirebase_messaging.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/$(FIREBASE_CPP_SDK_DIR)/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../../Classes/AppDelegate.cpp \
                   ../../../Classes/HelloWorldScene.cpp \
                   ../../../Repro/ReproCpp.cpp \
                   ../../../Repro/ReproConverterAndroid.cpp \
                   ../../../Repro/NewsFeed/NewsFeedEntry.cpp \
                   ../../../Repro/RemoteConfig/RemoteConfig.cpp \
                   ../../../Repro/Properties/StandardEventProperties.cpp \
                   ../../../Repro/Properties/ViewContentProperties.cpp \
                   ../../../Repro/Properties/SearchProperties.cpp \
                   ../../../Repro/Properties/AddToCartProperties.cpp \
                   ../../../Repro/Properties/AddToWishlistProperties.cpp \
                   ../../../Repro/Properties/InitiateCheckoutProperties.cpp \
                   ../../../Repro/Properties/AddPaymentInfoProperties.cpp \
                   ../../../Repro/Properties/PurchaseProperties.cpp \
                   ../../../Repro/Properties/ShareProperties.cpp \
                   ../../../Repro/Properties/LeadProperties.cpp \
                   ../../../Repro/Properties/CompleteRegistrationProperties.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Repro
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Repro/Properties

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_STATIC_LIBRARIES += firebase_app
LOCAL_STATIC_LIBRARIES += firebase_feature


# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
