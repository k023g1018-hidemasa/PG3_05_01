#pragma once

#include<memory>//STD::uniqueを使うために
#include"IScene.h"//シーンの基底クラスに加えて
#include"StageScene.h"//各しーんを読み込む
#include"TitleScene.h"
#include"ClearScene.h"


class GameManager
{
private:
	//シーンを保持してくれるメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	//度のステージを呼び出すかを管理
	int currentSceneNo_;//現在のしーん
	int prevSceneNo_;//前のシーン

public:
	GameManager();
	~GameManager();

	int Run();//この関数でゲームループを呼び出す
};

