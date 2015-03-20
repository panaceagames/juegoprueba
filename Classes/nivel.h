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
//#include "GameSprite.h"

class nivel : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void menuCloseCallback(Ref* pSender);
    
    void Pausa(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(nivel);

    cocos2d::Sprite* _bird;
    
    void inicioTouch();
    
    #define BIRD_COLLISION_BITMASK 0x000001
    #define OBSTACLE_COLLISION_BITMASK 0x000002
    #define POINT_COLLISION_BITMASK 0x000003
    #define COMIDA_COLLISION_BITMASK 0x000004
    #define SCORE_FONT_SIZE 0.1
    
    unsigned int score;
    
    cocos2d::Label *scoreLabel;
    
//private:
    void principio( cocos2d::Ref* pSender);
    
    cocos2d::Vector<cocos2d::Sprite*> _bombas;
    cocos2d::Vector<cocos2d::Sprite*> _comida;
    cocos2d::Vector<cocos2d::Sprite*> _puntos;
    
    
    void crearBomba(float dt);
    void crearComida(float dt);
    void crearPuntos(float dt);
    void agregarBombar(float dt);
    void inicializarFisicaBomba(cocos2d::Sprite* sprite);
    void inicializarFisicaComida(cocos2d::Sprite* sprite);
    void inicializarFisicaPuntos(cocos2d::Sprite* sprite);

    
    
   void moverJugador( cocos2d::Touch* toque, cocos2d::Event* event);
    void GameOve( cocos2d::Ref *sender );
    void perdio(float dt);
    
    bool onContactBegin(cocos2d::PhysicsContact& contact);

    
};


#endif /* defined(__juegoprueba__nivel__) */
