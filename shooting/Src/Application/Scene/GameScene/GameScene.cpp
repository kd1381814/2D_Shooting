#include "GameScene.h"

#include "../SceneManager.h"
#include "../../Entity/Player/Player.h"

void GameScene::Init()
{
	m_backTex.Load("Texture/Gui/Background.png");
	m_tex.Load("Texture/Scene/GameScene1.png");

	m_backScale = { 1,1 };
	m_backRotationZ = 0;
	m_backPos = { 0,0 };

	m_scale = { 1,1 };
	m_rotationZ = 0;
	m_pos = {0,65};

	m_player = new Player();
}

void GameScene::Update()
{
	m_scaleMat = Math::Matrix::CreateScale(m_backScale.x, m_backScale.y, 0);
	m_rotationMat = Math::Matrix::CreateRotationZ(ToRadians(m_backRotationZ));
	m_transMat = Math::Matrix::CreateTranslation(m_backPos.x, m_backPos.y, 0);

	m_backMat = m_scaleMat * m_rotationMat * m_transMat;

	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 0);
	m_rotationMat = Math::Matrix::CreateRotationZ(ToRadians(m_rotationZ));
	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);

	m_mat = m_scaleMat * m_rotationMat * m_transMat;

	m_player->Update();
}

void GameScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_backMat);
	SHADER.m_spriteShader.DrawTex(&m_backTex, { 0,0,1280,720 }, 1.0f);

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, { 0,0,1279,590 }, 1.0f);

	m_player->Draw();
}

void GameScene::Release()
{
	m_backTex.Release();
	m_tex.Release();

	if (m_player)
	{
		delete m_player;
		m_player = nullptr;
	}
}