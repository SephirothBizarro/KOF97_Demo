#include "VSPlayer.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;
Scene* VSPlayer::createScene()
{
	auto scene = Scene::create();
	auto layer = VSPlayer::create();
	scene->addChild(layer);
	return scene;
}

bool VSPlayer::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto listener = EventListenerKeyboard::create();
	auto loadingBar =  LoadingBar::create("LoadingBarFile.jpg");
	auto loadingBar2 = LoadingBar::create("LoadingBarFile2.jpg");
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background = Sprite::createWithSpriteFrameName("backGround2.png");
	background->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	background->setScale(2.5);
	this->addChild(background);
	loadingBar->setDirection(LoadingBar::Direction::LEFT);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	loadingBar2->setDirection(LoadingBar::Direction::LEFT);
	loadingBar->setScale(2);
	loadingBar2->setScale(2);

	loadingBar->setPosition(cocos2d::Vec2(500, 1050));
	loadingBar2->setPosition(cocos2d::Vec2(1500, 1050));
	loadingBar->setPercent(100);
	loadingBar2->setPercent(100);
	this->addChild(loadingBar,0);
	this->addChild(loadingBar2, 0);
	
	auto frames = getAnimation("iori_Idle/%04d.png", 9);
	auto frames2 = getAnimation("mai_Idle/%04d.png", 18);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());
	auto sprite2= Sprite::createWithSpriteFrame(frames2.front());
	background->addChild(sprite);
	background->addChild(sprite2);
	sprite->setPosition(100, 80);
	sprite2->setPosition(600, 80);
	sprite2->setFlippedX(true);
	auto animation2= Animation::createWithSpriteFrames(frames2, 1.0f / 18);

	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 9);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
	sprite2->runAction(RepeatForever::create(Animate::create(animation2)));
	auto mySprite = Sprite::create("VS.png");
	mySprite->setPosition(visibleSize.width / 2, 1150);
	this->addChild(mySprite);
	auto mySprite2 = Sprite::create("Fight.png");
	mySprite2->setPosition(visibleSize.width / 2, 1000);
	auto scaleBy = ScaleBy::create(0.5f, 2.0f,2.0f);
	auto fadeIn = FadeIn::create(1.0f);
	auto fadeOut = FadeOut::create(0.1f);
	auto delayTime = DelayTime::create(2.0f);
	
	auto seq = Sequence::create(scaleBy, delayTime, fadeOut, nullptr);
	mySprite2->runAction(seq);
	this->addChild(mySprite2);

	return true;
}
Vector<SpriteFrame*> VSPlayer::getAnimation(const char* format, int count)
{
	auto spriteCache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> animFrames;
	char str[100];
	for (int i = 1; i <= count; i++)
	{
		sprintf(str, format, i);
		animFrames.pushBack(spriteCache->getSpriteFrameByName(str));
	}
	return animFrames;
	
}