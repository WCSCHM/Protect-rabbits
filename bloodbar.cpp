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
    //�����ж�
    if (!Layer::init())
    {
        return false;
    }
    //��ȡ�����С��ԭ��
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    this->schedule(CC_SCHEDULE_SELECTOR(Bloodbar::BloodbarMove), 1.0f, 2, 1.0f);
    return true;
}
void Bloodbar::BloodbarMove(float dt)
{
    auto Blo_BG1 = Sprite::create("bloodbar-bg1.png");
    auto Blo1 = ProgressTimer::create(Sprite::create("bloodbar1.png"));
    this->addChild(Blo_BG1);
    Blo_BG1->addChild(Blo1);
    Blo_BG1->setPosition(150, 520);
    Blo_BG1->setAnchorPoint(Vec2(0.5f, 0.5f));
    // ��� Blo1 �� Blo_BG1�������� Blo1 ��ê��Ϊ����
    Blo1->setAnchorPoint(Vec2(0.0f, 0.0f));
    Blo1->setPosition(0,0); // ��Ὣ Blo1 ���� Blo_BG1 ������λ��
    Blo1->setType(ProgressTimer::Type::BAR);
    Blo1->setBarChangeRate(Vec2(1, 0));
    Blo1->setPercentage(100);  // ������ʼѪ��
    float currentHealth = 100.0f;  // ��ǰѪ��
    float reduceAmount = 20.0f;  // ���ٵ�Ѫ��
    currentHealth -= reduceAmount;
    Blo1->setPercentage(currentHealth);  // ����Ѫ����ʾ
    auto scalemove1 = ScaleBy::create(0.1, 0.1f);
    auto bloodmove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(1.8, Vec2(144, 0));
    auto fadeout = FadeOut::create(0.5f);
    auto seq = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, fadeout, nullptr);
    Blo_BG1->runAction(seq);
}
void Bloodbar::BloodbarChange(float dt)
{

}