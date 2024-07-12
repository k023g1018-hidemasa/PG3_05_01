#include "GameManager.h"
#include"Novice.h"
//コンストラクタ
GameManager::GameManager()
{
	//各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();
	//初期シーン設定
	currentSceneNo_ = TITLE;
}

GameManager::~GameManager()
{
}

int GameManager::Run()
{
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	while (Novice::ProcessMessage()==0)
	{
		// フレームの開始	
		Novice::BeginFrame();
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		
		//シーンチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		//シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}
		sceneArr_[currentSceneNo_]->Update();//シーンごとの更新処理

		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();//ループ終了

		//ESCでゲームを抜ける
		if(preKeys[DIK_ESCAPE]==0&&keys[DIK_ESCAPE]!=0){
			break;
		}
	}

	return 0;
}
