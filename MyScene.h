#include "cocos2d.h"
#include"Map.h"
#include<utility>
#include<vector>
#include"Tower.h"
#include"Monster.h"
#include<memory>
#include"barrier.h"
#include"bloodBar.h"

using namespace cocos2d;



class MyScene : public Scene
{
public:
    struct BLANK {
        int No;//在vector中的序号
        Sprite* blank; //空点图标
        Vec2 position; //空点位置
        int direction; //炮塔方向
        bool isOccupied = false; //是否放置防御塔
        BLANK* ptr; //指向该节点的指针
        Tower* tower; //防御塔
        bool isAttacking = false;
       // std::unique_ptr<Monster>target;
    };
    // 添加成员变量
    bool isAdded = false;
    std::vector<Vec2>InflectionPoint;
    std::vector< Vec2 >BarrierPoint;
    std::vector<BLANK> blanks;
    std::vector<float>distance;
    
    int selectedBlankIndex; // 记录选中的 blank 索引
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

    Sprite* Path;
    Sprite* shitSprite;
    Sprite* bottleSprite;
    Sprite* starSprite;
    Sprite* selectSprite;
    Sprite* upgradeSprite;
    Sprite* removeSprite;
    Action* moveAction;
    // 在类的成员变量中添加标志位
    bool isPause0Visible = true;


    int countdownValue = 3;
    int currentwave = 0;
    //bool isClear = false;//判断一波精灵有没有死完
    bool isTimeActive = true;
    int money = 200;
    float scaleX;
    float scaleY;
    float dsh_blank;

    static MyScene* createScene();
    virtual bool init();
    Vec2 nhSprite_2_position;
    Sprite* nhSprite_2;
    CREATE_FUNC(MyScene);
    int row = 8;
    int col = 14;
    struct square {
        int status;
        std::pair<float, float>CenterPoint;
    };
    virtual void initGrid();
   
    std::vector<barrier>Barrier;

    std::vector<Monster*>spriteOnStage;
    std::vector<Bloodbar*>bloodbarForSprite;
    std::vector<Bloodbar*>bloodbarForBarrier;

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
    Sprite* MyScene::showShitSprite(const Vec2& position);
    Sprite* MyScene::showStarSprite(const Vec2& position);
    bool MyScene::isClear();
};

#pragma once
