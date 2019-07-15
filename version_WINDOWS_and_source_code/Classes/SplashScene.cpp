#include "SplashScene.h"
#include "MainMenuScene.h"
#include"definitions.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
   // Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Add Background + transition to next scene
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto background = Sprite::create("res/Splash.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, -1);

	float rX = visibleSize.width / background->getContentSize().width;
	float rY = visibleSize.height / background->getContentSize().height;
	background->setScaleX(rX);
	background->setScaleY(rY);



	scheduleOnce(schedule_selector(SplashScene::SwitchToMainMenu), SPLASH_SCENE_SHOW_TIME);
    return true;
}
void SplashScene::SwitchToMainMenu(float dt)
{
	Scene* scene = MainMenuScene::createScene();
	TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);
	Director::getInstance()->replaceScene(transition);
}
