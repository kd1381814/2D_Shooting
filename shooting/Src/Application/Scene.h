#pragma once

class Scene
{
private:
	FILE* fp_c;
	static const int ScrWidth = 1280;
	static const int ScrHeight = 720;

public:

	// ‰Šúİ’è
	void Init();

	// XVˆ—
	void Update();

	// •`‰æˆ—
	void Draw2D();

	// ‰ğ•ú
	void Release();

	// GUIˆ—
	void ImGuiUpdate();

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
