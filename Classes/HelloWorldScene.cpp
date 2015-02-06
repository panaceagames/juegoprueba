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

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    
    auto nuevo = MenuItemImage::create("nuevojuego1.png", "nuevojuego2.png",
                                       CC_CALLBACK_1(HelloWorld::InicioJuego, this ));
    
   // nuevo->setPosition(Vec2(origin.x + visibleSize.width - nuevo->getContentSize().width/2 ,
     //                       origin.y + nuevo->getContentSize().height/2));
    
    auto closeItem = MenuItemImage::create(
                                           "salir1.png",
                                           "salir2.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    // create menu, it's an autorelease object
    auto menu = Menu::create(nuevo, closeItem, NULL);
    menu->setPosition( ccp(visibleSize.width / 2, visibleSize.height / 2));
    menu->alignItemsVertically();
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello Ulises", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("fondo.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
        
        
      // aca poner logo  menu->setPosition( ccp((visibleSize.width / 2)*1.8 , (visibleSize.height / 2)*0.2));
    
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


