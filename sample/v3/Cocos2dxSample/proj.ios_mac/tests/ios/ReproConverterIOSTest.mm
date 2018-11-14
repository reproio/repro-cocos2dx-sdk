//
//  ReproConverterIOSTest.mm
//  Cocos2dxSample-mobile
//
//  Created by Nagamine Hiromasa on 2018/09/11.
//

#import <XCTest/XCTest.h>
#include "ReproConverterIOS.h"
using namespace repro;

@interface ReproConverterIOSTest : XCTestCase

@end

@implementation ReproConverterIOSTest

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testConvertCStringToNSString {
    const char* str1 = "test";
    XCTAssert([ReproConverterIOS::convertCStringToNSString(str1) isEqualToString:@"test"]);

    const char* str2 = "";
    XCTAssert([ReproConverterIOS::convertCStringToNSString(str2) isEqualToString:@""]);

    const char* str3 = NULL;
    XCTAssert(ReproConverterIOS::convertCStringToNSString(str3) == nil);
}

- (void)testConvertNSStringToCString {
    NSString* nsstr1 = @"test";
    const char* str1 = ReproConverterIOS::convertNSStringToCString(nsstr1);
    XCTAssert(strcmp(str1, "test") == 0,  @"%s is not equal %s", str1, "test");

    NSString* nsstr2 = @"";
    const char* str2 = ReproConverterIOS::convertNSStringToCString(nsstr2);
    XCTAssert(strcmp(str2, "") == 0,  @"%s is not equal %s", str1, "");

    NSString* nsstr3 = nil;
    const char* str3 = ReproConverterIOS::convertNSStringToCString(nsstr3);
    XCTAssert(strcmp(str3, "") == 0,  @"%s is not %s", str1, "");
    XCTAssertFalse(strcmp(str3, "test") == 0,  @"%s is not %s", str1, "");
}

- (void)testConvertCStringJSONToNSDictionary {
    const char* json1 = R"({"string": "test", "number": 123, "double": 123.45, "isNull": null })";

    NSDictionary* dict1 = ReproConverterIOS::convertCStringJSONToNSDictionary(json1);
    XCTAssert([dict1[@"string"] isEqualToString: @"test"], @"%@ is not equal %@", dict1[@"string"], @"test");
    XCTAssert([dict1[@"number"] isEqualToNumber: @(123)], @"%@ is equal %@", dict1[@"number"], @(123));
    XCTAssert([dict1[@"double"] isEqualToNumber: @(123.45)], @"%@ is not %@", dict1[@"duuble"], @(123.45));
    XCTAssert([dict1[@"isNull"] isEqual: NSNull.null], @"%@ is not %@", dict1[@"isNull"], NSNull.null);
    XCTAssert(dict1[@"undefined"] == nil, @"%@ key is exists", @"undefined");

    const char* json2 = "{ string: \"test\" }";
    NSDictionary* dict2 = ReproConverterIOS::convertCStringJSONToNSDictionary(json2);
    XCTAssert(dict2 == nil, @"%@ key is not nil", dict2);
}

- (void) testConvertToViewContentPropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToViewContentProperties(NULL) == nil);

    ViewContentProperties cppProps;
    RPRViewContentProperties* props = ReproConverterIOS::convertToViewContentProperties(&cppProps);
    XCTAssert(props != nil);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}

- (void) testConvertToViewContentProperties {
    XCTAssert(ReproConverterIOS::convertToViewContentProperties(NULL) == nil);

    ViewContentProperties cppProps;
    cppProps.setContentName("Slim Jeans");
    cppProps.setContentCategory("Clothing & Shoes > Mens > Clothing");
    cppProps.setValue(5000.0);
    cppProps.setCurrency("JPY");
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRViewContentProperties* props = ReproConverterIOS::convertToViewContentProperties(&cppProps);
    NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentName isEqualToString: @"Slim Jeans"], @"%@ is not equal %@", props.contentName, @"Slim Jeans");
    XCTAssert([props.contentCategory isEqualToString: @"Clothing & Shoes > Mens > Clothing"], @"%@ is not equal %@", props.contentCategory, @"Clothing & Shoes > Mens > Clothing");
    XCTAssert(props.value == 5000.0, @"%f is not %f", props.value, 5000.0);
    XCTAssert([props.currency isEqualToString:@"JPY"], @"%@ is not equal %@", props.currency, @"JPY");
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}

