#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "AudioEngine.h"

USING_NS_CC;




class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init() ;
  

    void onEnterTransitionDidFinish();

    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
    // a selector callback
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    
private:
   
};

#endif // __HELLOWORLD_SCENE_H__
