#pragma once

#include "../BaseScene/BaseScene.h"

class Player;

class GameScene :public BaseScene
{
public:
	GameScene() { Init(); }
	~GameScene() { Release(); }

	void Init();
	void Update();
	void Draw();
	void Release();

	Player* m_player = nullptr;

private:

};