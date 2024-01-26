#include "Player.h"

Player::Player() {
	pos_.x = 640;
	pos_.y = 500;
	radius_ = 64;
	speed_ = 10;
	HP_ = 100;
	isAlive_ = TRUE;
}

void Player::Setpos(float x, float y) {
	this->pos_.x = x;
	this->pos_.y = y;
}

void Player::SetHP(float HP) {
	this->HP_ -= HP;
}

void Player::resetPlayer() {
	pos_.x = 640;
	pos_.y = 500;
	radius_ = 64;
	speed_ = 10;
	HP_ = 100;
	isAlive_ = TRUE;
}


void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_W] != 0)
	{
		pos_.y -= speed_;
	}
	if (keys[DIK_A] != 0)
	{
		pos_.x -= speed_;
	}
	if (keys[DIK_S] != 0)
	{
		pos_.y += speed_;
	}
	if (keys[DIK_D] != 0)
	{
		pos_.x += speed_;
	}


	if (Bullet_.GetisShot() == FALSE)
	{
		if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0)
		{
			Bullet_.SetBullet(pos_.x + Bullet_.Getradius() * 2, pos_.y);
			Bullet_.isShot_ = TRUE;
		}
	}
	Bullet_.Update();
	
}

void Player::Draw() {
	if (isAlive_ == TRUE)
	{
		Novice::DrawBox(int(pos_.x), int(pos_.y), radius_, radius_, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(10, 695, int(HP_) * 2, 20, 0.0f, BLUE, kFillModeSolid);
	}
}
