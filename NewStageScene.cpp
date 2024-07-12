#include "NewStageScene.h"

StageScene::StageScene()
{
}

void StageScene::Init()
{
	inputHandler_ = new InputHandle();

	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();

	player_ = new Player();

}

void StageScene::Update()
{
	icommand_ = inputHandler_->HandleInput();

	if (this->icommand_) {
		icommand_->Exec(*player_);
	}
	player_->Update();
}

void StageScene::Draw()
{
	player_->Draw();

}