- (void) testConvertToViewContentPropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToViewContentProperties(NULL) == nil);

    ViewContentProperties cppProps;
    cppProps.setContentName(NULL);
    cppProps.setContentCategory(NULL);
    cppProps.setValue(0);
    cppProps.setCurrency(NULL);
    cppProps.setExtras(NULL);

    RPRViewContentProperties* props = ReproConverterIOS::convertToViewContentProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_NAME));
    XCTAssert(cppProps.has(CONTENT_CATEGORY));
    XCTAssert(cppProps.has(VALUE));
    XCTAssert(cppProps.has(CURRENCY));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentName == nil, @"%@ is not nil", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not nil", props.contentCategory);
    XCTAssert(props.value == 0, @"%f is not 0", props.value);
    XCTAssert(props.currency == nil, @"%@ is not equal nil", props.currency);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}

- (void) testConvertToSearchPropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToSearchProperties(NULL) == nil);

    SearchProperties cppProps;
    RPRSearchProperties* props = ReproConverterIOS::convertToSearchProperties(&cppProps);
    XCTAssertFalse(cppProps.has(CONTENT_NAME));
    XCTAssertFalse(cppProps.has(CONTENT_CATEGORY));
    XCTAssertFalse(cppProps.has(VALUE));
    XCTAssertFalse(cppProps.has(CURRENCY));
    XCTAssertFalse(cppProps.has(EXTRAS));

    XCTAssert(props != nil);
    XCTAssert(props.contentID == nil, @"%@ is not \"\"", props.contentID);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.searchString  == nil, @"%@ is not \"\"", props.searchString);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}


- (void) testConvertToSearchProperties {
    XCTAssert(ReproConverterIOS::convertToSearchProperties(NULL) == nil);

    SearchProperties cppProps;
    cppProps.setContentId("1234");
    cppProps.setContentCategory("Clothing & Shoes > Mens > Clothing");
    cppProps.setValue(5000.0);
    cppProps.setCurrency("JPY");
    cppProps.setSearchString("Jeans");
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRSearchProperties* props = ReproConverterIOS::convertToSearchProperties(&cppProps);
        NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentID isEqualToString:@"1234"], @"%@ is not equal %@", props.contentID, @"1234");
    XCTAssert([props.contentCategory isEqualToString:@"Clothing & Shoes > Mens > Clothing"], @"%@ is not equal %@", props.contentCategory, @"game");
    XCTAssert(props.value == 5000.0, @"%f is not %f", props.value, 5000.0);
    XCTAssert([props.currency isEqualToString: @"JPY"], @"%@ is not equal %@", props.currency, @"JPY");
    XCTAssert([props.searchString isEqualToString: @"Jeans"], @"%@ is not equal %@", props.searchString, @"Jeans");
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}


- (void) testConvertToSearchPropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToSearchProperties(NULL) == nil);

    SearchProperties cppProps;
    cppProps.setContentId(NULL);
    cppProps.setContentCategory(NULL);
    cppProps.setSearchString(NULL);
    cppProps.setValue(0);
    cppProps.setCurrency(NULL);
    cppProps.setExtras(NULL);

    RPRSearchProperties* props = ReproConverterIOS::convertToSearchProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_ID));
    XCTAssert(cppProps.has(CONTENT_CATEGORY));
    XCTAssert(cppProps.has(VALUE));
    XCTAssert(cppProps.has(CURRENCY));
    XCTAssert(cppProps.has(SEARCH_STRING));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentID == nil, @"%@ is not nil", props.contentID);
    XCTAssert(props.contentCategory == nil, @"%@ is not nil", props.contentCategory);
    XCTAssert(props.value == 0, @"%f is not 0", props.value);
    XCTAssert(props.currency == nil, @"%@ is not equal nil", props.currency);
    XCTAssert(props.searchString == nil, @"%@ is not equal nil", props.searchString);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}


- (void) testConvertToAddToCartPropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToAddToCartProperties(NULL) == nil);

    AddToCartProperties cppProps;
    RPRAddToCartProperties* props = ReproConverterIOS::convertToAddToCartProperties(&cppProps);
    XCTAssert(props != nil);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}

- (void) testConvertToAddToCartProperties {
    XCTAssert(ReproConverterIOS::convertToAddToCartProperties(NULL) == nil);

    AddToCartProperties cppProps;
    cppProps.setContentName("Slim Jeans");
    cppProps.setContentCategory("Clothing & Shoes > Mens > Clothing");
    cppProps.setValue(5000.0);
    cppProps.setCurrency("JPY");
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRAddToCartProperties* props = ReproConverterIOS::convertToAddToCartProperties(&cppProps);
    NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentName isEqualToString: @"Slim Jeans"], @"%@ is not equal %@", props.contentName, @"Slim Jeans");
    XCTAssert([props.contentCategory isEqualToString:@"Clothing & Shoes > Mens > Clothing"], @"%@ is not equal %@", props.contentCategory, @"Clothing & Shoes > Mens > Clothing");
    XCTAssert(props.value == 5000.0, @"%f is not %f", props.value, 5000.0);
    XCTAssert([props.currency isEqualToString: @"JPY"], @"%@ is not equal %@", props.currency, @"JPY");
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}

- (void) testConvertToAddToCartPropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToAddToCartProperties(NULL) == nil);

    AddToCartProperties cppProps;
    cppProps.setContentName(NULL);
    cppProps.setContentCategory(NULL);
    cppProps.setValue(0);
    cppProps.setCurrency(NULL);
    cppProps.setExtras(NULL);

    RPRAddToCartProperties* props = ReproConverterIOS::convertToAddToCartProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_NAME));
    XCTAssert(cppProps.has(CONTENT_CATEGORY));
    XCTAssert(cppProps.has(VALUE));
    XCTAssert(cppProps.has(CURRENCY));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.extras == nil, @"%@ is not nil", props.extras);
}

- (void) testConvertToAddToWishlistPropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToAddToWishlistProperties(NULL) == nil);

    AddToWishlistProperties cppProps;
    RPRAddToWishlistProperties* props = ReproConverterIOS::convertToAddToWishlistProperties(&cppProps);
    XCTAssert(props != nil);
    XCTAssert(props.contentID == nil, @"%@ is not \"\"", props.contentID);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}


- (void) testConvertToAddToWishlistProperties {
    XCTAssert(ReproConverterIOS::convertToAddToWishlistProperties(NULL) == nil);

    AddToWishlistProperties cppProps;
    cppProps.setContentId("1234");
    cppProps.setContentName("Slim Jeans");
    cppProps.setContentCategory("Clothing & Shoes > Mens > Clothing");
    cppProps.setValue(5000.0);
    cppProps.setCurrency("JPY");
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRAddToWishlistProperties* props = ReproConverterIOS::convertToAddToWishlistProperties(&cppProps);
    NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentID isEqualToString:@"1234"], @"%@ is not equal %@", props.contentID, @"1234");
    XCTAssert([props.contentName isEqualToString: @"Slim Jeans"], @"%@ is not equal %@", props.contentName, @"Slim Jeans");
    XCTAssert([props.contentCategory isEqualToString:@"Clothing & Shoes > Mens > Clothing"], @"%@ is not equal %@", props.contentCategory, @"Clothing & Shoes > Mens > Clothing");
    XCTAssert(props.value == 5000.0, @"%f is not %f", props.value, 5000.0);
    XCTAssert([props.currency isEqualToString: @"JPY"], @"%@ is not equal %@", props.currency, @"JPY");
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}

- (void) testConvertToAddToWishlistPropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToAddToWishlistProperties(NULL) == nil);

    AddToWishlistProperties cppProps;
    cppProps.setContentId(NULL);
    cppProps.setContentName(NULL);
    cppProps.setContentCategory(NULL);
    cppProps.setValue(0);
    cppProps.setCurrency(NULL);
    cppProps.setExtras(NULL);

    RPRAddToWishlistProperties* props = ReproConverterIOS::convertToAddToWishlistProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_ID));
    XCTAssert(cppProps.has(CONTENT_NAME));
    XCTAssert(cppProps.has(CONTENT_CATEGORY));
    XCTAssert(cppProps.has(VALUE));
    XCTAssert(cppProps.has(CURRENCY));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentID == nil, @"%@ is not \"\"", props.contentID);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.extras == nil, @"%@ is not nil", props.extras);
}

- (void) testConvertToInitiateCheckoutPropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToInitiateCheckoutProperties(NULL) == nil);

    InitiateCheckoutProperties cppProps;
    RPRInitiateCheckoutProperties* props = ReproConverterIOS::convertToInitiateCheckoutProperties(&cppProps);
    XCTAssert(props != nil);
    XCTAssert(props.contentID == nil, @"%@ is not \"\"", props.contentID);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.numItems == 0, @"%ld is not %d", (long)props.numItems, 0);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}


- (void) testConvertToInitiateCheckoutProperties {
    XCTAssert(ReproConverterIOS::convertToInitiateCheckoutProperties(NULL) == nil);

    InitiateCheckoutProperties cppProps;
    cppProps.setContentId("1234");
    cppProps.setContentName("Slim Jeans");
    cppProps.setContentCategory("Clothing & Shoes > Mens > Clothing");
    cppProps.setValue(5000.0);
    cppProps.setCurrency("JPY");
    cppProps.setNumItems(10);
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRInitiateCheckoutProperties* props = ReproConverterIOS::convertToInitiateCheckoutProperties(&cppProps);
    NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentID isEqualToString:@"1234"], @"%@ is not equal %@", props.contentID, @"1234");
    XCTAssert([props.contentName isEqualToString: @"Slim Jeans"], @"%@ is not equal %@", props.contentName, @"Slim Jeans");
    XCTAssert([props.contentCategory isEqualToString:@"Clothing & Shoes > Mens > Clothing"], @"%@ is not equal %@", props.contentCategory, @"Clothing & Shoes > Mens > Clothing");
    XCTAssert(props.value == 5000.0, @"%f is not %f", props.value, 5000.0);
    XCTAssert([props.currency isEqualToString: @"JPY"], @"%@ is not equal %@", props.currency, @"JPY");
    XCTAssert(props.numItems == 10, @"%ld is not %d", (long)props.numItems, 10);
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}

- (void) testConvertToInitiateCheckoutPropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToInitiateCheckoutProperties(NULL) == nil);

    InitiateCheckoutProperties cppProps;
    cppProps.setContentId(NULL);
    cppProps.setContentName(NULL);
    cppProps.setContentCategory(NULL);
    cppProps.setValue(0);
    cppProps.setCurrency(NULL);
    cppProps.setNumItems(0);
    cppProps.setExtras(NULL);

    RPRInitiateCheckoutProperties* props = ReproConverterIOS::convertToInitiateCheckoutProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_ID));
    XCTAssert(cppProps.has(CONTENT_NAME));
    XCTAssert(cppProps.has(CONTENT_CATEGORY));
    XCTAssert(cppProps.has(VALUE));
    XCTAssert(cppProps.has(CURRENCY));
    XCTAssert(cppProps.has(NUM_ITEMS));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentID == nil, @"%@ is not \"\"", props.contentID);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.numItems == 0, @"%ld is not %d", (long)props.numItems, 0);
    XCTAssert(props.extras == nil, @"%@ is not nil", props.extras);
}

- (void) testConvertToAddPaymentInfoPropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToAddPaymentInfoProperties(NULL) == nil);

    AddPaymentInfoProperties cppProps;
    RPRAddPaymentInfoProperties* props = ReproConverterIOS::convertToAddPaymentInfoProperties(&cppProps);
    XCTAssert(props != nil);
    XCTAssert(props.contentID == nil, @"%@ is not \"\"", props.contentID);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}

- (void) testConvertToAddPaymentInfoProperties {
    XCTAssert(ReproConverterIOS::convertToAddPaymentInfoProperties(NULL) == nil);

    AddPaymentInfoProperties cppProps;
    cppProps.setContentId("1234");
    cppProps.setContentCategory("Clothing & Shoes > Mens > Clothing");
    cppProps.setValue(5000.0);
    cppProps.setCurrency("JPY");
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRAddPaymentInfoProperties* props = ReproConverterIOS::convertToAddPaymentInfoProperties(&cppProps);
    NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentID isEqualToString:@"1234"], @"%@ is not equal %@", props.contentID, @"1234");
    XCTAssert([props.contentCategory isEqualToString:@"Clothing & Shoes > Mens > Clothing"], @"%@ is not equal %@", props.contentCategory, @"Clothing & Shoes > Mens > Clothing");
    XCTAssert(props.value == 5000.0, @"%f is not %f", props.value, 5000.0);
    XCTAssert([props.currency isEqualToString: @"JPY"], @"%@ is not equal %@", props.currency, @"JPY");
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}

- (void) testConvertToAddPaymentInfoPropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToAddPaymentInfoProperties(NULL) == nil);

    AddPaymentInfoProperties cppProps;
    cppProps.setContentId(NULL);
    cppProps.setContentCategory(NULL);
    cppProps.setValue(0);
    cppProps.setCurrency(NULL);
    cppProps.setExtras({});

    RPRAddPaymentInfoProperties* props = ReproConverterIOS::convertToAddPaymentInfoProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_ID));
    XCTAssert(cppProps.has(CONTENT_CATEGORY));
    XCTAssert(cppProps.has(VALUE));
    XCTAssert(cppProps.has(CURRENCY));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentID == nil, @"%@ is not \"\"", props.contentID);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.extras == nil, @"%@ is not nil", props.extras);

}


- (void) testConvertToPurchasePropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToPurchaseProperties(NULL) == nil);

    PurchaseProperties cppProps;
    RPRPurchaseProperties* props = ReproConverterIOS::convertToPurchaseProperties(&cppProps);
    XCTAssert(props != nil);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.numItems == 0, @"%ld is not %d", (long)props.numItems, 0);
    XCTAssert(props.extras == nil, @"%@ is not nil", props.extras);
}


- (void) testConvertToPurchaseProperties {
    XCTAssert(ReproConverterIOS::convertToPurchaseProperties(NULL) == nil);

    PurchaseProperties cppProps;
    cppProps.setContentName("Slim Jeans");
    cppProps.setContentCategory("Clothing & Shoes > Mens > Clothing");
    cppProps.setNumItems(2);
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRPurchaseProperties* props = ReproConverterIOS::convertToPurchaseProperties(&cppProps);
    NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentName isEqualToString: @"Slim Jeans"], @"%@ is not equal %@", props.contentName, @"Slim Jeans");
    XCTAssert([props.contentCategory isEqualToString:@"Clothing & Shoes > Mens > Clothing"], @"%@ is not equal %@", props.contentCategory, @"Clothing & Shoes > Mens > Clothing");
    XCTAssert(props.numItems == 2, @"%ld is not %d", (long)props.numItems, 2);
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}

- (void) testConvertToPurchasePropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToPurchaseProperties(NULL) == nil);

    PurchaseProperties cppProps;
    cppProps.setContentName(NULL);
    cppProps.setContentCategory(NULL);
    cppProps.setNumItems(0);
    cppProps.setExtras(NULL);

    RPRPurchaseProperties* props = ReproConverterIOS::convertToPurchaseProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_NAME));
    XCTAssert(cppProps.has(CONTENT_CATEGORY));
    XCTAssert(cppProps.has(NUM_ITEMS));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.numItems == 0, @"%ld is not %d", (long)props.numItems, 0);
    XCTAssert(props.extras == nil, @"%@ is not nil", props.extras);
}


