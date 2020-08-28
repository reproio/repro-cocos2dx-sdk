#include <android/log.h>
#include "platform/android/jni/JniHelper.h"
#include "ReproConverterAndroid.h"
#include "ReproCpp.h"

ReproCpp::RemoteConfig::RemoteConfig(NativeRemoteConfig remoteConfig)
{
    this->remoteConfig = remoteConfig;
}
