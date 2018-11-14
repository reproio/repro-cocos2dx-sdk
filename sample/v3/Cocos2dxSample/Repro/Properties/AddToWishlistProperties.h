#ifndef AddToWishlistProperties_h
#define AddToWishlistProperties_h

#include "StandardEventProperties.h"
namespace repro {
    class AddToWishlistProperties: public StandardEventProperties {
    private:
        const char* contentId;
        const char* contentName;
        const char* contentCategory;
        double value;
        const char* currency;

    public:
        void setContentId(const char* contentId);
        void setContentName(const char* contentName);
        void setContentCategory(const char* contentCategory);
        void setValue(double value);
        void setCurrency(const char* currency);

        const char* getContentId() const;
        const char* getContentName() const;
        const char* getContentCategory() const;
        double getValue() const;
        const char* getCurrency() const;
    };
};

#endif /* AddToWishlistProperties_h */
