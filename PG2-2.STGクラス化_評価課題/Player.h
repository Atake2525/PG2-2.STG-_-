#pragma once
#include "Novice.h"
#include "Vector2.h"
#include "Bullet.h"

class Player
{
public:
	Player();
	void Update(char* keys, char* preKeys);
	void Setpos(float x, float y);
	void SetHP(float HP);
	void resetPlayer();
	void Draw();
	int Getradius() { return radius_; }
	float GetHP() { return HP_; }
	Vector2 Getpos() { return pos_; }
public:
	Bullet Bullet_;
private:
	Vector2 pos_;
	float speed_;
	float HP_;
	int radius_;
	char isAlive_;
};

