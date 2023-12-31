#include "MyScene.h"
#include"Adventure.h"
#include"HelloWorldScene.h"
#include"Map.h"
#include"Tower.h";
#include"Bullet.h"
#include"Monster.h"
#include<utility>
#include<vector>
#include<math.h>
#include <algorithm>
#include"bloodBar.h"
#include"Carrots.h"
#include <cstdlib>
#include "SimpleAudioEngine.h"
using namespace std;
USING_NS_CC;
MyScene* MyScene::createScene()
{
    return MyScene::create();
}

bool MyScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // 从 UserDefault 中获取比例因子
    scaleX = UserDefault::getInstance()->getFloatForKey("scaleX", 1.0f);
    scaleY = UserDefault::getInstance()->getFloatForKey("scaleY", 1.0f);
    // 初始化地图
    initGrid();
    // 初始化 selectSprite，并设置为不可见
    selectSprite = Sprite::create("select_01.png");
    selectSprite->setVisible(false);
    this->addChild(selectSprite, 2);

    /// 播放背景音乐
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("BGMusic01.mp3", true);

    //在地图拐点处放怪物
    nhSprite_2 = Sprite::create("L22.png");
    float dsh = nhSprite_2->getTextureRect().size.height;

    float dsh_s;
    float dsh_s2;
    float dsh_s3;
    float dsh_s4;
    float dsh_s5;
    Barrier.resize(12);
    for (int i = 0; i < 12; i++) {
        if (i >= 0 && i <= 2) {
            Barrier[i].type = Sprite::create("S2.png");
            dsh_s = Barrier[i].type->getTextureRect().size.height;
        }
        else if (i >= 3 && i <= 6) {
            Barrier[i].type = Sprite::create("S1.png");
            dsh_s2 = Barrier[i].type->getTextureRect().size.height;
        }
        else if (i == 7) {
            Barrier[i].type = Sprite::create("S3.png");
            dsh_s3 = Barrier[i].type->getTextureRect().size.height;
        }
        else if (i >= 8 && i <= 9) {
            Barrier[i].type = Sprite::create("B1.png");
            dsh_s4 = Barrier[i].type->getTextureRect().size.height;
        }
        else if (i >= 10) {
            Barrier[i].type = Sprite::create("L3.png");
            dsh_s5 = Barrier[i].type->getTextureRect().size.height;
        }
    }

    Vec2 b1 = Vec2(202 * scaleX, 485 * scaleY + dsh_s / 2.0f);
    Vec2 b2 = Vec2(346 * scaleX, 485 * scaleY + dsh_s / 2.0f);
    Vec2 b3 = Vec2(555 * scaleX, 75 * scaleY + dsh_s / 2.0f);
    Vec2 b4 = Vec2(130 * scaleX, 355 * scaleY + dsh_s2 / 2.0f);
    Vec2 b5 = Vec2(203 * scaleX, 213 * scaleY + dsh_s2 / 2.0f);
    Vec2 b6 = Vec2(760 * scaleX, 213 * scaleY + dsh_s2 / 2.0f);
    Vec2 b7 = Vec2(832 * scaleX, 355 * scaleY + dsh_s2 / 2.0f);
    Vec2 b8 = Vec2(340 * scaleX, 213 * scaleY + dsh_s3 / 2.0f);
    Vec2 b9 = Vec2(365 * scaleX, 290 * scaleY + dsh_s4 / 2.0f);
    Vec2 b10 = Vec2(587 * scaleX, 410 * scaleY + dsh_s4 / 2.0f);
    Vec2 b11 = Vec2(587 * scaleX, 200 * scaleY + dsh_s5 / 2.0f);
    Vec2 b12 = Vec2(365 * scaleX, 70 * scaleY + dsh_s5 / 2.0f);

    BarrierPoint.push_back(b1);
    BarrierPoint.push_back(b2);
    BarrierPoint.push_back(b3);
    BarrierPoint.push_back(b4);
    BarrierPoint.push_back(b5);
    BarrierPoint.push_back(b6);
    BarrierPoint.push_back(b7);
    BarrierPoint.push_back(b8);
    BarrierPoint.push_back(b9);
    BarrierPoint.push_back(b10);
    BarrierPoint.push_back(b11);
    BarrierPoint.push_back(b12);
    ////////////////////////////////////////////////////////


    for (int j = 0; j < 12; j++) {
        Barrier[j].pos = BarrierPoint[j];
        Barrier[j].type->setPosition(Barrier[j].pos);
        this->addChild(Barrier[j].type, 2);
        auto blood = Bloodbar::create();
        blood->initBloodbar(Barrier[j].pos);
        this->addChild(blood, 2);
        bloodbarForBarrier.push_back(blood);
        blood->bloodbar->setVisible(false);
    }


    Vec2 p1(130 * scaleX, 435 * scaleY + dsh / 2.0f);
    Vec2 p2(275 * scaleX, 435 * scaleY + dsh / 2.0f);
    Vec2 p3(275 * scaleX, 147 * scaleY + dsh / 2.0f);
    Vec2 p4(695 * scaleX, 147 * scaleY + dsh / 2.0f);
    Vec2 p5(695 * scaleX, 435 * scaleY + dsh / 2.0f);
    Vec2 p6(832 * scaleX, 435 * scaleY + dsh / 2.0f);
    //拐点
    InflectionPoint.push_back(p1);
    InflectionPoint.push_back(p2);
    InflectionPoint.push_back(p3);
    InflectionPoint.push_back(p4);
    InflectionPoint.push_back(p5);
    InflectionPoint.push_back(p6);

    for (unsigned int i = 0; i <= 4; i++) {
        float d = InflectionPoint[i].distance(InflectionPoint[i + 1]);
        distance.push_back(d);
    }

    if (!isAdded) {
        mouseListener = EventListenerMouse::create();
        mouseListener->onMouseDown = [this](Event* event) {
            EventMouse* e = (EventMouse*)event;
            if (e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT) {
                Vec2 location = e->getLocationInView();
                location.y = 640 - location.y;
                location = Director::getInstance()->convertToGL(location); // 这里处理鼠标点击事件，location 是点击位置
                this->onTouchBeganForBlank(location);

            } };
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
        isAdded = true;
    }

    // 在你的初始化函数中设置初始值
    isPause0Visible = true;

    // 初始化 pause_0
    pause_0 = Sprite::create("pause_0.png");
    pause_0->setPosition(Vec2(800 * scaleX, 605 * scaleY));
    this->addChild(pause_0, 3);

    // 初始化 pause_1
    pause_1 = Sprite::create("pause_1.png");
    pause_1->setPosition(Vec2(800 * scaleX, 605 * scaleY));
    pause_1->setVisible(false);
    this->addChild(pause_1, 3);

    // 在初始化的地方添加触摸事件监听器
    touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForPause, this);
    // 添加触摸事件监听器到事件分发器
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, pause_0);

    //载入目录键
    //目录
    menu = Sprite::create("menu.png");
    menu->setPosition(Vec2(880 * scaleX, 605 * scaleY));
    this->addChild(menu, 3);
    listener_3 = EventListenerTouchOneByOne::create();
    listener_3->setSwallowTouches(true);
    listener_3->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForMenu, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener_3, this);
    //按目录键之后的显示
    adv_menu_bg = Sprite::create("adv_menu_bg.png");
    adv_menu_bg->setPosition(Vec2(480 * scaleX, 340 * scaleY));
    adv_menu_bg->setVisible(false);
    this->addChild(adv_menu_bg, 4);
    //按目录键之后的继续游戏键
    btn_green_b = Sprite::create("btn_green_b.png");
    btn_green_b->setPosition(Vec2(480 * scaleX, 422 * scaleY));
    btn_green_b->setVisible(false);
    this->addChild(btn_green_b, 5);
    adv_menu_continue = Sprite::create("adv_menu_continue.png");
    adv_menu_continue->setPosition(Vec2(480 * scaleX, 422 * scaleY));
    adv_menu_continue->setVisible(false);
    this->addChild(adv_menu_continue, 6);

    listener_btn_green_b = EventListenerTouchOneByOne::create();
    listener_btn_green_b->setSwallowTouches(true);
    listener_btn_green_b->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForBtnGreenB, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener_btn_green_b, btn_green_b);

    //按目录键之后的回主菜单键
    btn_blue_b = Sprite::create("btn_blue_b.png");
    btn_blue_b->setPosition(Vec2(480 * scaleX, 314 * scaleY));
    btn_blue_b->setVisible(false);
    this->addChild(btn_blue_b, 5);
    adv_menu_home = Sprite::create("adv_menu_home.png");
    adv_menu_home->setPosition(Vec2(480 * scaleX, 314 * scaleY));
    adv_menu_home->setVisible(false);
    this->addChild(adv_menu_home, 6);

    listener_home = EventListenerTouchOneByOne::create();
    listener_home->setSwallowTouches(true);
    listener_home->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForBtnBlueB, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener_home, btn_blue_b);


    //载入地图背景
    auto BG = Sprite::create("BG1.png");
    BG->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(BG, 0);

    Path = Sprite::create("Path1.png");
    Path->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(Path, 1);

    //在地图起点处放置标志物
    auto fflag = Sprite::create("start01.png");
    fflag->setPosition(Vec2(135 * scaleX, 525 * scaleY));
    this->addChild(fflag, 2);



    // 转换硬编码坐标为相对坐标
    Vec2 point1 = Vec2(130 * scaleX, 435 * scaleY + dsh / 2.0f);
    Vec2 point2 = Vec2(275 * scaleX, 435 * scaleY + dsh / 2.0f);
    Vec2 point3 = Vec2(275 * scaleX, 147 * scaleY + dsh / 2.0f);
    Vec2 point4 = Vec2(695 * scaleX, 147 * scaleY + dsh / 2.0f);
    Vec2 point5 = Vec2(695 * scaleX, 435 * scaleY + dsh / 2.0f);
    Vec2 point6 = Vec2(832 * scaleX, 435 * scaleY + dsh / 2.0f);
    //背景上面那一长条
    auto top_bg = Sprite::create("top_bg.png");
    top_bg->setPosition(Vec2(480 * scaleX, 610 * scaleY));
    this->addChild(top_bg, 2);

  


    //速度
    speed_0 = Sprite::create("speed_0.png");
    speed_0->setPosition(Vec2(700 * scaleX, 603 * scaleY));
    this->addChild(speed_0, 2);
    speed_1 = Sprite::create("speed_1.png");
    speed_1->setPosition(Vec2(700 * scaleX, 603 * scaleY));
    speed_1->setVisible(false);
    this->addChild(speed_1, 2);
    // 在初始化的地方添加触摸事件监听器
    touchListener_2 = EventListenerTouchOneByOne::create();
    touchListener_2->setSwallowTouches(true);

    touchListener_2->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForSpeed, this);
    // 添加触摸事件监听器到事件分发器
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener_2, speed_0);

    //第几波怪物的显示
    auto waves_bg = Sprite::create("waves_bg.png");
    waves_bg->setPosition(Vec2(480 * scaleX, 603 * scaleY));
    this->addChild(waves_bg, 2);

    auto blank = Sprite::create("select_01.png");
    dsh_blank = blank->getTextureRect().size.height;

    //可放防御塔的点
    Vec2 towerPosition[47] = {
        Vec2(202 * scaleX, 350 * scaleY + dsh_blank / 2.0f),
        Vec2(202 * scaleX, 280 * scaleY + dsh_blank / 2.0f),
        Vec2(135 * scaleX, 280 * scaleY + dsh_blank / 2.0f),
        Vec2(135 * scaleX, 211 * scaleY + dsh_blank / 2.0f),
        Vec2(135 * scaleX, 142 * scaleY + dsh_blank / 2.0f),
        Vec2(202 * scaleX, 142 * scaleY + dsh_blank / 2.0f),
        Vec2(202 * scaleX, 73 * scaleY + dsh_blank / 2.0f),
        Vec2(271 * scaleX, 73 * scaleY + dsh_blank / 2.0f),
        Vec2(409 * scaleX, 208 * scaleY + dsh_blank / 2.0f),
        Vec2(478 * scaleX, 208 * scaleY + dsh_blank / 2.0f),
        Vec2(626 * scaleX, 350 * scaleY + dsh_blank / 2.0f),
        Vec2(626 * scaleX, 280 * scaleY + dsh_blank / 2.0f),
        Vec2(553 * scaleX, 350 * scaleY + dsh_blank / 2.0f),
        Vec2(553 * scaleX, 280 * scaleY + dsh_blank / 2.0f),
        Vec2(478 * scaleX, 350 * scaleY + dsh_blank / 2.0f),
        Vec2(478 * scaleX, 280 * scaleY + dsh_blank / 2.0f),
        Vec2(340 * scaleX, 419 * scaleY + dsh_blank / 2.0f),
        Vec2(409 * scaleX, 419 * scaleY + dsh_blank / 2.0f),
        Vec2(478 * scaleX, 419 * scaleY + dsh_blank / 2.0f),
        Vec2(762 * scaleX, 350 * scaleY + dsh_blank / 2.0f),
        Vec2(762 * scaleX, 280 * scaleY + dsh_blank / 2.0f),
        Vec2(831 * scaleX, 280 * scaleY + dsh_blank / 2.0f),
        Vec2(831 * scaleX, 211 * scaleY + dsh_blank / 2.0f),
        Vec2(762 * scaleX, 142 * scaleY + dsh_blank / 2.0f),
        Vec2(831 * scaleX, 142 * scaleY + dsh_blank / 2.0f),
        Vec2(478 * scaleX, 73 * scaleY + dsh_blank / 2.0f),
        Vec2(626 * scaleX, 73 * scaleY + dsh_blank / 2.0f),
        Vec2(695 * scaleX, 73 * scaleY + dsh_blank / 2.0f),
        Vec2(762 * scaleX, 73 * scaleY + dsh_blank / 2.0f),
        Vec2(135 * scaleX, 488 * scaleY + dsh_blank / 2.0f),
        Vec2(271 * scaleX, 488 * scaleY + dsh_blank / 2.0f),
        Vec2(409 * scaleX, 488 * scaleY + dsh_blank / 2.0f),
        Vec2(478 * scaleX, 488 * scaleY + dsh_blank / 2.0f),
        Vec2(695 * scaleX, 488 * scaleY + dsh_blank / 2.0f),
        Vec2(762 * scaleX, 488 * scaleY + dsh_blank / 2.0f),
        Vec2(66 * scaleX, 488 * scaleY + dsh_blank / 2.0f),
        Vec2(66 * scaleX, 419 * scaleY + dsh_blank / 2.0f),
        Vec2(66 * scaleX, 350 * scaleY + dsh_blank / 2.0f),
        Vec2(66 * scaleX, 280 * scaleY + dsh_blank / 2.0f),
        Vec2(66 * scaleX, 211 * scaleY + dsh_blank / 2.0f),
        Vec2(66 * scaleX, 142 * scaleY + dsh_blank / 2.0f),
        Vec2(900 * scaleX, 488 * scaleY + dsh_blank / 2.0f),
        Vec2(900 * scaleX, 419 * scaleY + dsh_blank / 2.0f),
        Vec2(900 * scaleX, 350 * scaleY + dsh_blank / 2.0f),
        Vec2(900 * scaleX, 280 * scaleY + dsh_blank / 2.0f),
        Vec2(900 * scaleX, 211 * scaleY + dsh_blank / 2.0f),
        Vec2(900 * scaleX, 142 * scaleY + dsh_blank / 2.0f)
    };

    int towerDirection[47] = {
        -1,
        0,
        0,
        0,
        0,
        0,
        -1,
        -1,
        1,
        1,
        0,
        0,
        0,
        0,
        1,
        1,
        -2,
        -2,
        -2,
        -2,
        -2,
        -2,
        -2,
        -2,
        -2,
        -1,
        -1,
        -1,
        -1,
        1,
        1,
        -2,
        -2,
        1,
        1,
        1,
        0,
        -1,
        -1,
        0,
        0,
        1,
        -2,
        -1,
        -1,
        -2,
        -2
    };

    for (int i = 0; i < 47; i++) {
        BLANK* Node = new BLANK;
        Node->blank = Sprite::create("select_01.png");
        Node->blank->setPosition(towerPosition[i]);
        Node->blank->setVisible(false);
        Node->position = towerPosition[i];
        Node->direction = towerDirection[i];
        Node->ptr = Node;
        Node->No = i;
        this->addChild(Node->blank, 2);
        blanks.push_back(*Node);
    }

    // 创建一个Label来显示金钱的值
    auto label = Label::createWithTTF(std::to_string(money), "fonts/Marker Felt.ttf", 34);
    label->setPosition(145, 615);
    label->setTextColor(Color4B::WHITE);
    this->addChild(label, 5);
    // 定期更新Label
    this->schedule([label, this](float dt) {
        label->setString(std::to_string(money));
        }, 0.1f, "update_label");


    //在空白处放障碍物

    //放置萝卜
    // //萝卜的移动
    auto carrotsLayer = Carrots::create();
    carrotsLayer->MoveforCarrots1(0.0);
    this->addChild(carrotsLayer, 1);
    //萝卜血量
    //10
    auto carrotsblo10 = Sprite::create("carrotsblo10.png");
    carrotsblo10->setPosition(832, 525);
    this->addChild(carrotsblo10, 10);
    auto scalemove10 = ScaleBy::create(0.1, 0.3f);
    carrotsblo10->runAction(scalemove10);
    //9
    auto carrotsblo9 = Sprite::create("carrotsblo9.png");
    carrotsblo9->setPosition(832, 525);
    this->addChild(carrotsblo9, 9);
    auto scalemove9 = ScaleBy::create(0.1, 0.3f);
    carrotsblo9->runAction(scalemove9);
    carrotsblo9->setVisible(false);
    //8
    auto carrotsblo8 = Sprite::create("carrotsblo8.png");
    carrotsblo8->setPosition(832, 525);
    this->addChild(carrotsblo8, 8);
    auto scalemove8 = ScaleBy::create(0.1, 0.3f);
    carrotsblo8->runAction(scalemove8);
    carrotsblo8->setVisible(false);
    //7
    auto carrotsblo7 = Sprite::create("carrotsblo7.png");
    carrotsblo7->setPosition(832, 525);
    this->addChild(carrotsblo7, 7);
    auto scalemove7 = ScaleBy::create(0.1, 0.3f);
    carrotsblo7->runAction(scalemove7);
    carrotsblo7->setVisible(false);
    //6
    auto carrotsblo6 = Sprite::create("carrotsblo6.png");
    carrotsblo6->setPosition(832, 525);
    this->addChild(carrotsblo6, 6);
    auto scalemove6 = ScaleBy::create(0.1, 0.3f);
    carrotsblo6->runAction(scalemove6);
    carrotsblo6->setVisible(false);
    //5
    auto carrotsblo5 = Sprite::create("carrotsblo5.png");
    carrotsblo5->setPosition(832, 525);
    this->addChild(carrotsblo5, 5);
    auto scalemove5 = ScaleBy::create(0.1, 0.3f);
    carrotsblo5->runAction(scalemove5);
    carrotsblo5->setVisible(false);
    //4
    auto carrotsblo4 = Sprite::create("carrotsblo4.png");
    carrotsblo4->setPosition(832, 525);
    this->addChild(carrotsblo4, 4);
    auto scalemove4 = ScaleBy::create(0.1, 0.3f);
    carrotsblo4->runAction(scalemove4);
    carrotsblo4->setVisible(false);
    //3
    auto carrotsblo3 = Sprite::create("carrotsblo3.png");
    carrotsblo3->setPosition(832, 525);
    this->addChild(carrotsblo3, 3);
    auto scalemove3 = ScaleBy::create(0.1, 0.3f);
    carrotsblo3->runAction(scalemove3);
    carrotsblo3->setVisible(false);
    //2
    auto carrotsblo2 = Sprite::create("carrotsblo2.png");
    carrotsblo2->setPosition(832, 525);
    this->addChild(carrotsblo2, 2);
    auto scalemove2 = ScaleBy::create(0.1, 0.3f);
    carrotsblo2->runAction(scalemove2);
    carrotsblo2->setVisible(false);
    //1
    auto carrotsblo1 = Sprite::create("carrotsblo1.png");
    carrotsblo1->setPosition(832, 525);
    this->addChild(carrotsblo1, 1);
    auto scalemove1 = ScaleBy::create(0.1, 0.3f);
    carrotsblo1->runAction(scalemove1);
    carrotsblo1->setVisible(false);


    //一个怪物

  /*  nhSprite_2->setPosition(Vec2(0, 0));

    // 创建一个移动动作
    moveAction = MoveTo::create(5.0f, Vec2(500, 500));

    // 运行动作
    nhSprite_2->runAction(moveAction);

    // 添加精灵到场景
    this->addChild(nhSprite_2, 2);*/


    // 怪物总波数
    auto wavecount = Label::createWithTTF("10", "fonts/Marker Felt.ttf", 34);
    wavecount->setPosition(480, 605);
    wavecount->setTextColor(Color4B::WHITE);
    this->addChild(wavecount, 5);
    // 怪物实时波数
    auto currentwavecount = Label::createWithTTF(std::to_string(currentwave), "fonts/Marker Felt.ttf", 34);
    currentwavecount->setPosition(415, 605);
    currentwavecount->setTextColor(Color4B::WHITE);
    this->addChild(currentwavecount, 5);
    // 定期更新波数
    this->schedule([=](float dt) {
        currentwavecount->setString(std::to_string(currentwave));
        }, 0.1f, "updatecurrentwave");



    //进行游戏开场的倒计时
    countdownValue = 3;
    auto countdownlabel = Label::createWithTTF(std::to_string(countdownValue), "fonts/Marker Felt.ttf", 92);
    countdownlabel->setPosition(480, 320);
    countdownlabel->setTextColor(Color4B(255, 0, 0, 155)); // 红色
    this->addChild(countdownlabel, 5);
    this->schedule([=](float dt)
        {
            if (isClear()) {
                if (currentwave == 11) {
                    currentwave = 10;
                    auto labelend = Label::createWithTTF("VICTORY", "fonts/Marker Felt.ttf", 120);
                    labelend->setPosition(480, 320);
                    labelend->setTextColor(Color4B::RED);
                    this->addChild(labelend, 5);
                    Director::getInstance()->pause();
                }
                isTimeActive = true;
                //spriteOnStage.clear();
                //bloodbarForSprite.clear();
            }
    countdownValue--;
    if (countdownValue == 0)
    {
        countdownlabel->setVisible(false);
        this->schedule([this](float dt) {
            if (!isTimeActive)
            return;
        static int count = 0;
        int T = rand() % 6 + 1;
        auto a = Monster::CreateMonster();
        auto aa = Bloodbar::CreateBloodbar();
        a->initMonster(InflectionPoint, distance, this, T);
        aa->initBloodbar(InflectionPoint, distance, this, T, a->blood[a->type]);
        spriteOnStage.push_back(a);
        bloodbarForSprite.push_back(aa);
        this->addChild(a, 3);
        this->addChild(aa, 3);
        count++;
        if (count % 10 == 0) {
            isTimeActive = false;
            currentwave++;
        }
            }, 1.0f, "generateSprite");
    }
    countdownlabel->setString(std::to_string(countdownValue));

        }, 1.0f, "update_countdownlabel");



    this->schedule([=](float dt)
        {
            int monstersReachedEnd = 0;
    for (int i = 0; i < spriteOnStage.size(); i++) {
        monstersReachedEnd += spriteOnStage[i]->isEnd;
    }

    if (monstersReachedEnd > 0 && monstersReachedEnd < 4)
    {
        CCLOG("Number of monsters that reached the end: %d", monstersReachedEnd);
        // 调用 CarrotsLayer 中的方法来停止动画
        carrotsLayer->stopAnimation1();
        //开始第二段动画
        carrotsLayer->MoveforCarrots2(0.0);
    }
    if (monstersReachedEnd >= 4)
    {
        CCLOG("Number of monsters that reached the end: %d", monstersReachedEnd);
        // 调用 CarrotsLayer 中的方法来停止动画
        carrotsLayer->stopAnimation1();
        //开始第二段动画
        carrotsLayer->MoveforCarrots3(0.0);
    }
    if (monstersReachedEnd == 1)
    {
        carrotsblo10->setVisible(false);
        carrotsblo9->setVisible(true);
    }
    if (monstersReachedEnd == 2)
    {
        carrotsblo9->setVisible(false);
        carrotsblo8->setVisible(true);
    }
    if (monstersReachedEnd == 3)
    {
        carrotsblo8->setVisible(false);
        carrotsblo7->setVisible(true);
    }
    if (monstersReachedEnd == 4)
    {
        carrotsblo7->setVisible(false);
        carrotsblo6->setVisible(true);
    }
    if (monstersReachedEnd == 5)
    {
        carrotsblo6->setVisible(false);
        carrotsblo5->setVisible(true);
    }
    if (monstersReachedEnd == 6)
    {
        carrotsblo5->setVisible(false);
        carrotsblo4->setVisible(true);
    }
    if (monstersReachedEnd == 7)
    {
        carrotsblo4->setVisible(false);
        carrotsblo3->setVisible(true);
    }
    if (monstersReachedEnd == 8)
    {
        carrotsblo3->setVisible(false);
        carrotsblo2->setVisible(true);
    }
    if (monstersReachedEnd == 9)
    {
        carrotsblo2->setVisible(false);
        carrotsblo1->setVisible(true);
    }
    if (monstersReachedEnd == 10)
    {
        carrotsblo1->setVisible(false);
        auto labelend = Label::createWithTTF("GAME OVER", "fonts/Marker Felt.ttf", 120);
        labelend->setPosition(480, 320);
        labelend->setTextColor(Color4B::BLACK);
        this->addChild(labelend, 5);
        Director::getInstance()->pause();
    }
        }, 0.1f, "monsterCheckScheduler");

    Brain();

    return true;


}

