#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "ReproCpp.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2,
                                origin.y + closeItem->getContentSize().height/2 + 10));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "Marker Felt.ttf", 24); // LabelTTF::create("Hello World", "Marker Felt", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height - sprite->getContentSize().height));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    // Repro operation check
    Size s = Director::getInstance()->getVisibleSize();
    
    Menu* pMenu = Menu::create(MenuItemLabel::create(Label::createWithTTF("setup", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_setup, this)),
                               MenuItemLabel::create(Label::createWithTTF("opt in", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_optIn, this)),
                               MenuItemLabel::create(Label::createWithTTF("opt out", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_optOut, this)),
                               MenuItemLabel::create(Label::createWithTTF("setUserID", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_setUserID, this)),
                               MenuItemLabel::create(Label::createWithTTF("setUserProfile", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_setUserProfile, this)),
                               MenuItemLabel::create(Label::createWithTTF("track", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_track, this)),
                               MenuItemLabel::create(Label::createWithTTF("trackWithProperties", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_trackWithProperties, this)),
                               MenuItemLabel::create(Label::createWithTTF("crash", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_crash, this)),
                               NULL);
    
    pMenu->setPosition(Vec2(s.width*0.5, s.height*0.5));
    pMenu->alignItemsVerticallyWithPadding(10);
    this->addChild(pMenu);
    
    auto pLabelDebug = Label::createWithTTF("setLogLevel : Debug", "Marker Felt.ttf", 30);
    auto pBtnItemDebug = MenuItemLabel::create(pLabelDebug, CC_CALLBACK_1(HelloWorld::repro_setLoglevel, this));
    pBtnItemDebug->setTag(1);
    auto pLabelInfo = Label::createWithTTF("setLogLevel : Info", "Marker Felt.ttf", 30);
    auto pBtnItemInfo = MenuItemLabel::create(pLabelInfo, CC_CALLBACK_1(HelloWorld::repro_setLoglevel, this));
    pBtnItemInfo->setTag(2);
    auto pLabelWarn = Label::createWithTTF("setLogLevel : Warn", "Marker Felt.ttf", 30);
    auto pBtnItemWarn = MenuItemLabel::create(pLabelWarn, CC_CALLBACK_1(HelloWorld::repro_setLoglevel, this));
    pBtnItemWarn->setTag(3);
    auto pLabelError = Label::createWithTTF("setLogLevel : Error", "Marker Felt.ttf", 30);
    auto pBtnItemError = MenuItemLabel::create(pLabelError, CC_CALLBACK_1(HelloWorld::repro_setLoglevel, this));
    pBtnItemError->setTag(4);
    auto pLabelNone = Label::createWithTTF("setLogLevel : None", "Marker Felt.ttf", 30);
    auto pBtnItemNone = MenuItemLabel::create(pLabelNone, CC_CALLBACK_1(HelloWorld::repro_setLoglevel, this));
    pBtnItemNone->setTag(5);
    auto pLabelInAppMessage = Label::createWithTTF("In-AppMessage", "Marker Felt.ttf", 30);
    auto pBtnItemInAppMessage = MenuItemLabel::create(pLabelInAppMessage, CC_CALLBACK_1(HelloWorld::repro_showInAppMessage, this));
    pBtnItemNone->setTag(6);
    auto pLabelDisableShowInAppMessageOnActive = Label::createWithTTF("DisableShowInAppMessageOnActive", "Marker Felt.ttf", 30);
    auto pBtnItemDisableShowInAppMessageOnActive = MenuItemLabel::create(pLabelDisableShowInAppMessageOnActive, CC_CALLBACK_1(HelloWorld::repro_disableInAppMessageOnActive, this));
    pBtnItemNone->setTag(7);
    auto pLabelSetPushRegistrationID = Label::createWithTTF("SetPushRegistrationID", "Marker Felt.ttf", 30);
    auto pBtnItemSetPushRegistrationID = MenuItemLabel::create(pLabelSetPushRegistrationID, CC_CALLBACK_1(HelloWorld::repro_setPushRegistrationID, this));
    pBtnItemNone->setTag(8);

    Menu* pMenu2 = Menu::create(pBtnItemDebug,
                                pBtnItemInfo,
                                pBtnItemWarn,
                                pBtnItemError,
                                pBtnItemNone,
                                pBtnItemInAppMessage,
                                pBtnItemDisableShowInAppMessageOnActive,
                                pBtnItemSetPushRegistrationID,
                                NULL);
    pMenu2->setPosition(Vec2(150, s.height*0.5));
    pMenu2->alignItemsVerticallyWithPadding(10);
    this->addChild(pMenu2);

    Menu* standardAPIMenu = Menu::create(
                               MenuItemLabel::create(Label::createWithTTF("viewContent", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_viewContent, this)),
                               MenuItemLabel::create(Label::createWithTTF("search", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_search, this)),
                               MenuItemLabel::create(Label::createWithTTF("addToCart", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_addToCart, this)),
                               MenuItemLabel::create(Label::createWithTTF("addToWishlist", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_addToWishlist, this)),
                               MenuItemLabel::create(Label::createWithTTF("initiateCheckout", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_initiateCheckout, this)),
                               MenuItemLabel::create(Label::createWithTTF("addPaymentInfo", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_addPaymentInfo, this)),
                               MenuItemLabel::create(Label::createWithTTF("purchase", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_purchase, this)),
                               MenuItemLabel::create(Label::createWithTTF("share", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_share, this)),
                               MenuItemLabel::create(Label::createWithTTF("lead", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_lead, this)),
                               MenuItemLabel::create(Label::createWithTTF("completeRegistration", "Marker Felt.ttf", 30),
                                                     CC_CALLBACK_1(HelloWorld::repro_completeRegistration, this)),

                               NULL);
    
    standardAPIMenu->setPosition(Vec2(s.width - 150, s.height*0.5));
    standardAPIMenu->alignItemsVerticallyWithPadding(10);
    this->addChild(standardAPIMenu);
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

