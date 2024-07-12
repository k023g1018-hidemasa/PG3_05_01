#pragma once
#include"IScene.h"
#include"ICommand.h"
#include"InputHandler.h"
class  StageScene :public IScene
{
private:

	InputHandle* inputHandler_ = nullptr;
	ICommand* icommand_ = nullptr;
	Player* player_;
public:
	StageScene();

	void Init()override;
	void Update()override;
	void Draw()override;


};
