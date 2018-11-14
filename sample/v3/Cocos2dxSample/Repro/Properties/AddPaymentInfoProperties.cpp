#include "AddPaymentInfoProperties.h"
using namespace repro;

void AddPaymentInfoProperties::setContentId(const char* contentId) {
    this->set(CONTENT_ID);
    this->contentId = contentId;
}

void AddPaymentInfoProperties::setContentCategory(const char* contentCategory) {
    this->set(CONTENT_CATEGORY);
    this->contentCategory = contentCategory;
}

void AddPaymentInfoProperties::setValue(double value) {
    this->set(VALUE);
    this->value = value;
}

void AddPaymentInfoProperties::setCurrency(const char* currency) {
    this->set(CURRENCY);
    this->currency = currency;
}

const char* AddPaymentInfoProperties::getContentId() const {
    return this->contentId;
}

const char* AddPaymentInfoProperties::getContentCategory() const {
    return this->contentCategory;
}

double AddPaymentInfoProperties::getValue() const {
    return this->value;
}

const char* AddPaymentInfoProperties::getCurrency() const {
    return this->currency;
}

