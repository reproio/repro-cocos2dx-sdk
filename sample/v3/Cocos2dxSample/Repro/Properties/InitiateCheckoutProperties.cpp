#include "InitiateCheckoutProperties.h"
using namespace repro;

void InitiateCheckoutProperties::setContentId(const char* contentId) {
    this->set(CONTENT_ID);
    this->contentId = contentId;
}

void InitiateCheckoutProperties::setContentName(const char *contentName) {
    this->set(CONTENT_NAME);
    this->contentName = contentName;
}

void InitiateCheckoutProperties::setContentCategory(const char* contentCategory) {
    this->set(CONTENT_CATEGORY);
    this->contentCategory = contentCategory;
}

void InitiateCheckoutProperties::setValue(double value) {
    this->set(VALUE);
    this->value = value;
}

void InitiateCheckoutProperties::setCurrency(const char* currency) {
    this->set(CURRENCY);
    this->currency = currency;
}

void InitiateCheckoutProperties::setNumItems(int numItems) {
    this->set(NUM_ITEMS);
    this->numItems = numItems;
}

const char* InitiateCheckoutProperties::getContentId() const {
    return this->contentId;
}

const char* InitiateCheckoutProperties::getContentName() const {
    return this->contentName;
}

const char* InitiateCheckoutProperties::getContentCategory() const {
    return this->contentCategory;
}

double InitiateCheckoutProperties::getValue() const {
    return this->value;
}

const char* InitiateCheckoutProperties::getCurrency() const {
    return this->currency;
}

int InitiateCheckoutProperties::getNumItems() const {
    return this->numItems;
}