void MyScene::Brain() {

    this->schedule(CC_SCHEDULE_SELECTOR(MyScene::updateSprite), 0.1f); // 1.0f代表每秒更新一次

}

void MyScene::updateSprite(float dt) {
    for (unsigned int i = 0; i < spriteOnStage.size(); i++) {
        //只检查活着的精灵
        if (!spriteOnStage[i]->isChecked) {

            //精灵已经阵亡
            if ((spriteOnStage[i]->isDead && !spriteOnStage[i]->isChecked) || spriteOnStage[i]->isEnd) {
                //精灵死后爆金币
                if (spriteOnStage[i]->isDead) {
                    money += 50;
                }
                //让防御塔停止攻击这只精灵
                for (unsigned int k = 0; k < spriteOnStage[i]->isAttackingMe.size(); k++) {
                    blanks[spriteOnStage[i]->isAttackingMe[k]].tower->setIncoming(Vec2(INT_MAX, INT_MAX));

                    //把定时器取消
                    std::string schedulerName = "update_position_scheduler_" + std::to_string(i) + std::to_string(spriteOnStage[i]->isAttackingMe[k]);
                    this->unschedule(schedulerName);
                    CCLOG("delete string is: %s", schedulerName.c_str());
                    blanks[spriteOnStage[i]->isAttackingMe[k]].isAttacking = false;
                }

                //设置精灵状态，以后不在遍历这只精灵
                spriteOnStage[i]->isChecked = true;
            }

            else {
                for (unsigned int j = 0; j < blanks.size(); j++) {
                    if (blanks[j].isOccupied) {//搜索放置防御塔的地方
                        Vec2 current = spriteOnStage[i]->monster->getPosition();
                        float x = current.x - blanks[j].position.x;
                        float y = current.y - blanks[j].position.y;
                        float distance = sqrt(x * x + y * y);

                        //精灵处于防御塔的攻击范围且防御塔不在攻击,并且精灵i与防御塔j之间的的关系还没有建立
                        std::string schedulerName = "update_position_scheduler_" + std::to_string(i) + std::to_string(j);
                        bool isScheduled = Director::getInstance()->getScheduler()->isScheduled(schedulerName, this);

                        if (distance <= blanks[j].tower->attackRange && (!blanks[j].isAttacking) && (!isScheduled)) {
                            //CCLOG("%d", spriteOnStage[i]->type);
                            std::string schedulerName = "update_position_scheduler_" + std::to_string(i) + std::to_string(j);
                            this->schedule([i, j, this](float dt) {
                                Vec2 currentPosition = spriteOnStage[i]->monster->getPosition();
                            blanks[j].tower->setIncoming(currentPosition);
                                }, 0.3f, schedulerName);
                            CCLOG("The string is: %s", schedulerName.c_str());
                            blanks[j].isAttacking = true;
                            blanks[j].tower->spriteNum = i;//把正在攻击的精灵序号存起来,表示blanks[j]的防御塔正在攻击精灵i
                            blanks[j].tower->enemyType = spriteOnStage[i]->type;
                            spriteOnStage[i]->isAttackingMe.push_back(blanks[j].No);//把这个防御塔加入vector
                        }

                        //发现精灵超出了防御塔范围
                        else if (distance >= blanks[j].tower->attackRange && isScheduled) {
                            //查看精灵i与防御塔j之间是否存在定时器
                            if (isScheduled) {//如果有
                                blanks[j].tower->setIncoming(Vec2(INT_MAX, INT_MAX));
                                this->unschedule(schedulerName);
                                blanks[j].isAttacking = false;
                                auto it = std::find(spriteOnStage[i]->isAttackingMe.begin(), spriteOnStage[i]->isAttackingMe.end(), blanks[j].tower->No);
                                if (it != spriteOnStage[i]->isAttackingMe.end()) {
                                    spriteOnStage[i]->isAttackingMe.erase(it);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < Barrier.size(); i++) {
        if (Barrier[i].barrierBlood <= 0) {
            Barrier[i].type->setVisible(false);
        }
    }

}




void MyScene::onTouchBeganForBlank(Vec2 location) {
    static bool selected = false;//记录方框之前是否有被选中过

    static bool selectedChoice = false;//记录升级和删除两个按钮是否有被选中过

    static bool selectedPause = true;
    static BLANK newPos;//记录上一次点击
    Vec2 touchLocation = location;

    /*Rect pauseRect = pause_0->getBoundingBox();
    if (pauseRect.containsPoint(touchLocation)) {
        if (selectedPause) {
            pause_0->setTexture("pause_1.png");
            Director::getInstance()->pause();
        }
        else {
            Director::getInstance()->resume();
            pause_0->setTexture("pause_0.png");
            selectedPause = false;
        }
    }*/



    Rect pathRect = Path->getBoundingBox();
    if (pathRect.containsPoint(touchLocation) && !selected && !selectedChoice) {
        for (int k = 0; k < spriteOnStage.size(); k++) {
            if (spriteOnStage[k]->monster->getPosition().distance(location) < 30 && !spriteOnStage[k]->isDead) {
                for (int i = 0; i < blanks.size(); i++) {
                    if (blanks[i].isOccupied && blanks[i].position.distance(location) <= blanks[i].tower->attackRange) {
                        std::string scheduler1 = "update_position_scheduler_" + std::to_string(blanks[i].tower->spriteNum) + std::to_string(blanks[i].tower->No);
                        bool isScheduled = Director::getInstance()->getScheduler()->isScheduled(scheduler1, this);
                        if (isScheduled)
                            this->unschedule(scheduler1);
                        std::string scheduler2 = "barrier" + std::to_string(blanks[i].tower->No) + std::to_string(blanks[i].tower->barrierNum);
                        isScheduled = Director::getInstance()->getScheduler()->isScheduled(scheduler2, this);
                        if (isScheduled) {
                            this->unschedule(scheduler2);
                            blanks[i].tower->isAttackingBarrier = false;
                        }
                        blanks[i].tower->setIncoming(Vec2(INT_MAX, INT_MAX));
                        std::string schedulerName = "update_position_scheduler_" + std::to_string(k) + std::to_string(i);
                        this->schedule([i, k, this](float dt) {
                            Vec2 currentPosition = spriteOnStage[k]->monster->getPosition();
                        blanks[i].tower->setIncoming(currentPosition);
                            }, 0.3f, schedulerName);
                        blanks[i].isAttacking = true;
                        blanks[i].tower->spriteNum = k;//把正在攻击的精灵序号存起来,表示blanks[j]的防御塔正在攻击精灵i
                        blanks[i].tower->enemyType = spriteOnStage[k]->type;
                        spriteOnStage[k]->isAttackingMe.push_back(blanks[i].No);//把这个防御塔加入vector
                    }
                }
                return;
            }
        }
    }

    if (selected) {
        Rect bottleRect = bottleSprite->getBoundingBox();
        Rect shitRect = shitSprite->getBoundingBox();
        Rect starRect = starSprite->getBoundingBox();
        if (bottleRect.containsPoint(touchLocation) && money >= 100) {//点击瓶子位置，放置防御塔
            money -= 100;
            blanks[selectedBlankIndex].isOccupied = true;
            bottleSprite->setVisible(false);
            shitSprite->setVisible(false);
            starSprite->setVisible(false);
            selectSprite->setVisible(false);
            Tower* newTower = new Tower;
            newTower = Tower::createTower();
            newTower->placeTower(newPos.position, newPos.direction, this, 1, selectedBlankIndex);
            newTower->enemyBloodbar = &bloodbarForSprite;
            newTower->barrierBloodbar = &bloodbarForBarrier;
            newTower->enemies = &spriteOnStage;
            newTower->enemyBarrier = &Barrier;
            blanks[selectedBlankIndex].tower = newTower;
            selected = false;
            this->addChild(newTower, 3);
            return;
        }
        else if (shitRect.containsPoint(touchLocation) && money >= 120) {
            money -= 120;
            blanks[selectedBlankIndex].isOccupied = true;
            bottleSprite->setVisible(false);
            shitSprite->setVisible(false);
            starSprite->setVisible(false);
            selectSprite->setVisible(false);
            Tower* newTower = new Tower;
            newTower = Tower::createTower();
            newTower->placeTower(newPos.position, newPos.direction, this, 2, selectedBlankIndex);
            newTower->enemyBloodbar = &bloodbarForSprite;
            newTower->barrierBloodbar = &bloodbarForBarrier;
            newTower->enemies = &spriteOnStage;
            newTower->enemyBarrier = &Barrier;
            blanks[selectedBlankIndex].tower = newTower;
            selected = false;
            this->addChild(newTower, 3);
            return;
        }
        else if (starRect.containsPoint(touchLocation) && money >= 160) {
            money -= 160;
            blanks[selectedBlankIndex].isOccupied = true;
            bottleSprite->setVisible(false);
            shitSprite->setVisible(false);
            starSprite->setVisible(false);
            selectSprite->setVisible(false);
            Tower* newTower = new Tower;
            newTower = Tower::createTower();
            newTower->placeTower(newPos.position, newPos.direction, this, 3, selectedBlankIndex);
            newTower->enemyBloodbar = &bloodbarForSprite;
            newTower->barrierBloodbar = &bloodbarForBarrier;
            newTower->enemies = &spriteOnStage;
            newTower->enemyBarrier = &Barrier;
            blanks[selectedBlankIndex].tower = newTower;
            selected = false;
            this->addChild(newTower, 3);
            return;
        }
        else {//点击其它位置，选中区域取消
            bottleSprite->setVisible(false);
            shitSprite->setVisible(false);
            starSprite->setVisible(false);
            selectSprite->setVisible(false);
            selected = false;
            return;
        }

    }

    if (selectedChoice) {
        Rect upgradeRect = upgradeSprite->getBoundingBox();
        Rect removeRect = removeSprite->getBoundingBox();
        if (upgradeRect.containsPoint(touchLocation)) {//升级防御塔
            if ((money >= 180 && blanks[selectedBlankIndex].tower->level == 1) || (money >= 380 && blanks[selectedBlankIndex].tower->level == 2)) {
                if (blanks[selectedBlankIndex].tower->level != 3) {
                    upgradeSprite->setVisible(false);
                    removeSprite->setVisible(false);
                    blanks[selectedBlankIndex].tower->Upgrade = true;
                    selectedChoice = false;
                }
            }
            return;
        }
        else if (removeRect.containsPoint(touchLocation)) {//移除防御塔
            if (blanks[selectedBlankIndex].tower->level == 1) money += 80;
            else if (blanks[selectedBlankIndex].tower->level == 2)money += 160;
            else if (blanks[selectedBlankIndex].tower->level == 3) money += 320;

            auto Stop = CallFunc::create([this]() {
                if (blanks[selectedBlankIndex].isAttacking) {//如果这个防御塔正在攻击精灵
                    //把定时器删掉
                    //如果
                    std::string schedulerName = "update_position_scheduler_" + std::to_string(blanks[selectedBlankIndex].tower->spriteNum) + std::to_string(blanks[selectedBlankIndex].tower->No);
                    this->unschedule(schedulerName);

                    for (int n = 0; n < Barrier.size(); n++) {
                        std::string barrierScheduler = "barrier" + std::to_string(blanks[selectedBlankIndex].No) + std::to_string(n);
                        bool isScheduled = Director::getInstance()->getScheduler()->isScheduled(barrierScheduler, this);
                        if (isScheduled)
                            this->unschedule(barrierScheduler);
                    }
                }
            blanks[selectedBlankIndex].tower->stopAllActions();
            blanks[selectedBlankIndex].tower->setVisible(false);
                });
            auto delay_to_remove = DelayTime::create(1.0f);
            auto removeTower = CallFunc::create([this]() {
                blanks[selectedBlankIndex].tower->removeFromParent();
                });
            auto sequence = Sequence::create(Stop, removeTower, nullptr);
            this->runAction(sequence);

            upgradeSprite->setVisible(false);
            removeSprite->setVisible(false);
            selectedChoice = false;
            blanks[selectedBlankIndex].isOccupied = false;
            return;
        }
        else {
            upgradeSprite->setVisible(false);
            removeSprite->setVisible(false);
            selectedChoice = false;
            return;
        }
    }

    // 检查是否点击在 blank 区域上,或防止防御塔的blank区域
    for (int i = 0; i < blanks.size(); ++i)
    {
        Rect blankRect = blanks[i].blank->getBoundingBox();

        if (blankRect.containsPoint(touchLocation) && !blanks[i].isOccupied)
        {
            newPos = blanks[i];


            // 点击在了某个 blank 区域上，记录选中的 blank 索引
            selectedBlankIndex = i;

            // 如果菜单图标可见，不执行后续逻辑，并阻止事件传递
            //if (btn_green_b->isVisible()) {
               // return ;
            //}

            // 显示 select_01.png
            showSelectSprite();

            // 在这里可以添加其他点击 blank 区域的逻辑

            // 获取点击的 blank 中心坐标
            Vec2 blankCenter(blankRect.getMidX(), blankRect.getMidY());

            // 显示 Bottle01.png 在 (x, y + 70) 位置
            bottleSprite = showBottleSprite(Vec2(blankCenter.x, blankCenter.y + 70));
            shitSprite = showShitSprite(Vec2(blankCenter.x + 70, blankCenter.y + 70));
            starSprite = showStarSprite(Vec2(blankCenter.x - 70, blankCenter.y + 70));
            selected = true;
            return;
        }
        else if (blanks[i].isOccupied) {
            Rect pedestalRect = blanks[i].tower->pedestal->getBoundingBox();
            if (pedestalRect.containsPoint(touchLocation)) {
                selectedChoice = true;
                selectedBlankIndex = i;
                Vec2 pedestalCenter(pedestalRect.getMidX(), pedestalRect.getMidY());
                showUpgradeSprite(Vec2(pedestalCenter.x, pedestalCenter.y + 70), blanks[i].tower);
                showRemoveSprite(Vec2(pedestalCenter.x, pedestalCenter.y - 70), blanks[i].tower);
                return;
            }
        }
    }

    for (int k = 0; k < Barrier.size(); k++) {
        Rect barrierRect = Barrier[k].type->getBoundingBox();

        if (barrierRect.containsPoint(touchLocation) && Barrier[k].barrierBlood > 0) {
            for (int t = 0; t < blanks.size(); t++) {
                if (blanks[t].isOccupied && Barrier[k].pos.distance(blanks[t].tower->pos) <= blanks[t].tower->attackRange) {
                    if (blanks[t].isAttacking) {
                        std::string schedulerName = "update_position_scheduler_" + std::to_string(blanks[t].tower->spriteNum) + std::to_string(blanks[t].No);
                        bool isScheduled = Director::getInstance()->getScheduler()->isScheduled(schedulerName, this);
                        if (isScheduled)
                            this->unschedule(schedulerName);
                        for (int n = 0; n < Barrier.size(); n++) {
                            std::string barrierScheduler = "barrier" + std::to_string(t) + std::to_string(n);
                            bool isScheduled = Director::getInstance()->getScheduler()->isScheduled(barrierScheduler, this);
                            if (isScheduled)
                                this->unschedule(barrierScheduler);
                            blanks[t].tower->isAttackingBarrier = false;
                        }
                    }
                    this->schedule([this, t, k](float dt) {
                        Vec2 currentPosition = Barrier[k].pos;
                    blanks[t].tower->setIncoming(currentPosition);
                    if (Barrier[k].barrierBlood <= 0) {
                        money += 200;
                        Barrier[k].type->setVisible(false);
                        this->unschedule("barrier" + std::to_string(t) + std::to_string(k));
                        blanks[t].tower->setIncoming(Vec2(INT_MAX, INT_MAX));
                        blanks[t].isAttacking = false;
                        blanks[t].tower->isAttackingBarrier = false;
                        auto dead = CallFunc::create([this, k]() {
                            auto Cloud = Sprite::create("effect2.png");
                        this->addChild(Cloud, 1);
                        Cloud->setPosition(Barrier[k].pos);
                        auto scalemove = ScaleBy::create(0.1, 2.0f);
                        auto fadeout = FadeOut::create(1.0f);
                        auto seq1 = Sequence::create(scalemove, fadeout, nullptr);
                        Cloud->runAction(seq1);
                            });
                        this->runAction(dead);
                        BLANK* Node = new BLANK;
                        Node->blank = Sprite::create("select_01.png");
                        Node->blank->setPosition(Barrier[k].pos);
                        Node->blank->setVisible(false);
                        Node->position = Barrier[k].pos;
                        Node->direction = 0;
                        Node->ptr = Node;
                        Node->No = blanks.size();
                        this->addChild(Node->blank, 2);
                        blanks.push_back(*Node);
                    }
                        }, 0.3f, "barrier" + std::to_string(t) + std::to_string(k));
                    blanks[t].isAttacking = true;
                    blanks[t].tower->isAttackingBarrier = true;
                    blanks[t].tower->barrierNum = k;
                    bloodbarForBarrier[k]->bloodbar->setVisible(true);
                }
            }
        }
    }





    // 如果点击位置不在任何 blank 区域上，隐藏 Bottle01.png 和 select_01.png
    if (bottleSprite) bottleSprite->setVisible(false);
    if (selectSprite) selectSprite->setVisible(false);
    // 重置选中的 blank 索引
    selectedBlankIndex = -1;

    return;
}




bool MyScene::onTouchBeganForBottle(cocos2d::Touch* touch, cocos2d::Event* event) {
    return false;
}
void MyScene::hideBottleAndSelectSprites()
{
    // 隐藏 Bottle01.png
    if (bottleSprite != nullptr && bottleSprite->isVisible())
    {
        bottleSprite->setVisible(false);
    }

    // 隐藏 select_01.png
    if (selectSprite != nullptr && selectSprite->isVisible())
    {
        selectSprite->setVisible(false);
    }
}

Sprite* MyScene::showBottleSprite(const Vec2& position)
{
    // 移除之前的 Bottle01.png
    if (bottleSprite != nullptr && bottleSprite->getParent() != nullptr)
    {
        bottleSprite->removeFromParent();
    }

    // 创建并显示新的 Bottle01.png 精灵
    if (money < 100)
        bottleSprite = Sprite::create("Bottle00.png");
    else
        bottleSprite = Sprite::create("Bottle01.png");
    bottleSprite->setPosition(position);
    this->addChild(bottleSprite, 4);
    return bottleSprite;
}

Sprite* MyScene::showShitSprite(const Vec2& position)
{
    // 移除之前的 Bottle01.png
    if (shitSprite != nullptr && shitSprite->getParent() != nullptr)
    {
        shitSprite->removeFromParent();
    }

    // 创建并显示新的 Bottle01.png 精灵
    if (money < 120)
        shitSprite = Sprite::create("Shit0.png");
    else
        shitSprite = Sprite::create("Shit.png");
    shitSprite->setPosition(position);
    this->addChild(shitSprite, 4);
    return shitSprite;
}

Sprite* MyScene::showStarSprite(const Vec2& position) {
    if (starSprite != nullptr && starSprite->getParent() != nullptr)
    {
        starSprite->removeFromParent();
    }

    // 创建并显示新的 Bottle01.png 精灵
    if (money < 160)
        starSprite = Sprite::create("Star01.png");
    else
        starSprite = Sprite::create("Star00.png");
    starSprite->setPosition(position);
    this->addChild(starSprite, 4);
    return starSprite;
}






Sprite* MyScene::showUpgradeSprite(Vec2 position, Tower* tower) {
    if (upgradeSprite != nullptr && upgradeSprite->getParent() != nullptr)
    {
        upgradeSprite->removeFromParent();
    }

    if (tower->level == 1) {
        if (money < 180)
            upgradeSprite = Sprite::create("0upgrade1.png");
        else
            upgradeSprite = Sprite::create("1upgrade1.png");
        upgradeSprite->setPosition(position);
        this->addChild(upgradeSprite, 4);
        return upgradeSprite;
    }
    else if (tower->level == 2) {
        if (money < 380)
            upgradeSprite = Sprite::create("0upgrade2.png");
        else
            upgradeSprite = Sprite::create("1upgrade2.png");
        upgradeSprite->setPosition(position);
        this->addChild(upgradeSprite, 4);
        return upgradeSprite;
    }
    else if (tower->level == 3) {
        upgradeSprite = Sprite::create("upgrade3.png");
        upgradeSprite->setPosition(position);
        this->addChild(upgradeSprite, 4);
        return upgradeSprite;
    }


}

Sprite* MyScene::showRemoveSprite(Vec2 position, Tower* tower) {
    if (removeSprite != nullptr && removeSprite->getParent() != nullptr)
    {
        removeSprite->removeFromParent();
    }

    if (tower->level == 1) {
        removeSprite = Sprite::create("1remove1.png");
        removeSprite->setPosition(position);
        this->addChild(removeSprite, 3);
        return removeSprite;
    }
    else if (tower->level == 2) {
        removeSprite = Sprite::create("1remove2.png");
        removeSprite->setPosition(position);
        this->addChild(removeSprite, 3);
        return removeSprite;
    }
    else if (tower->level == 3) {
        removeSprite = Sprite::create("1remove3.png");
        removeSprite->setPosition(position);
        this->addChild(removeSprite, 3);
        return removeSprite;
    }
}
bool MyScene::onTouchBeganForSpeed(cocos2d::Touch* touch, cocos2d::Event* event) {
    // 获取触摸点位置
    Vec2 locationInNode = speed_0->convertToNodeSpace(touch->getLocation());
    Rect rectSpeed0 = Rect(0, 0, speed_0->getContentSize().width, speed_0->getContentSize().height);
    Rect rectSpeed1 = Rect(0, 0, speed_1->getContentSize().width, speed_1->getContentSize().height);

    // 检查触摸点是否在 speed_0 上
    if (rectSpeed0.containsPoint(locationInNode) && !speed_1->isVisible()) {
        // 点击了 speed_0，将 speed_0 设置为不可见，speed_1 设置为可见
        speed_0->setVisible(false);
        speed_1->setVisible(true);

        // 将游戏速度设置为二倍
        Director::getInstance()->getScheduler()->setTimeScale(2.0f);

        return true;
    }

    // 判断是否点击了 speed_1 区域
    if (rectSpeed1.containsPoint(locationInNode) && speed_1->isVisible()) {
        // 点击了 speed_1，将 speed_1 设置为不可见，speed_0 设置为可见
        speed_1->setVisible(false);
        speed_0->setVisible(true);

        // 将游戏速度恢复为正常
        Director::getInstance()->getScheduler()->setTimeScale(1.0f);

        return true;
    }

    return false;
}


bool MyScene::onTouchBeganForPause(cocos2d::Touch* touch, cocos2d::Event* event) {
    // 获取触摸点位置
    Vec2 locationInNode = pause_0->convertToNodeSpace(touch->getLocation());
    Rect rectPause0 = Rect(0, 0, pause_0->getContentSize().width, pause_0->getContentSize().height);
    Rect rectPause1 = Rect(0, 0, pause_1->getContentSize().width, pause_1->getContentSize().height);

    // 检查触摸点是否在 pause_0 上
    if (rectPause0.containsPoint(locationInNode) && !pause_1->isVisible()) {
        // 点击了 pause_0，将 pause_0 设置为不可见，pause_1 设置为可见
        pause_0->setVisible(false);
        pause_1->setVisible(true);

        // 暂停游戏
        Director::getInstance()->pause();

        return true;
    }

    // 判断是否点击了 pause_1.png 区域
    if (rectPause1.containsPoint(locationInNode) && pause_1->isVisible()) {
        // 点击了 pause_1，将 pause_1 设置为不可见，pause_0 设置为可见
        pause_1->setVisible(false);
        pause_0->setVisible(true);

        // 恢复游戏
        Director::getInstance()->resume();

        return true;
    }

    return false;
}


bool MyScene::onTouchBeganForBtnGreenB(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = btn_green_b->convertToNodeSpace(touch->getLocation());
    // 您的逻辑处理代码
    Rect continue_position = Rect(0, 0, btn_green_b->getContentSize().width, btn_green_b->getContentSize().height);
    if (continue_position.containsPoint(locationInNode) && btn_green_b->isVisible()) {
        Director::getInstance()->resume();
        adv_menu_bg->setVisible(false);
        btn_green_b->setVisible(false);
        adv_menu_continue->setVisible(false);
        btn_blue_b->setVisible(false);
        adv_menu_home->setVisible(false);
        return true;
    }
    return false;
}
bool MyScene::onTouchBeganForBtnBlueB(Touch* touch, Event* event) {
    Vec2 locationInNode = btn_blue_b->convertToNodeSpace(touch->getLocation());
    Rect continue_position = Rect(0, 0, btn_blue_b->getContentSize().width, btn_blue_b->getContentSize().height);

    if (continue_position.containsPoint(locationInNode) && btn_blue_b->isVisible()) {
      
        Director::getInstance()->getEventDispatcher()->removeEventListener(touchListener);
        Director::getInstance()->getEventDispatcher()->removeEventListener(listener_btn_green_b);
        Director::getInstance()->getEventDispatcher()->removeEventListener(listener_3);
        Director::getInstance()->getEventDispatcher()->removeEventListener(listener_home);
        Director::getInstance()->getEventDispatcher()->removeEventListener(touchListener_2);
        if (isAdded) {
            this->getEventDispatcher()->removeEventListener(mouseListener);
            isAdded = false;
        }
        Director::getInstance()->getScheduler()->setTimeScale(1.0f);
        Director::getInstance()->resume();
        unscheduleAllSelectors();
        stopAllActions();
        removeFromParentAndCleanup(true);
        auto newScene = Adventure::createScene();
        Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5, newScene));
        return true; // 消费触摸事件
    }

    return false; // 不消费触摸事件
}



bool MyScene::onTouchBeganForMenu(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = menu->convertToNodeSpace(touch->getLocation());
    Rect menu_position = Rect(0, 0, menu->getContentSize().width, menu->getContentSize().height);


    if (menu_position.containsPoint(locationInNode)) {

        // 点击了 目录
        adv_menu_bg->setVisible(true);
        btn_green_b->setVisible(true);
        adv_menu_continue->setVisible(true);
        btn_blue_b->setVisible(true);
        adv_menu_home->setVisible(true);
        Director::getInstance()->pause();
        return true;
    }



    return false;
}



void MyScene::showSelectSprite()
{
    if (selectedBlankIndex != -1)
    {
        Vec2 initialPosition = blanks[selectedBlankIndex].blank->getPosition();
        selectSprite->setPosition(initialPosition);
        selectSprite->setVisible(true);
    }
}
void MyScene::initGrid() {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
}

bool MyScene::isClear() {
    for (unsigned int i = 0; i < spriteOnStage.size(); i++) {
        if (spriteOnStage[i]->isDead || spriteOnStage[i]->isEnd)
            ;
        else
            return false;
    }
    return true;
}
void MyScene::onExit() {
    // 停止当前场景的逻辑更新，清理资源等
    unscheduleUpdate();
    // 其他清理操作...

    // 调用父类的 onExit 方法
    Scene::onExit();
}
