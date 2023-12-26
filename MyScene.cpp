#include "MyScene.h"
#include"Tower.h";
#include"Bullet.h"
#include<utility>
#include<vector>
#include<math.h>
#include"monster.h"
#include"Carrots.h"
using namespace std;
USING_NS_CC;
Scene* MyScene::createScene()
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
    // �� UserDefault �л�ȡ��������
    scaleX = UserDefault::getInstance()->getFloatForKey("scaleX", 1.0f);
    scaleY = UserDefault::getInstance()->getFloatForKey("scaleY", 1.0f);
    // ��ʼ����ͼ
    initGrid();
    // ��ʼ�� selectSprite��������Ϊ���ɼ�
    selectSprite = Sprite::create("select_01.png");
    selectSprite->setVisible(false);
    this->addChild(selectSprite, 2);

    /* auto listener = EventListenerTouchOneByOne::create();
     listener->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForBlank, this);
     this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);*/
    
    if (!isAdded) {
        auto mouseListener = EventListenerMouse::create();
        mouseListener->onMouseDown = [this](Event* event) {
            EventMouse* e = (EventMouse*)event;
            if (e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT) {
                Vec2 location = e->getLocationInView();
                location.y = 640 - location.y;
                location = Director::getInstance()->convertToGL(location); // ���ﴦ��������¼���location �ǵ��λ��
                this->onTouchBeganForBlank(location);

            } };
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
        isAdded = true;
    }
    // ����ĳ�ʼ�����������ó�ʼֵ
    isPause0Visible = true;

    // ��ʼ�� pause_0
    pause_0 = Sprite::create("pause_0.png");
    pause_0->setPosition(Vec2(800 * scaleX, 605 * scaleY));
    this->addChild(pause_0, 3);

    // ��ʼ�� pause_1
    pause_1 = Sprite::create("pause_1.png");
    pause_1->setPosition(Vec2(800 * scaleX, 605 * scaleY));
    pause_1->setVisible(false);
    this->addChild(pause_1, 3);

    /* auto listener_2 = EventListenerTouchOneByOne::create();
     listener_2->setSwallowTouches(true);
     listener_2->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForPause, this);
     _eventDispatcher->addEventListenerWithSceneGraphPriority(listener_2, this);

     // ��ʼ����ͣ����
     pause_info = Sprite::create("pause_info.png");
     pause_info->setPosition(Vec2(480 * scaleX, 602 * scaleY));
     pause_info->setVisible(false);
     this->addChild(pause_info, 3);

     //Ŀ¼
     menu = Sprite::create("menu.png");
     menu->setPosition(Vec2(880 * scaleX, 605 * scaleY));
     this->addChild(menu, 3);
     auto listener_3 = EventListenerTouchOneByOne::create();
     listener_3->setSwallowTouches(true);
     listener_3->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForMenu, this);
     _eventDispatcher->addEventListenerWithSceneGraphPriority(listener_3, this);
     //��Ŀ¼��֮�����ʾ
      adv_menu_bg = Sprite::create("adv_menu_bg.png");
     adv_menu_bg->setPosition(Vec2(480 * scaleX, 340 * scaleY));
     adv_menu_bg->setVisible(false);
     this->addChild(adv_menu_bg, 3);
     //��Ŀ¼��֮��ļ�����Ϸ��
      btn_green_b = Sprite::create("btn_green_b.png");
     btn_green_b->setPosition(Vec2(480 * scaleX, 422 * scaleY));
     btn_green_b->setVisible(false);
     this->addChild(btn_green_b, 4);
      adv_menu_continue = Sprite::create("adv_menu_continue.png");
     adv_menu_continue->setPosition(Vec2(480 * scaleX, 422 * scaleY));
     adv_menu_continue->setVisible(false);
     this->addChild(adv_menu_continue, 5);

     auto listener_btn_green_b = EventListenerTouchOneByOne::create();
     listener_btn_green_b->setSwallowTouches(true);
     listener_btn_green_b->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForBtnGreenB, this);
     _eventDispatcher->addEventListenerWithSceneGraphPriority(listener_btn_green_b, btn_green_b);


     //��Ŀ¼��֮������¿�ʼ��
      btn_blue_b = Sprite::create("btn_blue_b.png");
     btn_blue_b->setPosition(Vec2(480 * scaleX, 314 * scaleY));
     btn_blue_b->setVisible(false);
     this->addChild(btn_blue_b, 4);
      adv_menu_restart = Sprite::create("adv_menu_restart.png");
     adv_menu_restart->setPosition(Vec2(480 * scaleX, 314 * scaleY));
     adv_menu_restart->setVisible(false);
     this->addChild(adv_menu_restart, 5);

     auto listener_restart = EventListenerTouchOneByOne::create();
     listener_restart->setSwallowTouches(true);
     listener_restart->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForBtnBlueB, this);
     _eventDispatcher->addEventListenerWithSceneGraphPriority(listener_restart, btn_blue_b);

     //��Ŀ¼��֮��Ļ����˵���
      btn_blue_l = Sprite::create("btn_blue_l.png");
     btn_blue_l->setPosition(Vec2(397 * scaleX, 204 * scaleY));
     btn_blue_l->setVisible(false);
     this->addChild(btn_blue_l, 4);
      adv_menu_home = Sprite::create("adv_menu_home.png");
     adv_menu_home->setPosition(Vec2(397 * scaleX, 204 * scaleY));
     adv_menu_home->setVisible(false);
     this->addChild(adv_menu_home, 5);

     auto listener_home = EventListenerTouchOneByOne::create();
     listener_home->setSwallowTouches(true);
     listener_home->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForBtnBlueL, this);
     _eventDispatcher->addEventListenerWithSceneGraphPriority(listener_home, btn_blue_l);

     //��Ŀ¼��֮���ת����
      btn_blue_l_2 = Sprite::create("btn_blue_l.png");
     btn_blue_l_2->setPosition(Vec2(565 * scaleX, 204 * scaleY));
     btn_blue_l_2->setVisible(false);
     this->addChild(btn_blue_l_2, 4);
      adv_menu_weibo = Sprite::create("adv_menu_weibo.png");
     adv_menu_weibo->setPosition(Vec2(565 * scaleX, 204 * scaleY));
     adv_menu_weibo->setVisible(false);
     this->addChild(adv_menu_weibo, 5);

     auto listener_weibo = EventListenerTouchOneByOne::create();
     listener_weibo->setSwallowTouches(true);
     listener_weibo->onTouchBegan = CC_CALLBACK_2(MyScene::onTouchBeganForBtnBlueL_2, this);
     _eventDispatcher->addEventListenerWithSceneGraphPriority(listener_weibo, btn_blue_l_2);*/

     //�����ͼ����
    auto BG = Sprite::create("BG1.png");
    BG->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(BG, 0);

    auto Path1 = Sprite::create("Path1.png");
    Path1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(Path1, 1);
    

    //�ڵ�ͼ��㴦���ñ�־��
    auto fflag = Sprite::create("start01.png");
    fflag->setPosition(Vec2(135 * scaleX, 525 * scaleY));
    this->addChild(fflag, 2);

    //�ڵ�ͼ�յ㴦�Ź���
    nhSprite_2 = Sprite::create("L22.png");
    float dsh = nhSprite_2->getTextureRect().size.height;

    // ת��Ӳ��������Ϊ�������
    Vec2 point1 = Vec2(130 * scaleX, 435 * scaleY + dsh / 2.0f);
    Vec2 point2 = Vec2(275 * scaleX, 435 * scaleY + dsh / 2.0f);
    Vec2 point3 = Vec2(275 * scaleX, 147 * scaleY + dsh / 2.0f);
    Vec2 point4 = Vec2(695 * scaleX, 147 * scaleY + dsh / 2.0f);
    Vec2 point5 = Vec2(695 * scaleX, 435 * scaleY + dsh / 2.0f);
    Vec2 point6 = Vec2(832 * scaleX, 435 * scaleY + dsh / 2.0f);
    //����������һ����
    auto top_bg = Sprite::create("top_bg.png");
    top_bg->setPosition(Vec2(480 * scaleX, 610 * scaleY));
    this->addChild(top_bg, 2);

    //��ͣ��
  /*  auto pause_0 = Sprite::create("pause_0.png");
    pause_0->setPosition(Vec2(800 * scaleX, 605 * scaleY));
    this->addChild(pause_0, 2);*/


    //�ٶ�
    auto speed_0 = Sprite::create("speed_0.png");
    speed_0->setPosition(Vec2(700 * scaleX, 603 * scaleY));
    this->addChild(speed_0, 2);
    //�ڼ����������ʾ
    auto waves_bg = Sprite::create("waves_bg.png");
    waves_bg->setPosition(Vec2(480 * scaleX, 603 * scaleY));
    this->addChild(waves_bg, 2);

    auto blank = Sprite::create("select_01.png");
    dsh_blank = blank->getTextureRect().size.height;
    //��ʼ���յ�
    std::pair<float, float>p1(130 * scaleX, 435 * scaleY + dsh / 2.0f);
    std::pair<float, float>p2(275 * scaleX, 435 * scaleY + dsh / 2.0f);
    std::pair<float, float>p3(275 * scaleX, 155 * scaleY + dsh / 2.0f);
    std::pair<float, float>p4(695 * scaleX, 155 * scaleY + dsh / 2.0f);
    std::pair<float, float>p5(695 * scaleX, 435 * scaleY + dsh / 2.0f);
    std::pair<float, float>p6(832 * scaleX, 435 * scaleY + dsh / 2.0f);
    //�յ�
    InflectionPoint.push_back(p1);
    InflectionPoint.push_back(p2);
    InflectionPoint.push_back(p3);
    InflectionPoint.push_back(p4);
    InflectionPoint.push_back(p5);
    InflectionPoint.push_back(p6);
    //�����ܲ�
    // //�ܲ����ƶ�
    auto carrotsLayer = Carrots::create();
    carrotsLayer->MoveforCarrots(0.0);
    this->addChild(carrotsLayer, 1);
    //�ܲ�Ѫ��
    //10
    auto carrotsblo10 = Sprite::create("carrotsblo10.png");
    carrotsblo10->setPosition(832,525);
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
    
    //��ʼ������
    auto monster1_1 = Monster::create();
    this->addChild(monster1_1, 5);
    auto monster2_1 = Monster::create();
    this->addChild(monster2_1, 5);
    auto monster3_1 = Monster::create();
    this->addChild(monster3_1, 5);
    auto monster4_1 = Monster::create();
    this->addChild(monster4_1, 5);
    auto monster5_1 = Monster::create();
    this->addChild(monster5_1, 5);
    auto monster6_1 = Monster::create();
    this->addChild(monster6_1, 5);
    monster1_1->initMonster(this, 1);
    // ����һ����ʱ����
    auto delay1 = DelayTime::create(1.0f);
    auto delay2 = DelayTime::create(1.0f);
    auto delay3 = DelayTime::create(1.0f);
    auto delay4 = DelayTime::create(1.0f);
    auto delay5 = DelayTime::create(1.0f);
    // ����һ���ص�����
    auto callback1 = CallFunc::create([=]() {
        monster2_1->initMonster(this, 2);
        });
    auto callback2 = CallFunc::create([=]() {
        monster3_1->initMonster(this, 3);
        });
    auto callback3 = CallFunc::create([=]() {
        monster4_1->initMonster(this, 4);
        });
    auto callback4 = CallFunc::create([=]() {
        monster5_1->initMonster(this, 5);
        });
    auto callback5 = CallFunc::create([=]() {
        monster6_1->initMonster(this, 6);
        });
    // ����һ�����ж���
    auto sequence = Sequence::create(delay1, callback1, delay2, callback2, delay3, callback3, delay4, callback4, delay5, callback5, nullptr);
    // �������ж���
    this->runAction(sequence);
    //�ɷŷ������ĵ�
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
        Node->ptr =Node;
        this->addChild(Node->blank, 2);
        blanks.push_back(*Node);
    }

    //�ڿհ״����ϰ���
    float dsh_s;
    float dsh_s2;
    float dsh_s3;
    float dsh_s4;
    float dsh_s5;

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
    }


    
    //һ������

    nhSprite_2->setPosition(Vec2(0, 0));

    // ����һ���ƶ�����
    moveAction = MoveTo::create(5.0f, Vec2(500, 500));

    // ���ж���
    nhSprite_2->runAction(moveAction);

    // ���Ӿ��鵽����
    this->addChild(nhSprite_2, 2);


    return true;

    /*1��130, 435
      2��275,435
      3��275,147
      4��695,147
      5��695,435
      6��832, 435
      */
}

