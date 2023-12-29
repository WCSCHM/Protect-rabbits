#include"bloodbar.h";
#include"monster.h";
#include"background.h"
#include"Carrots.h"
#include"MyScene.h"
#include<vector>
USING_NS_CC;
Layer* Bloodbar::CreateBloodbar()
{
    return Bloodbar::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool Bloodbar::init()
{
    //进行判断
    if (!Layer::init())
    {
        return false;
    }
    //获取界面大小及原点
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    return true;
}
void Bloodbar::initBloodbar(std::vector<Vec2>InflectionPoint,std::vector<float>distance, Scene* background, int spriteType, float health)
{
    bloodbar=ProgressTimer::create(Sprite::create("bloodbar2.png"));
    destination.assign(InflectionPoint.begin(),InflectionPoint.end());
    type = spriteType;
    BG = background;
    this->addChild(bloodbar, 1);
    //将血条设置为水平方向的进度条
    bloodbar->setType(ProgressTimer::Type::BAR);
    bloodbar->setMidpoint(Vec2(0, 0)); // 从左边开始变化
    bloodbar->setBarChangeRate(Vec2(1, 0)); // 只在x方向上变化
    if (type== 1)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = 5; // 最大血量
        float healthPercentage = (currentHealth / maxHealth)*100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y+50);
        // 移动和淡出的动作序列
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(distance[0] / velocity[type], Vec2(destination[1].x, destination[1].y+50));
        auto bloodbarmove2 = MoveTo::create(distance[1] / velocity[type], Vec2(destination[2].x, destination[2].y+50));
        auto bloodbarmove3 = MoveTo::create(distance[2] / velocity[type], Vec2(destination[3].x, destination[3].y+50));
        auto bloodbarmove4 = MoveTo::create(distance[3] / velocity[type], Vec2(destination[4].x, destination[4].y+50));
        auto bloodbarmove5 = MoveTo::create(distance[4] / velocity[type], Vec2(destination[5].x, destination[5].y+50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1,bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    else if (type == 2)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = 3; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(distance[0] / velocity[type], Vec2(destination[1].x, destination[1].y + 50));
        auto bloodbarmove2 = MoveTo::create(distance[1] / velocity[type], Vec2(destination[2].x, destination[2].y + 50));
        auto bloodbarmove3 = MoveTo::create(distance[2] / velocity[type], Vec2(destination[3].x, destination[3].y + 50));
        auto bloodbarmove4 = MoveTo::create(distance[3] / velocity[type], Vec2(destination[4].x, destination[4].y + 50));
        auto bloodbarmove5 = MoveTo::create(distance[4] / velocity[type], Vec2(destination[5].x, destination[5].y + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    else if (type == 3)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = 5; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(distance[0] / velocity[type], Vec2(destination[1].x, destination[1].y + 50));
        auto bloodbarmove2 = MoveTo::create(distance[1] / velocity[type], Vec2(destination[2].x, destination[2].y + 50));
        auto bloodbarmove3 = MoveTo::create(distance[2] / velocity[type], Vec2(destination[3].x, destination[3].y + 50));
        auto bloodbarmove4 = MoveTo::create(distance[3] / velocity[type], Vec2(destination[4].x, destination[4].y + 50));
        auto bloodbarmove5 = MoveTo::create(distance[4] / velocity[type], Vec2(destination[5].x, destination[5].y + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    
    else if (type == 4)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = 3; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(distance[0] / velocity[type], Vec2(destination[1].x, destination[1].y + 50));
        auto bloodbarmove2 = MoveTo::create(distance[1] / velocity[type], Vec2(destination[2].x, destination[2].y + 50));
        auto bloodbarmove3 = MoveTo::create(distance[2] / velocity[type], Vec2(destination[3].x, destination[3].y + 50));
        auto bloodbarmove4 = MoveTo::create(distance[3] / velocity[type], Vec2(destination[4].x, destination[4].y + 50));
        auto bloodbarmove5 = MoveTo::create(distance[4] / velocity[type], Vec2(destination[5].x, destination[5].y + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    else if (type == 5)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = 5; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(distance[0] / velocity[type], Vec2(destination[1].x, destination[1].y + 50));
        auto bloodbarmove2 = MoveTo::create(distance[1] / velocity[type], Vec2(destination[2].x, destination[2].y + 50));
        auto bloodbarmove3 = MoveTo::create(distance[2] / velocity[type], Vec2(destination[3].x, destination[3].y + 50));
        auto bloodbarmove4 = MoveTo::create(distance[3] / velocity[type], Vec2(destination[4].x, destination[4].y + 50));
        auto bloodbarmove5 = MoveTo::create(distance[4] / velocity[type], Vec2(destination[5].x, destination[5].y + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    else
    {
        float currentHealth = health; // 当前血量
        float maxHealth = 3; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(distance[0] / velocity[type], Vec2(destination[1].x, destination[1].y + 50));
        auto bloodbarmove2 = MoveTo::create(distance[1] / velocity[type], Vec2(destination[2].x, destination[2].y + 50));
        auto bloodbarmove3 = MoveTo::create(distance[2] / velocity[type], Vec2(destination[3].x, destination[3].y + 50));
        auto bloodbarmove4 = MoveTo::create(distance[3] / velocity[type], Vec2(destination[4].x, destination[4].y + 50));
        auto bloodbarmove5 = MoveTo::create(distance[4] / velocity[type], Vec2(destination[5].x, destination[5].y + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
}