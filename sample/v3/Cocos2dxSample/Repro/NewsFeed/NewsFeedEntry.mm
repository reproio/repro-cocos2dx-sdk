#import <Repro/Repro.h>
#include "ReproConverterIOS.h"
#include "ReproCpp.h"

ReproCpp::NewsFeedEntry::NewsFeedEntry(NativeNewsFeedEntry newsFeedEntry)
{
    this->newsFeedEntry = newsFeedEntry;
}

NativeNewsFeedEntry ReproCpp::NewsFeedEntry::getNativeNewsFeedEntry()
{
    return this->newsFeedEntry;
}

uint64_t ReproCpp::NewsFeedEntry::getID()
{
    return this->newsFeedEntry.ID;
}

const char * ReproCpp::NewsFeedEntry::getDeviceID()
{
    return repro::ReproConverterIOS::convertNSStringToCString(this->newsFeedEntry.deviceID);
}

const char * ReproCpp::NewsFeedEntry::getTitle()
{
    return repro::ReproConverterIOS::convertNSStringToCString(this->newsFeedEntry.title);
}

const char * ReproCpp::NewsFeedEntry::getSummary()
{
    return repro::ReproConverterIOS::convertNSStringToCString(this->newsFeedEntry.summary);
}

const char * ReproCpp::NewsFeedEntry::getBody()
{
    return repro::ReproConverterIOS::convertNSStringToCString(this->newsFeedEntry.body);
}

const char * ReproCpp::NewsFeedEntry::getLinkUrl()
{
    NSURL *url = this->newsFeedEntry.linkUrl;
    return repro::ReproConverterIOS::convertNSStringToCString([url absoluteString]);
}

const char * ReproCpp::NewsFeedEntry::getImageUrl()
{
    NSURL *url = this->newsFeedEntry.imageUrl;
    return repro::ReproConverterIOS::convertNSStringToCString([url absoluteString]);
}

time_t ReproCpp::NewsFeedEntry::getDeliveredAt()
{
    return (time_t)[this->newsFeedEntry.deliveredAt timeIntervalSince1970];
}

bool ReproCpp::NewsFeedEntry::getShown()
{
    return this->newsFeedEntry.shown ? true : false;
}

bool ReproCpp::NewsFeedEntry::getRead()
{
    return this->newsFeedEntry.read ? true : false;
}

void ReproCpp::NewsFeedEntry::setShown(bool value)
{
    this->newsFeedEntry.shown = value;
}

void ReproCpp::NewsFeedEntry::setRead(bool value)
{
    this->newsFeedEntry.read = value;
}
