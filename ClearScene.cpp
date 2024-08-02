#include "ClearScene.h"

void ClearScene::Init()
{
	GAMECLEAR = Novice::LoadTexture("./img/nightmeaWin.png");
}

void ClearScene::Update()
{
	if(Input::GetInstance()->TriggerKey(DIK_SPACE)){
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::DrawSprite(0, 0, GAMECLEAR, 1.2f, 1.2f, 0.0f, WHITE);
}