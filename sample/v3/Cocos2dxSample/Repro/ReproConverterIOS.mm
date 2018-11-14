//
//  ReproConverterIOS.cpp
//  Cocos2dxSample-mobile
//
//  Created by Nagamine Hiromasa on 2018/09/11.
//

#include "ReproConverterIOS.h"
using namespace repro;

NSString* ReproConverterIOS::convertCStringToNSString(const char* string) {
    if (string) {
        return [NSString stringWithUTF8String:string];
    } else {
        return nil;
    }
}

const char* ReproConverterIOS::convertNSStringToCString(NSString* string) {
    if (string) {
        const char* src = [string UTF8String];
        char* dst = (char*)malloc(strlen(src) + 1);
        strncpy(dst, src, strlen(src) + 1);
        return dst;
    } else {
        return "";
    }
}

NSDictionary* ReproConverterIOS::convertCStringJSONToNSDictionary(const char* string) {
    if (string) {
        NSString* json = convertCStringToNSString(string);
        NSData* data = [json dataUsingEncoding:NSUTF8StringEncoding];

        return [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:nil];;
    } else {
        return nil;
    }
}

RPRViewContentProperties* ReproConverterIOS::convertToViewContentProperties(const ViewContentProperties* properties) {
    if (!properties) {
        return NULL;
    }

    RPRViewContentProperties* rprProps = [[RPRViewContentProperties alloc] init];
    if (properties->has(CONTENT_NAME)) rprProps.contentName = ReproConverterIOS::convertCStringToNSString(properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) rprProps.contentCategory = ReproConverterIOS::convertCStringToNSString(properties->getContentCategory());
    if (properties->has(VALUE)) rprProps.value = properties->getValue();
    if (properties->has(CURRENCY)) rprProps.currency = ReproConverterIOS::convertCStringToNSString(properties->getCurrency());
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}

RPRSearchProperties* ReproConverterIOS::convertToSearchProperties(const SearchProperties* properties) {
    if (!properties) {
        return NULL;
    }

    RPRSearchProperties* rprProps = [[RPRSearchProperties alloc] init];
    if (properties->has(CONTENT_ID)) rprProps.contentID = ReproConverterIOS::convertCStringToNSString(properties->getContentId());
    if (properties->has(CONTENT_CATEGORY)) rprProps.contentCategory = ReproConverterIOS::convertCStringToNSString(properties->getContentCategory());
    if (properties->has(VALUE)) rprProps.value = properties->getValue();
    if (properties->has(CURRENCY)) rprProps.currency = ReproConverterIOS::convertCStringToNSString(properties->getCurrency());
    if (properties->has(SEARCH_STRING)) rprProps.searchString = ReproConverterIOS::convertCStringToNSString(properties->getSearchString());
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}

RPRAddToCartProperties* ReproConverterIOS::convertToAddToCartProperties(const AddToCartProperties* properties) {
    if (!properties) {
        return NULL;
    }
    RPRAddToCartProperties* rprProps = [[RPRAddToCartProperties alloc] init];
    if (properties->has(CONTENT_NAME)) rprProps.contentName = ReproConverterIOS::convertCStringToNSString(properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) rprProps.contentCategory = ReproConverterIOS::convertCStringToNSString(properties->getContentCategory());
    if (properties->has(VALUE)) rprProps.value = properties->getValue();
    if (properties->has(CURRENCY)) rprProps.currency = ReproConverterIOS::convertCStringToNSString(properties->getCurrency());
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}

RPRAddToWishlistProperties* ReproConverterIOS::convertToAddToWishlistProperties(const AddToWishlistProperties* properties) {
    if (!properties) {
        return NULL;
    }

    RPRAddToWishlistProperties* rprProps = [[RPRAddToWishlistProperties alloc] init];
    if (properties->has(CONTENT_ID)) rprProps.contentID = ReproConverterIOS::convertCStringToNSString(properties->getContentId());
    if (properties->has(CONTENT_NAME)) rprProps.contentName = ReproConverterIOS::convertCStringToNSString(properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) rprProps.contentCategory = ReproConverterIOS::convertCStringToNSString(properties->getContentCategory());
    if (properties->has(VALUE)) rprProps.value = properties->getValue();
    if (properties->has(CURRENCY)) rprProps.currency = ReproConverterIOS::convertCStringToNSString(properties->getCurrency());
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}

