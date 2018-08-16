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
    void repro_setLoglevel(Ref* pSender);
    void repro_startRecording(Ref* pSender);
    void repro_stopRecording(Ref* pSender);
    void repro_pauseRecording(Ref* pSender);
    void repro_resumeRecording(Ref* pSender);
    void repro_maskWithRect(Ref* pSender);
    void repro_unmaskWithRect(Ref* pSender);
    void repro_setUserID(Ref* pSender);
    void repro_setUserProfile(Ref* pSender);
    void repro_track(Ref* pSender);
    void repro_trackWithProperties(Ref* pSender);
    void repro_crash(Ref* pSender);
    void repro_disableInAppMessageOnActive(Ref* pSender);
    void repro_showInAppMessage(Ref* pSender);
    void repro_setPushRegistrationID(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
