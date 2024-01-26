#pragma once
#include "Novice.h"
#include "Vector2.h"
#include "Bullet.h"
#include "Player.h"

class Enemy
{
public:
	Enemy();
	void Update(Player* Player_);
	void Draw();
	void resetEnemy();
	char GetisAlive() { return isAlive_; }
	Vector2 GetEnemyPos() { return pos_; }
	int Getradius() { return radius_; }
private:
	Vector2 pos_;
	Vector2	speed_;
	int radius_;
	float HP_;
	float hitTime;
	float hitCount;
	float HPradius_;
	char isAlive_;
	char hitFlag_;
};