RPRInitiateCheckoutProperties* ReproConverterIOS::convertToInitiateCheckoutProperties(const InitiateCheckoutProperties* properties) {
    if (!properties) {
        return NULL;
    }

    RPRInitiateCheckoutProperties* rprProps = [[RPRInitiateCheckoutProperties alloc] init];
    if (properties->has(CONTENT_ID)) rprProps.contentID = ReproConverterIOS::convertCStringToNSString(properties->getContentId());
    if (properties->has(CONTENT_NAME)) rprProps.contentName = ReproConverterIOS::convertCStringToNSString(properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) rprProps.contentCategory = ReproConverterIOS::convertCStringToNSString(properties->getContentCategory());
    if (properties->has(VALUE)) rprProps.value = properties->getValue();
    if (properties->has(CURRENCY)) rprProps.currency = ReproConverterIOS::convertCStringToNSString(properties->getCurrency());
    if (properties->has(NUM_ITEMS)) rprProps.numItems = properties->getNumItems();
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}

RPRAddPaymentInfoProperties* ReproConverterIOS::convertToAddPaymentInfoProperties(const AddPaymentInfoProperties* properties) {
    if (!properties) {
        return NULL;
    }

    RPRAddPaymentInfoProperties* rprProps = [[RPRAddPaymentInfoProperties alloc] init];
    if (properties->has(CONTENT_ID)) rprProps.contentID = ReproConverterIOS::convertCStringToNSString(properties->getContentId());
    if (properties->has(CONTENT_CATEGORY)) rprProps.contentCategory = ReproConverterIOS::convertCStringToNSString(properties->getContentCategory());
    if (properties->has(VALUE)) rprProps.value = properties->getValue();
    if (properties->has(CURRENCY)) rprProps.currency = ReproConverterIOS::convertCStringToNSString(properties->getCurrency());
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}

RPRPurchaseProperties* ReproConverterIOS::convertToPurchaseProperties(const PurchaseProperties* properties) {
    if (!properties) {
        return NULL;
    }

    RPRPurchaseProperties* rprProps = [[RPRPurchaseProperties alloc] init];
    if (properties->has(CONTENT_NAME)) rprProps.contentName = ReproConverterIOS::convertCStringToNSString(properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) rprProps.contentCategory = ReproConverterIOS::convertCStringToNSString(properties->getContentCategory());
    if (properties->has(NUM_ITEMS)) rprProps.numItems = properties->getNumItems();
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}

RPRShareProperties* ReproConverterIOS::convertToShareProperties(const ShareProperties* properties) {
    if (!properties) {
        return NULL;
    }

    RPRShareProperties* rprProps = [[RPRShareProperties alloc] init];
    if (properties->has(CONTENT_ID)) rprProps.contentID = ReproConverterIOS::convertCStringToNSString(properties->getContentId());
    if (properties->has(CONTENT_NAME)) rprProps.contentName = ReproConverterIOS::convertCStringToNSString(properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) rprProps.contentCategory = ReproConverterIOS::convertCStringToNSString(properties->getContentCategory());
    if (properties->has(SERVICE_NAME)) rprProps.serviceName = ReproConverterIOS::convertCStringToNSString(properties->getServiceName());
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}

RPRLeadProperties* ReproConverterIOS::convertToLeadProperties(const LeadProperties* properties) {
    if (!properties) {
        return NULL;
    }

    RPRLeadProperties* rprProps = [[RPRLeadProperties alloc] init];
    if (properties->has(CONTENT_NAME)) rprProps.contentName = ReproConverterIOS::convertCStringToNSString(properties->getContentName());
    if (properties->has(CONTENT_CATEGORY)) rprProps.contentCategory = ReproConverterIOS::convertCStringToNSString(properties->getContentCategory());
    if (properties->has(VALUE)) rprProps.value = properties->getValue();
    if (properties->has(CURRENCY)) rprProps.currency = ReproConverterIOS::convertCStringToNSString(properties->getCurrency());
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}

RPRCompleteRegistrationProperties* ReproConverterIOS::convertToCompleteRegistrationProperties(const CompleteRegistrationProperties* properties) {
    if (!properties) {
        return NULL;
    }

    RPRCompleteRegistrationProperties* rprProps = [[RPRCompleteRegistrationProperties alloc] init];
    if (properties->has(CONTENT_NAME)) rprProps.contentName = ReproConverterIOS::convertCStringToNSString(properties->getContentName());
    if (properties->has(VALUE)) rprProps.value = properties->getValue();
    if (properties->has(CURRENCY)) rprProps.currency = ReproConverterIOS::convertCStringToNSString(properties->getCurrency());
    if (properties->has(STATUS)) rprProps.status = ReproConverterIOS::convertCStringToNSString(properties->getStatus());
    if (properties->has(EXTRAS)) rprProps.extras = ReproConverterIOS::convertCStringJSONToNSDictionary(properties->getExtras());

    return rprProps;
}
