#include"bloodBar.h";
#include"Monster.h";

#include"Carrots.h"
USING_NS_CC;
Layer* Carrots::CreateCarrots()
{
    return Carrots::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool Carrots::init()
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
void Carrots::MoveforCarrots1(float dt, Vec2 position)
{
    //加载图集
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("carrots.plist");
    Vector<SpriteFrame*> animFrames;
    char str[30];
    for (int i = 21; i <= 23; i++)
    {
        sprintf(str, "hlb1_%d.png", i);
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    //设置动画
    auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 2);
    animateSprite1 = Sprite::createWithSpriteFrame(animFrames.front());
    animateSprite1->setPosition(position);
    this->addChild(animateSprite1);
    auto animate = Animate::create(animation);
    animateSprite1->runAction(RepeatForever::create(animate));
}
void Carrots::MoveforCarrots2(float dt, Vec2 position)
{
    //加载图集
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("carrots.plist");
    Vector<SpriteFrame*> animFrames;
    char str[30];
    for (int i = 7; i <= 9; i++)
    {
        sprintf(str, "hlb1_%d.png", i);
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    //设置动画
    auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 2);
    animateSprite1 = Sprite::createWithSpriteFrame(animFrames.front());
    animateSprite1->setPosition(position);
    this->addChild(animateSprite1);
    auto animate = Animate::create(animation);
    animateSprite1->runAction(RepeatForever::create(animate));
}
void Carrots::MoveforCarrots3(float dt, Vec2 position)
{
    //加载图集
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("carrots.plist");
    Vector<SpriteFrame*> animFrames;
    char str[30];
    for (int i = 3; i <= 6; i++)
    {
        sprintf(str, "hlb1_%d.png", i);
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    //设置动画
    auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 2);
    animateSprite1 = Sprite::createWithSpriteFrame(animFrames.front());
    animateSprite1->setPosition(position);
    this->addChild(animateSprite1);
    auto animate = Animate::create(animation);
    animateSprite1->runAction(RepeatForever::create(animate));
}
void Carrots::stopAnimation1()
{
    if (animateSprite1)
    {
        animateSprite1->stopAllActions();
        animateSprite1->removeFromParentAndCleanup(true);
    }
}