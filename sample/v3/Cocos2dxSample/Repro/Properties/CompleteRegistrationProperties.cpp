#include "CompleteRegistrationProperties.h"
using namespace repro;

void CompleteRegistrationProperties::setContentName(const char* contentName) {
    this->set(CONTENT_NAME);
    this->contentName = contentName;
}

void CompleteRegistrationProperties::setValue(double value) {
    this->set(VALUE);
    this->value = value;
}

void CompleteRegistrationProperties::setCurrency(const char* currency) {
    this->set(CURRENCY);
    this->currency = currency;
}


void CompleteRegistrationProperties::setStatus(const char* status) {
    this->set(STATUS);
    this->status = status;
}

const char* CompleteRegistrationProperties::getContentName() const {
    return this->contentName;
}

double CompleteRegistrationProperties::getValue() const {
    return this->value;
}

const char* CompleteRegistrationProperties::getCurrency() const {
    return this->currency;
}

const char* CompleteRegistrationProperties::getStatus() const {
    return this->status;
}

