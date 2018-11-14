#ifndef InitiateCheckoutProperties_h
#define InitiateCheckoutProperties_h

#include "StandardEventProperties.h"
namespace repro {
    class InitiateCheckoutProperties: public StandardEventProperties{
    private:
        const char* contentId;
        const char* contentName;
        const char* contentCategory;
        double value;
        const char* currency;
        int numItems;

    public:
        void setContentId(const char* contentId);
        void setContentName(const char* contentName);
        void setContentCategory(const char* contentCategory);
        void setValue(double value);
        void setCurrency(const char* currency);
        void setNumItems(int numItems);

        const char* getContentId() const;
        const char* getContentName() const;
        const char* getContentCategory() const;
        double getValue() const;
        const char* getCurrency() const;
        int getNumItems() const;
    };
};

#endif /* InitiateCheckoutProperties_h */
