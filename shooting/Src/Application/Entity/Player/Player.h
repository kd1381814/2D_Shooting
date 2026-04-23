#pragma once

#include"../CharaBase.h"

class Player:public CharaBase
{
public:
	Player() {}
	~Player() { Release(); }

	void Init();
	void Update();
	void Action();
	void Draw();

private:

	void Release();

};