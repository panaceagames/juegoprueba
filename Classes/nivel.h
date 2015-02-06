//
//  nivel.h
//  juegoprueba
//
//  Created by BigBoss on 24/1/15.
//
//

#ifndef __juegoprueba__nivel__
#define __juegoprueba__nivel__

#include "cocos2d.h"

class nivel : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void menuCloseCallback(Ref* pSender);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(nivel);
    
private:
    void principio( cocos2d::Ref* pSender);
  //  void GoToGameScene( cocos2d::Ref *sender );
};


#endif /* defined(__juegoprueba__nivel__) */
