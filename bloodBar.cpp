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
    //�����ж�
    if (!Layer::init())
    {
        return false;
    }
    //��ȡ�����С��ԭ��
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
    //��Ѫ������Ϊˮƽ����Ľ�����
    bloodbar->setType(ProgressTimer::Type::BAR);
    bloodbar->setMidpoint(Vec2(0, 0)); // ����߿�ʼ�仯
    bloodbar->setBarChangeRate(Vec2(1, 0)); // ֻ��x�����ϱ仯
    ScaleBy* scalemove1;
    if (type == 1)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = health; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // �ƶ��͵����Ķ�������
        scalemove1 = ScaleBy::create(0.1, 0.3f);

    }
    else if (type == 2)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = health; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // �ƶ��͵����Ķ�������
        scalemove1 = ScaleBy::create(0.1, 0.3f);
      
    }
    else if (type == 3)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = health; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // �ƶ��͵����Ķ�������
        scalemove1 = ScaleBy::create(0.1, 0.3f);
    }

    else if (type == 4)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = health; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // �ƶ��͵����Ķ�������
        scalemove1 = ScaleBy::create(0.1, 0.3f);
    }
    else if (type == 5)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = health; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // �ƶ��͵����Ķ�������
        scalemove1 = ScaleBy::create(0.1, 0.3f);
    }
    else
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = health; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].x, destination[0].y + 50);
        // �ƶ��͵����Ķ�������
        scalemove1 = ScaleBy::create(0.1, 0.3f);
    }
    auto changeVis = CallFunc::create([=]() {
        bloodbar->setVisible(false);
        });
    Vector<FiniteTimeAction*> allActions;
    auto startUpdate = CallFunc::create([this]() {
        // ʹ��schedule������ÿ�����update����
        this->schedule(CC_SCHEDULE_SELECTOR(Bloodbar::update), 0.1f); // 1.0f����ÿ�����һ��
        });
    // ��֮ǰ�Ķ�����ӵ�������
    allActions.pushBack(startUpdate);
    allActions.pushBack(scalemove1);

    // ѭ������ƶ�����������������
    for (size_t i = 1; i < destination.size(); ++i) {
        auto moveAction = MoveTo::create(distance[i - 1] / velocity[type], Vec2(destination[i].x,destination[i].y+50));
        moveAction->setTag(i);
        allActions.pushBack(moveAction);
    }

    // ������Ķ���
    allActions.pushBack(changeVis);

    // ����һ����������
    auto seq = Sequence::create(allActions);

    // ���ж�������
    bloodbar->runAction(seq);
}

void Bloodbar::initBloodbar(Vec2 BarrierPosition)
{
    bloodbar = ProgressTimer::create(Sprite::create("bloodbar2.png"));
    this->addChild(bloodbar, 1);
    //��Ѫ������Ϊˮƽ����Ľ�����
    bloodbar->setType(ProgressTimer::Type::BAR);
    bloodbar->setMidpoint(Vec2(0, 0)); // ����߿�ʼ�仯
    bloodbar->setBarChangeRate(Vec2(1, 0)); // ֻ��x�����ϱ仯
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