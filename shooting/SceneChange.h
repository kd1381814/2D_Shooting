#pragma once
enum SceneType {
	Titie, Game, Result
};

class SceneChange
{
public:
	SceneChange() {}
	~SceneChange() {}

	void Init();
	void Update();
	void Draw();

private:
	SceneType scene;

};