// Repro API
void HelloWorld::repro_setup(Ref* pSender)
{
    log("setup");
    ReproCpp::setup("YOUR_APP_TOKEN");
}

void HelloWorld::repro_optIn(Ref* pSender)
{
    ReproCpp::optIn(true);
}

void HelloWorld::repro_optOut(Ref* pSender)
{
    ReproCpp::optIn(false);
}

void HelloWorld::repro_setLoglevel(Ref* pSender)
{
    log("setLogLevel");
    Sprite* sprite = (Sprite*)pSender;
    int tag = sprite->getTag();
    switch (tag) {
        case 1:
            ReproCpp::setLogLevel("Debug");
            break;
        case 2:
            ReproCpp::setLogLevel("Info");
            break;
        case 3:
            ReproCpp::setLogLevel("Warn");
            break;
        case 4:
            ReproCpp::setLogLevel("Error");
            break;
        case 5:
            ReproCpp::setLogLevel("None");
            break;
        default:
            break;
    }
}

void HelloWorld::repro_setUserID(Ref* pSender)
{
    log("setUserID");
    ReproCpp::setUserID("Cocos2dx-Android-1");
}

void HelloWorld::repro_setUserProfile(Ref* pSender)
{
    log("setUserProfile");
    ReproCpp::setStringUserProfile("Gender", "Male");
    ReproCpp::setStringUserProfile("Job", "Software Engineer");
}

void HelloWorld::repro_track(Ref* pSender)
{
    log("track");
    ReproCpp::track("eventName1");
}

void HelloWorld::repro_trackWithProperties(Ref* pSender)
{
    log("trackWithProperties");
    ReproCpp::trackWithProperties("eventName", R"({"hoge": "moge", "fuga": "hage"})");
}

void HelloWorld::repro_crash(Ref* pSender)
{
    log("crash");
    abort();
}

void HelloWorld::repro_disableInAppMessageOnActive(Ref* pSender)
{
    log("disableInAppMessageOnActive");
    ReproCpp::disableInAppMessageOnActive();
}

void HelloWorld::repro_showInAppMessage(Ref* pSender)
{
    log("showInAppMessage");
    ReproCpp::showInAppMessage();
}

