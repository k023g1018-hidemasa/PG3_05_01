#pragma once
#include<Player.h>
class Player;

class ICommand
{
public:
	virtual ~ICommand();
	virtual void Exec(Player& player) = 0;
};

class MoveRigthCommand:public ICommand
{
public:

	void Exec(Player& player)override;


private:

};
class MoveLeftCommand :public ICommand {
public:
	void Exec(Player& player)override;
};




