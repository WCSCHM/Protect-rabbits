#include"bloodbar.h";
#include"monster.h";
#include"background.h"
#include"Carrots.h"
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
    this->schedule(CC_SCHEDULE_SELECTOR(Bloodbar::BloodbarMove1), 1.0f, 2, 1.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Bloodbar::BloodbarMove2), 1.0f, 2, 4.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Bloodbar::BloodbarMove3), 1.0f, 2, 7.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Bloodbar::BloodbarMove4), 1.0f, 2, 10.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Bloodbar::BloodbarMove5), 1.0f, 2, 13.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Bloodbar::BloodbarMove6), 1.0f, 2, 16.0f);
    return true;
}
void Bloodbar::BloodbarMove1(float dt)
{
    // 创建血条背景和血条
    auto Blo_BG1 = Sprite::create("bloodbar-bg1.png");
    auto Blo1 = ProgressTimer::create(Sprite::create("bloodbar1.png"));
    // 将血条设置为水平方向的进度条
    Blo1->setType(ProgressTimer::Type::BAR);
    Blo1->setMidpoint(Vec2(0, 0)); // 从左边开始变化
    Blo1->setBarChangeRate(Vec2(1, 0)); // 只在x方向上变化
    // 设置血条的初始百分比
    Blo1->setPercentage(100);
    // 创建一个节点作为血条和背景的容器
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG1);
    bloodContainer->addChild(Blo1);
    // 将容器添加到场景中
    this->addChild(bloodContainer, 1);
    // 设置容器的初始位置
    bloodContainer->setPosition(150, 540);
    // 减少血量的方法
    float reduceAmount = 20.0f; // 减少的血量百分比
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo1->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo1->getPercentage() - 40.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo1->getPercentage() - 80.0f);
    // 移动和淡出的动作序列
    auto scalemove1 = ScaleBy::create(0.1, 0.1f);
    auto bloodmove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(1.8, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // 动作序列：先移动，然后淡出
    auto sequence = Sequence::create(scalemove1,bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, removeBloodBar, nullptr);
    bloodContainer->runAction(sequence);
    // 创建减少血量的动作序列
    Blo1->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction1,nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(4.0f), reduceHealthAction2, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(6.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove2(float dt)
{
    // 创建血条背景和血条
    auto Blo_BG1 = Sprite::create("bloodbar-bg1.png");
    auto Blo1 = ProgressTimer::create(Sprite::create("bloodbar1.png"));
    // 将血条设置为水平方向的进度条
    Blo1->setType(ProgressTimer::Type::BAR);
    Blo1->setMidpoint(Vec2(0, 0)); // 从左边开始变化
    Blo1->setBarChangeRate(Vec2(1, 0)); // 只在x方向上变化
    // 设置血条的初始百分比
    Blo1->setPercentage(100);
    // 创建一个节点作为血条和背景的容器
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG1);
    bloodContainer->addChild(Blo1);
    // 将容器添加到场景中
    this->addChild(bloodContainer, 1);
    // 设置容器的初始位置
    bloodContainer->setPosition(150, 520);
    // 减少血量的方法
    float reduceAmount = 20.0f; // 减少的血量百分比
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo1->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo1->getPercentage() - 40.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo1->getPercentage() - 80.0f);
    // 移动和淡出的动作序列
    auto scalemove1 = ScaleBy::create(0.1, 0.1f);
    auto bloodmove1 = MoveBy::create(0.9, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(1.65, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(2.4, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(1.65, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(0.9, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // 动作序列：先移动，然后淡出
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, removeBloodBar, nullptr);
    bloodContainer->runAction(sequence);
    // 创建减少血量的动作序列
    Blo1->runAction(Sequence::create(DelayTime::create(1.0f), reduceHealthAction1, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction2, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(3.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove3(float dt)
{
    // 创建血条背景和血条
    auto Blo_BG1 = Sprite::create("bloodbar-bg1.png");
    auto Blo1 = ProgressTimer::create(Sprite::create("bloodbar1.png"));
    // 将血条设置为水平方向的进度条
    Blo1->setType(ProgressTimer::Type::BAR);
    Blo1->setMidpoint(Vec2(0, 0)); // 从左边开始变化
    Blo1->setBarChangeRate(Vec2(1, 0)); // 只在x方向上变化
    // 设置血条的初始百分比
    Blo1->setPercentage(100);
    // 创建一个节点作为血条和背景的容器
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG1);
    bloodContainer->addChild(Blo1);
    // 将容器添加到场景中
    this->addChild(bloodContainer, 1);
    // 设置容器的初始位置
    bloodContainer->setPosition(150, 520);
    // 减少血量的方法
    float reduceAmount = 20.0f; // 减少的血量百分比
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo1->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo1->getPercentage() - 40.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo1->getPercentage() - 80.0f);
    // 移动和淡出的动作序列
    auto scalemove1 = ScaleBy::create(0.1, 0.1f);
    auto bloodmove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(1.8, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // 动作序列：先移动，然后淡出
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, removeBloodBar, nullptr);
    bloodContainer->runAction(sequence);
    // 创建减少血量的动作序列
    Blo1->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction1, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(4.0f), reduceHealthAction2, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(6.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove4(float dt)
{
    // 创建血条背景和血条
    auto Blo_BG1 = Sprite::create("bloodbar-bg1.png");
    auto Blo1 = ProgressTimer::create(Sprite::create("bloodbar1.png"));
    // 将血条设置为水平方向的进度条
    Blo1->setType(ProgressTimer::Type::BAR);
    Blo1->setMidpoint(Vec2(0, 0)); // 从左边开始变化
    Blo1->setBarChangeRate(Vec2(1, 0)); // 只在x方向上变化
    // 设置血条的初始百分比
    Blo1->setPercentage(100);
    // 创建一个节点作为血条和背景的容器
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG1);
    bloodContainer->addChild(Blo1);
    // 将容器添加到场景中
    this->addChild(bloodContainer, 1);
    // 设置容器的初始位置
    bloodContainer->setPosition(150, 520);
    // 减少血量的方法
    float reduceAmount = 20.0f; // 减少的血量百分比
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo1->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo1->getPercentage() - 40.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo1->getPercentage() - 80.0f);
    // 移动和淡出的动作序列
    auto scalemove1 = ScaleBy::create(0.1, 0.1f);
    auto bloodmove1 = MoveBy::create(0.9, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(1.65, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(2.4, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(1.65, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(0.9, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // 动作序列：先移动，然后淡出
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, removeBloodBar, nullptr);
    bloodContainer->runAction(sequence);
    // 创建减少血量的动作序列
    Blo1->runAction(Sequence::create(DelayTime::create(1.0f), reduceHealthAction1, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction2, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(3.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove5(float dt)
{
    // 创建血条背景和血条
    auto Blo_BG1 = Sprite::create("bloodbar-bg1.png");
    auto Blo1 = ProgressTimer::create(Sprite::create("bloodbar1.png"));
    // 将血条设置为水平方向的进度条
    Blo1->setType(ProgressTimer::Type::BAR);
    Blo1->setMidpoint(Vec2(0, 0)); // 从左边开始变化
    Blo1->setBarChangeRate(Vec2(1, 0)); // 只在x方向上变化
    // 设置血条的初始百分比
    Blo1->setPercentage(100);
    // 创建一个节点作为血条和背景的容器
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG1);
    bloodContainer->addChild(Blo1);
    // 将容器添加到场景中
    this->addChild(bloodContainer, 1);
    // 设置容器的初始位置
    bloodContainer->setPosition(150, 520);
    // 减少血量的方法
    float reduceAmount = 20.0f; // 减少的血量百分比
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo1->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo1->getPercentage() - 40.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo1->getPercentage() - 80.0f);
    // 移动和淡出的动作序列
    auto scalemove1 = ScaleBy::create(0.1, 0.1f);
    auto bloodmove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(1.8, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // 动作序列：先移动，然后淡出
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, removeBloodBar, nullptr);
    bloodContainer->runAction(sequence);
    // 创建减少血量的动作序列
    Blo1->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction1, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(4.0f), reduceHealthAction2, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(6.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove6(float dt)
{
    // 创建血条背景和血条
    auto Blo_BG1 = Sprite::create("bloodbar-bg1.png");
    auto Blo1 = ProgressTimer::create(Sprite::create("bloodbar1.png"));
    // 将血条设置为水平方向的进度条
    Blo1->setType(ProgressTimer::Type::BAR);
    Blo1->setMidpoint(Vec2(0, 0)); // 从左边开始变化
    Blo1->setBarChangeRate(Vec2(1, 0)); // 只在x方向上变化
    // 设置血条的初始百分比
    Blo1->setPercentage(100);
    // 创建一个节点作为血条和背景的容器
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG1);
    bloodContainer->addChild(Blo1);
    // 将容器添加到场景中
    this->addChild(bloodContainer, 1);
    // 设置容器的初始位置
    bloodContainer->setPosition(150, 520);
    // 减少血量的方法
    float reduceAmount = 20.0f; // 减少的血量百分比
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo1->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo1->getPercentage() - 40.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo1->getPercentage() - 80.0f);
    // 移动和淡出的动作序列
    auto scalemove1 = ScaleBy::create(0.1, 0.1f);
    auto bloodmove1 = MoveBy::create(0.9, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(1.65, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(2.4, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(1.65, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(0.9, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // 动作序列：先移动，然后淡出
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, removeBloodBar, nullptr);
    bloodContainer->runAction(sequence);
    // 创建减少血量的动作序列
    Blo1->runAction(Sequence::create(DelayTime::create(1.0f), reduceHealthAction1, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction2, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(3.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarChange(float dt)
{

}