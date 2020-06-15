#include "HelloWorldScene.h"
#include "selectMenu.h"

Scene* HelloWorld::createScene()
{
	
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
  
    if ( !Scene::init() )
    {
        return false;
    }
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
   
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   

    auto label = Label::createWithTTF("Press any key to continue!", "fonts/Marker Felt.ttf", 32);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("bg1.jpg");
    if (sprite == nullptr)
    {
        problemLoading("'bg1.jpg'");
    }
    else
    {
      /*  sprite->setAnchorPoint(Vec2(-1,-1));*/
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
        sprite->setScale(2.5);
        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    return true;
}



void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    auto myScene = selectMenu::create();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, myScene, Color3B(0, 255, 255)));
}

void HelloWorld::onEnterTransitionDidFinish()
{
  
    auto audioID = AudioEngine::play2d("Fire (Title).mp3");

 
}
