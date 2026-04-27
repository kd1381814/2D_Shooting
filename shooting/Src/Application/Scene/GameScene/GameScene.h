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

	std::shared_ptr<Player> m_player;

private:

};