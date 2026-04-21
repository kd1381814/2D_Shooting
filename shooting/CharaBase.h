#pragma once

class CharaBase
{
public:
	CharaBase() {}
	~CharaBase() {}

	virtual void Init();
	virtual void Update();
	virtual void Draw();

protected:
	KdTexture* m_tex;
	Math::Vector2	m_pos;
	Math::Vector2	m_move;
	Math::Vector2	m_scale;
	float			m_rotationZ;

	Math::Matrix	m_scaleMat;
	Math::Matrix	m_rotationMat;
	Math::Matrix	m_transMat;
	Math::Matrix	m_mat;

};