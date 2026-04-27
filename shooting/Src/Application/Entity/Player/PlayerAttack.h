#pragma once

#include "../CharaBase.h"

class PlayerAttack:public CharaBase
{
public:
	PlayerAttack() { Init(); }
	~PlayerAttack() { Release(); }

	void Init();
	void Update();
	void Action();
	void Draw();

private:

	void Release();

};