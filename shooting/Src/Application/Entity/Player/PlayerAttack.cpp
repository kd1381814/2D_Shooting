#include "PlayerAttack.h"

void PlayerAttack::Init()
{
	m_tex.Load("Texture/Entity/Player/Move.png");

	/*m_scale = {1.5f,1.5f};
	m_rotationZ = 0;
	m_pos = {};
	m_move = {0,0};
	m_moveSpeed = 5;
	m_alive = true;*/

	// プールを確保して初期化
	m_bullets.resize(m_poolSize);
	for (size_t i = 0; i < m_bullets.size(); ++i) {
		m_bullets[i].alive = false;
	}
	//////////////////////////////////

	m_coolDown = 0;
}

void PlayerAttack::Update()
{

	// 各弾を更新
	for (size_t i = 0; i < m_bullets.size(); ++i) {
		Bullet& b = m_bullets[i];
		if (!b.alive) continue;

		// 位置更新
		b.pos += b.move;

		// 行列更新
		b.scaleMat = Math::Matrix::CreateScale(b.scale.x, b.scale.y, 0);
		b.rotationMat = Math::Matrix::CreateRotationZ(ToRadians(b.rotationZ));
		b.transMat = Math::Matrix::CreateTranslation(b.pos.x, b.pos.y, 0);
		b.mat = b.scaleMat * b.rotationMat * b.transMat;

		// 画面外や無効条件で消す（画面サイズに合わせて調整）
		const float limit = 2000.0f;
		if (fabsf(b.pos.x) > limit || fabsf(b.pos.y) > limit) {
			b.alive = false;
		}
	}
	////////////////////////////////////////////////////////////

	// （不要）削除は行わない。alive=false にして再利用する設計なので erase しない。


	////座標更新
	//m_pos += m_move;

	/////////////////////////////////////////////////////

	//m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 0);
	//m_rotationMat = Math::Matrix::CreateRotationZ(ToRadians(m_rotationZ));
	//m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);

	//m_mat = m_scaleMat * m_rotationMat * m_transMat;
}

void PlayerAttack::Spawn(const Math::Vector2& pos, const Math::Vector2& vel)
{
	if(m_coolDown>=7)
	{
		m_coolDown = 0;

		// 空きスロットを探す
		for (size_t i = 0; i < m_bullets.size(); ++i) {
			Bullet& b = m_bullets[i];
			if (!b.alive) {
				b.pos = pos;
				b.move = vel;
				b.scale = Math::Vector2{ 1.5f, 1.5f };
				b.rotationZ = 0.0f;
				b.alive = true;

				b.scaleMat = Math::Matrix::CreateScale(b.scale.x, b.scale.y, 0);
				b.rotationMat = Math::Matrix::CreateRotationZ(ToRadians(b.rotationZ));
				b.transMat = Math::Matrix::CreateTranslation(b.pos.x, b.pos.y, 0);
				b.mat = b.scaleMat * b.rotationMat * b.transMat;
				return;
			}
		}

		// 空きがない場合のポリシー
		if (m_autoExpand) {
			Bullet nb;
			nb.pos = pos;
			nb.move = vel;
			nb.scale = Math::Vector2{ 1.5f, 1.5f };
			nb.rotationZ = 0.0f;
			nb.alive = true;
			nb.scaleMat = Math::Matrix::CreateScale(nb.scale.x, nb.scale.y, 0);
			nb.rotationMat = Math::Matrix::CreateRotationZ(ToRadians(nb.rotationZ));
			nb.transMat = Math::Matrix::CreateTranslation(nb.pos.x, nb.pos.y, 0);
			nb.mat = nb.scaleMat * nb.rotationMat * nb.transMat;
			m_bullets.push_back(nb);
		}
		// m_autoExpand == false の場合は発射を無視（または上書きポリシーを実装しても良い）
	}

	m_coolDown += 1;
}


void PlayerAttack::Action()
{
	// 自動連射や発射間隔をここで実装する場合はここに
}

void PlayerAttack::Draw()
{
	///////////////////////////////////////////
	for (size_t i = 0; i < m_bullets.size(); ++i) {
		Bullet& b = m_bullets[i];
		if (!b.alive) continue;
		SHADER.m_spriteShader.SetMatrix(b.mat);
		SHADER.m_spriteShader.DrawTex(&m_tex, { 0,0,24,5 }, 1.0f);
	}
	///////////////////////////////////////////

	//SHADER.m_spriteShader.SetMatrix(m_mat);
	//SHADER.m_spriteShader.DrawTex(&m_tex, { 0,0,24,5 }, 1.0f);
}

void PlayerAttack::Release()
{
	m_tex.Release();
	////////////////////
	m_bullets.clear();
	/////////////////////
}
