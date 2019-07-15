#include "AppDelegate.h"
#include "SplashScene.h"

// is the game landscape or portrait (true for landscape and false for portrait)
#define IS_LANDSCAPE false

USING_NS_CC;
static cocos2d::Size designResolutionSize = cocos2d::Size(1333.5, 724.5); //  904, 503
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);


AppDelegate::AppDelegate() {
    
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("Jeu De Moulin", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
		glview = GLViewImpl::create("Jeu De Moulin");
#endif
		director->setOpenGLView(glview);
    }
    
    // turn on display FPS
    director->setDisplayStats(false);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    auto fileUtils = FileUtils::getInstance( );
    auto screenSize = glview->getFrameSize( );
    std::vector<std::string> resDirOrders;
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // check which assets the devices requires
    if ( 2048 == screenSize.width || 2048 == screenSize.height ) // retina iPad
    {
        resDirOrders.push_back( "ipadhd" );
        resDirOrders.push_back( "ipad" );
        resDirOrders.push_back( "iphonehd5" );
        resDirOrders.push_back( "iphonehd" );
        resDirOrders.push_back( "iphone" );
        
        if ( true == IS_LANDSCAPE )
        {
            glview->setDesignResolutionSize( 2048, 1536, ResolutionPolicy::NO_BORDER );
        }
        else
        {
            glview->setDesignResolutionSize( 1536, 2048, ResolutionPolicy::NO_BORDER );
        }
    }
    else if ( 1024 == screenSize.width || 1024 == screenSize.height ) // non retina iPad
    {
        resDirOrders.push_back( "ipad" );
        resDirOrders.push_back( "iphonehd5" );
        resDirOrders.push_back( "iphonehd" );
        resDirOrders.push_back( "iphone" );
        
        if ( true == IS_LANDSCAPE )
        {
            glview->setDesignResolutionSize( 1024, 768, ResolutionPolicy::NO_BORDER );
        }
        else
        {
            glview->setDesignResolutionSize( 768, 1024, ResolutionPolicy::NO_BORDER );
        }
    }
    else if ( 1136 == screenSize.width || 1136 == screenSize.height ) // retina iPhone (5 and 5S)
    {
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        
        if ( true == IS_LANDSCAPE )
        {
            glview->setDesignResolutionSize( 1136, 640, ResolutionPolicy::NO_BORDER );
        }
        else
        {
            glview->setDesignResolutionSize( 640, 1136, ResolutionPolicy::NO_BORDER );
        }
    }
    else if ( 960 == screenSize.width || 960 == screenSize.height ) // retina iPhone (4 and 4S)
    {
        resDirOrders.push_back( "iphonehd" );
        resDirOrders.push_back( "iphone" );
        
        if ( true == IS_LANDSCAPE )
        {
            glview->setDesignResolutionSize( 960, 640, ResolutionPolicy::NO_BORDER );
        }
        else
        {
            glview->setDesignResolutionSize( 640, 960, ResolutionPolicy::NO_BORDER );
        }
    }
    else // non retina iPhone and Android devices
    {
        if ( 1080 < screenSize.width && 1080 < screenSize.height ) // android devices that have a high resolution
        {
            resDirOrders.push_back( "iphonehd" );
            resDirOrders.push_back( "iphone" );
            
            if ( true == IS_LANDSCAPE )
            {
                glview->setDesignResolutionSize( 960, 640, ResolutionPolicy::NO_BORDER );
            }
            else
            {
                glview->setDesignResolutionSize( 640, 960, ResolutionPolicy::NO_BORDER );
            }
        }
        else // non retina iPhone and Android devices with lower resolutions
        {
            resDirOrders.push_back( "iphone" );
            
            if ( true == IS_LANDSCAPE )
            {
                glview->setDesignResolutionSize( 480, 320, ResolutionPolicy::NO_BORDER );
            }
            else
            {
                glview->setDesignResolutionSize( 320, 480, ResolutionPolicy::NO_BORDER );
            }
        }
    }
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    resDirOrders.push_back( "ipad" );
    resDirOrders.push_back( "iphonehd5" );
    resDirOrders.push_back( "iphonehd" );
    resDirOrders.push_back( "iphone" );
    
    if ( true == IS_LANDSCAPE )
    {
        glview->setFrameSize( 1024, 768 );
        glview->setDesignResolutionSize( 1024, 768, ResolutionPolicy::NO_BORDER );
    }
    else
    {
        glview->setFrameSize( 768, 1024 );
        glview->setDesignResolutionSize( 768, 1024, ResolutionPolicy::NO_BORDER );
    }
#endif
    
    fileUtils->setSearchPaths(resDirOrders);
    
    // create a scene. it's an autorelease object
    auto scene = SplashScene::createScene();
    
    // run
    director->runWithScene(scene);
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
