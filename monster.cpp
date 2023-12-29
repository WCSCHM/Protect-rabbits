#include"bloodbar.h";
#include"monster.h";
#include"background.h"
#include"Carrots.h"
#include<vector>
USING_NS_CC;
Monster* Monster::CreateMonster()
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
    return true;
}
void Monster::initMonster(std::vector<Vec2>InflectionPoint, std::vector<float>distance, Scene* background, int spriteType)
{
    type = spriteType;
    destination.assign(InflectionPoint.begin(), InflectionPoint.end());
    BG = background;
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster1.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster2.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster3.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster4.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster5.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("monster6.plist");

    ScaleBy* scalemove1;
    MoveTo* monstermove1;
    MoveTo* monstermove2;
    MoveTo* monstermove3;
    MoveTo* monstermove4;
    MoveTo* monstermove5;

    switch (type)
    {
    case 1:
    {
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
        monster = Sprite::createWithSpriteFrame(animFrames.front());
        monster->setPosition(destination[0]);
        this->addChild(monster);
        //运行动画
        auto animate = Animate::create(animation);
        monster->runAction(RepeatForever::create(animate));
        //怪物运动
        scalemove1 = ScaleBy::create(0.1, 0.5f);
        monstermove1 = MoveTo::create(distance[0] / velocity[1], destination[1]);
        monstermove2 = MoveTo::create(distance[1] / velocity[1], destination[2]);
        monstermove3 = MoveTo::create(distance[2] / velocity[1], destination[3]);
        monstermove4 = MoveTo::create(distance[3] / velocity[1], destination[4]);
        monstermove5 = MoveTo::create(distance[4] / velocity[1], destination[5]);
        auto fadeout = FadeOut::create(0.5f);
    }
    break;
    case 2:
    {
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
        monster = Sprite::createWithSpriteFrame(animFrames.front());
        monster->setPosition(destination[0]);
        this->addChild(monster);
        //运行动画
        auto animate = Animate::create(animation);
        monster->runAction(RepeatForever::create(animate));
        //怪物运动
        scalemove1 = ScaleBy::create(0.1, 0.5f);
        monstermove1 = MoveTo::create(distance[0] / velocity[2], destination[1]);
        monstermove2 = MoveTo::create(distance[1] / velocity[2], destination[2]);
        monstermove3 = MoveTo::create(distance[2] / velocity[2], destination[3]);
        monstermove4 = MoveTo::create(distance[3] / velocity[2], destination[4]);
        monstermove5 = MoveTo::create(distance[4] / velocity[2], destination[5]);
        auto fadeout = FadeOut::create(0.5f);

    }
    break;
    case 3:
    {
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
        monster = Sprite::createWithSpriteFrame(animFrames.front());
        monster->setPosition(destination[0]);
        this->addChild(monster);
        //运行动画
        auto animate = Animate::create(animation);
        monster->runAction(RepeatForever::create(animate));
        //怪物运动
        scalemove1 = ScaleBy::create(0.1, 0.5f);
        monstermove1 = MoveTo::create(distance[0] / velocity[3], destination[1]);
        monstermove2 = MoveTo::create(distance[1] / velocity[3], destination[2]);
        monstermove3 = MoveTo::create(distance[2] / velocity[3], destination[3]);
        monstermove4 = MoveTo::create(distance[3] / velocity[3], destination[4]);
        monstermove5 = MoveTo::create(distance[4] / velocity[3], destination[5]);
        auto fadeout = FadeOut::create(0.5f);

    }
    break;
    case 4:
    {
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
        monster = Sprite::createWithSpriteFrame(animFrames.front());
        monster->setPosition(destination[0]);
        this->addChild(monster);
        //运行动画
        auto animate = Animate::create(animation);
        monster->runAction(RepeatForever::create(animate));
        //怪物运动
        scalemove1 = ScaleBy::create(0.1, 0.5f);
        monstermove1 = MoveTo::create(distance[0] / velocity[4], destination[1]);
        monstermove2 = MoveTo::create(distance[1] / velocity[4], destination[2]);
        monstermove3 = MoveTo::create(distance[2] / velocity[4], destination[3]);
        monstermove4 = MoveTo::create(distance[3] / velocity[4], destination[4]);
        monstermove5 = MoveTo::create(distance[4] / velocity[4], destination[5]);
        auto fadeout = FadeOut::create(0.5f);

    }
    break;
    case 5:
    {
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
        monster = Sprite::createWithSpriteFrame(animFrames.front());
        monster->setPosition(destination[0]);
        this->addChild(monster);
        //运行动画
        auto animate = Animate::create(animation);
        monster->runAction(RepeatForever::create(animate));
        //怪物运动
        scalemove1 = ScaleBy::create(0.1, 0.5f);
        monstermove1 = MoveTo::create(distance[0] / velocity[5], destination[1]);
        monstermove2 = MoveTo::create(distance[1] / velocity[5], destination[2]);
        monstermove3 = MoveTo::create(distance[2] / velocity[5], destination[3]);
        monstermove4 = MoveTo::create(distance[3] / velocity[5], destination[4]);
        monstermove5 = MoveTo::create(distance[4] / velocity[5], destination[5]);
        auto fadeout = FadeOut::create(0.5f);

    }
    break;
    case 6:
    {
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
        monster = Sprite::createWithSpriteFrame(animFrames.front());
        monster->setPosition(destination[0]);
        this->addChild(monster);
        //运行动画
        auto animate = Animate::create(animation);
        monster->runAction(RepeatForever::create(animate));
        //怪物运动
        scalemove1 = ScaleBy::create(0.1, 0.5f);
        monstermove1 = MoveTo::create(distance[0] / velocity[6], destination[1]);
        monstermove2 = MoveTo::create(distance[1] / velocity[6], destination[2]);
        monstermove3 = MoveTo::create(distance[2] / velocity[6], destination[3]);
        monstermove4 = MoveTo::create(distance[3] / velocity[6], destination[4]);
        monstermove5 = MoveTo::create(distance[4] / velocity[6], destination[5]);
    }
    break;
    }

    auto startUpdate = CallFunc::create([this]() {
        // 使用schedule函数来每秒调用update方法
        this->schedule(CC_SCHEDULE_SELECTOR(Monster::update), 0.1f); // 1.0f代表每秒更新一次
        });
    auto changeEnd = CallFunc::create([=]() {
        this->isEnd = true;
        monster->setVisible(false);
        auto Cloud = Sprite::create("effect2.png");
        this->addChild(Cloud, 1);
        Cloud->setPosition(monster->getPosition());
        auto scalemove = ScaleBy::create(0.1, 2.0f);
        auto fadeout = FadeOut::create(1.0f);
        auto seq1 = Sequence::create(scalemove, fadeout, nullptr);
        Cloud->runAction(seq1);
        });
    auto seq = Sequence::create(startUpdate, scalemove1, monstermove1, monstermove2, monstermove3, monstermove4, monstermove5,changeEnd,nullptr);
    monster->runAction(seq);
}

