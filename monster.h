#pragma once
#include"cocos2d.h"
class Monster :public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Layer* CreateMonster();
	void MoveforMonster1(float dt);
	void MoveforMonster2(float dt);
	void MoveforMonster3(float dt);
	void MoveforMonster4(float dt);
	void MoveforMonster5(float dt);
	void MoveforMonster6(float dt);
	CREATE_FUNC(Monster);
};