#include "prFightScene.h"
#include "prGameObject.h"
#include "prPet.h"
#include "prPlayer.h"
#include "prTransform.h"
#include "prSpriteRenderer.h"

namespace pr
{
	FightScene::FightScene()
	{
	}
	FightScene::~FightScene()
	{
	}
	void FightScene::Initialize()
	{
		float delY = -150.0f;
		float delX = 120.0f;

		//�� �� ��ġ
		for (int i = 0; i < 5; i++)
		{
			GameObject* EnemyPet = new PET();
			Transform* tr = EnemyPet->AddComponent<Transform>();
			tr->SetPos(120 + (delX * i), 650 + (delY * i));
			tr->SetName(L"TR");

			SpriteRenderer* sr = EnemyPet->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddEnemyPet(EnemyPet);
		}
		
		//�÷��̾� ��ġ
		{
			Transform* tr = mPlayer->GetComponent<Transform>();
			tr->SetPos(1200, 700);
		}

		//�Ʊ� �� ��ġ
		{
			GameObject* myPet = new PET();
			Transform* tr = myPet->AddComponent<Transform>();
			tr->SetPos(1000, 550);

			tr->SetName(L"TR");

			SpriteRenderer* sr = myPet->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddMyPet(myPet);
		}



		Scene::Initialize();
	}
	void FightScene::Update()
	{
		Scene::Update();
	}
	void FightScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void FightScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
