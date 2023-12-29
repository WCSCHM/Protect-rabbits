#pragma once
#include"cocos2d.h"
#include"MyScene.h"
class Bloodbar :public cocos2d::Layer
{
public:
	std::vector<cocos2d::ProgressTimer*> bloodbars;
	ProgressTimer* bloodbar;
	int bloodTemplate[7] = { 0,1,2,3,4,5,6 };
	int blood[7] = { 0,1,2,3,4,5,6 };
	int type;
	Scene* BG;
	std::vector<Vec2>destination;
	float velocity[7] = { 0,50,50,100,100,100,100 };
	virtual bool init();
	static cocos2d::Layer* CreateBloodbar();
	void initBloodbar(std::vector<Vec2>InflectionPoint, std::vector<float>distance, Scene* background, int spriteType,float health);
	CREATE_FUNC(Bloodbar);
};