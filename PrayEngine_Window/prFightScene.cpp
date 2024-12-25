#include "prFightScene.h"
#include "prGameObject.h"
#include "prPlayer.h"
#include "prPet.h"

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
			EnemyPet->SetPosition(120+ (delX*i), 650+(delY * i));
			AddEnemyPet(EnemyPet);
		}
		
		//�÷��̾� ��ġ
		mPlayer->SetPosition(1200, 700);
		//�Ʊ� �� ��ġ
		GameObject* myPet = new PET();
		myPet->SetPosition(1000, 550);
		AddMyPet(myPet);

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
