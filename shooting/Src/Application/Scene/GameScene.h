#pragma once

class Player;

class GameScene
{
public:
	GameScene() {}
	~GameScene() { Release(); }

	void Init();
	void Update();
	void Draw();

	Player* m_player = nullptr;

private:

	void Release();

};