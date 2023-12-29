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
void Bloodbar::initBloodbar(MyScene* background,int type,float health)
{
    bloodbar=ProgressTimer::create(Sprite::create("bloodbar2.png"));
    destination.assign(background->InflectionPoint.begin(), background->InflectionPoint.end());
    this->addChild(bloodbar, 1);
    //��Ѫ������Ϊˮƽ����Ľ�����
    bloodbar->setType(ProgressTimer::Type::BAR);
    bloodbar->setMidpoint(Vec2(0, 0)); // ����߿�ʼ�仯
    bloodbar->setBarChangeRate(Vec2(1, 0)); // ֻ��x�����ϱ仯
    if (type== 1)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = 5; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth)*100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].first, destination[0].second+50);
        // �ƶ��͵����Ķ�������
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(1.5, Vec2(destination[1].first, destination[1].second+50));
        auto bloodbarmove2 = MoveTo::create(3.0, Vec2(destination[2].first, destination[2].second+50));
        auto bloodbarmove3 = MoveTo::create(4.5, Vec2(destination[3].first, destination[3].second+50));
        auto bloodbarmove4 = MoveTo::create(3.0, Vec2(destination[4].first, destination[4].second+50));
        auto bloodbarmove5 = MoveTo::create(1.5, Vec2(destination[5].first, destination[5].second+50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1,bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    else if (type == 2)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = 3; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].first, destination[0].second + 50);
        // �ƶ��͵����Ķ�������
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(1.5, Vec2(destination[1].first, destination[1].second + 50));
        auto bloodbarmove2 = MoveTo::create(3.0, Vec2(destination[2].first, destination[2].second + 50));
        auto bloodbarmove3 = MoveTo::create(4.5, Vec2(destination[3].first, destination[3].second + 50));
        auto bloodbarmove4 = MoveTo::create(3.0, Vec2(destination[4].first, destination[4].second + 50));
        auto bloodbarmove5 = MoveTo::create(1.5, Vec2(destination[5].first, destination[5].second + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    else if (type == 3)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = 5; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].first, destination[0].second + 50);
        // �ƶ��͵����Ķ�������
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(1.5, Vec2(destination[1].first, destination[1].second + 50));
        auto bloodbarmove2 = MoveTo::create(3.0, Vec2(destination[2].first, destination[2].second + 50));
        auto bloodbarmove3 = MoveTo::create(4.5, Vec2(destination[3].first, destination[3].second + 50));
        auto bloodbarmove4 = MoveTo::create(3.0, Vec2(destination[4].first, destination[4].second + 50));
        auto bloodbarmove5 = MoveTo::create(1.5, Vec2(destination[5].first, destination[5].second + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    
    else if (type == 4)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = 3; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].first, destination[0].second + 50);
        // �ƶ��͵����Ķ�������
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(1.5, Vec2(destination[1].first, destination[1].second + 50));
        auto bloodbarmove2 = MoveTo::create(3.0, Vec2(destination[2].first, destination[2].second + 50));
        auto bloodbarmove3 = MoveTo::create(4.5, Vec2(destination[3].first, destination[3].second + 50));
        auto bloodbarmove4 = MoveTo::create(3.0, Vec2(destination[4].first, destination[4].second + 50));
        auto bloodbarmove5 = MoveTo::create(1.5, Vec2(destination[5].first, destination[5].second + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    else if (type == 5)
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = 5; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].first, destination[0].second + 50);
        // �ƶ��͵����Ķ�������
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(1.5, Vec2(destination[1].first, destination[1].second + 50));
        auto bloodbarmove2 = MoveTo::create(3.0, Vec2(destination[2].first, destination[2].second + 50));
        auto bloodbarmove3 = MoveTo::create(4.5, Vec2(destination[3].first, destination[3].second + 50));
        auto bloodbarmove4 = MoveTo::create(3.0, Vec2(destination[4].first, destination[4].second + 50));
        auto bloodbarmove5 = MoveTo::create(1.5, Vec2(destination[5].first, destination[5].second + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
    else
    {
        float currentHealth = health; // ��ǰѪ��
        float maxHealth = 3; // ���Ѫ��
        float healthPercentage = (currentHealth / maxHealth) * 100.0f;
        bloodbar->setPercentage(healthPercentage);
        bloodbar->setPosition(destination[0].first, destination[0].second + 50);
        // �ƶ��͵����Ķ�������
        auto scalemove1 = ScaleBy::create(0.1, 0.3f);
        auto bloodbarmove1 = MoveTo::create(1.5, Vec2(destination[1].first, destination[1].second + 50));
        auto bloodbarmove2 = MoveTo::create(3.0, Vec2(destination[2].first, destination[2].second + 50));
        auto bloodbarmove3 = MoveTo::create(4.5, Vec2(destination[3].first, destination[3].second + 50));
        auto bloodbarmove4 = MoveTo::create(3.0, Vec2(destination[4].first, destination[4].second + 50));
        auto bloodbarmove5 = MoveTo::create(1.5, Vec2(destination[5].first, destination[5].second + 50));
        auto changeVis = CallFunc::create([=]() {
            bloodbar->setVisible(false);
            });
        auto seq = Sequence::create(scalemove1, bloodbarmove1, bloodbarmove2, bloodbarmove3, bloodbarmove4, bloodbarmove5, changeVis, nullptr);
        bloodbar->runAction(seq);
    }
}
void Bloodbar::BloodbarMove1(float dt)
{
    // ����Ѫ��������Ѫ��
    auto Blo_BG1 = Sprite::create("bloodbar-bg2.png");
    auto Blo1 = ProgressTimer::create(Sprite::create("bloodbar2.png"));
    // ��Ѫ������Ϊˮƽ����Ľ�����
    Blo1->setType(ProgressTimer::Type::BAR);
    Blo1->setMidpoint(Vec2(0, 0)); // ����߿�ʼ�仯
    Blo1->setBarChangeRate(Vec2(1, 0)); // ֻ��x�����ϱ仯
    // ����Ѫ���ĳ�ʼ�ٷֱ�
    Blo1->setPercentage(100);
    //Ѫ��������ӽ�������
    bloodbars_bgs.push_back(Blo_BG1);
    bloodbars.push_back(Blo1);
    // ����һ���ڵ���ΪѪ���ͱ���������
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG1);
    bloodContainer->addChild(Blo1);
    // ��������ӵ�������
    this->addChild(bloodContainer, 1);
    // ���������ĳ�ʼλ��
    bloodContainer->setPosition(150, 540);
    // ����Ѫ���ķ���
    float reduceAmount = 33.3f; // ���ٵ�Ѫ���ٷֱ�
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo1->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo1->getPercentage() - 50.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo1->getPercentage() - 100.0f);
    // �ƶ��͵����Ķ�������
    auto scalemove1 = ScaleBy::create(0.1, 0.3f);
    auto bloodmove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(1.8, Vec2(144, 0));
    /*auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });*/
    // �������У����ƶ���Ȼ�󵭳�
    auto fadeout = FadeOut::create(0.5f);
    auto sequence = Sequence::create(scalemove1,bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5,fadeout,nullptr);
    bloodContainer->runAction(sequence);
    // ��������Ѫ���Ķ�������
    Blo1->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction1,nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(4.0f), reduceHealthAction2, nullptr));
    Blo1->runAction(Sequence::create(DelayTime::create(6.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove2(float dt)
{
    // ����Ѫ��������Ѫ��
    auto Blo_BG2 = Sprite::create("bloodbar-bg2.png");
    auto Blo2 = ProgressTimer::create(Sprite::create("bloodbar2.png"));
    // ��Ѫ������Ϊˮƽ����Ľ�����
    Blo2->setType(ProgressTimer::Type::BAR);
    Blo2->setMidpoint(Vec2(0, 0)); // ����߿�ʼ�仯
    Blo2->setBarChangeRate(Vec2(1, 0)); // ֻ��x�����ϱ仯
    // ����Ѫ���ĳ�ʼ�ٷֱ�
    Blo2->setPercentage(100);
    //Ѫ��������ӽ�������
    bloodbars_bgs.push_back(Blo_BG2);
    bloodbars.push_back(Blo2);
    // ����һ���ڵ���ΪѪ���ͱ���������
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG2);
    bloodContainer->addChild(Blo2);
    // ��������ӵ�������
    this->addChild(bloodContainer, 1);
    // ���������ĳ�ʼλ��
    bloodContainer->setPosition(150, 520);
    // ����Ѫ���ķ���
    float reduceAmount = 33.3f; // ���ٵ�Ѫ���ٷֱ�
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo2->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo2->getPercentage() - 50.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo2->getPercentage() - 100.0f);
    // �ƶ��͵����Ķ�������
    auto scalemove1 = ScaleBy::create(0.1, 0.3f);
    auto bloodmove1 = MoveBy::create(0.9, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(1.65, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(2.4, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(1.65, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(0.9, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // �������У����ƶ���Ȼ�󵭳�
    auto fadeout = FadeOut::create(0.5f);
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, fadeout, nullptr);
    bloodContainer->runAction(sequence);
    // ��������Ѫ���Ķ�������
    Blo2->runAction(Sequence::create(DelayTime::create(1.0f), reduceHealthAction1, nullptr));
    Blo2->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction2, nullptr));
    Blo2->runAction(Sequence::create(DelayTime::create(3.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove3(float dt)
{
    // ����Ѫ��������Ѫ��
    auto Blo_BG3 = Sprite::create("bloodbar-bg2.png");
    auto Blo3 = ProgressTimer::create(Sprite::create("bloodbar2.png"));
    // ��Ѫ������Ϊˮƽ����Ľ�����
    Blo3->setType(ProgressTimer::Type::BAR);
    Blo3->setMidpoint(Vec2(0, 0)); // ����߿�ʼ�仯
    Blo3->setBarChangeRate(Vec2(1, 0)); // ֻ��x�����ϱ仯
    // ����Ѫ���ĳ�ʼ�ٷֱ�
    Blo3->setPercentage(100);
    //Ѫ��������ӽ�������
    bloodbars_bgs.push_back(Blo_BG3);
    bloodbars.push_back(Blo3);
    // ����һ���ڵ���ΪѪ���ͱ���������
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG3);
    bloodContainer->addChild(Blo3);
    // ��������ӵ�������
    this->addChild(bloodContainer, 1);
    // ���������ĳ�ʼλ��
    bloodContainer->setPosition(150, 520);
    // ����Ѫ���ķ���
    float reduceAmount = 33.3f; // ���ٵ�Ѫ���ٷֱ�
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo3->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo3->getPercentage() - 50.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo3->getPercentage() - 100.0f);
    // �ƶ��͵����Ķ�������
    auto scalemove1 = ScaleBy::create(0.1, 0.3f);
    auto bloodmove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(1.8, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // �������У����ƶ���Ȼ�󵭳�
    auto fadeout = FadeOut::create(0.5f);
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, fadeout, nullptr);
    bloodContainer->runAction(sequence);
    // ��������Ѫ���Ķ�������
    Blo3->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction1, nullptr));
    Blo3->runAction(Sequence::create(DelayTime::create(4.0f), reduceHealthAction2, nullptr));
    Blo3->runAction(Sequence::create(DelayTime::create(6.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove4(float dt)
{
    // ����Ѫ��������Ѫ��
    auto Blo_BG4 = Sprite::create("bloodbar-bg2.png");
    auto Blo4 = ProgressTimer::create(Sprite::create("bloodbar2.png"));
    // ��Ѫ������Ϊˮƽ����Ľ�����
    Blo4->setType(ProgressTimer::Type::BAR);
    Blo4->setMidpoint(Vec2(0, 0)); // ����߿�ʼ�仯
    Blo4->setBarChangeRate(Vec2(1, 0)); // ֻ��x�����ϱ仯
    // ����Ѫ���ĳ�ʼ�ٷֱ�
    Blo4->setPercentage(100);
    //Ѫ��������ӽ�������
    bloodbars_bgs.push_back(Blo_BG4);
    bloodbars.push_back(Blo4);
    // ����һ���ڵ���ΪѪ���ͱ���������
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG4);
    bloodContainer->addChild(Blo4);
    // ��������ӵ�������
    this->addChild(bloodContainer, 1);
    // ���������ĳ�ʼλ��
    bloodContainer->setPosition(150, 520);
    // ����Ѫ���ķ���
    float reduceAmount = 33.3f; // ���ٵ�Ѫ���ٷֱ�
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo4->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo4->getPercentage() - 50.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo4->getPercentage() - 100.0f);
    // �ƶ��͵����Ķ�������
    auto scalemove1 = ScaleBy::create(0.1, 0.3f);
    auto bloodmove1 = MoveBy::create(0.9, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(1.65, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(2.4, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(1.65, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(0.9, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // �������У����ƶ���Ȼ�󵭳�
    auto fadeout = FadeOut::create(0.5f);
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, fadeout, nullptr);
    bloodContainer->runAction(sequence);
    // ��������Ѫ���Ķ�������
    Blo4->runAction(Sequence::create(DelayTime::create(1.0f), reduceHealthAction1, nullptr));
    Blo4->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction2, nullptr));
    Blo4->runAction(Sequence::create(DelayTime::create(3.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove5(float dt)
{
    // ����Ѫ��������Ѫ��
    auto Blo_BG5 = Sprite::create("bloodbar-bg2.png");
    auto Blo5 = ProgressTimer::create(Sprite::create("bloodbar2.png"));
    // ��Ѫ������Ϊˮƽ����Ľ�����
    Blo5->setType(ProgressTimer::Type::BAR);
    Blo5->setMidpoint(Vec2(0, 0)); // ����߿�ʼ�仯
    Blo5->setBarChangeRate(Vec2(1, 0)); // ֻ��x�����ϱ仯
    // ����Ѫ���ĳ�ʼ�ٷֱ�
    Blo5->setPercentage(100);
    //Ѫ��������ӽ�������
    bloodbars_bgs.push_back(Blo_BG5);
    bloodbars.push_back(Blo5);
    // ����һ���ڵ���ΪѪ���ͱ���������
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG5);
    bloodContainer->addChild(Blo5);
    // ��������ӵ�������
    this->addChild(bloodContainer, 1);
    // ���������ĳ�ʼλ��
    bloodContainer->setPosition(150, 520);
    // ����Ѫ���ķ���
    float reduceAmount = 33.3f; // ���ٵ�Ѫ���ٷֱ�
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo5->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo5->getPercentage() - 50.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo5->getPercentage() - 100.0f);
    // �ƶ��͵����Ķ�������
    auto scalemove1 = ScaleBy::create(0.1, 0.3f);
    auto bloodmove1 = MoveBy::create(1.8, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(3.3, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(4.8, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(3.3, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(1.8, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // �������У����ƶ���Ȼ�󵭳�
    auto fadeout = FadeOut::create(0.5f);
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, fadeout, nullptr);
    bloodContainer->runAction(sequence);
    // ��������Ѫ���Ķ�������
    Blo5->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction1, nullptr));
    Blo5->runAction(Sequence::create(DelayTime::create(4.0f), reduceHealthAction2, nullptr));
    Blo5->runAction(Sequence::create(DelayTime::create(6.0f), reduceHealthAction3, nullptr));
}
void Bloodbar::BloodbarMove6(float dt)
{
    // ����Ѫ��������Ѫ��
    auto Blo_BG6 = Sprite::create("bloodbar-bg2.png");
    auto Blo6 = ProgressTimer::create(Sprite::create("bloodbar2.png"));
    // ��Ѫ������Ϊˮƽ����Ľ�����
    Blo6->setType(ProgressTimer::Type::BAR);
    Blo6->setMidpoint(Vec2(0, 0)); // ����߿�ʼ�仯
    Blo6->setBarChangeRate(Vec2(1, 0)); // ֻ��x�����ϱ仯
    // ����Ѫ���ĳ�ʼ�ٷֱ�
    Blo6->setPercentage(100);
    //Ѫ��������ӽ�������
    bloodbars_bgs.push_back(Blo_BG6);
    bloodbars.push_back(Blo6);
    // ����һ���ڵ���ΪѪ���ͱ���������
    auto bloodContainer = Node::create();
    bloodContainer->addChild(Blo_BG6);
    bloodContainer->addChild(Blo6);
    // ��������ӵ�������
    this->addChild(bloodContainer, 1);
    // ���������ĳ�ʼλ��
    bloodContainer->setPosition(150, 520);
    // ����Ѫ���ķ���
    float reduceAmount = 33.3f; // ���ٵ�Ѫ���ٷֱ�
    auto reduceHealthAction1 = ProgressTo::create(0.5f, Blo6->getPercentage() - reduceAmount);
    auto reduceHealthAction2 = ProgressTo::create(0.5f, Blo6->getPercentage() - 50.0f);
    auto reduceHealthAction3 = ProgressTo::create(0.5f, Blo6->getPercentage() - 100.0f);
    // �ƶ��͵����Ķ�������
    auto scalemove1 = ScaleBy::create(0.1, 0.3f);
    auto bloodmove1 = MoveBy::create(0.9, Vec2(144, 0));
    auto bloodmove2 = MoveBy::create(1.65, Vec2(0, -264));
    auto bloodmove3 = MoveBy::create(2.4, Vec2(384, 0));
    auto bloodmove4 = MoveBy::create(1.65, Vec2(0, 264));
    auto bloodmove5 = MoveBy::create(0.9, Vec2(144, 0));
    auto removeBloodBar = CallFunc::create([bloodContainer]() {
        bloodContainer->removeFromParentAndCleanup(true);
        });
    // �������У����ƶ���Ȼ�󵭳�
    auto fadeout = FadeOut::create(0.5f);
    auto sequence = Sequence::create(scalemove1, bloodmove1, bloodmove2, bloodmove3, bloodmove4, bloodmove5, fadeout, nullptr);
    bloodContainer->runAction(sequence);
    // ��������Ѫ���Ķ�������
    Blo6->runAction(Sequence::create(DelayTime::create(1.0f), reduceHealthAction1, nullptr));
    Blo6->runAction(Sequence::create(DelayTime::create(2.0f), reduceHealthAction2, nullptr));
    Blo6->runAction(Sequence::create(DelayTime::create(3.0f), reduceHealthAction3, nullptr));
}