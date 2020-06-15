#pragma once
#include "cocos2d.h"
#include "AudioEngine.h"

class selectMenu:public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init() override;
	void cleanup();
	CREATE_FUNC(selectMenu);
private:
	

};

