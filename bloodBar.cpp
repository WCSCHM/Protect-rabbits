#include"bloodBar.h";

#include<vector>
USING_NS_CC;
Bloodbar* Bloodbar::CreateBloodbar()
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
void Bloodbar::initBloodbar(std::vector<Vec2>InflectionPoint, std::vector<float>distance, Scene* background, int spriteType, float health)
{
    bloodbar = ProgressTimer::create(Sprite::create("bloodbar2.png"));
    destination.assign(InflectionPoint.begin(), InflectionPoint.end());
    type = spriteType;
    BG = background;
    this->addChild(bloodbar, 1);
    //将血条设置为水平方向的进度条
    bloodbar->setType(ProgressTimer::Type::BAR);
    bloodbar->setMidpoint(Vec2(0, 0)); // 从左边开始变化
    bloodbar->setBarChangeRate(Vec2(1, 0)); // 只在x方向上变化
    ScaleBy* scalemove1;
    if (type == 1)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = health; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        scalemove1 = ScaleBy::create(0.1, 0.3f);

    }
    else if (type == 2)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = health; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        scalemove1 = ScaleBy::create(0.1, 0.3f);
      
    }
    else if (type == 3)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = health; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        scalemove1 = ScaleBy::create(0.1, 0.3f);
    }

    else if (type == 4)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = health; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        scalemove1 = ScaleBy::create(0.1, 0.3f);
    }
    else if (type == 5)
    {
        float currentHealth = health; // 当前血量
        float maxHealth = health; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        scalemove1 = ScaleBy::create(0.1, 0.3f);
    }
    else
    {
        float currentHealth = health; // 当前血量
        float maxHealth = health; // 最大血量
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // 移动和淡出的动作序列
        scalemove1 = ScaleBy::create(0.1, 0.3f);
    }
    auto changeVis = CallFunc::create([=]() {
        bloodbar->setVisible(false);
        });
    Vector<FiniteTimeAction*> allActions;
    auto startUpdate = CallFunc::create([this]() {
        // 使用schedule函数来每秒调用update方法
        this->schedule(CC_SCHEDULE_SELECTOR(Bloodbar::update), 0.1f); // 1.0f代表每秒更新一次
        });
    // 将之前的动作添加到数组中
    allActions.pushBack(startUpdate);
    allActions.pushBack(scalemove1);

    // 循环添加移动动作到动作数组中
    for (size_t i = 1; i < destination.size(); ++i) {
        auto moveAction = MoveTo::create(distance[i - 1] / velocity[type], Vec2(destination[i].x,destination[i].y+50));
        moveAction->setTag(i);
        allActions.pushBack(moveAction);
    }

    // 添加最后的动作
    allActions.pushBack(changeVis);

    // 创建一个动作序列
    auto seq = Sequence::create(allActions);

    // 运行动作序列
    bloodbar->runAction(seq);
}

void Bloodbar::initBloodbar(Vec2 BarrierPosition)
{
    bloodbar = ProgressTimer::create(Sprite::create("bloodbar2.png"));
    this->addChild(bloodbar, 1);
    //将血条设置为水平方向的进度条
    bloodbar->setType(ProgressTimer::Type::BAR);
    bloodbar->setMidpoint(Vec2(0, 0)); // 从左边开始变化
    bloodbar->setBarChangeRate(Vec2(1, 0)); // 只在x方向上变化
    bloodbar->setPercentage(100.0f);
    bloodbar->setPosition(BarrierPosition.x, BarrierPosition.y + 50);
    auto scalemove1 = ScaleBy::create(0.1, 0.3f);
    bloodbar->runAction(scalemove1);
}

void Bloodbar::update(float dt) {
    if (slowDown) {
        velocity[type] *= 0.5;
        slowDown = false;
    }
}