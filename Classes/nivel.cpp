//
//  nivel.cpp
//  juegoprueba
//
//  Created by BigBoss on 24/1/15.
//
//

#include "HelloWorldScene.h"
#include "nivel.h"

#define TRANSITION_TIME 0.9

USING_NS_CC;

Scene* nivel::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = nivel::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool nivel::init()
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
    
    auto nuevo = MenuItemImage::create("bloque.png", "bloque.png",
                                       CC_CALLBACK_1(nivel::principio, this ));
    
    auto closeItem = MenuItemImage::create(
                                           "salir1.png",
                                           "salir2.png",
                                           CC_CALLBACK_1(nivel::menuCloseCallback, this));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(nuevo, closeItem, NULL);
    menu->setPosition( ccp((visibleSize.width / 2)*1.8 , (visibleSize.height / 2)*1.8));
    menu->alignItemsVertically();
    this->addChild(menu, 1);
    
    auto label = LabelTTF::create("Hello Game", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("fondo.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void nivel::menuCloseCallback(Ref* pSender)
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

void nivel::principio( cocos2d::Ref* pSender)
{
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene( TransitionFade::create( TRANSITION_TIME, scene));
}


