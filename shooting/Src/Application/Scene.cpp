#include "main.h"
#include "Scene.h"
#include "Scene/GameScene.h"

void Scene::Init()
{
	m_gameScene = new GameScene();
	m_gameScene->Init();
}

void Scene::Update()
{
	m_gameScene->Update();
}

void Scene::Draw2D()
{
	m_gameScene->Draw();
}

void Scene::Release()
{
	if(m_gameScene)
	{
		delete m_gameScene;
		m_gameScene = nullptr;
	}
}

void Scene::ImGuiUpdate()
{

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
