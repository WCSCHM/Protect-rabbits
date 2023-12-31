
#include"Monster.h"
#include"MyScene.h"
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
            scalemove1 = ScaleBy::create(0.1, 0.5f);
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
            
        }
        break;
    }

   
    auto changeEnd = CallFunc::create([=]() {
        if (!isDead) {
            this->isEnd = true;
            monster->setVisible(false);
            auto Cloud = Sprite::create("effect2.png");
            this->addChild(Cloud, 1);
            Cloud->setPosition(monster->getPosition());
            auto scalemove = ScaleBy::create(0.1, 2.0f);
            auto fadeout = FadeOut::create(1.0f);
            auto seq1 = Sequence::create(scalemove, fadeout, nullptr);
            Cloud->runAction(seq1);
        }
        });

    auto startUpdate = CallFunc::create([this]() {
        // 使用schedule函数来每秒调用update方法
        this->schedule(CC_SCHEDULE_SELECTOR(Monster::update), 0.1f); // 1.0f代表每秒更新一次
        });

    Vector<FiniteTimeAction*> allActions;

    // 将之前的动作添加到数组中
    allActions.pushBack(startUpdate);
    allActions.pushBack(scalemove1);

    // 循环添加移动动作到动作数组中
    for (size_t i = 1; i < destination.size(); ++i) {
        auto moveAction = MoveTo::create(distance[i - 1] / velocity[type], destination[i]);
        allActions.pushBack(moveAction);
    }

    // 添加最后的动作
    allActions.pushBack(changeEnd);

    // 创建一个动作序列
    auto seq = Sequence::create(allActions);

    // 运行动作序列
    monster->runAction(seq);
}

void Monster::update(float dt) {
    if (blood[type] <= 0&&!isDead) {
        isDead = true;
        auto dead = CallFunc::create([=]() {
            monster->setVisible(false);
            auto Cloud = Sprite::create("effect2.png");
            this->addChild(Cloud, 1);
            Cloud->setPosition(monster->getPosition());
            auto scalemove = ScaleBy::create(0.1, 2.0f);
            auto fadeout = FadeOut::create(1.0f);
            auto seq1 = Sequence::create(scalemove, fadeout, nullptr);
            Cloud->runAction(seq1);
            });
        this->runAction(dead);
    }
   
  
}

void Monster::recover() {
    velocity[type] *= 2;
    this->unschedule("follower_update");
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
    auto monster1 = Sprite::createWithSpriteFrame(animFrames.front());
    monster1->setPosition(150, 480);
    monsters.push_back(monster1);
    this->addChild(monster1);
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
    monster1->runAction(seq);
    monster1->runAction(RepeatForever::create(animate));
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
    auto monster2 = Sprite::createWithSpriteFrame(animFrames.front());
    monster2->setPosition(150, 480);
    monsters.push_back(monster2);
    this->addChild(monster2);
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
    monster2->runAction(seq);
    monster2->runAction(RepeatForever::create(animate));
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
    auto monster3 = Sprite::createWithSpriteFrame(animFrames.front());
    monster3->setPosition(150, 480);
    monsters.push_back(monster3);
    this->addChild(monster3);
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
    monster3->runAction(seq);
    monster3->runAction(RepeatForever::create(animate));
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
    auto monster4 = Sprite::createWithSpriteFrame(animFrames.front());
    monster4->setPosition(150, 480);
    monsters.push_back(monster4);
    this->addChild(monster4);
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
    monster4->runAction(seq);
    monster4->runAction(RepeatForever::create(animate));
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
    auto monster5 = Sprite::createWithSpriteFrame(animFrames.front());
    monster5->setPosition(150, 480);
    monsters.push_back(monster5);
    this->addChild(monster5);
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
    monster5->runAction(seq);
    monster5->runAction(RepeatForever::create(animate));
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
    auto monster6 = Sprite::createWithSpriteFrame(animFrames.front());
    monster6->setPosition(150, 480);
    monsters.push_back(monster6);
    this->addChild(monster6);
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
    monster6->runAction(seq);
    monster6->runAction(RepeatForever::create(animate));
}
std::vector<Vec2> Monster::getMonstersPositions()
{
    std::vector<Vec2> positions;
    for (auto monster : monsters)
    {
        if (monster->getOpacity() != 0)
            positions.push_back(monster->getPosition());
    }
    return positions;
}
int Monster::checkMonstersReachedEnd(const Vec2& endPoint, float threshold)
{
    int count = 0;
    for (auto monster : monsters)
    {
        if (monster->getOpacity() != 0)
        {
            cocos2d::Vec2 monsterPosition = monster->getPosition();
            // 计算怪物位置和终点之间的距离
            float distance = monsterPosition.distance(endPoint);
            // 如果距离小于阈值，认为怪物到达了终点
            if (distance < threshold)
            {
                count++;
            }
        }
    }
    return count;
}