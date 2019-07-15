#include"MainMenuScene.h"
#include"definitions.h"
#include "ui/CocosGUI.h"
#include<iostream>
#include"go2.h"

using namespace std;

#include "cocos2d.h"

USING_NS_CC;

Scene* go2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = go2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool go2::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("res/b_winner.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, -1);

	float rX = visibleSize.width / background->getContentSize().width;
	float rY = visibleSize.height / background->getContentSize().height;
	background->setScaleX(rX);
	background->setScaleY(rY);


	auto CPUvPlayerButton = cocos2d::ui::Button::create("res/menu.png", "res/menu_p.png");
	CPUvPlayerButton->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 4 + origin.y));
	CPUvPlayerButton->addTouchEventListener([&](Ref * sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{

		case ui::Widget::TouchEventType::ENDED:
			auto scene = MainMenuScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}
		});

	CPUvPlayerButton->setScale(rY);
	this->addChild(CPUvPlayerButton);
    
    return true;
}
