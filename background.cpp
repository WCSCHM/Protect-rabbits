#include"bloodbar.h";
#include"monster.h";
#include"background.h"
#include"Carrots.h"
USING_NS_CC;
Scene* Background::Createscene()
{
    Scene* scene = Scene::create();
    Background* layer = Background::create();
    scene->addChild(layer);
    return scene;
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool Background::init()
{
    //进行判断
    if(!Scene::init())
    {
        return false;
    }
    //获取界面大小及原点
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //设置界面标题
    auto headline = Label::createWithTTF("Crrots Guard", "fonts/Marker Felt.ttf", 36);
    if (headline == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        headline->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - headline->getContentSize().height));
        // add the label as a child to this layer
        this->addChild(headline, 1);
    }
    //设置背景
    auto background = Sprite::create("background.png");
    if (background == nullptr)
    {
        problemLoading("'background.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        background->setPosition(480, 320);
        //添加胡萝卜和怪物
        auto carrotsLayer = Carrots::create();
        auto monsterLayer = Monster::create();
        auto bloodbarLayer = Bloodbar::create();
        this->addChild(bloodbarLayer, 1);
        this->addChild(carrotsLayer, 1);
        this->addChild(monsterLayer, 1);
        // add the sprite as a child to this layer
        this->addChild(background, 0);
    }
    return true;
}