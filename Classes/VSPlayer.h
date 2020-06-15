#include "cocos2d.h"
class VSPlayer :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(VSPlayer);
private:
	cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char* format, int count);
};