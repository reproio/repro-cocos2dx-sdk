#import <Repro/Repro.h>
#include "ReproConverterIOS.h"
#include "ReproCpp.h"

ReproCpp::RemoteConfig::RemoteConfig(NativeRemoteConfig remoteConfig)
{
    this->remoteConfig = remoteConfig;
}

void ReproCpp::RemoteConfig::setDefaultsFromJsonString(const char *jsonString)
{
    [this->remoteConfig setDefaultsFromJsonString: repro::ReproConverterIOS::convertCStringToNSString(jsonString)];
}
