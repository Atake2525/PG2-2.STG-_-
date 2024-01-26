#include "Enemy.h"

Enemy::Enemy() {
	pos_ = { 0, 0, };
	speed_ = { 8, 6 };
	radius_ = 128;
	HP_ = 100;
	hitTime = 0;
	hitCount = 0;
	HPradius_ = HP_;
	isAlive_ = TRUE;
	hitFlag_ = FALSE;
}

void Enemy::resetEnemy() {
	pos_ = { 0, 0, };
	speed_ = { 8, 6 };
	radius_ = 128;
	HP_ = 100;
	hitTime = 0;
	hitCount = 0;
	HPradius_ = HP_;
	isAlive_ = TRUE;
	hitFlag_ = FALSE;
}

void Enemy::Update(Player* Player_) {
	if (pos_.x <= 0)
	{
		speed_.x = 8;
	}
	if (pos_.x >= 1280 - radius_)
	{
		speed_.x = -8;
	}
	if (pos_.y <= 75)
	{
		speed_.y = 8;
	}
	if (pos_.y >= 720 - radius_)
	{
		speed_.y = -8;
	}
	pos_.x += speed_.x;
	pos_.y += speed_.y;
	if (HP_ <= 0)
	{
		isAlive_ = FALSE;
	}
	if (Player_->Bullet_.isShot_ == TRUE)
	{
		if (pos_.x + radius_ > Player_->Bullet_.GetBullet().x && pos_.x < Player_->Bullet_.GetBullet().x + Player_->Bullet_.Getradius()){
			if (pos_.y + radius_ > Player_->Bullet_.GetBullet().y && pos_.y < Player_->Bullet_.GetBullet().y + Player_->Bullet_.Getradius()) {
				hitCount++;
				HP_ -= 10;
				Player_->Bullet_.SetBullet(-10, -10);
				Player_->Bullet_.isShot_ = FALSE;
			}
		}
	}
	if (hitFlag_ == FALSE)
	{
		if (pos_.x + radius_ > Player_->Getpos().x && pos_.x < Player_->Getpos().x + Player_->Getradius()) {
			if (pos_.y + radius_ > Player_->Getpos().y && pos_.y < Player_->Getpos().y + Player_->Getradius()) {
				hitFlag_ = TRUE;
			}
		}
	}
	if (hitFlag_ == TRUE)
	{
 		hitTime++;
	}
	if (hitTime == 1)
	{
		Player_->SetHP(10);
	}
	if (hitTime >= 60)
	{
		hitFlag_ = FALSE;
		hitTime = 0;
	}

}

void Enemy::Draw() {
	if (isAlive_ == TRUE)
	{
		Novice::DrawBox(int(pos_.x), int(pos_.y), radius_, radius_, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(140, 25, int(HP_) * 10, 50, 0.0f, RED, kFillModeSolid);
		Novice::DrawBox(139, 24, int(HPradius_) * 10 + 1, 52, 0.0f, BLACK, kFillModeWireFrame);
	}
}