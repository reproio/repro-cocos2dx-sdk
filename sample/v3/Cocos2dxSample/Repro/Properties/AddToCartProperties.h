#ifndef AddToCartProperties_h
#define AddToCartProperties_h

#include "StandardEventProperties.h"
namespace repro {
    class AddToCartProperties: public StandardEventProperties {
    private:
        const char* contentName;
        const char* contentCategory;
        double value;
        const char* currency;

    public:
        void setContentName(const char* contentName);
        void setContentCategory(const char* contentCategory);
        void setValue(double value);
        void setCurrency(const char* currency);

        const char* getContentName() const;
        const char* getContentCategory() const;
        double getValue() const;
        const char* getCurrency() const;
    };
};

#endif /* AddToCartProperties_h */
