#pragma once
#include"cocos2d.h"
#include "AudioEngine.h"

USING_NS_CC;




class selectPlayer:public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	Label* createLable(const char* playerName);
	void onEnterTransitionDidFinish();
	CREATE_FUNC(selectPlayer);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void playerList(float X,float Y);
	void setSpriteColor(float x,float y, Vector<SpriteFrame*>::iterator it);
private:
	cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char* format, int count);
	
};


