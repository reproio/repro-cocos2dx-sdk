#include "ShareProperties.h"
using namespace repro;

void ShareProperties::setContentId(const char* contentId) {
    this->set(CONTENT_ID);
    this->contentId = contentId;
}

void ShareProperties::setContentName(const char *contentName) {
    this->set(CONTENT_NAME);
    this->contentName = contentName;
}

void ShareProperties::setContentCategory(const char* contentCategory) {
    this->set(CONTENT_CATEGORY);
    this->contentCategory = contentCategory;
}

void ShareProperties::setServiceName(const char* serviceName) {
    this->set(SERVICE_NAME);
    this->serviceName = serviceName;
}

const char* ShareProperties::getContentId() const {
    return this->contentId;
}

const char* ShareProperties::getContentName() const {
    return this->contentName;
}

const char* ShareProperties::getContentCategory() const {
    return this->contentCategory;
}

const char* ShareProperties::getServiceName() const {
    return this->serviceName;
}
