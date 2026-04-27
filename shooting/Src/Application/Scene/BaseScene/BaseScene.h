#pragma once

class BaseScene
{
public:
	BaseScene() {}
	virtual ~BaseScene() {}

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();

protected:
	KdTexture m_tex;
	KdTexture m_backTex;
	Math::Vector2	m_pos;			//À•W
	Math::Vector2	m_scale;		//Šg‘å—¦
	float			m_rotationZ;	//‰ñ“]—¦

	Math::Vector2	m_backPos;			//À•W
	Math::Vector2	m_backScale;		//Šg‘å—¦
	float			m_backRotationZ;	//‰ñ“]—¦

	//s—ñ
	Math::Matrix	m_scaleMat;
	Math::Matrix	m_rotationMat;
	Math::Matrix	m_transMat;
	Math::Matrix	m_mat;
	Math::Matrix	m_backMat;

};