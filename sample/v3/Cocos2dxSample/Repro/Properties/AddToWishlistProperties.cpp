#include "AddToWishlistProperties.h"
using namespace repro;

void AddToWishlistProperties::setContentId(const char* contentId) {
    this->set(CONTENT_ID);
    this->contentId = contentId;
}

void AddToWishlistProperties::setContentName(const char* contentName) {
    this->set(CONTENT_NAME);
    this->contentName = contentName;
}

void AddToWishlistProperties::setContentCategory(const char* contentCategory) {
    this->set(CONTENT_CATEGORY);
    this->contentCategory = contentCategory;
}

void AddToWishlistProperties::setValue(double value) {
    this->set(VALUE);
    this->value = value;
}

void AddToWishlistProperties::setCurrency(const char* currency) {
    this->set(CURRENCY);
    this->currency = currency;
}

const char* AddToWishlistProperties::getContentId() const {
    return this->contentId;
}

const char* AddToWishlistProperties::getContentName() const {
    return this->contentName;
}

const char* AddToWishlistProperties::getContentCategory() const {
    return this->contentCategory;
}

double AddToWishlistProperties::getValue() const {
    return this->value;
}

const char* AddToWishlistProperties::getCurrency() const {
    return this->currency;
}
