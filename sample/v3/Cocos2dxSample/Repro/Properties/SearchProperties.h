#ifndef SearchProperties_h
#define SearchProperties_h

#include "StandardEventProperties.h"

namespace repro {
    class SearchProperties: public StandardEventProperties {
    private:
        const char* contentId;
        const char* contentCategory;
        double value;
        const char* currency;
        const char* searchString;

    public:
        void setContentId(const char* contentId);
        void setContentCategory(const char* contentCategory);
        void setValue(double value);
        void setSearchString(const char* searchString);
        void setCurrency(const char* currency);

        const char* getContentId() const;
        const char* getContentCategory() const;
        double getValue() const;
        const char* getSearchString() const;
        const char* getCurrency() const;
    };
};

#endif /* SearchProperties_h */
