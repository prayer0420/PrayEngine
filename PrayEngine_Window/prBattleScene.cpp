#include "prBattleScene.h"
#include "prGameObject.h"
#include "prMyPet.h"
#include "prPlayer.h"
#include "prTransform.h"
#include "prSpriteRenderer.h"
#include "prUI.h"
#include "prObject.h"
#include "prEnemyPet.h"
#include "prTexture.h"
#include "prResources.h"

namespace pr
{
	BattleScene::BattleScene()
	{
	}
	BattleScene::~BattleScene()
	{
	}
	void BattleScene::Initialize()
	{
		float delY = -150.0f;
		float delX = 120.0f;

		//�� �� ��ġ
		for (int i = 0; i < 5; i++)
		{
			GameObject* enemyPet = object::Instantiate<EnemyPet>(enums::eLayerType::EnemyPet, 
									Vector2({ 120 + (delX * i), 650 + (delY * i) }));

			SpriteRenderer* sr = enemyPet->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			//AddEnemyPet(enemyPet, enums::eLayerType::EnemyPet);
		}
		
		//�÷��̾� ��ġ
		{
			GameObject* player = object::Instantiate<Player>(enums::eLayerType::Player,Vector2(1200, 700));

			SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			//AddPlayer(player, enums::eLayerType::Player);
		}

		//�Ʊ� �� ��ġ
		{
			GameObject* myPet = object::Instantiate<MyPet>(enums::eLayerType::MyPet, Vector2(1000, 550));

			SpriteRenderer* sr = myPet->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			//AddMyPet(myPet, enums::eLayerType::MyPet);
		}

		//���
		{
			GameObject* bg = object::Instantiate<UI>(enums::eLayerType::BackGround, Vector2(0, 0));

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			graphics::Texture* bgTex = Resources::Find<graphics::Texture>(L"BattleBG");
			sr->SetTexture(bgTex);
			
			//sr->ImageLoad(L"C:\\Users\\User\\Desktop\\WinApi\\PrayEngine\\Resources\\battleMap1.bmp");

			//AddUI(bg, enums::eLayerType::BackGround);
		}

		Scene::Initialize();
	}
	void BattleScene::Update()
	{
		Scene::Update();
	}
	void BattleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void BattleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void BattleScene::OnEnter()
	{
	}
	void BattleScene::OnExit()
	{

	}
}
