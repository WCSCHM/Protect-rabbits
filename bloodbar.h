#pragma once
#include"cocos2d.h"
class Bloodbar :public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Layer* CreateBloodbar();
	void BloodbarMove1(float dt);
	void BloodbarMove2(float dt);
	void BloodbarMove3(float dt);
	void BloodbarMove4(float dt);
	void BloodbarMove5(float dt);
	void BloodbarMove6(float dt);
	void BloodbarChange(float dt);
	CREATE_FUNC(Bloodbar);
};