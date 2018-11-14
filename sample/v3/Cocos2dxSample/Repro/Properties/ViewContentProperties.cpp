#include "ViewContentProperties.h"
using namespace repro;

void ViewContentProperties::setContentName(const char* contentName) {
    this->set(CONTENT_NAME);
    this->contentName = contentName;
}

void ViewContentProperties::setContentCategory(const char* contentCategory) {
    this->set(CONTENT_CATEGORY);
    this->contentCategory = contentCategory;
}

void ViewContentProperties::setValue(double value) {
    this->set(VALUE);
    this->value = value;
}

void ViewContentProperties::setCurrency(const char* currency) {
    this->set(CURRENCY);
    this->currency = currency;
}

const char* ViewContentProperties::getContentName() const {
    return this->contentName;
}

const char* ViewContentProperties::getContentCategory() const {
    return this->contentCategory;
}

double ViewContentProperties::getValue() const {
    return this->value;
}

const char* ViewContentProperties::getCurrency() const {
    return this->currency;
}
