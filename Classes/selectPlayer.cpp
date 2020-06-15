#include "selectPlayer.h"
#include "VSPlayer.h"

enum getKeyCode
{

};
Scene* selectPlayer::createScene()
{
	auto scene = Scene::create();
	auto layer = selectPlayer::create();
	scene->addChild(layer);
	return scene;
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool selectPlayer::init()
{

	if (!Layer::init())
	{
		return false;
	}
	

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spriteList.plist");



	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto h = 1000;
	auto w = 500;
	Vector<SpriteFrame*>::iterator it;



	auto frames = getAnimation("avatar/%04d.jpg", 20);
	it = frames.begin();
	//遍历渲染精灵

	for (int i = 0; i < 5; ++i)//i代表行
	{
		for (int j = 0; j < 4; ++j)//j代表列
		{
			//每次生成的精灵在容器中的位置为当前列数的第几个加上行数与4的乘积
			auto sprite = Sprite::createWithSpriteFrame(*(it + 4 * i + j));
			//放在屏幕中间并且偏移为当前次数与100的乘积
			sprite->setPosition(1200 - 100 * j, h);
			this->addChild(sprite);



		}
		h -= 100;//每输出一行 加一次精灵高度换行

	}
	
	
	createLable("VS");
	createLable("P1");
	createLable("P2");
	auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = CC_CALLBACK_2(selectPlayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	
	
	
	
	return true;
}
void selectPlayer::onEnterTransitionDidFinish()
{

	auto backgroundAudioID = AudioEngine::play2d("ORDER (Player Select).mp3", true);
}
//将精灵存入vector
Vector<SpriteFrame*> selectPlayer::getAnimation(const char* format, int count)
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
Label* selectPlayer::createLable(const char* playerName)
{
	log("call function!");
	auto labelPlayer = Label::createWithTTF(playerName, "fonts/arial.ttf", 48);
	
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (labelPlayer == nullptr)
	{
		problemLoading("'fonts/arial.ttf'");
		
	}
	else
	{
		
		if (strcmp(playerName,"P1")==0)
		{
			// position the label on the center of the screen
			labelPlayer->setPosition(Vec2(900, 1000));
			labelPlayer->setTextColor(Color4B::RED);
			labelPlayer->enableGlow(Color4B::YELLOW);
			// add the label as a child to this layer
			labelPlayer->setTag(100);
			
		}
		if(strcmp(playerName, "P2")==0)
		{
			labelPlayer->setPosition(Vec2(1200, 1000));
			labelPlayer->setTextColor(Color4B::RED);
			labelPlayer->enableGlow(Color4B::YELLOW);
			labelPlayer->setTag(200);
		
		}
		if (strcmp(playerName, "VS")==0)
		{
			labelPlayer->setPosition(Vec2(origin.x + visibleSize.width / 2,
						origin.y + visibleSize.height - labelPlayer->getContentSize().height));
		
		}
		this->addChild(labelPlayer, 1);
		return labelPlayer;
	}
}
void selectPlayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto target = getChildByTag(100);
	auto target2 = getChildByTag(200);
	float X = target->getPositionX();
	float Y = target->getPositionY();
	float X1 = target2->getPositionX();
	float Y1 = target2->getPositionY();
	static float down, left, up, right;
	static bool isNoSelected = true;
	
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_S :
		if (isNoSelected)
		{
			down = 100;


			if ((int)target->getPositionY() == 600)
			{


				target->setPosition(X, 1000);
				down = 0;
			}
			else
			{

				target->setPosition(X, Y - down);


			}
		}
		
		
	
	
		break;                                                                                            
		


	case EventKeyboard::KeyCode::KEY_A :
		if (isNoSelected)
		{
			left = 100;



			if ((int)target->getPositionX() == 900)
			{
				target->setPosition(1200, Y);

				left = 0;
			}
			else
			{

				target->setPosition(X - left, Y);


			}
		}
		
		
		
		
		
		break;

case EventKeyboard::KeyCode::KEY_W:
	if (isNoSelected)
	{
		up = 100;

		if ((int)target->getPositionY() == 1000)
		{
			target->setPosition(X, 600);

			up = 0;
		}

		else
		{
			target->setPosition(X, Y + up);


		}
	}
	

	break;
	case EventKeyboard::KeyCode::KEY_D:
		if (isNoSelected)
		{
			right = 100;


			if (target->getPositionX() == 1200)
			{


				target->setPosition(900, Y);
				right = 0;
			}
			else
			{

				target->setPosition(X + right, Y);

			}
		}
		
    break;
	case EventKeyboard::KeyCode::KEY_J:
		isNoSelected = false;
		playerList(700, 1200);
	/*	Director::getInstance()->replaceScene(TransitionFade::create(0.5, myScene, Color3B(0, 255, 255)));;*/
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		if (isNoSelected)
		{
			left = 100;



			if ((int)target2->getPositionX() == 900)
			{
				target2->setPosition(1200, Y1);

				left = 0;
			}
			else
			{

				target2->setPosition(X1 - left, Y1);


			}
		}

			break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		if (isNoSelected)
		{
			right = 100;


			if (target2->getPositionX() == 1200)
			{


				target2->setPosition(900, Y1);
				right = 0;
			}
			else
			{

				target2->setPosition(X1 + right, Y1);

			}
		}

		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		if (isNoSelected)
		{
			up = 100;

			if ((int)target2->getPositionY() == 1000)
			{
				target2->setPosition(X1, 600);

				up = 0;
			}

			else
			{
				target2->setPosition(X1, Y1 + up);


			}
		}
		break;

	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		if (isNoSelected)
		{
			down = 100;


			if ((int)target2->getPositionY() == 600)
			{


				target2->setPosition(X1, 1000);
				down = 0;
			}
			else
			{

				target2->setPosition(X1, Y1 - down);


			}
		}
		break;
	/*default:
		break;*/
	}


}
void selectPlayer::playerList(float X, float Y)
{
	if ( X == 720 && Y == 620)
	{
		log("%d", X);
		log("%d", Y);
		log("you choose mai!!have fun!");
	}
	if (X == 700 && Y == 1200)
	{
		log("you choose iori!have fun!");
		Director::getInstance()->replaceScene(VSPlayer::createScene());
	}

}
void selectPlayer::setSpriteColor(float x, float y, Vector<SpriteFrame*>::iterator it)
{
	/*auto frames = getAnimation("avatar/%04d.jpg", 20);
	it = frames.begin();
	if (x == 900 && y == 1000)
		*(it)->setColor(Color3B::RED);*/
}
