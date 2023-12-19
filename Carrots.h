#pragma once
#include"cocos2d.h"
class Carrots :public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Layer* CreateCarrots();
	void MoveforCarrots(float dt);
	CREATE_FUNC(Carrots);
};