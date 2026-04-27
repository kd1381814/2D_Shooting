#include "PlayerAttack.h"

void PlayerAttack::Init()
{
	m_tex.Load("Texture/Entity/Player/Move.png");

	m_scale = {1.5f,1.5f};
	m_rotationZ = 0;
	m_pos = {};
	m_move = {0,0};
	m_moveSpeed = 5;
	m_alive = true;
}

void PlayerAttack::Update()
{
	//ç¿ïWçXêV
	m_pos += m_move;

	///////////////////////////////////////////////////

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 0);
	m_rotationMat = Math::Matrix::CreateRotationZ(ToRadians(m_rotationZ));
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);

	m_mat = m_scaleMat * m_rotationMat * m_transMat;
}

void PlayerAttack::Action()
{

}

void PlayerAttack::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, { 0,0,24,5 }, 1.0f);
}

void PlayerAttack::Release()
{
	m_tex.Release();
}
