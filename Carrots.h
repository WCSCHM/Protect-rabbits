#pragma once
#include"cocos2d.h"
class Carrots :public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Layer* CreateCarrots();
	void MoveforCarrots(float dt);
	//void stopAnimation();
	//Sprite* animateSprite;
	CREATE_FUNC(Carrots);
	enum ActionTag;
};