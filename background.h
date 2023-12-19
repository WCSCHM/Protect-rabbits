#pragma once
#include"cocos2d.h"
class Background :public cocos2d::Scene
{
public:
	virtual bool init();
	static cocos2d::Scene* Createscene();
	CREATE_FUNC(Background);
};