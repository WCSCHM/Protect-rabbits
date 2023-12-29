#pragma once
#include"cocos2d.h"
class Carrots :public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Layer* CreateCarrots();
	void MoveforCarrots(float dt);
	void MoveforCarrots1(float dt);
	void MoveforCarrots2(float dt);
	void stopAnimation1();
	cocos2d::Sprite* animateSprite1;
	cocos2d::Sprite* animateSprite2;
	CREATE_FUNC(Carrots);
};