#pragma once
#include"cocos2d.h"
#include"MyScene.h"
class Bloodbar :public cocos2d::Layer
{
public:
	std::vector<cocos2d::Sprite*> bloodbars_bgs;
	std::vector<cocos2d::ProgressTimer*> bloodbars;
	ProgressTimer* bloodbar;
	std::vector<std::pair<float, float> >destination;
	virtual bool init();
	static cocos2d::Layer* CreateBloodbar();
	void BloodbarMove1(float dt);
	void BloodbarMove2(float dt);
	void BloodbarMove3(float dt);
	void BloodbarMove4(float dt);
	void BloodbarMove5(float dt);
	void BloodbarMove6(float dt);
	void initBloodbar(MyScene* background,int type,float health);
	CREATE_FUNC(Bloodbar);
};