#ifndef CompleteRegistrationProperties_h
#define CompleteRegistrationProperties_h

#include "StandardEventProperties.h"

namespace repro {
    class CompleteRegistrationProperties: public StandardEventProperties {
    private:
        const char* contentName;
        double value;
        const char* currency;
        const char* status;

    public:
        void setContentName(const char* contentName);
        void setValue(double value);
        void setCurrency(const char* currency);
        void setStatus(const char* status);

        const char* getContentName() const;
        double getValue() const;
        const char* getCurrency() const;
        const char* getStatus() const;
    };
}

#endif /* CompleteRegistrationProperties_h */
