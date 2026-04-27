#pragma once

class CharaBase
{
public:
	CharaBase() {}
	~CharaBase() { Release(); }

	virtual void Update();

protected:

	void Release();

	//•Ï”
	KdTexture m_tex;			
	Math::Vector2	m_pos;			//À•W
	Math::Vector2	m_move;			//ˆÚ“®—Ê
	Math::Vector2	m_scale;		//Šg‘å—¦
	float			m_rotationZ;	//‰ñ“]—¦
	float			m_moveSpeed;	
	bool			m_alive;

	//s—ñ
	Math::Matrix	m_scaleMat;
	Math::Matrix	m_rotationMat;
	Math::Matrix	m_transMat;
	Math::Matrix	m_mat;

};
