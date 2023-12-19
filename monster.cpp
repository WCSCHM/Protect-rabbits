#include"bloodbar.h";
#include"monster.h";
#include"background.h"
#include"Carrots.h"
USING_NS_CC;
Layer* Monster::CreateMonster()
{
    return Monster::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool Monster::init()
{
    //进行判断
    if (!Layer::init())
    {
        return false;
    }
    //获取界面大小及原点
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    this->schedule(CC_SCHEDULE_SELECTOR(Monster::MoveforMonster1), 1.0f, 2, 1.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Monster::MoveforMonster2), 1.0f, 2, 4.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Monster::MoveforMonster3), 1.0f, 2, 7.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Monster::MoveforMonster4), 1.0f, 2, 10.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Monster::MoveforMonster5), 1.0f, 2, 13.0f);
    this->schedule(CC_SCHEDULE_SELECTOR(Monster::MoveforMonster6), 1.0f, 2, 16.0f);
    return true;
}
void Monster::MoveforMonster1(float dt)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster1.plist");
    Vector<SpriteFrame*> animFrames;
    char str[10];
    //加载图集
    for (int i = 1; i <= 3; i++)
    {
        sprintf(str, "BB1%d.png", i);
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    //创建动画
    auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 3);
    auto sprite = Sprite::createWithSpriteFrame(animFrames.front());
    sprite->setPosition(150,480);
    this->addChild(sprite);
    auto animate = Animate::create(animation);
    auto scalemove1 = ScaleBy::create(0.1, 0.5f);
    auto monstermove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto monstermove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto monstermove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto monstermove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto monstermove5 = MoveBy::create(1.8, Vec2(144, 0));
    auto fadeout = FadeOut::create(0.5f);
    auto seq = Sequence::create(scalemove1, monstermove1, monstermove2, monstermove3, monstermove4, monstermove5,fadeout,nullptr);
    // 运行动画
    sprite->runAction(seq);
    sprite->runAction(RepeatForever::create(animate));
}
void Monster::MoveforMonster2(float dt)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster2.plist");
    Vector<SpriteFrame*> animFrames;
    char str[10];
    //加载图集
    for (int i = 1; i <= 3; i++)
    {
        sprintf(str, "B1%d.png", i);
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    //创建动画
    auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 3);
    auto sprite = Sprite::createWithSpriteFrame(animFrames.front());
    sprite->setPosition(150, 480);
    this->addChild(sprite);
    auto animate = Animate::create(animation);
    auto scalemove1 = ScaleBy::create(0.1, 0.5f);
    auto monstermove1 = MoveBy::create(0.9, Vec2(144, 0));
    auto monstermove2 = MoveBy::create(1.65, Vec2(0, -264));
    auto monstermove3 = MoveBy::create(2.4, Vec2(384, 0));
    auto monstermove4 = MoveBy::create(1.65, Vec2(0, 264));
    auto monstermove5 = MoveBy::create(0.9, Vec2(144, 0));
    auto fadeout = FadeOut::create(0.5f);
    auto seq = Sequence::create(scalemove1, monstermove1, monstermove2, monstermove3, monstermove4, monstermove5, fadeout, nullptr);
    // 运行动画
    sprite->runAction(seq);
    sprite->runAction(RepeatForever::create(animate));
}
void Monster::MoveforMonster3(float dt)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster3.plist");
    Vector<SpriteFrame*> animFrames;
    char str[10];
    //加载图集
    for (int i = 1; i <= 3; i++)
    {
        sprintf(str, "BM1%d.png", i);
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    //创建动画
    auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 3);
    auto sprite = Sprite::createWithSpriteFrame(animFrames.front());
    sprite->setPosition(150, 480);
    this->addChild(sprite);
    auto animate = Animate::create(animation);
    auto scalemove1 = ScaleBy::create(0.1, 0.5f);
    auto monstermove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto monstermove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto monstermove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto monstermove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto monstermove5 = MoveBy::create(1.8, Vec2(144, 0));
    auto fadeout = FadeOut::create(0.5f);
    auto seq = Sequence::create(scalemove1, monstermove1, monstermove2, monstermove3, monstermove4, monstermove5, fadeout, nullptr);
    // 运行动画
    sprite->runAction(seq);
    sprite->runAction(RepeatForever::create(animate));
}
void Monster::MoveforMonster4(float dt)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster4.plist");
    Vector<SpriteFrame*> animFrames;
    char str[10];
    //加载图集
    for (int i = 1; i <= 3; i++)
    {
        sprintf(str, "SL1%d.png", i);
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    //创建动画
    auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 3);
    auto sprite = Sprite::createWithSpriteFrame(animFrames.front());
    sprite->setPosition(150, 480);
    this->addChild(sprite);
    auto animate = Animate::create(animation);
    auto scalemove1 = ScaleBy::create(0.1, 0.5f);
    auto monstermove1 = MoveBy::create(0.9, Vec2(144, 0));
    auto monstermove2 = MoveBy::create(1.65, Vec2(0, -264));
    auto monstermove3 = MoveBy::create(2.4, Vec2(384, 0));
    auto monstermove4 = MoveBy::create(1.65, Vec2(0, 264));
    auto monstermove5 = MoveBy::create(0.9, Vec2(144, 0));
    auto fadeout = FadeOut::create(0.5f);
    auto seq = Sequence::create(scalemove1, monstermove1, monstermove2, monstermove3, monstermove4, monstermove5, fadeout, nullptr);
    // 运行动画
    sprite->runAction(seq);
    sprite->runAction(RepeatForever::create(animate));
}
void Monster::MoveforMonster5(float dt)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster5.plist");
    Vector<SpriteFrame*> animFrames;
    char str[10];
    //加载图集
    for (int i = 1; i <= 3; i++)
    {
        sprintf(str, "SL3%d.png", i);
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    //创建动画
    auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 3);
    auto sprite = Sprite::createWithSpriteFrame(animFrames.front());
    sprite->setPosition(150, 480);
    this->addChild(sprite);
    auto animate = Animate::create(animation);
    auto scalemove1 = ScaleBy::create(0.1, 0.5f);
    auto monstermove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto monstermove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto monstermove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto monstermove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto monstermove5 = MoveBy::create(1.8, Vec2(144, 0));
    auto fadeout = FadeOut::create(0.5f);
    auto seq = Sequence::create(scalemove1, monstermove1, monstermove2, monstermove3, monstermove4, monstermove5, fadeout, nullptr);
    // 运行动画
    sprite->runAction(seq);
    sprite->runAction(RepeatForever::create(animate));
}
void Monster::MoveforMonster6(float dt)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster6.plist");
    Vector<SpriteFrame*> animFrames;
    char str[10];
    //加载图集
    for (int i = 1; i <= 3; i++)
    {
        sprintf(str, "SP1%d.png", i);
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    //创建动画
    auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 3);
    auto sprite = Sprite::createWithSpriteFrame(animFrames.front());
    sprite->setPosition(150, 480);
    this->addChild(sprite);
    auto animate = Animate::create(animation);
    auto scalemove1 = ScaleBy::create(0.1, 0.5f);
    auto monstermove1 = MoveBy::create(0.9, Vec2(144, 0));
    auto monstermove2 = MoveBy::create(1.65, Vec2(0, -264));
    auto monstermove3 = MoveBy::create(2.4, Vec2(384, 0));
    auto monstermove4 = MoveBy::create(1.65, Vec2(0, 264));
    auto monstermove5 = MoveBy::create(0.9, Vec2(144, 0));
    auto fadeout = FadeOut::create(0.5f);
    auto seq = Sequence::create(scalemove1, monstermove1, monstermove2, monstermove3, monstermove4, monstermove5, fadeout, nullptr);
    // 运行动画
    sprite->runAction(seq);
    sprite->runAction(RepeatForever::create(animate));
}