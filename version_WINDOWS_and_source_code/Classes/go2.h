#ifndef __GO2_H__
#define __GO2_H__

#include "cocos2d.h"

class go2 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(go2);

private:
	Layer* menu;

};

#endif // __GO2_H__
