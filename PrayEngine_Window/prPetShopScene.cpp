#include "prPetShopScene.h"
#include "prGameObject.h"
#include "prNPC.h"
#include "prTransform.h"
#include "prSpriteRenderer.h"
#include "prUI.h"

namespace pr
{
	PetShopScene::PetShopScene()
	{
	}
	PetShopScene::~PetShopScene()
	{
	}
	void PetShopScene::Initialize()
	{
		for (int i = 0; i < 2; i++)
		{
			GameObject* npc = new NPC();
			Transform* tr = npc->AddComponent<Transform>();

			tr->SetPos({ 300 + (i * 200) , 350 + (i * -200) });

			tr->SetName(L"TR");

			SpriteRenderer* sr = npc->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			AddNPC(npc);
		}

		{
			Transform* tr = mPlayer->GetComponent<Transform>();
			tr->SetPos({ 1300, 600 });
		}


		//���
		{
			UI* bg = new UI();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\Users\\User\\Desktop\\WinApi\\PrayEngine\\Resources\\tile.bmp");

			AddUI(bg);
		}


		Scene::Initialize();
	}
	void PetShopScene::Update()
	{
		Scene::Update();
	}
	void PetShopScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PetShopScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}