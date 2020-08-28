#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void repro_setup(Ref* pSender);
    void repro_optIn(Ref* pSender);
    void repro_optOut(Ref* pSender);
    void repro_setLoglevel(Ref* pSender);
    void repro_setUserID(Ref* pSender);
    void repro_setUserProfile(Ref* pSender);
    void repro_setUserGender(Ref* pSender);
    void repro_setUserEmailAddress(Ref* pSender);
    void repro_track(Ref* pSender);
    void repro_trackWithProperties(Ref* pSender);
    void repro_crash(Ref* pSender);
    void repro_disableInAppMessagesOnForegroundTransition(Ref* pSender);
    void repro_enableInAppMessagesOnForegroundTransition(Ref* pSender);
    void repro_setPushRegistrationID(Ref* pSender);

    // standard event tracking
    void repro_viewContent(Ref* pSender);
    void repro_search(Ref* pSender);
    void repro_addToCart(Ref* pSender);
    void repro_addToWishlist(Ref* pSender);
    void repro_initiateCheckout(Ref* pSender);
    void repro_addPaymentInfo(Ref* pSender);
    void repro_purchase(Ref* pSender);
    void repro_share(Ref* pSender);
    void repro_lead(Ref* pSender);
    void repro_completeRegistration(Ref* pSender);

    // SilverEgg
    void repro_setSilverEggCookie(Ref* pSender);
    void repro_setSilverEggProdKey(Ref* pSender);
    void repro_trySilverEgg(Ref* pSender);

    // NewsFeed
    void repro_getNewsFeeds(Ref* pSender);
    void repro_updateNewsFeeds(Ref* pSender);

    // RemoteConfig
    void repro_remoteConfigSetDefaults(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