void Monster::update(float dt) {
    if (blood[type] <= 0) {
        isDead = true;
        //this->removeFromParent();
    }
    /* if (!isAttackingMe.empty()) {
        for (unsigned int i = 0; i < isAttackingMe.size(); i++) {

           if (isAttackingMe[i]->type == 2) {
                velocity[type] *= 0.5;
                auto delay = DelayTime::create(3.0f);
                auto changeValue = CallFunc::create(CC_CALLBACK_0(Monster::recover, this));
                auto sequence = Sequence::create(delay, changeValue, nullptr);
                this->schedule([this](float dt) {

                    }, 0.016f, "follower_update");
                this->runAction(sequence);
            }
        }
    }*/
}
std::vector<Vec2> Monster::getMonstersPositions()
{
    std::vector<Vec2> positions;
    for (auto monster : monsters)
    {
        if(monster->getOpacity() != 0)
            positions.push_back(monster->getPosition());
    }
    return positions;
}
int Monster::checkMonstersReachedEnd(const Vec2& endPoint, float threshold)
{
    int count = 0;
    if (monster->getOpacity() != 0)
    {
        cocos2d::Vec2 monsterPosition = monster->getPosition();
        // 计算怪物位置和终点之间的距离
        float distance = monsterPosition.distance(endPoint);
        // 如果距离小于阈值，认为怪物到达了终点
        if (distance < threshold)
        {
            count=1;
        }
    }
    return count;
}