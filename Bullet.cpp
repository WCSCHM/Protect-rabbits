#include"Bullet.h"
#include"Tower.h"
#include "cocos2d.h"
#include"math.h"
#include "SimpleAudioEngine.h"
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

void Bullet::loadBullet(int level,Scene* background,int type) {
	switch (level) {
		case 1: {
			if (type == 1) {
				bullet = Sprite::create("PBottle11.png");
				this->addChild(bullet, 4);
				BG = background;
				break;
			}
			if (type == 2) {
				bullet = Sprite::create("PShit1.png");
				this->addChild(bullet, 4);
				BG = background;
				break;
			}
			if (type == 3) {
				bullet = Sprite::create("Star1.png");
				this->addChild(bullet, 4);
				BG = background;
				break;
			}
		}
		case 2: {
			if (type == 1) {
				bullet = Sprite::create("PBottle21.png");
				this->addChild(bullet, 4);
				BG = background;
				break;
			}
			if (type == 2) {
				bullet = Sprite::create("PShit2.png");
				this->addChild(bullet, 4);
				BG = background;
				break;
			}
			if (type == 3) {
				bullet = Sprite::create("Star2.png");
				this->addChild(bullet, 4);
				BG = background;
				break;
			}
		}
		case 3: {
			if (type == 1) {
				bullet = Sprite::create("PBottle31.png");
				this->addChild(bullet, 4);
				BG = background;
				break;
			}
			if (type == 2) {
				bullet = Sprite::create("PShit3.png");
				this->addChild(bullet, 4);
				BG = background;
				break;
			}
			if (type == 3) {
				bullet = Sprite::create("Star3.png");
				this->addChild(bullet, 4);
				BG = background;
				break;
			}
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
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Bottle.mp3");
	auto fire = MoveTo::create(distance / velocity[1], enemyPos);
	
	auto playAnimations = CallFunc::create([this, enemyPos]() {
		bullet->setVisible(false);
		// ֱ�Ӵ�SpriteFrameCache��ȡSpriteFrame
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
		// ��������������
		auto animationEnd = CallFunc::create([this,explosion1, explosion2]() {
			hitTarget = true;
			explosion1->removeFromParent();
			explosion2->removeFromParent();
			explosion1->release();
			explosion2->release();
			});
		auto delayAction = DelayTime::create(0.2f);
		// ���ж�������

		auto delay_to_remove= DelayTime::create(1.0f);
		auto removeBullet = CallFunc::create([this]() {
			this->removeFromParent(); // �Ƴ��ӵ�
			});
		auto animationSequence = Sequence::create(act1,delayAction,act2, animationEnd,delay_to_remove,removeBullet,nullptr);
		bullet->runAction(animationSequence);
		});


	auto sequence = Sequence::create(fire, playAnimations, nullptr);
	bullet->runAction(sequence);
}

void Bullet::shitAttack(Vec2 enemyPos) {
	this->enemyPos = enemyPos;
	is_active = true;
	double x = enemyPos.x - startPos.x;
	double y = enemyPos.y - startPos.y;
	double distance = sqrt(x * x + y * y);
	auto fire = MoveTo::create(distance / velocity[2], enemyPos);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Shit.mp3");
	auto playAnimations = CallFunc::create([this, enemyPos]() {
		bullet->setVisible(false);
		// ֱ�Ӵ�SpriteFrameCache��ȡSpriteFrame
		auto explosion1 = Sprite::create("shiteffect1.png");
		auto explosion2 = Sprite::create("shiteffect2.png");


		explosion1->retain();
		explosion2->retain();

		auto act1 = CallFunc::create([this, enemyPos, explosion1]() {
			explosion1->setPosition(enemyPos);
			BG->addChild(explosion1, 4);
			});

		auto act2 = CallFunc::create([this, enemyPos, explosion1, explosion2]() {
			explosion1->setVisible(false);
			explosion2->setPosition(enemyPos);
			BG->addChild(explosion2, 5);
			});
		// ��������������
		auto animationEnd = CallFunc::create([explosion1, explosion2]() {
			explosion1->removeFromParent();
			explosion2->removeFromParent();
			explosion1->release();
			explosion2->release();
			});
		auto delayAction = DelayTime::create(0.2f);
		// ���ж�������
		auto removeBullet = CallFunc::create([this]() {
			this->removeFromParent(); // �Ƴ��ӵ�
			});
		auto animationSequence = Sequence::create(act1, delayAction, act2, animationEnd, removeBullet, nullptr);
		bullet->runAction(animationSequence);
		});

	auto track= CallFunc::create([this]() {
		is_active = false; // ȷ�������ڶ������������
		hitTarget = true;
		});

	auto setInactive = CallFunc::create([this]() {
		is_active = false; // ȷ�������ڶ������������
		hitTarget = true;
		});
	
	auto sequence = Sequence::create(fire, playAnimations, setInactive,nullptr);
	bullet->runAction(sequence);

}

void Bullet::starAttack(Vec2 enemyPos) {
	float omega = 240;
	this->enemyPos = enemyPos;
	is_active = true;
	double x = enemyPos.x - startPos.x;
	double y = enemyPos.y - startPos.y;
	double distance = sqrt(x * x + y * y);
	auto fire = MoveTo::create(distance / velocity[3], enemyPos);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Star.mp3");

	//auto rotate = RotateBy::create(0.2, omega * 0.2);



	auto rotateAction = RotateBy::create(distance / velocity[3], omega* (distance / velocity[3]));

	auto spawnAction = Spawn::create(rotateAction,fire, nullptr);

	auto StarEffect = CallFunc::create([=]() {
		// ���ڴ��ÿ�����������
		auto removeBullet = CallFunc::create([this]() {
			this->removeFromParent(); // �Ƴ��ӵ�
			});
		Vector<FiniteTimeAction*> combinedActions;
		std::vector<cocos2d::Vec2> directionVectors;
		// ����8�����������
		for (int i = 0; i < 8; ++i) {
			float angle = M_PI / 4 * i; // ÿ45��һ������
			float x = cosf(angle);
			float y = sinf(angle);
			directionVectors.push_back(cocos2d::Vec2(x, y));
		}
		// �������������Ǿ���Ķ���
		
		for (const auto& direction : directionVectors) {
			// �������Ǿ���
			auto starSprite = cocos2d::Sprite::create("star.png");
			starSprite->setPosition(enemyPos);
			this->addChild(starSprite);
			// �����ƶ�����
			float moveDistance = 200.0f; // �����ƶ��ľ���
			float moveDuration = 1.0f; // �����ƶ��ĳ���ʱ��
			auto moveAction = cocos2d::MoveBy::create(moveDuration, direction * moveDistance);
			// ������������
			auto fadeAction = cocos2d::FadeOut::create(moveDuration);
			// �����������
			auto spawnAction = cocos2d::Spawn::createWithTwoActions(moveAction, fadeAction);
			// ���ж���������ɺ���������
			starSprite->runAction(cocos2d::Sequence::create(spawnAction, cocos2d::RemoveSelf::create(),removeBullet, nullptr));
		}
		});

	auto setInactive = CallFunc::create([this]() {
		bullet->setVisible(false);
		is_active = false; // ȷ�������ڶ������������
		hitTarget = true;
		});

	
	auto delayForStarEffect = DelayTime::create(1.5f);
	auto sequence = Sequence::create(spawnAction,StarEffect ,setInactive,nullptr);
	bullet->runAction(sequence);
}



