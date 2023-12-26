#pragma once
#include "cocos2d.h"
#include<string>
#include"Bullet.h"
using namespace cocos2d;

class Bullet;
class Tower :public Sprite {
public:
	Vec2 pos;
	int type = 1;
	int level=1;
	enum {
		up=-1,
		left=-2,
		right=0,
		down=1,
	};
	
	std::vector<Bullet*>Magazine1;
	std::vector<Bullet*>Magazine2;
	std::vector<Bullet*>Magazine3;

	Scene* BG;
	int dir;
	double enemyDirection=0;
	double currentAngle;
	float attackRange = 300.0;
	bool startFire = false;
	bool Incoming = false;
	bool Upgrade = false;
	int money;
	
	Vec2 enemyPos;


	Sprite* newTower;
	Sprite* pedestal;
	double angel;
	float enemyHurt=0;
	
	float hurt[4] = { 0,1,1.5,2 };
	bool MagazineLoaded[4] = { false,false,false,false };

	

	virtual bool init();
	
	static Tower* createTower();

	static Tower* create() {
		Tower* pRet = new(std::nothrow) Tower(); if (pRet && pRet->init()) {
			pRet->autorelease(); return pRet;
		}
		else {
			delete pRet; pRet = nullptr; return nullptr;
		}
	};
	void setIncoming(Vec2 CurrentPosition);
	void placeTower(Vec2 pos,int direction,Scene* background);
	void checkstartFire(float dt);
	void update(float dt);
	void prepareFire();
	void Fire();
	double CalculateArccos();
	Bullet* selectBullet();
	void bornEffect();
	void upgrade();
};