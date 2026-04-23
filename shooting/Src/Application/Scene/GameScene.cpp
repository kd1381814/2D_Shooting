#include "GameScene.h"
#include "../Entity/Player/Player.h"

void GameScene::Init()
{
	m_player = new Player();
	m_player->Init();
}

void GameScene::Update()
{
	m_player->Update();
}

void GameScene::Draw()
{
	m_player->Draw();
}

void GameScene::Release()
{
	if (m_player)
	{
		delete m_player;
		m_player = nullptr;
	}
}
