#include "SceneChange.h"

void SceneChange::Init()
{
	scene = Titie;
}

void SceneChange::Update()
{
	switch (scene)
	{
	case SceneType::Titie:
		break;
	case SceneType::Game:
		break;
	case SceneType::Result:
		break;
	default:
		break;
	}
}

void SceneChange::Draw()
{

}
