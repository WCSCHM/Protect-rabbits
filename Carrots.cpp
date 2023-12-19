#include"bloodbar.h";
#include"monster.h";
#include"background.h"
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
    MoveforCarrots(0.0);
    return true;
}
void Carrots::MoveforCarrots(float dt)
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
    auto sprite = Sprite::createWithSpriteFrame(animFrames.front());
    sprite->setPosition(830, 520);
    this->addChild(sprite);
    auto animate = Animate::create(animation);
    sprite->runAction(RepeatForever::create(animate));
}