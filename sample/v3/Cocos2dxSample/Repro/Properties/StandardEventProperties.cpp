//
//  StandardEventProperties.cpp
//  Cocos2dxSample-mobile
//
//  Created by Nagamine Hiromasa on 2018/09/27.
//

#include "StandardEventProperties.h"
#include <regex>
using namespace repro;

void StandardEventProperties::setExtras(const char* extras) {
    this->set(EXTRAS);
    this->extras = extras;
}

const char* StandardEventProperties::getExtras() const {
    return this->extras;
}

void StandardEventProperties::set(EventPropertySetIndicator key) {
    this->hasProperties |= key;
}

bool StandardEventProperties::has(EventPropertySetIndicator key) const {
    return (this->hasProperties & key) != 0;
}
