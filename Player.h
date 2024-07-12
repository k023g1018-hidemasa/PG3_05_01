#pragma once
struct Vector2
{
	int X;
	int y;
};
class Player
{
public:
	Player();

	void Init();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();

private:
	Vector2 pos = {300,300};
	int speed=5;
	




};

