#include "HelloWorldScene.h"
#include "nivel.h"
#include "GameOver.h"
#include "GamePause.h"

#define TRANSITION_TIME 0.9

USING_NS_CC;

Scene* GamePause::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GamePause::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GamePause::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    
    auto nuevo = MenuItemImage::create("iniciomenu/new game.png", "iniciomenu/new game selec.png",
                                       CC_CALLBACK_1(GamePause::Retry, this ));
    
    auto nuevo1 = MenuItemImage::create("iniciomenu/continue.png", "iniciomenu/continue selec.png",
                                       CC_CALLBACK_1(GamePause::Resume, this ));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(nuevo, nuevo1, NULL);
    menu->setPosition( Vec2(origin.x + visibleSize.width / 2,origin.y + visibleSize.height / 2));
    menu->alignItemsVertically();
    this->addChild(menu, 2);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto imagenGameOver = LabelTTF::create("PAUSE", "Arial", 48);
    
    // position the label on the center of the screen
    imagenGameOver->setPosition(Vec2(origin.x + visibleSize.width/2,
                                     origin.y + (visibleSize.height * 0.78) - imagenGameOver->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(imagenGameOver, 2);
    
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
    
    auto close = MenuItemImage::create("iniciomenu/exit.png","iniciomenu/exit selec.png",
                                       CC_CALLBACK_1(GamePause::menuCloseCallback, this));
    
    // create menu, it's an autorelease object
    auto exit = Menu::create(close, NULL);
    exit->setAnchorPoint(Vec2::ZERO);
    exit->setPosition( Vec2(visibleSize.width * 0.88, visibleSize.height * 0.06));
    this->addChild(exit, 2);
    
    return true;
}


void GamePause::menuCloseCallback(Ref* pSender)
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

void GamePause::Resume( cocos2d::Ref* sender)
{
    Director::getInstance()->popScene();
}

void GamePause::Retry( cocos2d::Ref* sender)
{
    auto scene = nivel::createScene();
    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}
