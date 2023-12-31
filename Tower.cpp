#include "cocos2d.h"
#include"Tower.h"
#include<stdlib.h>
#include<vector>
#include<math.h>
#include"Bullet.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
#define pi 3.14159

void Tower::setIncoming(Vec2 CurrentPosition) {
	if (CurrentPosition == Vec2(INT_MAX, INT_MAX)) {
		Incoming = false;
		startFire = false;
	}
	double x = CurrentPosition.x - pos.x;
	double y = CurrentPosition.y - pos.y;
	double distance = sqrt(x * x + y * y);
	if (distance <= attackRange) {
		if (!Incoming) {
			Incoming = true;
		}
		enemyPos = CurrentPosition;
		startFire = true; // 设置为true以开始发射
	}
	else {
		Incoming = false;
		startFire = false; // 设置为false以停止发射
	}
}

Tower* Tower::createTower() {
	
	return Tower::create();
	
}

bool Tower::init() {
	if (!Sprite::init())
		return false;


	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("tower1.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Bottle.plist");


	

	return true;
}

void Tower::placeTower(Vec2 Pos,int direction,Scene* background,int towerType,int j) {
	BG = background;
	pos = Pos;
	dir = direction;
	type = towerType;
	No = j;
	
	switch (type) {
		case 1: {
			pedestal = Sprite::create("Bottle_3.png");
			newTower = Sprite::create("Bottle11.png");
			break;
		}
		case 2: {
			pedestal = Sprite::create("ShitP.png");
			newTower = Sprite::create("Shit1.png");
			break;
		}
		case 3: {
			pedestal = Sprite::create("StarP.png");
			newTower = Sprite::create("Star1.png");
			break;
		}
	}
	auto place = CallFunc::create([this]() {
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("TowerBulid.mp3");
		switch (type) {
			case 1: {
				newTower->setRotation(dir * 90.0);
				newTower->setPosition(pos);
				pedestal->setPosition(pos);
				pedestal->setScale(0.80);
				break;
			}
			case 2: {
				newTower->setScale(0.9);
				pedestal->setPosition(pos);
				newTower->setPosition(Vec2(pos.x, pos.y+10));
				break;
			}
			case 3: {
				newTower->setPosition(Vec2(pos.x + 4, pos.y + 2));
				pedestal->setPosition(pos);
				attackRange = 300;
				break;
			}  
		}
		
		});
	auto startUpdate = CallFunc::create([this]() {
		// 使用schedule函数来每秒调用update方法
		this->schedule(CC_SCHEDULE_SELECTOR(Tower::update), 1.0f); // 1.0f代表每秒更新一次
		});


	auto effect = CallFunc::create([this]() {
		this->bornEffect();
		});

	auto sequence = Sequence::create(effect,place,startUpdate,nullptr);
	
	// 应用这个序列到newTower精灵
	newTower->runAction(sequence);
	this->addChild(pedestal, 1);
	this->addChild(newTower, 2);
}


void Tower::update(float dt) {
	if (Upgrade) {
		upgrade();

	}
	else if (startFire) {
		//开火
		switch (type) {
			case 1: {
				this->bottleFire();
				break;
			}
			case 2: {
				this->shitFire();
				break;
			}
			case 3: {
				this->starFire();
			}
		}
	}

	else {
		newTower->setVisible(true);
	}
}

//以水平向右为基准，得到炮口与精灵实际位置的夹角
double Tower::CalculateArccos() {
	double y = enemyPos.y - pos.y;
	double x = enemyPos.x - pos.x;
	double result = 0;
	double z = sqrt(x * x + y * y);
	double cos = x / z;
	if (x > 0 && y > 0) {
		result= pi / 2 - cos - cos * cos * cos / 6;
	}
	else if (x < 0 && y>0) {
		result= pi / 2 - cos - cos * cos * cos / 6;
	}
	else if (x < 0 && y < 0) {
		result = 2 * pi - (pi / 2 - cos - cos * cos * cos / 6);
	}
	else if (x > 0 && y < 0) {
		result = 2 * pi - (pi / 2 - cos - cos * cos * cos / 6);
	}
	return result*180/pi;
}


