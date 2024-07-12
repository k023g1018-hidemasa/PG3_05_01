﻿#include "StageScene.h"

void StageScene::Init()
{
	 playerPosX = 500;
	 playerPosY = 300;
	 playerSpeedX = 10;
	 playerSpeedY = 10;
	 playerR = 50;
	//-----------------------------------------プレイヤーの位置とスピード
	 screenSpeedX = 0;
	 screenSpeedY = 0;
	//----------------------------------------------スクリーン用の速度
	 bulletPosX = 500;
	 bulletPosY = 500;
	 bulletSpeedY = 10;
	 bulletR = 20;
	//------------------------------------------------弾の位置とスピードと半径
	 bulletShot = false;
	//-----------------------------------------------------------弾の宣言
	 enemyPosX = 400;
	 enemyPosY = 100;
	 enemySpeed = 5;
	 enemyR = 20;
	//-------------------------------------------------------敵の座標スピード半径--------------
	 enemyAlive = true;
	//----------------------------------------------------敵が生きているか-----------
	 enemyRespawnTimer = 120;
	//--------------------------------------------------------------------------------------------
	 distance = 0;
	//－－－－－－－－－－－－－－－－－－－－－－－－－－－－敵と弾との距離----------------------------------更新処理に移動135
	 bulletRANDenemyR = (bulletR + enemyR) * (bulletR + enemyR);
	//-----------------------敵と弾のが当たっているかの距離---------------------------
	 explode = Novice::LoadTexture("./explode.png");
	 explodeIsTrue = 0;
	//--------------------------------------------------------------------爆発のフラグ（爆発してるかどうか）




}

void StageScene::Update()
{
	if (keys[DIK_W]) {
		playerPosY += -playerSpeedY;
	}//上方向 下にもELSEを使ったら下が適応され続けてうえのスピードが使えなくなる//スピード表示用の数をｉｎｔして解決
	if (keys[DIK_S]) {
		playerPosY += playerSpeedY;
	}	//下方向
	if (keys[DIK_D]) {
		playerPosX += playerSpeedX;
	}//右方向　上に同じく
	if (keys[DIK_A]) {
		playerPosX += -playerSpeedX;
	}//左方向
	//-------------------------------------------------------player移動設定-----------//
	if (keys[DIK_W]) {
		screenSpeedY = -10;
	}
	else {
		screenSpeedY = 0;
	}//上方向 下にもELSEを使ったら下が適応され続けてうえのスピードが使えなくなる//スピード表示用の数をｉｎｔして解決
	if (keys[DIK_S]) {
		screenSpeedY = 10;
	}	//下方向
	if (keys[DIK_D]) {
		screenSpeedX = 10;
	}
	else {
		screenSpeedX = 0;
	}//右方向　上に同じく
	if (keys[DIK_A]) {
		screenSpeedX = -10;
	}//左方向
	//－－－－－－－-------------------------------------プレイヤーの速度観測用ＳＰＥＥＤ-------------//
	if (enemyAlive == true) {//敵が生きているとき、動く
		enemyPosX += enemySpeed;
	}
	if (enemyPosX > 1230) {//右の壁についたときに反転
		enemySpeed = -5;
	}
	if (enemyPosX < 50) {//左の壁についたとき反転
		enemySpeed = 5;
	}

	//--------------------------------------------------------敵の動き--------------------------------
	if (playerPosX > 1230) {
		playerPosX = playerPosX - 10;
	}
	if (playerPosX < 0) {
		playerPosX = playerPosX + 10;
	}
	if (playerPosY > 670) {
		playerPosY = playerPosY - 10;
	}
	if (playerPosY < 50) {
		playerPosY = playerPosY + 10;
	}
	//--------------------壁の当たり判定------------------------------------------//
	if (bulletPosY < -bulletR) {
		bulletPosY = bulletPosY + 10;
	}
	//------------壁の当たり判定、弾版------------------------------------------//

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && bulletShot == false) {//ここをbulletShotに変えたら弾が止まる　解決　true(1)なので座標がずっとplayerPosXでとまってしまう
		//↑鍵　bulletShotが0のときしかうごかない
		bulletPosX = playerPosX;//ここが機能してない解決、数が入ってはいたけど下のスピードに書き換えられてた
		bulletPosY = playerPosY;
		bulletShot = true;
	}//PLの座標を入れた//弾の位置
		if (bulletShot) {
		bulletPosY += -bulletSpeedY;//余分な文を消した、PlayerSpeedに上書きされてたので消して、スピードを足し続けるに変えた
	}//ここで弾のスピードを入れる
	if (bulletPosY <= -bulletR)
	{
		bulletShot = false;
	}//弾消し
	//-------------------------------------------------------弾の処理------------------------------------------
	distance = (bulletPosX - enemyPosX) * (bulletPosX - enemyPosX) + (bulletPosY - enemyPosY) * (bulletPosY - enemyPosY);//弾と敵の距離

	if (bulletRANDenemyR >= distance) {//(本当は以下)敵が消える
		enemyAlive = false;
	}
	//-----------------------------------------------------弾と敵のあたり判定---------------

	if (enemyAlive == false && enemyRespawnTimer <= 0) {//敵が死んだときとタイマーがゼロになった時に敵が復活
		enemyAlive = true;
		enemyRespawnTimer = 120;//タイマー初期化120フレーム
	}
	if (enemyRespawnTimer < 120 && enemyRespawnTimer >= 30) {//30～120フレーム(残り時間)の時
		explodeIsTrue = 1;//爆発を描画（true）
	}
	else {
		explodeIsTrue = 0;//描画しない
	}
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		sceneNo = CLEAR;
	}


}

