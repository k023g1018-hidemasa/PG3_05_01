#include "TitleScene.h"

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::DrawBox(0, 0, wide, higth, 0.0f, BLUE, kFillModeSolid);
}
