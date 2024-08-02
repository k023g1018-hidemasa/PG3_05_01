#include "TitleScene.h"

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	title=Novice::LoadTexture("./img/startScreen.png");//スタート画面
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::DrawSprite(0, 0, title, 2.0f, 2.0f, 0.0f, WHITE);
}
