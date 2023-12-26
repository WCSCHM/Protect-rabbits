#include"Bullet.h"
#include"Tower.h"
#include "cocos2d.h"
#include"math.h"
using namespace cocos2d;
#define pi 3.14159


Bullet* Bullet::createBullet() {

	return Bullet::create();

}

bool Bullet::init() {
	if (!Sprite::init())
		return false;
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("tower1.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Bottle.plist");
	return true;
}

void Bullet::loadBullet(int level,Scene* background) {
	switch (level) {
		case 1: {
			bullet = Sprite::create("PBottle11.png");
			this->addChild(bullet, 4);
			BG = background;
			break;
		}
		case 2: {
			bullet = Sprite::create("PBottle21.png");
			this->addChild(bullet, 4);
			BG = background;
			break;
		}
		case 3: {
			bullet = Sprite::create("PBottle31.png");
			this->addChild(bullet, 4);
			BG = background;
			break;
		}
	}
}

void Bullet::aimEnemy(double enemyDirection,Vec2 pos) {
	double offset = 30.0;
	Vec2 bulletPos;
	bulletPos.x = cos(enemyDirection*pi/180)*offset+pos.x;
	bulletPos.y = sin(enemyDirection * pi / 180) * offset + pos.y;
	bullet->setVisible(true);
	bullet->setRotation(-enemyDirection);
	bullet->setPosition(bulletPos);
	startPos = bulletPos;
}

void Bullet::shoot(Vec2 enemyPos) {
	this->enemyPos = enemyPos;
	is_active = true;
	double x = enemyPos.x - startPos.x;
	double y = enemyPos.y - startPos.y;
	double distance = sqrt(x * x + y * y);
	auto fire = MoveTo::create(distance / velosity, enemyPos);
	
	auto playAnimations = CallFunc::create([this, enemyPos]() {
		bullet->setVisible(false);
		// 直接从SpriteFrameCache获取SpriteFrame
		auto explosion1 = Sprite::create("PBottle01.png");
		auto explosion2 = Sprite::create("PBottle02.png");


		explosion1->retain();
		explosion2->retain();

		auto act1 = CallFunc::create([this,enemyPos,explosion1]() {
			explosion1->setPosition(enemyPos);
			BG->addChild(explosion1,4);
			});

		auto act2 = CallFunc::create([this, enemyPos, explosion1,explosion2]() {
			explosion1->setVisible(false);
			explosion2->setPosition(enemyPos);
			BG->addChild(explosion2, 5);
			});
		// 动画结束后清理
		auto animationEnd = CallFunc::create([explosion1, explosion2]() {
			explosion1->removeFromParent();
			explosion2->removeFromParent();
			explosion1->release();
			explosion2->release();
			});
		auto delayAction = DelayTime::create(0.2f);
		// 运行动画序列
		auto animationSequence = Sequence::create(act1,delayAction,act2, animationEnd,nullptr);
		bullet->runAction(animationSequence);
		});

	auto setInactive = CallFunc::create([this]() {
		is_active = false; // 确保这是在动画结束后调用
		hitTarget = true;
		});

	auto sequence = Sequence::create(fire, playAnimations, setInactive, nullptr);
	bullet->runAction(sequence);
}


