#ifndef AddPaymentInfoProperties_h
#define AddPaymentInfoProperties_h

#include "StandardEventProperties.h"
namespace repro {
    class AddPaymentInfoProperties: public StandardEventProperties {
    private:
        const char* contentId;
        const char* contentCategory;
        double value;
        const char* currency;

    public:
        void setContentId(const char* contentId);
        void setContentCategory(const char* contentCategory);
        void setValue(double value);
        void setCurrency(const char* currency);

        const char* getContentId() const;
        const char* getContentCategory() const;
        double getValue() const;
        const char* getCurrency() const;
    };
}

#endif /* AddPaymentInfoProperties_h */
