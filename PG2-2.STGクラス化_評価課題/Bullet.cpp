#include "Bullet.h"

Bullet::Bullet() {
	pos_.x = 0;
	pos_.y = 0;
	speed_ = 10;
	radius_ = 16;
	isShot_ = FALSE;
}

void Bullet::resetBullet() {
	pos_.x = 0;
	pos_.y = 0;
	speed_ = 10;
	radius_ = 16;
	isShot_ = FALSE;
}

void Bullet::SetBullet(float x, float y) {
	pos_.x = x;
	pos_.y = y;
}

void Bullet::Update() {
	if (isShot_ == TRUE)
	{
		pos_.y -= speed_;
	}
	if (pos_.y <= -32)
	{
		isShot_ = FALSE;
	}
}

void Bullet::Draw() {
	if (isShot_ == TRUE)
	{
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), radius_, radius_, 0.0f, GREEN, kFillModeSolid);
	}
}