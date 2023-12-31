#pragma once
#include "cocos2d.h"
#include<string>
#include"Bullet.h"
#include"Monster.h"
#include"barrier.h"
#include"bloodBar.h"
using namespace cocos2d;

class Bullet;

/**************************************/

class Tower :public Sprite {
public:
	int mark = 0;
	Vec2 pos;
	int type;
	int level=1;
	enum {
		up=-1,
		left=-2,
		right=0,
		down=1,
	};
	
	
	std::vector<Sprite*>myTower;
	std::vector<Monster*>*enemies;
	std::vector<barrier>*enemyBarrier;
	std::vector<Bloodbar*>*enemyBloodbar;
	std::vector<Bloodbar*>*barrierBloodbar;


	bool isAttackingBarrier = false;


	int enemyType;

	Scene* BG;
	int dir;
	double enemyDirection=0;
	double currentAngle;
	float attackRange = 150.0;
	bool startFire = false;
	bool Incoming = false;
	bool Upgrade = false;
	int money;
	int No;
	int spriteNum;
	int barrierNum;
	
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
	void placeTower(Vec2 pos,int direction,Scene* background,int towerType,int j);
	void update(float dt);
	void bottleFire();
	void starFire();
	void shitFire();
	double CalculateArccos();
	void bornEffect();
	void upgrade();
	
};