#import <Repro/Repro.h>
#include "ReproConverterIOS.h"
#include "ReproCpp.h"

// RemoteConfigValue

ReproCpp::RemoteConfigValue::RemoteConfigValue(NativeRemoteConfigValue remoteConfigValue)
{
    this->remoteConfigValue = remoteConfigValue;
}

const char* ReproCpp::RemoteConfigValue::getStringValue()
{
    return repro::ReproConverterIOS::convertNSStringToCString(this->remoteConfigValue.stringValue);
}

// RemoteConfig

ReproCpp::RemoteConfig::RemoteConfig(NativeRemoteConfig remoteConfig)
{
    this->remoteConfig = remoteConfig;
}

void ReproCpp::RemoteConfig::fetch(double timeout, std::function<void(ReproCpp::RemoteConfig::FetchStatus error)> completion)
{
    return [this->remoteConfig fetchWithTimeout:(NSTimeInterval)timeout completionHandler:^(RPRRemoteConfigFetchStatus status) {
        ReproCpp::RemoteConfig::FetchStatus fetchStatus;
        switch (status) {
            case RPRRemoteConfigFetchStatusSuccess:
                fetchStatus = ReproCpp::RemoteConfig::FetchStatusSuccess;
                break;
            case RPRRemoteConfigFetchStatusTimeoutReached:
                fetchStatus = ReproCpp::RemoteConfig::FetchStatusTimeoutReached;
                break;
            case RPRRemoteConfigFetchStatusAlreadyFetched:
                fetchStatus = ReproCpp::RemoteConfig::FetchStatusAlreadyFetched;
                break;
        }
        if (completion) {
            completion(fetchStatus);
        }
    }];
}

bool ReproCpp::RemoteConfig::activateFetched()
{
    return [this->remoteConfig activateFetched];
}

bool ReproCpp::RemoteConfig::setDefaultsFromMap(std::map<std::string, std::string> values)
{
    NSMutableDictionary *defaults = [NSMutableDictionary dictionary];
    for (auto iter = values.begin(); iter != values.end(); iter++) {
        NSString *key   = repro::ReproConverterIOS::convertCStringToNSString(iter->first.c_str());
        NSString *value = repro::ReproConverterIOS::convertCStringToNSString(iter->second.c_str());
        [defaults setObject:value forKey:key];
    }
    return [this->remoteConfig setDefaultsFromDictionary:defaults];
}

bool ReproCpp::RemoteConfig::setDefaultsFromJsonFile(const char *filePath)
{
    NSString *path = repro::ReproConverterIOS::convertCStringToNSString(filePath);
    NSURL *url = [NSURL fileURLWithPath:path];

    return [this->remoteConfig setDefaultsFromJsonFile:url];
}

bool ReproCpp::RemoteConfig::setDefaultsFromJsonString(const char *jsonString)
{
    return [this->remoteConfig setDefaultsFromJsonString: repro::ReproConverterIOS::convertCStringToNSString(jsonString)];
}

ReproCpp::RemoteConfigValue ReproCpp::RemoteConfig::get(const char *key)
{
    NSString *stringKey = repro::ReproConverterIOS::convertCStringToNSString(key);
    RPRRemoteConfigValue *value = [this->remoteConfig valueForKey:stringKey];
    return ReproCpp::RemoteConfigValue(value);
}

ReproCpp::RemoteConfigValue ReproCpp::RemoteConfig::getLocalDefaultValue(const char *key)
{
    NSString *stringKey = repro::ReproConverterIOS::convertCStringToNSString(key);
    RPRRemoteConfigValue *value = [this->remoteConfig localDefaultValueForKey:stringKey];
    return ReproCpp::RemoteConfigValue(value);
}

std::map<std::string, ReproCpp::RemoteConfigValue*> ReproCpp::RemoteConfig::getAllValues()
{
    std::map<std::string, ReproCpp::RemoteConfigValue*> values;
    NSDictionary<NSString *, RPRRemoteConfigValue *> *nativeValues = [this->remoteConfig allValues];
    for (NSString *dictKey in [nativeValues keyEnumerator]) {
        std::string key = repro::ReproConverterIOS::convertNSStringToCString(dictKey);
        ReproCpp::RemoteConfigValue value = ReproCpp::RemoteConfigValue(nativeValues[dictKey]);

        values[key] = &value;
    }

    return std::move(values);
}

std::map<std::string, ReproCpp::RemoteConfigValue*> ReproCpp::RemoteConfig::getAllValuesWithPrefix(const char *prefix)
{
    std::map<std::string, ReproCpp::RemoteConfigValue*> values;
    NSString *stringPrefix = repro::ReproConverterIOS::convertCStringToNSString(prefix);

    NSDictionary<NSString *, RPRRemoteConfigValue *> *nativeValues = [this->remoteConfig allValuesWithPrefix:stringPrefix];
    for (NSString *dictKey in [nativeValues keyEnumerator]) {
        std::string key = repro::ReproConverterIOS::convertNSStringToCString(dictKey);
        ReproCpp::RemoteConfigValue value = ReproCpp::RemoteConfigValue(nativeValues[dictKey]);

        values[key] = &value;
    }

    return std::move(values);
}

void ReproCpp::RemoteConfig::forceReset()
{
    [this->remoteConfig forceReset];
}
