#pragma once
#include"cocos2d.h"
#include"MyScene.h"
class Monster :public cocos2d::Layer
{
public:
	std::vector<cocos2d::Sprite*> monsters;
	Sprite* monster;
	bool isDead = false;
	bool isEnd = false;
	int bloodTemplate[7] = { 0,1,2,3,4,5,6 };
	int blood[7] = { 0,1,2,3,4,5,6 };
	int type;
	Scene* BG;
	std::vector<Vec2>destination;
	float velocity[7] = { 0,50,50,100,100,100,100 };
	void initMonster(std::vector<Vec2>InflectionPoint, std::vector<float>distance, Scene* background, int spriteType);
	virtual bool init();
	void update(float dt);
	Monster* CreateMonster();
	int checkMonstersReachedEnd(const cocos2d::Vec2& endPoint, float threshold);
	CREATE_FUNC(Monster);
	std::vector<cocos2d::Vec2>getMonstersPositions();
};
