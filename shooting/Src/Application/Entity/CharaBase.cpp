#include "CharaBase.h"

void CharaBase::Update()
{

	//ç¿ïWçXêV
	m_pos += m_move;

	///////////////////////////////////////////////////

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 0);
	m_rotationMat = Math::Matrix::CreateRotationZ(ToRadians(m_rotationZ));
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);

	m_mat = m_scaleMat * m_rotationMat * m_transMat;
}

void CharaBase::Release()
{

}
