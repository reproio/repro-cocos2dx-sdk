#ifndef PurchaseProperties_h
#define PurchaseProperties_h

#include "StandardEventProperties.h"

namespace repro {
    class PurchaseProperties: public StandardEventProperties {
    private:
        const char* contentName;
        const char* contentCategory;
        int numItems;

    public:
        void setContentName(const char* contentName);
        void setContentCategory(const char* contentCategory);
        void setNumItems(int numItems);

        const char* getContentName() const;
        const char* getContentCategory() const;
        int getNumItems() const;
    };
}

#endif /* PurchaseProperties_h */
