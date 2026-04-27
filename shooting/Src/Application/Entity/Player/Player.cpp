#include "Player.h"
#include "PlayerAttack.h"

void Player::Init()
{
	m_tex.Load("Texture/Entity/Player/Idle.png");

	m_scale = {1.5f,1.5f};
	m_rotationZ = 0;
	m_pos = {};
	m_move = {};
	m_moveSpeed = 5;
	m_alive = true;
	m_attack = false;

	m_topRange = 300;
	m_bottomRange = -170;

	//攻撃初期化
	m_playerAtk = std::make_shared<PlayerAttack>();
}

void Player::Update()
{
	if (!m_alive)return;

	// 移動
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_pos.x = 500;
		m_scale.x *= -1;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_pos.x = -500;
		m_scale.x *= -1;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_move.y = m_moveSpeed;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_move.y = -m_moveSpeed;
	}

	//攻撃(スペース)
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		m_attack = true;
	}

	//座標更新
	m_pos += m_move;
	m_move = {};

	if (m_pos.y >= m_topRange)
	{
		m_pos.y = m_topRange;
	}
	if (m_pos.y <= m_bottomRange)
	{
		m_pos.y = m_bottomRange;
	}

	///////////////////////////////////////////////////

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 0);
	m_rotationMat = Math::Matrix::CreateRotationZ(ToRadians(m_rotationZ));
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);

	m_mat = m_scaleMat * m_rotationMat * m_transMat;

	//攻撃更新
	if (m_attack)
	{
		m_playerAtk->Update();
	}
}

void Player::Action()
{
	
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, { 0,0,100,100 }, 1.0f);

	//攻撃描画
	if (m_attack)
	{
		m_playerAtk->Draw();
	}
}

void Player::Release()
{
	m_tex.Release();
}
