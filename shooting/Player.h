#pragma once

class CharaBase;

class Player :public CharaBase
{
public:
	Player() {}
	~Player() {}

	void Init();
	void Update();
	void Draw();

private:

};