void MyScene::Brain() {
    auto startUpdate = CallFunc::create([this]() {
        // ʹ��schedule������ÿ�����update����
        this->schedule(CC_SCHEDULE_SELECTOR(MyScene::update), 0.1f); // 1.0f����ÿ�����һ��
        });

}

void MyScene::updateSprite(float dt) {
    for (unsigned int i = 0; i < spriteOnStage.size(); i++) {
        if (spriteOnStage[i]) {

        }
        else
			for (unsigned int j = 0; j < blanks.size(); j++) {
				if (blanks[j].isOccupied) {//�������÷������ĵط�
					Vec2 current = spriteOnStage[i]->getPosition();
					float x = current.x - blanks[j].position.x;
					float y = current.y - blanks[j].position.y;
					float distance = sqrt(x * x + y * y);
					if (distance <= blanks[j].tower->attackRange && !blanks[j].isAttacking) {//���鴦�ڷ������Ĺ�����Χ��
						//���������ڹ���
						std::string schedulerName = "update_position_scheduler_" + std::to_string(i);
						this->schedule([i, j, this](float dt) {
							Vec2 currentPosition = spriteOnStage[i]->getPosition();
							blanks[j].tower->setIncoming(currentPosition);
							}, 0.3f, schedulerName);
						blanks[j].isAttacking = true;
					}
				}
			}
    }
}




