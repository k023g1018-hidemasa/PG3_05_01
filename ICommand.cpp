#include "ICommand.h"

void MoveRigthCommand::Exec(Player& player)
{
	player.MoveRight();
}

void MoveLeftCommand::Exec(Player& player)
{
	player.MoveLeft();
}

ICommand::~ICommand()
{
}
