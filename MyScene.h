#include "cocos2d.h"

#include<utility>
#include<vector>
#include"Tower.h"
using namespace cocos2d;
class MyScene : public Scene
{
public:
    struct BLANK {
        Sprite* blank; //�յ�ͼ��
        Vec2 position; //�յ�λ��
        int direction; //��������
        bool isOccupied = false; //�Ƿ���÷�����
        BLANK* ptr; //ָ��ýڵ��ָ��
        Tower* tower; //������
        bool isAttacking = false;
    };
    // ��ӳ�Ա����
    bool isAdded = false;
    std::vector< std::pair<float, float> >InflectionPoint;
    std::vector< Vec2 >BarrierPoint;
    std::vector<BLANK> blanks;
    
    int selectedBlankIndex; // ��¼ѡ�е� blank ����
    Sprite* pause_0;
    Sprite* pause_1;
    Sprite* pause_info;
    Sprite* menu;
    Sprite* adv_menu_bg;
    Sprite* btn_green_b;
    Sprite* adv_menu_continue;
    Sprite* btn_blue_b;
    Sprite* adv_menu_restart;
    Sprite* btn_blue_l;
    Sprite* adv_menu_home;
    Sprite* btn_blue_l_2;
    Sprite* adv_menu_weibo;
    Sprite* bottleSprite;
    Sprite* selectSprite;
    Sprite* upgradeSprite;
    Sprite* removeSprite;
    Action* moveAction;
    // ����ĳ�Ա��������ӱ�־λ
    bool isPause0Visible = true;

    float scaleX;
    float scaleY;
    float dsh_blank;

    static cocos2d::Scene* createScene();
    virtual bool init();
    Vec2 nhSprite_2_position;
    Sprite* nhSprite_2;
    CREATE_FUNC(MyScene);
    int row = 8;
    int col = 14;
    int countdownValue;
    struct square {
        int status;
        std::pair<float, float>CenterPoint;
    };
    virtual void initGrid();
    struct barrier {
        Vec2 pos;
        Sprite* type;
        bool isDestroyed = false;
    };
    barrier Barrier[12];

    std::vector<Sprite*>spriteOnStage;


    void Brain();
    void updateSprite(float dt);
    //  bool onTouchBeganForBlank(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onTouchBeganForPause(cocos2d::Touch* touch, cocos2d::Event* event);
    bool onTouchBeganForMenu(cocos2d::Touch* touch, cocos2d::Event* event);
    void hideMenuItems();
    void showSelectSprite();
    bool MyScene::onTouchBeganForBtnGreenB(cocos2d::Touch* touch, cocos2d::Event* event);
    bool MyScene::onTouchBeganForBtnBlueB(cocos2d::Touch* touch, cocos2d::Event* event);
    bool MyScene::onTouchBeganForBtnBlueL(cocos2d::Touch* touch, cocos2d::Event* event);
    bool MyScene::onTouchBeganForBtnBlueL_2(cocos2d::Touch* touch, cocos2d::Event* event);
    Sprite* MyScene::showBottleSprite(const Vec2& position);
    void MyScene::hideBottleSprite();
    void MyScene::hideBottleAndSelectSprites();
    bool MyScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    bool MyScene::onTouchBeganForOther(Touch* touch, Event* event);
    bool MyScene::onTouchBeganForBottle(cocos2d::Touch* touch, cocos2d::Event* event);
    void MyScene::onTouchBeganForBlank(Vec2 location);
    Sprite* MyScene::showUpgradeSprite(Vec2 position, Tower* tower);
    Sprite* MyScene::showRemoveSprite(Vec2 position, Tower* tower);
};

#pragma once
