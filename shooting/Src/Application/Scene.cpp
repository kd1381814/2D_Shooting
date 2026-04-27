#include "main.h"
#include "Scene.h"

#include "Scene/SceneManager.h"

void Scene::Init()
{

}

void Scene::Update()
{

	SceneManager::Instance().PreUpdate();

	SceneManager::Instance().Update();

}

void Scene::Draw2D()
{
	SceneManager::Instance().Draw();
}

void Scene::Release()
{

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