void Tower::bottleFire() {
	
	//获取旋转角度
	double enemyAngle = CalculateArccos();
	enemyDirection=enemyAngle;
	auto rotateAction = RotateTo::create(0.1, -enemyAngle);
	Bullet* bullet = Bullet::createBullet();
	bullet->loadBullet(this->level, BG, type);
	
	auto startFire = CallFunc::create([this]() {
		Bullet* bullet = Bullet::createBullet();
		bullet->loadBullet(this->level, BG, type);
		if (bullet != nullptr) {
			if (!bullet->getParent()) {
				BG->addChild(bullet, 4);
			}
			this->schedule([=](float dt) {
				if (bullet->hitTarget) {
					bullet->hitTarget = false;
					if (isAttackingBarrier) {
						(*enemyBarrier)[barrierNum].barrierBlood -= hurt[level];
						(*barrierBloodbar)[barrierNum]->bloodbar->setPercentage((*enemyBarrier)[barrierNum].barrierBlood / 20 * 100.0f);
					}
					else {
						(*enemies)[spriteNum]->blood[enemyType] -= hurt[level];
						(*enemyBloodbar)[spriteNum]->bloodbar->setPercentage((*enemies)[spriteNum]->blood[enemyType] / (*enemies)[spriteNum]->bloodTemplate[enemyType] * 100.0);
					}
					this->unschedule("check_hit");
					
				}
				else
					enemyHurt = 0;
				}, 0.1, "check_hit");

			bullet->hitTarget = false;
			bullet->aimEnemy(enemyDirection, pos);
			bullet->shoot(enemyPos);
		}
		});

	// 定义一个回调函数来播放动画
	auto playAnimations = CallFunc::create([this, enemyAngle]() {
		
		Sprite* newTower11;
		Sprite* newTower12;
		Sprite* newTower13;
		switch (this->level) {
			case 1:{
				newTower11 = Sprite::createWithSpriteFrameName("Bottle11.png");
				newTower12 = Sprite::createWithSpriteFrameName("Bottle12.png");
				newTower13 = Sprite::createWithSpriteFrameName("Bottle13.png");
				break;
			}
			case 2: {
				newTower11 = Sprite::createWithSpriteFrameName("Bottle21.png");
				newTower12 = Sprite::createWithSpriteFrameName("Bottle22.png");
				newTower13 = Sprite::createWithSpriteFrameName("Bottle23.png");
				break;
			}
			case 3: {
				newTower11 = Sprite::createWithSpriteFrameName("Bottle31.png");
				newTower12 = Sprite::createWithSpriteFrameName("Bottle32.png");
				newTower13 = Sprite::createWithSpriteFrameName("Bottle33.png");
				break;
			}
		}
		

		newTower11->setRotation(-enemyAngle);
		newTower12->setRotation(-enemyAngle);
		newTower13->setRotation(-enemyAngle);

		auto animation = Animation::create();

		auto frame0 = newTower11->getSpriteFrame();
		auto frame1 = newTower12->getSpriteFrame();
		auto frame2 = newTower13->getSpriteFrame();

		animation->addSpriteFrame(frame0);
		animation->addSpriteFrame(frame1);
		animation->addSpriteFrame(frame2);

		animation->setDelayPerUnit(0.1f); // 每帧间隔0.5秒
		animation->setLoops(1); // 动画循环播放

		// 创建动画动作
		auto animate = Animate::create(animation);

		auto animationEnd = CallFunc::create([newTower11, newTower12, newTower13]() {
			newTower11->removeFromParent();
			});

		auto animationSequence = Sequence::create(animate, animationEnd, nullptr);
		newTower11->setPosition(pos);
		newTower11->runAction(animationSequence);
		this->addChild(newTower11, 3);
		});

	auto disappear = CallFunc::create([this]() {
		newTower->setVisible(false);
		});

	auto recover= CallFunc::create([this]() {
		newTower->setVisible(true);
		
		});


	auto sequenceAction = Sequence::create(rotateAction,disappear, playAnimations,startFire,recover,nullptr);
	newTower->setVisible(true);
	newTower->runAction(sequenceAction);
	Incoming = false;
}

void Tower::bornEffect() {
	float offset = 30.0;
	Vec2 center = pos;
	auto effect1 = Sprite::create("effect1.png");
	auto effect2 = Sprite::create("effect2.png");
	auto effect31=Sprite::create("effect31.png");
	auto effect32 = Sprite::create("effect32.png");
	auto effect33 = Sprite::create("effect33.png");
	


	effect1->retain();
	effect2->retain();
	effect31->retain();
	effect32->retain();
	effect33->retain();

	auto act1 = CallFunc::create([this, effect1,center]() {
		effect1->setPosition(center);
		this->addChild(effect1, 5);
		});

	auto act2 = CallFunc::create([this, effect1, effect2,center]() {
		effect1->setVisible(false);
		effect2->setPosition(center);
		this->addChild(effect2, 4);
		});

	auto act3 = CallFunc::create([this, effect2, effect31, effect32, effect33,center,offset]() {
		effect2->setVisible(false);
		effect31->setPosition(pos);
		effect31->setPosition(center);
		effect32->setPosition(Vec2(center.x + 5, center.y - offset));
		effect33->setPosition(Vec2(center.x + offset, center.y - 5));
		this->addChild(effect31, 4);
		this->addChild(effect32, 4);
		this->addChild(effect33, 4);
		});
	// 动画结束后清理
	auto animationEnd = CallFunc::create([effect1,effect2, effect31, effect32, effect33]() {
		effect1->removeFromParent();
		effect2->removeFromParent();
		effect31->removeFromParent();
		effect32->removeFromParent();
		effect33->removeFromParent();
		effect1->release();
		effect2->release();
		effect31->release();
		effect32->release();
		effect33->release();
		});
	auto delayAction = DelayTime::create(0.15f);
	// 运行动画序列
	auto animationSequence = Sequence::create(act1, delayAction, act2, delayAction, act3, animationEnd, nullptr);
	newTower->runAction(animationSequence);
}

