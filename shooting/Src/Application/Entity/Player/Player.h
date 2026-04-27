#pragma once

#include"../CharaBase.h"

class Player:public CharaBase
{
public:
	Player() { Init(); }
	~Player() { Release(); }

	void Init();
	void Update();
	void Action();
	void Draw();

private:

	void Release();

	float m_topRange;
	float m_bottomRange;

};