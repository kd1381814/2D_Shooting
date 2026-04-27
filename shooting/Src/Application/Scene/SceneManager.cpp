#include "SceneManager.h"

// 各シーンのヘッダーをインクルード
#include "GameScene/GameScene.h"

void SceneManager::PreUpdate()
{
	//シーン切り替え
	if (m_currentSceneType != m_nextSceneType)
	{
		ChangeScene(m_nextSceneType);
	}
}

void SceneManager::Update()
{
	m_currentScene->Update();
}


void SceneManager::Draw()
{
	m_currentScene->Draw();
}

void SceneManager::Init()
{
	ChangeScene(m_currentSceneType);
}

void SceneManager::Release()
{
}

void SceneManager::ChangeScene(SceneType _sceneType)
{
	//①次のシーンを作成　②フラグを更新する

	//①
	switch (_sceneType)
	{
	case SceneManager::Title:
		
		break;
	case SceneManager::Game:
		m_currentScene = std::make_shared<GameScene>();
		break;
	default:
		break;
	}

	//②フラグ更新
	m_currentSceneType = _sceneType;

}