- (void) testConvertToSharePropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToShareProperties(NULL) == nil);

    ShareProperties cppProps;
    RPRShareProperties* props = ReproConverterIOS::convertToShareProperties(&cppProps);
    XCTAssert(props != nil);
    XCTAssert(props.contentID == nil, @"%@ is not \"\"", props.contentID);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.serviceName == nil, @"%@ is not \"\"", props.serviceName);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}


- (void) testConvertToShareProperties {
    XCTAssert(ReproConverterIOS::convertToShareProperties(NULL) == nil);

    ShareProperties cppProps;
    cppProps.setContentId("1234");
    cppProps.setContentName("Slim Jeans");
    cppProps.setContentCategory("Clothing & Shoes > Mens > Clothing");
    cppProps.setServiceName("twitter");
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRShareProperties* props = ReproConverterIOS::convertToShareProperties(&cppProps);
    NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentID isEqualToString:@"1234"], @"%@ is not equal %@", props.contentID, @"1234");
    XCTAssert([props.contentName isEqualToString: @"Slim Jeans"], @"%@ is not equal %@", props.contentName, @"Slim Jeans");
    XCTAssert([props.contentCategory isEqualToString:@"Clothing & Shoes > Mens > Clothing"], @"%@ is not equal %@", props.contentCategory, @"Clothing & Shoes > Mens > Clothing");
    XCTAssert([props.serviceName isEqualToString: @"twitter"], @"%@ is not equal %@", props.serviceName, @"twitter");
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}

- (void) testConvertToSharePropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToShareProperties(NULL) == nil);

    ShareProperties cppProps;
    cppProps.setContentId(NULL);
    cppProps.setContentName(NULL);
    cppProps.setContentCategory(NULL);
    cppProps.setServiceName(NULL);
    cppProps.setExtras(NULL);

    RPRShareProperties* props = ReproConverterIOS::convertToShareProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_ID));
    XCTAssert(cppProps.has(CONTENT_NAME));
    XCTAssert(cppProps.has(CONTENT_CATEGORY));
    XCTAssert(cppProps.has(SERVICE_NAME));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentID == nil, @"%@ is not \"\"", props.contentID);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.serviceName == nil, @"%@ is not \"\"", props.serviceName);
    XCTAssert(props.extras == nil, @"%@ is not nil", props.extras);
}

- (void) testConvertToLeadPropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToLeadProperties(NULL) == nil);

    LeadProperties cppProps;
    RPRLeadProperties* props = ReproConverterIOS::convertToLeadProperties(&cppProps);
    XCTAssert(props != nil);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}

- (void) testConvertToLeadProperties {
    XCTAssert(ReproConverterIOS::convertToLeadProperties(NULL) == nil);

    LeadProperties cppProps;
    cppProps.setContentName("Slim Jeans");
    cppProps.setContentCategory("Clothing & Shoes > Mens > Clothing");
    cppProps.setValue(5000.0);
    cppProps.setCurrency("JPY");
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRLeadProperties* props = ReproConverterIOS::convertToLeadProperties(&cppProps);
    NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentName isEqualToString:@"Slim Jeans"], @"%@ is not equal %@", props.contentName, @"Slim Jeans");
    XCTAssert([props.contentCategory isEqualToString:@"Clothing & Shoes > Mens > Clothing"], @"%@ is not equal %@", props.contentCategory, @"Clothing & Shoes > Mens > Clothing");
    XCTAssert(props.value == 5000.0, @"%f is not %f", props.value, 5000.0);
    XCTAssert([props.currency isEqualToString: @"JPY"], @"%@ is not equal %@", props.currency, @"JPY");
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}

