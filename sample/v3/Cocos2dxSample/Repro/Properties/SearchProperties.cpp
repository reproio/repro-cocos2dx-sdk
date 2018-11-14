#include "SearchProperties.h"
using namespace repro;

void SearchProperties::setContentId(const char* contentId) {
    this->set(CONTENT_ID);
    this->contentId = contentId;
}

void SearchProperties::setContentCategory(const char* contentCategory) {
    this->set(CONTENT_CATEGORY);
    this->contentCategory = contentCategory;
}

void SearchProperties::setValue(double value) {
    this->set(VALUE);
    this->value = value;
}

void SearchProperties::setCurrency(const char* currency) {
    this->set(CURRENCY);
    this->currency = currency;
}

void SearchProperties::setSearchString(const char* searchString) {
    this->set(SEARCH_STRING);
    this->searchString = searchString;
}

const char* SearchProperties::getContentId() const {
    return this->contentId;
}

const char* SearchProperties::getContentCategory() const {
    return this->contentCategory;
}

double SearchProperties::getValue() const {
    return this->value;
}

const char* SearchProperties::getCurrency() const {
    return this->currency;
}

const char* SearchProperties::getSearchString() const {
    return this->searchString;
}
