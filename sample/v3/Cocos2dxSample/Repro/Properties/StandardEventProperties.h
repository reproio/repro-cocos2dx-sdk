//
//  StandardEventProperties.h
//  Cocos2dxSample
//
//  Created by Nagamine Hiromasa on 2018/09/27.
//

#ifndef StandardEventProperties_h
#define StandardEventProperties_h

#include <string>
#include <map>

namespace repro {
    enum EventPropertySetIndicator : uint32_t
    {
        CONTENT_ID = (1 << 0),
        CONTENT_NAME = (1 << 1),
        CONTENT_CATEGORY = (1 << 2),
        VALUE = (1 << 3),
        CURRENCY = (1 << 4),
        NUM_ITEMS = (1 << 5),
        SEARCH_STRING = (1 << 6),
        SERVICE_NAME = (1 << 7),
        STATUS = (1 << 8),
        EXTRAS = (1 << 9)
    };
    class StandardEventProperties {
    private:
        uint32_t hasProperties = 0;
        const char* extras;

    protected:
        void set(EventPropertySetIndicator key);

    public:
        bool has(EventPropertySetIndicator key) const;

        void setExtras(const char* extras);
        const char* getExtras() const;
    };
};
#endif /* StandardEventProperties_h */
