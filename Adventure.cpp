#include"Adventure.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include"Myscene.h"
#include"Myscene_2.h"
#include<vector>
using namespace cocos2d;

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

Scene* Adventure::createScene() {
	Scene* scene = Scene::create();
	Scene* layer = Adventure::create();
	scene->addChild(layer, 0);
	return scene;
}

bool Adventure::init() {
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();



	auto gobackNormal = Sprite::create("Btn_Return.PNG");
	auto gobackDisable = Sprite::create("Btn_ReturnLight.PNG");

	auto level_bg = Sprite::create("LevelBg.png");
	level_bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(level_bg, 0);

	//设置返回按钮，返回HelloWorld界面
	MenuItemSprite* goback = MenuItemSprite::create(gobackNormal, gobackDisable, CC_CALLBACK_1(Adventure::callBack, this));
	Menu* gobackButton = Menu::create(goback, NULL);
	this->addChild(gobackButton, 1);
	gobackButton->setPosition(visibleSize.width / 10, visibleSize.height / 8 * 7);

	auto map1 = Sprite::create("Path_1.png");

	Size originalSize = map1->getContentSize();

	// 设置缩放比例，这里是将图片等比例缩小到原始尺寸的一半
	float scale = 0.65f;
	map1->setScale(scale);

	// 获取缩小后的尺寸
	Size newSize = Size(originalSize.width * scale, originalSize.height * scale);

	auto map2 = Sprite::create("Path_2.png");
	//auto map3 = Sprite::create("map3.jpg");

	Size originalSize_2 = map2->getContentSize();


	map2->setScale(scale);

	this->mapArray.push_back(map1);
	this->mapArray.push_back(map2);
	//this->mapArray.push_back(map3);

	//map1->setAnchorPoint(Vec2(1, 0.5));
	//map1->setAnchorPoint(Vec2(1, 0.5));
	map1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	map2->setPosition(Vec2(visibleSize.width / 4 * 5, visibleSize.height / 2));
	//map3->setPosition(Vec2(visibleSize.width / 4 * 5, visibleSize.height / 2));

	this->addChild(map1, 2);
	auto listener = EventListenerTouchOneByOne::create();

	// 触摸开始时的回调
	listener->onTouchBegan = [map1](Touch* touch, Event* event) {
		// 获取触摸点的位置
		Vec2 touchLocation = touch->getLocation();
		Vec2 nodeLocation = map1->getParent()->convertToNodeSpace(touchLocation);

		// 检查触摸点是否在map1的范围内
		Rect rect = map1->getBoundingBox();
		if (rect.containsPoint(nodeLocation)) {
			// 在这里切换到MyScene场景
			auto scene = MyScene::createScene(); // 假设你有一个创建MyScene的静态方法
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
			return true; // 触摸事件被处理
		}

		return false; // 触摸事件未被处理
	};

	// 将事件监听器添加到事件分发器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, map1);

	this->addChild(map2, 2);
	auto listener_2 = EventListenerTouchOneByOne::create();

	// 触摸开始时的回调
	listener_2->onTouchBegan = [map2](Touch* touch, Event* event) {
		// 获取触摸点的位置
		Vec2 touchLocation_2 = touch->getLocation();
		Vec2 nodeLocation_2 = map2->getParent()->convertToNodeSpace(touchLocation_2);

		// 检查触摸点是否在map1的范围内
		Rect rect = map2->getBoundingBox();
		if (rect.containsPoint(nodeLocation_2)) {
			// 在这里切换到MyScene场景
			auto scene_2 = MyScene_2::createScene(); // 假设你有一个创建MyScene的静态方法
			Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene_2));
			return true; // 触摸事件被处理
		}

		return false; // 触摸事件未被处理
	};

	// 将事件监听器添加到事件分发器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_2, map2);

	//this->addChild(map3, 2);

	auto cloud_left = Sprite::create("Cloud_Left.png");
	cloud_left->setPosition(Vec2(150, 450));
	this->addChild(cloud_left, 1);

	auto cloud_right = Sprite::create("Cloud_Right.png");
	cloud_right->setPosition(Vec2(850, 130));
	this->addChild(cloud_right, 1);

	mapArray.resize(2);


	auto rightArrow = Sprite::create("LeftNormal.png");
	auto rightArrowDisable = Sprite::create("LeftSelect.png");
	MenuItemSprite* rArrow = MenuItemSprite::create(rightArrow, rightArrowDisable, CC_CALLBACK_1(Adventure::rightTranslation, this));
	Menu* rightArrowButton = Menu::create(rArrow, NULL);
	this->addChild(rightArrowButton, 3);
	rightArrowButton->setPosition(Vec2(visibleSize.width / 18 * 17, visibleSize.height / 2));

	auto leftArrow = Sprite::create("RightNormal.png");
	auto leftArrowDisable = Sprite::create("RightSelect.png");
	MenuItemSprite* lArrow = MenuItemSprite::create(leftArrow, leftArrowDisable, CC_CALLBACK_1(Adventure::leftTranslation, this));
	Menu* leftArrowButton = Menu::create(lArrow, NULL);
	this->addChild(leftArrowButton, 3);
	leftArrowButton->setPosition(Vec2(visibleSize.width / 18, visibleSize.height / 2));


	/*MenuItemSprite* Map1 = MenuItemSprite::create(map1, map1, CC_CALLBACK_1(Adventure::callMap1, this));
	Menu* Map1Button = Menu::create(Map1, NULL);
	this->addChild(Map1Button, 3);
	Map1Button->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 2));*/

	return true;
}

void Adventure::callBack(Ref* pSender) {
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, scene, Color3B::BLACK));
}

void Adventure::rightTranslation(Ref* pSender) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (mapArray[mapArray.size() - 1]->getPosition().x != visibleSize.width / 2 && mapArray[mapArray.size() - 2]->getPosition().x != -visibleSize.width / 2) {
		mapArray[0]->runAction(MoveTo::create(0.5, Vec2(mapArray[0]->getPosition().x - visibleSize.width,
			visibleSize.height / 2)));
		mapArray[1]->runAction(MoveTo::create(0.5, Vec2(visibleSize.width / 1.9,
			visibleSize.height / 2)));
	}
}

void Adventure::leftTranslation(Ref* pSender) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (mapArray[0]->getPosition().x != visibleSize.width / 2) {
		mapArray[0]->runAction(MoveTo::create(0.5, Vec2(mapArray[0]->getPosition().x + visibleSize.width,
			visibleSize.height / 2)));
		mapArray[1]->runAction(MoveTo::create(0.5, Vec2(mapArray[1]->getPosition().x + visibleSize.width,
			visibleSize.height / 2)));
	}
}

/*void Adventure::callMap1(Ref* pSender) {
	Scene* map1 = MyScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0f, map1, Color3B::BLACK));
}*/