void HelloWorld::repro_setPushRegistrationID(Ref* pSender)
{
    log("setPushRegistrationID");
    ReproCpp::setPushRegistrationID("");
}

// Starndard API
void HelloWorld::repro_viewContent(Ref* pSender) {
    log("trackViewContent");

    repro::ViewContentProperties properties;
    properties.setContentName("Slim Jeans");
    properties.setContentCategory("Clothing & Shoes > Mens > Clothing");
    properties.setValue(5000.0);
    properties.setCurrency("JPY");
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackViewContent("1234", &properties);
}

void HelloWorld::repro_search(Ref* pSender) {
    log("trackSearch");

    repro::SearchProperties properties;
    properties.setContentId("1234");
    properties.setContentCategory("Clothing & Shoes > Mens > Clothing");
    properties.setValue(5000.0);
    properties.setCurrency("JPY");
    properties.setSearchString("Jeans");
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackSearch(&properties);
}

void HelloWorld::repro_addToCart(Ref* pSender) {
    log("trackAddToCart");

    repro::AddToCartProperties properties;
    properties.setContentName("Slim Jeans");
    properties.setContentCategory("Clothing & Shoes > Mens > Clothing");
    properties.setValue(5000.0);
    properties.setCurrency("JPY");
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackAddToCart("1234", &properties);
}

void HelloWorld::repro_addToWishlist(Ref* pSender) {
    log("trackAddToWishlist");

    repro::AddToWishlistProperties properties;
    properties.setContentId("1234");
    properties.setContentName("Slim Jeans");
    properties.setContentCategory("Clothing & Shoes > Mens > Clothing");
    properties.setValue(5000.0);
    properties.setCurrency("JPY");
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackAddToWishlist(&properties);
}

void HelloWorld::repro_initiateCheckout(Ref* pSender) {
    log("trackInitiateCheckout");

    repro::InitiateCheckoutProperties properties;
    properties.setContentId("1234");
    properties.setContentName("Slim Jeans");
    properties.setContentCategory("Clothing & Shoes > Mens > Clothing");
    properties.setValue(5000.0);
    properties.setCurrency("JPY");
    properties.setNumItems(10);
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackInitiateCheckout(&properties);
}

void HelloWorld::repro_addPaymentInfo(Ref* pSender) {
    log("trackAddPaymentInfo");

    repro::AddPaymentInfoProperties properties;
    properties.setContentId("1234");
    properties.setContentCategory("Clothing & Shoes > Mens > Clothing");
    properties.setValue(5000.0);
    properties.setCurrency("JPY");
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackAddPaymentInfo(&properties);
}

void HelloWorld::repro_purchase(Ref* pSender) {
    log("trackPurchase");

    repro::PurchaseProperties properties;
    properties.setContentName("Slim Jeans");
    properties.setContentCategory("Clothing & Shoes > Mens > Clothing");
    properties.setNumItems(2);
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackPurchase("1234", 5000.0, "JPY", &properties);
}

void HelloWorld::repro_share(Ref* pSender) {
    log("trackShare");

    repro::ShareProperties properties;
    properties.setContentId("1234");
    properties.setContentName("Slim Jeans");
    properties.setContentCategory("Clothing & Shoes > Mens > Clothing");
    properties.setServiceName("twitter");
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackShare(&properties);
}

void HelloWorld::repro_lead(Ref* pSender) {
    log("trackLead");

    repro::LeadProperties properties;
    properties.setContentName("Slim Jeans");
    properties.setContentCategory("Clothing & Shoes > Mens > Clothing");
    properties.setValue(5000.0);
    properties.setCurrency("JPY");
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackLead(&properties);
}

void HelloWorld::repro_completeRegistration(Ref* pSender) {
    log("trackCompleteRegistration");

    repro::CompleteRegistrationProperties properties;
    properties.setContentName("Slim Jeans");
    properties.setValue(5000.0);
    properties.setCurrency("JPY");
    properties.setStatus("completed");
    properties.setExtras(R"({"color": "blue", "waist": 80})");

    ReproCpp::trackCompleteRegistration(&properties);
}
