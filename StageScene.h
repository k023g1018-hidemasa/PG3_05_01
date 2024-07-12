#pragma once
#include "Input.h"
#include"IScene.h"
class StageScene :public IScene
{
public:
	void Init()override;
	void Update()override;
	void Draw()override;
private:
	int playerPosX;
	int playerPosY;
	int playerSpeedX;
	int playerSpeedY;
	int playerR;
	//-----------------------------------------プレイヤーの位置とスピード
	int screenSpeedX;
	int screenSpeedY;
	//-----------------------------------------------スクリーン用の速度
	int bulletPosX;
	int bulletPosY;
	int bulletSpeedY;
	int bulletR;
	//-------------------------------------------------弾の位置とスピードと半径
	bool bulletShot;
	//------------------------------------------------------------弾の宣言
	int enemyPosX;
	int enemyPosY;
	int enemySpeed;
	int enemyR;
	//--------------------------------------------------------敵の座標スピード半径--------------
	bool enemyAlive;
	//-----------------------------------------------------敵が生きているか-----------
	int enemyRespawnTimer;
	//---------------------------------------------------------------------------------------------
	int distance;
	//－－－－－－－－－－－－－－－－－－－－－－－－－－－－－敵と弾との距離----------------------------------更新処理に移動135
	int bulletRANDenemyR;
	//------------------------敵と弾のが当たっているかの距離---------------------------
	int explode;
	bool explodeIsTrue;
	//--------------------------------------------------------------------爆発のフラグ（爆発してるかどうか）

};