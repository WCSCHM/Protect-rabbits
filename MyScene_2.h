#pragma once
#include"MyScene.h"
#include "cocos2d.h"

class MyScene_2 : public MyScene
{
private:
    Sprite* pause_02;  // 将 pause_0 声明为类的成员变量
    MyScene* mySceneReference;
public:
    static MyScene_2* createScene();
    virtual bool init();
    bool MyScene_2::onTouchBeganForPause_2(cocos2d::Touch* touch, cocos2d::Event* event);
    CREATE_FUNC(MyScene_2);
    bool init(MyScene* scene);

};