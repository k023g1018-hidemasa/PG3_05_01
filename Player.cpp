#include "Player.h"
#include"Novice.h"
Player::Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	Novice::DrawBox(this->pos.X, this->pos.y, 50, 50, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight()
{
	this->pos.X += this->speed;

}

void Player::MoveLeft()
{
	this->pos.X -= this->speed;

}
