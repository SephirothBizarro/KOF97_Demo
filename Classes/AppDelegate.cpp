#include "HelloWorldScene.h"
#include "AppDelegate.h"

#define USE_AUDIO_ENGINE 1


#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"

#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(2048, 1536);
static cocos2d::Size smallResolutionSize = cocos2d::Size(512, 384);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
	initOpenGL();
	initDirector();
	initMultiResolution();
	createAndRunScene();
	return true;
   
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}

void AppDelegate::initMultiResolution()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();

    glview->setDesignResolutionSize(
        designResolutionSize.width,
        designResolutionSize.height,
        ResolutionPolicy::NO_BORDER
    );
	std::vector<std::string> searchPaths;
	float scaleFactor = 1.0f;
	Size frameSize = glview->getFrameSize();

	if (frameSize.height > mediumResolutionSize.height)
	{
		searchPaths.push_back("res/HDR");
		scaleFactor = largeResolutionSize.height / designResolutionSize.height;
	}
	else if (frameSize.height > smallResolutionSize.height)
	{
		searchPaths.push_back("res/HD");
		scaleFactor = mediumResolutionSize.height / designResolutionSize.height;
	}
	else
	{
		searchPaths.push_back("res/SD");
		scaleFactor = smallResolutionSize.height / designResolutionSize.height;
	}

	director->setContentScaleFactor(scaleFactor);
	FileUtils::getInstance()->setSearchPaths(searchPaths);
}
void AppDelegate::initOpenGL()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("KOF97_Demo", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
		glview = GLViewImpl::create("KOF97_Demo");
#endif
		director->setOpenGLView(glview);
	}
}
void AppDelegate::initDirector()
{
	auto director = Director::getInstance();
	director->setAnimationInterval(1.0 / 60);
	director->setDisplayStats(true);
}
void AppDelegate::createAndRunScene()
{
	auto scene = HelloWorld::createScene();
	Director::getInstance()->runWithScene(scene);
}