- (void) testConvertToLeadPropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToLeadProperties(NULL) == nil);

    LeadProperties cppProps;
    cppProps.setContentName(NULL);
    cppProps.setContentCategory(NULL);
    cppProps.setValue(0);
    cppProps.setCurrency(NULL);
    cppProps.setExtras(NULL);

    RPRLeadProperties* props = ReproConverterIOS::convertToLeadProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_NAME));
    XCTAssert(cppProps.has(CONTENT_CATEGORY));
    XCTAssert(cppProps.has(VALUE));
    XCTAssert(cppProps.has(CURRENCY));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.contentCategory == nil, @"%@ is not \"\"", props.contentCategory);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.extras == nil,  @"%@ is not nil", props.extras);
}

- (void) testConvertToCompleteRegistrationPropertiesForInitial {
    XCTAssert(ReproConverterIOS::convertToCompleteRegistrationProperties(NULL) == nil);

    CompleteRegistrationProperties cppProps;
    RPRCompleteRegistrationProperties* props = ReproConverterIOS::convertToCompleteRegistrationProperties(&cppProps);
    XCTAssert(props != nil);
    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.status == nil, @"%@ is not \"\"", props.status);
    XCTAssert(props.extras == nil, @"%@ is not equal nil", props.extras);
}

- (void) testConvertToCompleteRegistrationProperties {
    XCTAssert(ReproConverterIOS::convertToCompleteRegistrationProperties(NULL) == nil);

    CompleteRegistrationProperties cppProps;
    cppProps.setContentName("Slim Jeans");
    cppProps.setValue(5000.0);
    cppProps.setCurrency("JPY");
    cppProps.setStatus("completed");
    cppProps.setExtras(R"({"color": "blue", "waist": 80, "double": 80.1, "minus": -80.1, "bool_true": true, "bool_false": false, "isnull": null})");

    RPRCompleteRegistrationProperties* props = ReproConverterIOS::convertToCompleteRegistrationProperties(&cppProps);
    NSDictionary *expectedDict = @{@"color": @"blue", @"waist": @80, @"double": @80.1, @"minus": @-80.1, @"bool_true": @YES, @"bool_false": @NO, @"isnull": NSNull.null};

    XCTAssert(props != nil);
    XCTAssert([props.contentName isEqualToString:@"Slim Jeans"], @"%@ is not equal %@", props.contentName, @"Slim Jeans");
    XCTAssert(props.value == 5000.0, @"%f is not %f", props.value, 5000.0);
    XCTAssert([props.currency isEqualToString: @"JPY"], @"%@ is not equal %@", props.currency, @"JPY");
    XCTAssert([props.status isEqualToString:@"completed"], @"%@ is not equal %@", props.status, @"completed");
    XCTAssert([props.extras isEqualToDictionary: expectedDict], @"%@ is not equal %@", props.extras, expectedDict);
}

- (void) testConvertToCompleteRegistrationPropertiesWithNULL {
    XCTAssert(ReproConverterIOS::convertToCompleteRegistrationProperties(NULL) == nil);

    CompleteRegistrationProperties cppProps;
    cppProps.setContentName(NULL);
    cppProps.setValue(0);
    cppProps.setCurrency(NULL);
    cppProps.setStatus(NULL);
    cppProps.setExtras(NULL);

    RPRCompleteRegistrationProperties* props = ReproConverterIOS::convertToCompleteRegistrationProperties(&cppProps);

    XCTAssert(props != nil);
    XCTAssert(cppProps.has(CONTENT_NAME));
    XCTAssert(cppProps.has(VALUE));
    XCTAssert(cppProps.has(CURRENCY));
    XCTAssert(cppProps.has(STATUS));
    XCTAssert(cppProps.has(EXTRAS));

    XCTAssert(props.contentName == nil, @"%@ is not \"\"", props.contentName);
    XCTAssert(props.value == 0.0, @"%f is not %f", props.value, 0.0);
    XCTAssert(props.currency == nil, @"%@ is not \"\"", props.currency);
    XCTAssert(props.status == nil, @"%@ is not \"\"", props.status);
    XCTAssert(props.extras == nil, @"%@ is not nil", props.extras);
}
@end
