#pragma once

//前方宣言
class BaseScene;

//全てのシーンを管理する
class SceneManager
{
public:

	//シーン情報
	enum SceneType
	{
		Title,
		Game
	};

	void PreUpdate();
	void Update();
	void Draw();

	void SetNextScene(SceneType _nextScene)
	{
		m_nextSceneType = _nextScene;
	}
	SceneType GetCurrentScene() const
	{
		return m_currentSceneType;
	}

private:

	void Init();
	void Release();
	void ChangeScene(SceneType _sceneType);

	std::shared_ptr<BaseScene> m_currentScene;

	//どのシーンにいるかを管理するフラグ関数
	SceneType m_currentSceneType = SceneType::Game;
	SceneType m_nextSceneType = m_currentSceneType;

	// シングルトンパターン(デザインパターン)
private:

	SceneManager() { Init(); }
	~SceneManager() { Release(); }

public:

	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}

};