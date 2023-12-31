#pragma once
#pragma once
#include"cocos2d.h"

using namespace cocos2d;

class Monster :public cocos2d::Layer
{
public:
	bool isDead = false;
	bool isChecked = false;
	bool isEnd = false;
	bool slowDown = false;

	int type;
	float bloodTemplate[7]= { 0,1,2,3,4,5,6 };
	float blood[7] = { 0,1,2,3,4,5,6 };
	Scene* BG;
	std::vector<cocos2d::Sprite*> monsters;
	std::vector<Vec2>destination;
	float velocity[7] = { 0,50,50,100,100,100,100 };
	Sprite* monster;
	
	std::vector<int>isAttackingMe;

	virtual bool init();
	void initMonster(std::vector<Vec2>InflectionPoint, std::vector<float>distance,Scene* background, int spriteType);
	void update(float dt);
	static Monster* CreateMonster();
	void MoveforMonster1(float dt);
	void MoveforMonster2(float dt);
	void MoveforMonster3(float dt);
	void MoveforMonster4(float dt);
	void MoveforMonster5(float dt);
	void MoveforMonster6(float dt);
	void recover();
	int checkMonstersReachedEnd(const cocos2d::Vec2& endPoint, float threshold);
	CREATE_FUNC(Monster);
	std::vector<cocos2d::Vec2>getMonstersPositions();

	Vec2 realTimeLocation();
};