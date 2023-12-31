#include "MyScene_2.h"
#include "MyScene.h"
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
USING_NS_CC;
MyScene_2* MyScene_2::createScene()
{
    auto scene = MyScene_2::create();
    return scene;
}
bool MyScene_2::init()
{
    if (!Scene::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 从 UserDefault 中获取比例因子
    float scaleX = UserDefault::getInstance()->getFloatForKey("scaleX", 1.0f);
    float scaleY = UserDefault::getInstance()->getFloatForKey("scaleY", 1.0f);

    // 初始化 selectSprite，并设置为不可见
    selectSprite = Sprite::create("select_01.png");
    selectSprite->setVisible(false);
    this->addChild(selectSprite, 2);
    if (!isAdded) {
        auto mouseListener = EventListenerMouse::create();
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

    //载入地图背景
    auto BG = Sprite::create("BG1.png");
    BG->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(BG, 0);

    Path = Sprite::create("Path2.png");
    Path->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(Path, 1);

  

    //在地图起点处放置标志物
    auto fflag = Sprite::create("start01.png");
    fflag->setPosition(Vec2(480 * scaleX, 170 * scaleY));
    this->addChild(fflag, 3);

    //在地图拐点放怪物
    auto nhSprite_2 = Sprite::create("L33.png");
    float dsh = nhSprite_2->getTextureRect().size.height;
   

    Vec2 b1 = Vec2(165 * scaleX, 490 * scaleY);
    Vec2 b2 = Vec2(375 * scaleX, 490 * scaleY);
    Vec2 b3 = Vec2(660 * scaleX, 490 * scaleY);
    Vec2 b4 = Vec2(515 * scaleX, 385 * scaleY);
    Vec2 b5 = Vec2(240 * scaleX, 275 * scaleY);
    Vec2 b6 = Vec2(510 * scaleX, 210 * scaleY);
    Vec2 b7 = Vec2(340 * scaleX, 240 * scaleY);
    Vec2 b8 = Vec2(340 * scaleX, 180 * scaleY);
    Vec2 b9 = Vec2(410 * scaleX, 180 * scaleY);
    Vec2 b10 = Vec2(550 * scaleX, 110 * scaleY);
    Vec2 b11 = Vec2(690 * scaleX, 110 * scaleY);
    Vec2 b12 = Vec2(55 * scaleX, 390 * scaleY);
    Vec2 b13 = Vec2(55 * scaleX, 240 * scaleY);
    Vec2 b14 = Vec2(690 * scaleX, 320 * scaleY);
    Vec2 b15 = Vec2(830 * scaleX, 320 * scaleY);
    Vec2 b16 = Vec2(830 * scaleX, 245 * scaleY);
    Vec2 b17 = Vec2(830 * scaleX, 175 * scaleY);
    Vec2 b18 = Vec2(890 * scaleX, 385 * scaleY);

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
    BarrierPoint.push_back(b13);
    BarrierPoint.push_back(b14);
    BarrierPoint.push_back(b15);
    BarrierPoint.push_back(b16);
    BarrierPoint.push_back(b17);
    BarrierPoint.push_back(b18);

    Barrier.resize(18);
    for (int i = 0; i < 18; i++) {
        if (i >= 0 && i <= 2) {
            Barrier[i].type = Sprite::create("B2.png");
            //dsh_s = Barrier[i].type->getTextureRect().size.height;
        }
        else if (i ==3) {
            Barrier[i].type = Sprite::create("L2.png");
            //dsh_s2 = Barrier[i].type->getTextureRect().size.height;
        }
        else if (i >=4&&i<=5) {
            Barrier[i].type = Sprite::create("B1.png");
            //dsh_s3 = Barrier[i].type->getTextureRect().size.height;
        }
        else if (i >= 6 && i <= 10) {
            Barrier[i].type = Sprite::create("S2.png");
            //dsh_s4 = Barrier[i].type->getTextureRect().size.height;
        }
        else if (i >= 11&&i<=13) {
            Barrier[i].type = Sprite::create("S3.png");
            //dsh_s5 = Barrier[i].type->getTextureRect().size.height;
        }
        else if (i >= 14)
        {
            Barrier[i].type = Sprite::create("S1.png");
        }
    }

    for (int j = 0; j < 18; j++) {
        Barrier[j].pos = BarrierPoint[j];
        Barrier[j].type->setPosition(Barrier[j].pos);
        this->addChild(Barrier[j].type, 2);
        auto blood = Bloodbar::create();
        blood->initBloodbar(Barrier[j].pos);
        this->addChild(blood, 2);
        bloodbarForBarrier.push_back(blood);
        blood->bloodbar->setVisible(false);
    }

    //拐点
    Vec2 p11 = Vec2(760 * scaleX, 430 * scaleY + dsh / 2.0f);
    Vec2 p10 = Vec2(760 * scaleX, 150 * scaleY + dsh / 2.0f);
    Vec2 p9 = Vec2(620 * scaleX, 150 * scaleY + dsh / 2.0f);
    Vec2 p8 = Vec2(620 * scaleX, 300 * scaleY + dsh / 2.0f);
    Vec2 p7 = Vec2(345 * scaleX, 300 * scaleY + dsh / 2.0f);
    Vec2 p6 = Vec2(345 * scaleX, 365 * scaleY + dsh / 2.0f);
    Vec2 p5 = Vec2(135 * scaleX, 365 * scaleY + dsh / 2.0f);
    Vec2 p4 = Vec2(135 * scaleX, 155 * scaleY + dsh / 2.0f);
    Vec2 p3 = Vec2(200 * scaleX, 155 * scaleY + dsh / 2.0f);
    Vec2 p2 = Vec2(200 * scaleX, 80 * scaleY + dsh / 2.0f);
    Vec2 p1 = Vec2(485 * scaleX, 80 * scaleY + dsh / 2.0f);

    //初始化拐点
    InflectionPoint.push_back(p1);
    InflectionPoint.push_back(p2);
    InflectionPoint.push_back(p3);
    InflectionPoint.push_back(p4);
    InflectionPoint.push_back(p5);
    InflectionPoint.push_back(p6);
    InflectionPoint.push_back(p7);
    InflectionPoint.push_back(p8);
    InflectionPoint.push_back(p9);
    InflectionPoint.push_back(p10);
    InflectionPoint.push_back(p11);
    for (unsigned int i = 0; i <= 9; i++) {
        float d = InflectionPoint[i].distance(InflectionPoint[i + 1]);
        distance.push_back(d);
    }


    //可放防御塔的点
    Vec2 towerPosition[36] = {
     Vec2(60 * scaleX, 460 * scaleY),
     Vec2(60 * scaleX, 315 * scaleY),
     Vec2(60 * scaleX, 170 * scaleY),
     Vec2(60 * scaleX, 100 * scaleY),
     Vec2(135 * scaleX, 100 * scaleY),
     Vec2(270 * scaleX, 170 * scaleY),
     Vec2(410 * scaleX, 240 * scaleY),
     Vec2(620 * scaleX, 105 * scaleY),
     Vec2(760 * scaleX, 105 * scaleY),
     Vec2(693 * scaleX, 245 * scaleY),
     Vec2(410 * scaleX, 380 * scaleY),
     Vec2(693 * scaleX, 385 * scaleY),//12
     Vec2(623 * scaleX, 385 * scaleY),
     Vec2(830 * scaleX, 385 * scaleY),
     Vec2(895 * scaleX, 315 * scaleY),
     Vec2(895 * scaleX, 245 * scaleY),
     Vec2(895 * scaleX, 175 * scaleY),
     Vec2(273 * scaleX, 458 * scaleY),
     Vec2(483 * scaleX, 460 * scaleY),
     Vec2(553 * scaleX, 460 * scaleY),
     Vec2(830 * scaleX, 460 * scaleY),
     Vec2(900 * scaleX, 460 * scaleY),//22
     Vec2(900 * scaleX, 530 * scaleY),
     Vec2(830 * scaleX, 530 * scaleY),
     Vec2(760 * scaleX, 530 * scaleY),
     Vec2(550 * scaleX, 530 * scaleY),
     Vec2(480 * scaleX, 530 * scaleY),
     Vec2(270 * scaleX, 530 * scaleY),
     Vec2(60 * scaleX, 530 * scaleY),
     Vec2(480 * scaleX, 35 * scaleY),
     Vec2(410 * scaleX, 35 * scaleY),
     Vec2(340 * scaleX, 35 * scaleY),
     Vec2(270 * scaleX, 35 * scaleY),//33
     Vec2(200 * scaleX, 35 * scaleY),
     Vec2(550 * scaleX, 35 * scaleY),
     Vec2(620 * scaleX, 35 * scaleY) };

    int towerDirection[36] = {
        0,
        0,
        0,
        0,
        -1,
        -2,
        -1,
        -1,
        -1,
        1,
        1,
        0,
        1,
        -2,
        -2,
        -2,
        -2,
        1,
        1,
        1,
        -2,
        -2,
        -2,
        -2,
        1,
        1,
        1,
        1,
        0,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1
    };

    //背景上面那一长条
    auto top_bg = Sprite::create("top_bg.png");
    top_bg->setPosition(Vec2(480 * scaleX, 610 * scaleY));
    this->addChild(top_bg, 2);

    //暂停键
    pause_0 = Sprite::create("pause_0.png");
    pause_0->setPosition(Vec2(800 * scaleX, 605 * scaleY));
    this->addChild(pause_0, 2);


    //速度
    auto speed_0 = Sprite::create("speed_0.png");
    speed_0->setPosition(Vec2(700 * scaleX, 603 * scaleY));
    this->addChild(speed_0, 2);
    //第几波怪物的显示
    auto waves_bg = Sprite::create("waves_bg.png");
    waves_bg->setPosition(Vec2(480 * scaleX, 603 * scaleY));
    this->addChild(waves_bg, 2);

    auto blank = Sprite::create("select_01.png");
    dsh_blank = blank->getTextureRect().size.height;


    for (int i = 0; i < 36; i++) {
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
    carrotsLayer->MoveforCarrots1(0.0,Vec2(760,480));
    this->addChild(carrotsLayer, 1);
    //萝卜血量
    //10
    auto carrotsblo10 = Sprite::create("carrotsblo10.png");
    carrotsblo10->setPosition(760,550);
    this->addChild(carrotsblo10, 10);
    auto scalemove10 = ScaleBy::create(0.1, 0.3f);
    carrotsblo10->runAction(scalemove10);
    //9
    auto carrotsblo9 = Sprite::create("carrotsblo9.png");
    carrotsblo9->setPosition(760, 550);
    this->addChild(carrotsblo9, 9);
    auto scalemove9 = ScaleBy::create(0.1, 0.3f);
    carrotsblo9->runAction(scalemove9);
    carrotsblo9->setVisible(false);
    //8
    auto carrotsblo8 = Sprite::create("carrotsblo8.png");
    carrotsblo8->setPosition(760, 550);
    this->addChild(carrotsblo8, 8);
    auto scalemove8 = ScaleBy::create(0.1, 0.3f);
    carrotsblo8->runAction(scalemove8);
    carrotsblo8->setVisible(false);
    //7
    auto carrotsblo7 = Sprite::create("carrotsblo7.png");
    carrotsblo7->setPosition(760, 550);
    this->addChild(carrotsblo7, 7);
    auto scalemove7 = ScaleBy::create(0.1, 0.3f);
    carrotsblo7->runAction(scalemove7);
    carrotsblo7->setVisible(false);
    //6
    auto carrotsblo6 = Sprite::create("carrotsblo6.png");
    carrotsblo6->setPosition(760, 550);
    this->addChild(carrotsblo6, 6);
    auto scalemove6 = ScaleBy::create(0.1, 0.3f);
    carrotsblo6->runAction(scalemove6);
    carrotsblo6->setVisible(false);
    //5
    auto carrotsblo5 = Sprite::create("carrotsblo5.png");
    carrotsblo5->setPosition(760, 550);
    this->addChild(carrotsblo5, 5);
    auto scalemove5 = ScaleBy::create(0.1, 0.3f);
    carrotsblo5->runAction(scalemove5);
    carrotsblo5->setVisible(false);
    //4
    auto carrotsblo4 = Sprite::create("carrotsblo4.png");
    carrotsblo4->setPosition(760, 550);
    this->addChild(carrotsblo4, 4);
    auto scalemove4 = ScaleBy::create(0.1, 0.3f);
    carrotsblo4->runAction(scalemove4);
    carrotsblo4->setVisible(false);
    //3
    auto carrotsblo3 = Sprite::create("carrotsblo3.png");
    carrotsblo3->setPosition(760, 550);
    this->addChild(carrotsblo3, 3);
    auto scalemove3 = ScaleBy::create(0.1, 0.3f);
    carrotsblo3->runAction(scalemove3);
    carrotsblo3->setVisible(false);
    //2
    auto carrotsblo2 = Sprite::create("carrotsblo2.png");
    carrotsblo2->setPosition(760, 550);
    this->addChild(carrotsblo2, 2);
    auto scalemove2 = ScaleBy::create(0.1, 0.3f);
    carrotsblo2->runAction(scalemove2);
    carrotsblo2->setVisible(false);
    //1
    auto carrotsblo1 = Sprite::create("carrotsblo1.png");
    carrotsblo1->setPosition(760, 550);
    this->addChild(carrotsblo1, 1);
    auto scalemove1 = ScaleBy::create(0.1, 0.3f);
    carrotsblo1->runAction(scalemove1);
    carrotsblo1->setVisible(false);


    //一个怪物

    nhSprite_2->setPosition(Vec2(0, 0));

    // 创建一个移动动作
    moveAction = MoveTo::create(5.0f, Vec2(500, 500));

    // 运行动作
    nhSprite_2->runAction(moveAction);

    // 添加精灵到场景
    this->addChild(nhSprite_2, 2);


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
                carrotsLayer->MoveforCarrots2(0.0, Vec2(760, 480));
            }
            if (monstersReachedEnd >= 4)
            {
                CCLOG("Number of monsters that reached the end: %d", monstersReachedEnd);
                // 调用 CarrotsLayer 中的方法来停止动画
                carrotsLayer->stopAnimation1();
                //开始第二段动画
                carrotsLayer->MoveforCarrots3(0.0, Vec2(760, 480));
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
    // 初始化 pause_0
    pause_02 = Sprite::create("pause_0.png");
    pause_02->setPosition(Vec2(800 * scaleX, 605 * scaleY));
    this->addChild(pause_02, 3);
    return true;
}
bool MyScene_2::onTouchBeganForPause_2(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = pause_02->convertToNodeSpace(touch->getLocation());
    Rect rectPause0 = Rect(0, 0, pause_02->getContentSize().width, pause_02->getContentSize().height);

    if (rectPause0.containsPoint(locationInNode)) {
        // 获取 MyScene 的实例
        auto mySceneInstance = dynamic_cast<MyScene*>(Director::getInstance()->getRunningScene()->getChildByName("MySceneName")); // 请替换为您的 MyScene 名称

        if (mySceneInstance) {
            // 恢复 nhSprite_2 的位置
            mySceneInstance->nhSprite_2->setPosition(mySceneInstance->nhSprite_2_position);
        }

        // 回到 MyScene
        Director::getInstance()->popScene();
        return true;
    }
    return false;
}