void Tower::upgrade() {
	auto effect = CallFunc::create([this]() {
			bornEffect();
		});
	auto update = CallFunc::create([this]() {
		switch (type) {
			case 1:{
				if(level==1)
					newTower->setTexture("Bottle21.png");
				else if(level==2)
					newTower->setTexture("Bottle31.png");
				newTower->setPosition(pos);
				if (enemyDirection != 0)
					newTower->setRotation(-enemyDirection);
				else
					newTower->setRotation(dir * 90);
				break;		
			}
			case 2: {
				if (level == 1)
					newTower->setTexture("Shit2.png");
				else if (level == 2)
					newTower->setTexture("Shit3.png");
				newTower->setPosition(Vec2(pos.x,pos.y+10));
				break;
			}
			case 3: {
				if (level == 1)
					newTower->setTexture("Star2.png");
				else if (level == 2)
					newTower->setTexture("Star3.png");
				newTower->setPosition(Vec2(pos.x + 4, pos.y + 2));
				break;
			}
		}
		level++;
		newTower->setVisible(true);
		Upgrade = false;
		});
	auto sequence = Sequence::create(update,effect, nullptr);
	newTower->runAction(sequence);
}

void Tower::shitFire() {
	double enemyAngle = CalculateArccos();
	enemyDirection = enemyAngle;
	auto rotateAction = RotateTo::create(0.1, -enemyAngle);


	auto startFire = CallFunc::create([this]() {
		Bullet* bullet = Bullet::createBullet();
		bullet->loadBullet(this->level, BG, type);
		if (bullet != nullptr) {

			if (!bullet->getParent()) {
				BG->addChild(bullet, 4);
			}

			this->schedule([=](float dt) {
				if (bullet->hitTarget) {
					bullet->hitTarget = false;
					if (isAttackingBarrier) {
						(*enemyBarrier)[barrierNum].barrierBlood -= hurt[level];
						(*barrierBloodbar)[barrierNum]->bloodbar->setPercentage((*enemyBarrier)[barrierNum].barrierBlood / 20 * 100.0f);
					}
					else {
						(*enemies)[spriteNum]->blood[enemyType] -= hurt[level];
						(*enemyBloodbar)[spriteNum]->bloodbar->setPercentage((*enemies)[spriteNum]->blood[enemyType] / (*enemies)[spriteNum]->bloodTemplate[enemyType] * 100.0);
						(*enemies)[spriteNum]->slowDown = true;
						(*enemyBloodbar)[spriteNum]->slowDown = true;
					}
					this->unschedule("check_hit");
				}
				else
					enemyHurt = 0;
				}, 0.1, "check_hit");

			bullet->hitTarget = false;
			bullet->aimEnemy(enemyDirection, pos);
			bullet->shitAttack(enemyPos);
		}
		});

	// 定义一个回调函数来播放动画
	auto playAnimations = CallFunc::create([this, enemyAngle]() {
		Sprite* newTower11;
		Sprite* newTower12;
		Sprite* newTower13;
		switch (this->level) {
			case 1: {
				newTower11 = Sprite::create("Shit1.png");
				newTower12 = Sprite::create("Shit11.png");
				newTower13 = Sprite::create("Shit1.png");
				break;
			}
			case 2: {
				newTower11 = Sprite::create("Shit2.png");
				newTower12 = Sprite::create("Shit21.png");
				newTower13 = Sprite::create("Shit2.png");
				break;
			}
			case 3: {
				newTower11 = Sprite::create("Shit3.png");
				newTower12 = Sprite::create("Shit31.png");
				newTower13 = Sprite::create("Shit3.png");
				break;
			}
		}
		
		auto animation = Animation::create();

		auto frame0 = newTower11->getSpriteFrame();
		auto frame1 = newTower12->getSpriteFrame();
		auto frame2 = newTower13->getSpriteFrame();

		animation->addSpriteFrame(frame0);
		animation->addSpriteFrame(frame1);
		animation->addSpriteFrame(frame2);

		animation->setDelayPerUnit(0.1f); // 每帧间隔0.5秒
		animation->setLoops(1); // 动画循环播放

		// 创建动画动作
		auto animate = Animate::create(animation);

		auto animationEnd = CallFunc::create([newTower11, newTower12, newTower13]() {
			newTower11->removeFromParent();
			});

		auto animationSequence = Sequence::create(animate, animationEnd, nullptr);
		newTower11->setPosition(Vec2(pos.x, pos.y + 10));
		newTower11->runAction(animationSequence);
		this->addChild(newTower11, 3);
		});

	auto disappear = CallFunc::create([this]() {
		newTower->setVisible(false);
		});

	auto recover = CallFunc::create([this]() {

		newTower->setVisible(true);
		});



	auto sequenceAction = Sequence::create(disappear, playAnimations, startFire, recover, nullptr);
	newTower->setVisible(true);
	newTower->runAction(sequenceAction);
	Incoming = false;
}

