#pragma once
#include"cocos2d.h"
class Bloodbar :public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Layer* CreateBloodbar();
	void BloodbarMove(float dt);
	void BloodbarChange(float dt);
	CREATE_FUNC(Bloodbar);
};