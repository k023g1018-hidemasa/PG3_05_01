#pragma once
#include"IScene.h"
#include "Input.h"
class TitleScene:public IScene
{
public:
	void Init()override;
	void Update()override;
	void Draw()override;
private:
	int title;
};

