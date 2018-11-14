#include "LeadProperties.h"
using namespace repro;

void LeadProperties::setContentName(const char* contentName) {
    this->set(CONTENT_NAME);
    this->contentName = contentName;
}

void LeadProperties::setContentCategory(const char* contentCategory) {
    this->set(CONTENT_CATEGORY);
    this->contentCategory = contentCategory;
}

void LeadProperties::setValue(double value) {
    this->set(VALUE);
    this->value = value;
}

void LeadProperties::setCurrency(const char* currency) {
    this->set(CURRENCY);
    this->currency = currency;
}


const char* LeadProperties::getContentName() const {
    return this->contentName;
}

const char* LeadProperties::getContentCategory() const {
    return this->contentCategory;
}

double LeadProperties::getValue() const {
    return this->value;
}

const char* LeadProperties::getCurrency() const {
    return this->currency;
}