void StageScene::Draw()
{
	Novice::DrawBox(0, 0, wide, higth, 0.0f, RED, kFillModeSolid);
	if (bulletShot) {
		Novice::DrawTriangle(bulletPosX, bulletPosY - bulletR,
			bulletPosX - bulletR, bulletPosY + bulletR,
			bulletPosX + bulletR, bulletPosY + bulletR,
			RED, kFillModeSolid);
	}
	//弾------------------------------------------------------------------------------------↑
	Novice::DrawBox(playerPosX, playerPosY, playerR, playerR, 0.0f, WHITE, kFillModeSolid);
	//自機-----------------------------------------------------------------↑

	if (enemyAlive == true) {//生きているとき表示
		//Novice::DrawBox(enemyPosX+enemyR/2, enemyPosY+enemyR/2, enemyR, enemyR, 0.0f, BLACK, kFillModeSolid);//sikaku
		Novice::DrawEllipse(enemyPosX, enemyPosY, enemyR, enemyR, 0.0f, BLACK, kFillModeSolid);//sannkaku
	}
	else if (enemyAlive == false) {//敵が死んだとき

		enemyRespawnTimer--;//タイマーを縮める
	}//死んでいるときリスポーンタイマーを縮める
	if (explodeIsTrue == 1) {
		Novice::DrawSprite(enemyPosX - enemyR, enemyPosY - enemyR, explode, 1.0f, 1.0f, 0.0f, 0xffffffff);
	}
	//敵－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－↑


	Novice::ScreenPrintf(20, 10, "sousaWASD　　speedX%d/Y%d", screenSpeedX, screenSpeedY);//操作方法と自機のスピード
	Novice::ScreenPrintf(20, 30, "posisyon X%d/Y%d", playerPosX, playerPosY);//自機の場所
	Novice::ScreenPrintf(20, 50, "BaretP X%d/Y%d", bulletPosX, bulletPosY);//弾の場所
	Novice::ScreenPrintf(20, 70, "Bullet %d", bulletShot);//弾は発射されているか？
	Novice::ScreenPrintf(20, 90, "distance %f", sqrtf((float)distance));//弾と敵の距離
	Novice::ScreenPrintf(20, 110, "playerRANDenemyR %f", sqrtf((float)bulletRANDenemyR));//岸先作　弾と敵の半径の距離
	Novice::ScreenPrintf(20, 130, "RESframe%d bakuhatusiteiruka%d", enemyRespawnTimer, explodeIsTrue);
	//----------------------------------------------表示画面↑


}
