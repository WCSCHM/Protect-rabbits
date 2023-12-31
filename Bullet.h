#pragma once
#include "cocos2d.h"
#include "Tower.h"
#include<string>
using namespace cocos2d;

class Bullet :public Sprite {
public:
	Scene* BG;
	Sprite* bullet=NULL;
	int level;
	Vec2 enemyPos;
	bool is_active = false;
	bool hitTarget = false;
	Vec2 startPos;
	float velocity[4] = { 0,600,600,400 };

	void loadBullet(int level,Scene* background,int type);
	void aimEnemy(double enemyDirection, Vec2 pos);
	void shoot(Vec2 enemyPos);
	void dart(double enemyDirection, Vec2 pos);
	void shitAttack(Vec2 enemyPos);
	void starAttack(Vec2 enemyPos);
	float hurt[4] = { 0,0.25,0.34,0.5 };
	
	static Bullet* createBullet();


	virtual bool init();

	static Bullet* create() {
		Bullet* pRet = new(std::nothrow) Bullet(); if (pRet && pRet->init()) {
			pRet->autorelease(); return pRet;
		}
		else {
			delete pRet; pRet = nullptr; return nullptr;
		}
	};
};