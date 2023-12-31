/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include"Adventure.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //设置背景界面
    auto background = Sprite::create("MainBg.PNG");
    if (background == nullptr)
        problemLoading("MainBg.PNG");
    background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(background, 0);
    auto background_center_name = Sprite::create("MainTitle.PNG");
    background_center_name->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(background_center_name, 1);
    auto start_normal = Sprite::create("StartNormal.png");
    start_normal->setPosition(Vec2(visibleSize.width / 2, 70));
    this->addChild(start_normal, 1);

    // 添加触摸事件监听器
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    // 设置触摸事件回调函数
    touchListener->onTouchBegan = [=](Touch* touch, Event* event) {
        // 获取触摸点相对于当前节点的位置
        Vec2 touchLocation = this->convertToNodeSpace(touch->getLocation());

        // 检查是否点击到 start_normal
        if (start_normal->getBoundingBox().containsPoint(touchLocation)) {
            // 执行场景切换逻辑，这里是切换到 AdventuresScene
            auto adventure = Adventure::createScene();
            Director::getInstance()->replaceScene(TransitionFade::create(0.5, adventure));
            return true; // 消费触摸事件
        }

        return false; // 不消费触摸事件
    };

    // 添加触摸事件监听器到事件分发器
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, start_normal);

    auto flymonster = Sprite::create("FlyMonster.PNG");
    flymonster->setPosition(Vec2(130, 470));
    this->addChild(flymonster, 1);
    // 创建上下移动的动作
    auto moveUp = MoveBy::create(1.0f, Vec2(0, 50)); // 移动上升
    auto moveDown = MoveBy::create(1.0f, Vec2(0, -50)); // 移动下降

    // 创建无限循环的序列动作
    auto sequence = Sequence::create(moveUp, moveDown, nullptr);
    auto repeatForever = RepeatForever::create(sequence);

    // 运行动作
    flymonster->runAction(repeatForever);

    auto leaf_1 = Sprite::create("Leaf1.PNG");
    leaf_1->setPosition(Vec2(420, 450));
    this->addChild(leaf_1, 0);
    auto leaf_2 = Sprite::create("Leaf2.PNG");
    leaf_2->setPosition(Vec2(560, 450));
    this->addChild(leaf_2, 0);
    auto leaf_3 = Sprite::create("Leaf3.PNG");
    leaf_3->setPosition(Vec2(490, 470));
    this->addChild(leaf_3, 0);

    auto rotateForward = RotateBy::create(0.5f, 30);
    auto rotateBackward = RotateBy::create(0.5f, -30);
    auto delay_2 = DelayTime::create(3.0f);

    auto rotateForward_2 = RotateBy::create(0.5f, 15);
    auto rotateBackward_2 = RotateBy::create(0.5f, -15);
    auto delay_3 = DelayTime::create(3.0f);

    // Leaf3 的动作序列，不变
    auto sequenceAction_3 = Sequence::create(rotateForward, rotateBackward, delay_3, nullptr);
    auto repeatForever_3 = RepeatForever::create(sequenceAction_3);
    leaf_3->runAction(repeatForever_3);

    // Leaf2 的动作序列，添加额外的 3 秒延迟
    auto delayBeforeStart_2 = DelayTime::create(3.0f); // Leaf3动作时间(3秒)加上其延迟时间(3秒)
    auto sequenceAction_2 = Sequence::create(delayBeforeStart_2, rotateForward_2, rotateBackward_2, delay_2, nullptr);
    auto repeatForever_2 = RepeatForever::create(sequenceAction_2);
    leaf_2->runAction(repeatForever_2);

    auto carrot_body = Sprite::create("CarrotBody.PNG");
    carrot_body->setPosition(Vec2(visibleSize.width / 2, 370));
    this->addChild(carrot_body, 0);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    /*auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }*/
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
