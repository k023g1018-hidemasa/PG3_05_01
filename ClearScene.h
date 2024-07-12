#pragma once
#include"IScene.h"
#include "Input.h"

class ClearScene :public IScene
{
public:
	void Init()override;
	void Update()override;
	void Draw()override;
private:

};