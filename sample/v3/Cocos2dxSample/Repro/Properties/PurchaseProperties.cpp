#include "PurchaseProperties.h"
using namespace repro;

void PurchaseProperties::setContentName(const char *contentName) {
    this->set(CONTENT_NAME);
    this->contentName = contentName;
}

void PurchaseProperties::setContentCategory(const char* contentCategory) {
    this->set(CONTENT_CATEGORY);
    this->contentCategory = contentCategory;
}

void PurchaseProperties::setNumItems(int numItems) {
    this->set(NUM_ITEMS);
    this->numItems = numItems;
}

const char* PurchaseProperties::getContentName() const {
    return this->contentName;
}

const char* PurchaseProperties::getContentCategory() const {
    return this->contentCategory;
}

int PurchaseProperties::getNumItems() const {
    return this->numItems;
}
