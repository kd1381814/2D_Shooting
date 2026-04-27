#pragma once

#include "../CharaBase.h"

class PlayerAttack:public CharaBase
{
public:
	PlayerAttack() { Init(); }
	~PlayerAttack() { Release(); }

	void Init();
	void Update();

	//発射
	void Spawn(const Math::Vector2& pos, const Math::Vector2& vel);
	////////////////////////////////////////////////////

	void Action();
	void Draw();

private:

	void Release();

	/////////////////////////////////////////////////
	struct Bullet {
		Math::Vector2	pos;
		Math::Vector2	move;
		Math::Vector2	scale{ 1.5f, 1.5f };
		float			rotationZ = 0.0f;
		bool			alive = false;
		Math::Matrix	mat;
		Math::Matrix	scaleMat;
		Math::Matrix	rotationMat;
		Math::Matrix	transMat;
	};

	std::vector<Bullet>	m_bullets;
	size_t				m_poolSize = 256;   // 初期プールサイズ（必要に応じて変更）
	bool				m_autoExpand = false; // true にするとプール満杯時に拡張する
	///////////////////////////////////////////////////

	float m_coolDown;

};