void MyScene::onTouchBeganForBlank(Vec2 location) {
    static bool selected = false;//��¼����֮ǰ�Ƿ��б�ѡ�й�

    static bool selectedChoice = false;//��¼������ɾ��������ť�Ƿ��б�ѡ�й�

    static BLANK newPos;//��¼��һ�ε��
    Vec2 touchLocation = location;

    if (selected) {
        Rect bottleRect = bottleSprite->getBoundingBox();
        if (bottleRect.containsPoint(touchLocation)) {//���ƿ��λ�ã����÷�����
            blanks[selectedBlankIndex].isOccupied = true;
            bottleSprite->setVisible(false);
            selectSprite->setVisible(false);
            Tower* newTower = Tower:: createTower();
            newTower->placeTower(newPos.position,newPos.direction,this);
            blanks[selectedBlankIndex].tower = newTower;
            selected = false;
            this->addChild(newTower, 3);
            return;
        }
        else {//�������λ�ã�ѡ������ȡ��
            bottleSprite->setVisible(false);
            selectSprite->setVisible(false);
            selected = false;
            return;
        }

    }

    if (selectedChoice) {
        Rect upgradeRect = upgradeSprite->getBoundingBox();
        Rect removeRect=removeSprite->getBoundingBox();
        if (upgradeRect.containsPoint(touchLocation)) {//����������
            if (blanks[selectedBlankIndex].tower->level != 3) {
                upgradeSprite->setVisible(false);
                removeSprite->setVisible(false);
                blanks[selectedBlankIndex].tower->Upgrade = true;
                selectedChoice = false;
            }
            return;
        }
        else if (removeRect.containsPoint(touchLocation)) {//�Ƴ�������
            blanks[selectedBlankIndex].tower->removeFromParent();
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

    // ����Ƿ����� blank ������,���ֹ��������blank����
    for (int i = 0; i < 47; ++i)
    {
        Rect blankRect = blanks[i].blank->getBoundingBox();
        
        if (blankRect.containsPoint(touchLocation)&&!blanks[i].isOccupied)
        {
            newPos = blanks[i];

            
            // �������ĳ�� blank �����ϣ���¼ѡ�е� blank ����
            selectedBlankIndex = i;

            // ����˵�ͼ��ɼ�����ִ�к����߼�������ֹ�¼�����
            //if (btn_green_b->isVisible()) {
               // return ;
            //}

            // ��ʾ select_01.png
            showSelectSprite();

            // �������������������� blank ������߼�

            // ��ȡ����� blank ��������
            Vec2 blankCenter(blankRect.getMidX(), blankRect.getMidY());

            // ��ʾ Bottle01.png �� (x, y + 70) λ��
            bottleSprite = showBottleSprite(Vec2(blankCenter.x, blankCenter.y + 70));

            selected = true;
            return;
        }
        else if (blanks[i].isOccupied ) {
            Rect pedestalRect = blanks[i].tower->pedestal->getBoundingBox();
            if (pedestalRect.containsPoint(touchLocation)) {
                selectedChoice = true;
                selectedBlankIndex = i;
                Vec2 pedestalCenter(pedestalRect.getMidX(), pedestalRect.getMidY());
                upgradeSprite = showUpgradeSprite(Vec2(pedestalCenter.x, pedestalCenter.y + 70), blanks[i].tower);
                removeSprite= showRemoveSprite(Vec2(pedestalCenter.x, pedestalCenter.y - 70), blanks[i].tower);
                return;
            }
        }

    }


    // ������λ�ò����κ� blank �����ϣ����� Bottle01.png �� select_01.png
    if (bottleSprite) bottleSprite->setVisible(false);
    if (selectSprite) selectSprite->setVisible(false);
    // ����ѡ�е� blank ����
    selectedBlankIndex = -1;

    return;
}




bool MyScene::onTouchBeganForBottle(cocos2d::Touch* touch, cocos2d::Event* event) {
    return false;
}
void MyScene::hideBottleAndSelectSprites()
{
    // ���� Bottle01.png
    if (bottleSprite != nullptr && bottleSprite->isVisible())
    {
        bottleSprite->setVisible(false);
    }

    // ���� select_01.png
    if (selectSprite != nullptr && selectSprite->isVisible())
    {
        selectSprite->setVisible(false);
    }
}

Sprite* MyScene::showBottleSprite(const Vec2& position)
{
    // �Ƴ�֮ǰ�� Bottle01.png
    if (bottleSprite != nullptr && bottleSprite->getParent() != nullptr)
    {
        bottleSprite->removeFromParent();
    }

    // ��������ʾ�µ� Bottle01.png ����
    bottleSprite = Sprite::create("Bottle01.png");
    bottleSprite->setPosition(position);
    this->addChild(bottleSprite, 2);
    return bottleSprite;
}

Sprite* MyScene::showUpgradeSprite(Vec2 position, Tower* tower) {
    if (upgradeSprite != nullptr && upgradeSprite->getParent() != nullptr)
    {
        upgradeSprite->removeFromParent();
    }
    switch (tower->type) {
        case 1: {
            if (tower->level == 1) {
                upgradeSprite= Sprite::create("1upgrade1.png");
                upgradeSprite->setPosition(position);
                this->addChild(upgradeSprite, 2);
                return upgradeSprite;
            }
            else if (tower->level == 2) {
                upgradeSprite = Sprite::create("1upgrade2.png");
                upgradeSprite->setPosition(position);
                this->addChild(upgradeSprite, 2);
                return upgradeSprite;
            }
            else if (tower->level == 3) {
                upgradeSprite = Sprite::create("upgrade3.png");
                upgradeSprite->setPosition(position);
                this->addChild(upgradeSprite, 2);
                return upgradeSprite;
            }
        }
    }
}

Sprite* MyScene::showRemoveSprite(Vec2 position, Tower* tower) {
    if (removeSprite != nullptr && removeSprite->getParent() != nullptr)
    {
        removeSprite->removeFromParent();
    }
    switch (tower->type) {
        case 1: {
            if (tower->level == 1) {
                removeSprite = Sprite::create("1remove1.png");
                removeSprite->setPosition(position);
                this->addChild(removeSprite, 2);
                return removeSprite;
            }
            else if (tower->level == 2) {
                removeSprite = Sprite::create("1remove2.png");
                removeSprite->setPosition(position);
                this->addChild(removeSprite, 2);
                return removeSprite;
            }
            else if (tower->level == 3) {
                removeSprite = Sprite::create("1remove3.png");
                removeSprite->setPosition(position);
                this->addChild(removeSprite, 2);
                return removeSprite;
            }
        }
    }
}

bool MyScene::onTouchBeganForPause(cocos2d::Touch* touch, cocos2d::Event* event) {
    // ��ȡ������λ��
    Vec2 locationInNode = pause_0->convertToNodeSpace(touch->getLocation());
    Rect rectPause0 = Rect(0, 0, pause_0->getContentSize().width, pause_0->getContentSize().height);
    Rect rectPause1 = Rect(0, 0, pause_1->getContentSize().width, pause_1->getContentSize().height);

    // ��鴥�����Ƿ��� pause_0 ��
    if (rectPause0.containsPoint(locationInNode) && !pause_1->isVisible()) {
        // ����� pause_0���� pause_0 ����Ϊ���ɼ���pause_1 ����Ϊ�ɼ�
        pause_0->setVisible(false);
        pause_1->setVisible(true);
        pause_info->setVisible(true);

        // ��ͣ��Ϸ�߼�������ֹͣ������
        this->unscheduleUpdate();

        // ��ͣ������ƶ�����
        nhSprite_2->pause();

        return true;
    }

    // �ж��Ƿ����� pause_1.png ����
    if (rectPause1.containsPoint(locationInNode) && pause_1->isVisible()) {
        // ����� pause_1���� pause_1 ����Ϊ���ɼ���pause_0 ����Ϊ�ɼ�
        pause_1->setVisible(false);
        pause_info->setVisible(false);
        pause_0->setVisible(true);

        // �ָ���Ϸ�߼���������������������
        this->scheduleUpdate();

        // �ָ�������ƶ�����
        nhSprite_2->resume();

        return true;
    }

    return false;
}

bool MyScene::onTouchBeganForBtnGreenB(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = btn_green_b->convertToNodeSpace(touch->getLocation());
    // �����߼���������
    Rect continue_position = Rect(0, 0, btn_green_b->getContentSize().width, btn_green_b->getContentSize().height);
    if (continue_position.containsPoint(locationInNode) && btn_green_b->isVisible()) {
        // ����˼�����Ϸ
        hideMenuItems(); // �������Ԫ��

        // �ָ���Ϸ�߼���������������������
        this->scheduleUpdate();
        // ����������Ӽ�����Ϸ���߼�
        nhSprite_2->resume();
        return true;
    }
    return false;
}
bool MyScene::onTouchBeganForBtnBlueB(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = btn_blue_b->convertToNodeSpace(touch->getLocation());
    // �����߼���������
    Rect restart_position = Rect(0, 0, btn_blue_b->getContentSize().width, btn_blue_b->getContentSize().height);
    if (restart_position.containsPoint(locationInNode) && btn_blue_b->isVisible()) {
        // ��������¿�ʼ
        hideMenuItems(); // �������Ԫ��
        // ��������������¿�ʼ��Ϸ���߼�

        return true;
    }
    return false;
}
bool MyScene::onTouchBeganForBtnBlueL(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = btn_blue_l->convertToNodeSpace(touch->getLocation());
    Rect home_position = Rect(0, 0, btn_blue_l->getContentSize().width, btn_blue_l->getContentSize().height);
    if (home_position.containsPoint(locationInNode) && btn_blue_l->isVisible()) {
        // ��¼ nhSprite_2 �ĵ�ǰλ��
        nhSprite_2_position = nhSprite_2->getPosition();

        // ����˻����˵�
        hideMenuItems(); // �������Ԫ��

        // �л���myscene_2,��������Ϸ����
        //Director::getInstance()->pushScene(TransitionFade::create(0.5, MyScene_2::createScene())); // ʹ�ù���Ч��

        return true;
    }
    return false;
}

bool MyScene::onTouchBeganForBtnBlueL_2(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = btn_blue_l_2->convertToNodeSpace(touch->getLocation());
    // �����߼���������
    Rect weibo_position = Rect(0, 0, btn_blue_l_2->getContentSize().width, btn_blue_l_2->getContentSize().height);
    if (weibo_position.containsPoint(locationInNode) && btn_blue_l_2->isVisible()) {
        // �����ת��΢��
        hideMenuItems(); // �������Ԫ��

        // �����������ת��΢�����߼�

        return true;
    }
    return false;
}
bool MyScene::onTouchBeganForMenu(cocos2d::Touch* touch, cocos2d::Event* event) {
    Vec2 locationInNode = menu->convertToNodeSpace(touch->getLocation());
    Rect menu_position = Rect(0, 0, menu->getContentSize().width, menu->getContentSize().height);


    if (menu_position.containsPoint(locationInNode)) {

        // ����� Ŀ¼
        adv_menu_bg->setVisible(true);
        btn_green_b->setVisible(true);
        adv_menu_continue->setVisible(true);
        btn_blue_b->setVisible(true);
        adv_menu_restart->setVisible(true);
        btn_blue_l->setVisible(true);
        adv_menu_home->setVisible(true);
        btn_blue_l_2->setVisible(true);
        adv_menu_weibo->setVisible(true);
        // ��ͣ��Ϸ�߼�������ֹͣ������
        this->unscheduleUpdate();
        // ��ͣ������ƶ�����
        nhSprite_2->pause();
        return true;
    }



    return false;
}

void MyScene::hideMenuItems() {
    // �������Ԫ��
    adv_menu_bg->setVisible(false);
    btn_green_b->setVisible(false);
    adv_menu_continue->setVisible(false);
    btn_blue_b->setVisible(false);
    adv_menu_restart->setVisible(false);
    btn_blue_l->setVisible(false);
    adv_menu_home->setVisible(false);
    btn_blue_l_2->setVisible(false);
    adv_menu_weibo->setVisible(false);
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