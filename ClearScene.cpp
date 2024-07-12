#include "ClearScene.h"

void ClearScene::Init()
{
}

void ClearScene::Update()
{
	if(Input::GetInstance()->TriggerKey(DIK_SPACE)){
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::DrawBox(0, 0, wide, higth, 0.0f, GREEN, kFillModeSolid);
}