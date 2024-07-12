#include "InputHandler.h"
#include"Novice.h"

void InputHandle::AssignMoveLeftCommand2PressKeyA()
{
	ICommand* command = new MoveLeftCommand();
	this->presskeyA_ = command;
}

void InputHandle::AssignMoveRightCommand2PressKeyD()
{
	ICommand* command = new MoveRigthCommand();
	this->pressKeyD_ = command;
}

ICommand* InputHandle::HandleInput()
{
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}
	else if (Novice::CheckHitKey(DIK_A)) {
		return presskeyA_;
	}
	return nullptr;
}