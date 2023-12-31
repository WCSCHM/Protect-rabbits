#pragma once
#include "cocos2d.h"
#include<vector>
using namespace cocos2d;

class Adventure :public Scene
{
public:
	static Scene* createScene();

	virtual bool init();

	void callBack(Ref* pSender);

	void rightTranslation(Ref* pSender);

	void leftTranslation(Ref* pSender);

	void callMap1(Ref* pSender);


	CREATE_FUNC(Adventure);
private:
	std::vector<Sprite*>mapArray;
};
