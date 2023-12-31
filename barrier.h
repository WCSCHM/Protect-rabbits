#pragma once
struct barrier {
	Vec2 pos;
	Sprite* type;
	bool isDestroyed = false;
	float barrierBlood = 20;
};