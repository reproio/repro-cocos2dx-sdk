#include "AddToCartProperties.h"
using namespace repro;

void AddToCartProperties::setContentName(const char* contentName) {
    this->set(CONTENT_NAME);
    this->contentName = contentName;
}

void AddToCartProperties::setContentCategory(const char* contentCategory) {
    this->set(CONTENT_CATEGORY);
    this->contentCategory = contentCategory;
}

void AddToCartProperties::setValue(double value) {
    this->set(VALUE);
    this->value = value;
}

void AddToCartProperties::setCurrency(const char* currency) {
    this->set(CURRENCY);
    this->currency = currency;
}

const char* AddToCartProperties::getContentName() const {
    return this->contentName;
}

const char* AddToCartProperties::getContentCategory() const {
    return this->contentCategory;
}

double AddToCartProperties::getValue() const {
    return this->value;
}

const char* AddToCartProperties::getCurrency() const {
    return this->currency;
}
