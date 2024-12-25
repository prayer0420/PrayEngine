#include "prPlayScene.h"
#include "prGameObject.h"

namespace pr
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		for (size_t i = 0; i < 100; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj);
		}

	}

	void PlayScene::Update()
	{
		Scene::Update();
		//for (GameObject* gameObj : mGameObjects)
		//{
		//	gameObj->Update();
		//}
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
