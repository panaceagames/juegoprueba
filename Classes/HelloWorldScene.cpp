#include "HelloWorldScene.h"
#include "nivel.h"

#define TRANSITION_TIME 0.9

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto nuevo = MenuItemImage::create("iniciomenu/new game.png", "iniciomenu/new game selec.png",
                                       CC_CALLBACK_1(HelloWorld::InicioJuego, this ));
    
    auto closeItem = MenuItemImage::create(
                                           "iniciomenu/configuration.png",
                                           "iniciomenu/configuration selec.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    // create menu, it's an autorelease object
    auto menu = Menu::create(nuevo, closeItem, NULL);
    menu->setPosition( Vec2(origin.x + visibleSize.width / 2,origin.y + visibleSize.height / 2));
    menu->alignItemsVertically();
    this->addChild(menu, 1);

       // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("iniciomenu/fondo menu.png");

    // position the sprite on the center of the screen
    sprite -> setAnchorPoint(Vec2::ZERO);
        
        // position the sprite on the center of the screen
    sprite->setPosition(Vec2(0,0));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
        
    auto logo = Sprite::create("iniciomenu/titulo menu.png");
        logo->setAnchorPoint(Vec2::ZERO);
        logo->setPosition(Vec2(0,0));
        this->addChild(logo, 1);
        
     auto close = MenuItemImage::create(
                                        "iniciomenu/exit.png",
                                        "iniciomenu/exit selec.png",
                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
        
        // create menu, it's an autorelease object
        auto exit = Menu::create(close, NULL);
        exit->setAnchorPoint(Vec2::ZERO);
        exit->setPosition( Vec2(visibleSize.width * 0.88, visibleSize.height * 0.06));
        this->addChild(exit, 1);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::InicioJuego( cocos2d::Ref* sender)
{
        auto scene = nivel::createScene();
        Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME, scene));
}

