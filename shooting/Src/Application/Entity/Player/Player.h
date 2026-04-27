#pragma once

#include"../CharaBase.h"

class PlayerAttack;

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
	bool m_attack;

	//UŒ‚‚Ìƒ|ƒCƒ“ƒ^
	std::shared_ptr<PlayerAttack> m_playerAtk;

};