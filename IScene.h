#pragma once
#include"Novice.h"

//シーン名を列挙型で定義
enum SCENE {TITLE,STAGE,CLEAR};
//シーン内での処理を行う基底クラス
class IScene {
protected:
	//シーン番号を管理する変数
	static int sceneNo;

	int wide = 1280;
	int higth = 720;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
public:
	//継承先で実装される関数
	//抽象クラスなので純粋関数
	virtual void Init()=0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//仮想デストラクタを用意しないと警告される
	virtual ~IScene();

	//シーン番号のゲッター
	int GetSceneNo();

};