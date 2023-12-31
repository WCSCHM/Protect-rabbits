#pragma once
#include"cocos2d.h"

class Carrots :public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Layer* CreateCarrots();
	void Carrots::MoveforCarrots1(float dt, Vec2 position = Vec2(822, 480));
	void Carrots::MoveforCarrots2(float dt, Vec2 position = Vec2(822, 480));
	void Carrots::MoveforCarrots3(float dt, Vec2 position = Vec2(822, 480));
	void stopAnimation1();
	cocos2d::Sprite* animateSprite1;
	cocos2d::Sprite* animateSprite2;
	CREATE_FUNC(Carrots);
};