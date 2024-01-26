#pragma once
#include "Novice.h"
#include "Vector2.h"

class Bullet
{
public:
	Bullet();
	void Update();
	void SetBullet(float x, float y);
	void resetBullet();
	char GetisShot() { return isShot_; }
	int Getradius() { return radius_; }
	Vector2 GetBullet() { return pos_; }
	void Draw();
	char isShot_;
private:
	Vector2 pos_;
	float speed_;
	int radius_;

};

