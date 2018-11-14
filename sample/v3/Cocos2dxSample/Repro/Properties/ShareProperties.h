#ifndef ShareProperties_h
#define ShareProperties_h

#include "StandardEventProperties.h"
namespace repro {
    class ShareProperties: public StandardEventProperties {
    private:
        const char* contentId;
        const char* contentName;
        const char* contentCategory;
        const char* serviceName;

    public:
        void setContentId(const char* contentId);
        void setContentName(const char* contentName);
        void setContentCategory(const char* contentCategory);
        void setServiceName(const char* serviceName);

        const char* getContentId() const;
        const char* getContentName() const;
        const char* getContentCategory() const;
        const char* getServiceName() const;
    };
};

#endif /* ShareProperties_h */
