#pragma once
#include"cocos2d.h"
#include"MyScene.h"
class Monster :public cocos2d::Layer
{
public:
	std::vector<cocos2d::Sprite*> monsters;
	std::vector<std::pair<float, float> >destination;
	Sprite* monster;
	bool isDead = false;
	bool isEnd = false;
	virtual bool init();
	void initMonster(MyScene* background,int type);
	//void update(float dt);
	Monster* CreateMonster();
	void MoveforMonster1(float dt);
	void MoveforMonster2(float dt);
	void MoveforMonster3(float dt);
	void MoveforMonster4(float dt);
	void MoveforMonster5(float dt);
	void MoveforMonster6(float dt);
	int checkMonstersReachedEnd(const cocos2d::Vec2& endPoint, float threshold);
	CREATE_FUNC(Monster);
	std::vector<cocos2d::Vec2>getMonstersPositions();
};
//Monster* newMonster=CreateMonster();
//newMonster->initMonster();