void Tower::starFire() {
	double enemyAngle = CalculateArccos();
	enemyDirection = enemyAngle;

	auto startFire = CallFunc::create([this]() {
		Bullet* bullet = Bullet::createBullet();
		bullet->loadBullet(this->level, BG, type);
		if (bullet != nullptr) {

			if (!bullet->getParent()) {
				BG->addChild(bullet, 4);
			}

			this->schedule([=](float dt) {
				if (bullet->hitTarget) {
					bullet->hitTarget = false;
					if (isAttackingBarrier) {
						(*enemyBarrier)[barrierNum].barrierBlood -= hurt[level];
						(*barrierBloodbar)[barrierNum]->bloodbar->setPercentage((*enemyBarrier)[barrierNum].barrierBlood / 20 * 100.0f);
						for (int i = 0; i < (*enemyBarrier).size(); i++) {
							Vec2 around = (*enemyBarrier)[i].pos;
							if (around.distance(enemyPos) <= 200) {
								if ((*enemyBarrier)[i].barrierBlood == 20)
									(*barrierBloodbar)[i]->bloodbar->setVisible(true);
								(*enemyBarrier)[i].barrierBlood -= hurt[level];
								(*barrierBloodbar)[i]->bloodbar->setPercentage((*enemyBarrier)[i].barrierBlood /20 * 100.0);
							}
						}
						for (int i = 0; i < (*enemies).size(); i++) {
							Vec2 around = (*enemies)[i]->monster->getPosition();
							if (around.distance(enemyPos) <= 200) {
								(*enemies)[i]->blood[(*enemies)[i]->type] -= hurt[level];
								(*enemyBloodbar)[i]->bloodbar->setPercentage((*enemies)[i]->blood[(*enemies)[i]->type] / (*enemies)[i]->bloodTemplate[(*enemies)[i]->type] * 100.0);
							}
						}
					}
					else {
						(*enemies)[spriteNum]->blood[enemyType] -= hurt[level];
						(*enemyBloodbar)[spriteNum]->bloodbar->setPercentage((*enemies)[spriteNum]->blood[enemyType] / (*enemies)[spriteNum]->bloodTemplate[enemyType] * 100.0);
						for (int i = 0; i < (*enemies).size(); i++) {
							Vec2 around = (*enemies)[i]->monster->getPosition();
							if (around.distance(enemyPos) <= 200) {
								(*enemies)[i]->blood[(*enemies)[i]->type] -= hurt[level];
								(*enemyBloodbar)[i]->bloodbar->setPercentage((*enemies)[i]->blood[(*enemies)[i]->type] / (*enemies)[i]->bloodTemplate[(*enemies)[i]->type] * 100.0);
							}
						}
						for (int i = 0; i < (*enemyBarrier).size(); i++) {
							Vec2 around = (*enemyBarrier)[i].pos;
							if (around.distance(enemyPos) <= 200) {
								if ((*enemyBarrier)[i].barrierBlood == 20)
									(*barrierBloodbar)[i]->bloodbar->setVisible(true);
								(*enemyBarrier)[i].barrierBlood -= hurt[level];
								(*barrierBloodbar)[i]->bloodbar->setPercentage((*enemyBarrier)[i].barrierBlood / 20 * 100.0);
							}
						}
					}
					this->unschedule("check_hit");
				}
				else
					enemyHurt = 0;
				}, 0.1, "check_hit");

			bullet->hitTarget = false;
			bullet->aimEnemy(enemyDirection, pos);
			bullet->starAttack(enemyPos);
		}
		});

	

	auto disappear = CallFunc::create([this]() {
		newTower->setVisible(false);
		});

	auto recover = CallFunc::create([this]() {

		newTower->setVisible(true);
		});



	auto sequenceAction = Sequence::create(startFire, recover, nullptr);
	newTower->setVisible(true);
	newTower->runAction(sequenceAction);
	Incoming = false;
}