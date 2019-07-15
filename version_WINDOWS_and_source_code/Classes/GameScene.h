#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
using namespace std;
using namespace ui;


class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

public:
	// Touch event listeners
	EventListenerTouchOneByOne* listener;
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);
	bool validmove(int, int);
	bool moulinformation(int,int);
	void endgame();
	

	//graphics
	Sprite* tokens[24];
	
	int database[24];
	int player = -1;
	int times = 0;
	Sprite* black[9];
	Sprite* white[9];

	int selected = -1;
	int source = 0;
	int destination = 0;
	int capture = 0;
	int nocapture[24];
	int noir, blanc;



};


#endif // __GAME_SCENE_H__
