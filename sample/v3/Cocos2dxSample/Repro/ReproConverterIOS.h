//
//  ReproConverterIOS.hpp
//  Cocos2dxSample-mobile
//
//  Created by Nagamine Hiromasa on 2018/09/11.
//

#ifndef ReproConverterIOS_h
#define ReproConverterIOS_h

#import <Repro/Repro.h>
#include "ReproEventProperties.h"

namespace repro {
    class ReproConverterIOS {

    public:

        static NSString* convertCStringToNSString(const char* string);

        static const char* convertNSStringToCString(NSString* string);

        static NSDictionary* convertCStringJSONToNSDictionary(const char* string);

        static RPRViewContentProperties* convertToViewContentProperties(const ViewContentProperties* properties);

        static RPRSearchProperties* convertToSearchProperties(const SearchProperties* properties);

        static RPRAddToCartProperties* convertToAddToCartProperties(const AddToCartProperties* properties);

        static RPRAddToWishlistProperties* convertToAddToWishlistProperties(const AddToWishlistProperties* properties);

        static RPRInitiateCheckoutProperties* convertToInitiateCheckoutProperties(const InitiateCheckoutProperties* properties);

        static RPRAddPaymentInfoProperties* convertToAddPaymentInfoProperties(const AddPaymentInfoProperties* properties);

        static RPRPurchaseProperties* convertToPurchaseProperties(const PurchaseProperties* properties);

        static RPRShareProperties* convertToShareProperties(const ShareProperties* properties);

        static RPRLeadProperties* convertToLeadProperties(const LeadProperties* properties);

        static RPRCompleteRegistrationProperties* convertToCompleteRegistrationProperties(const CompleteRegistrationProperties* properties);
    };
};

#endif /* ReproConverterIOS_h */
