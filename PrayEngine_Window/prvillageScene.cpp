#include "prvillageScene.h"
#include "prGameObject.h"
#include "prTransform.h"
#include "prSpriteRenderer.h"
#include "prUI.h"
#include "prPlayer.h"
#include "prObject.h"
#include "prTexture.h"
#include "prResources.h"
#include "prPlayerScript.h"
#include "prCamera.h"
#include "prRenderer.h"
#include "prAnimator.h"
#include "prFakePlayerScript.h"
#include "prLoadAnimation.h"


namespace pr
{
	villageScene::villageScene()
		:mCamera(nullptr)
		,mPlayers{}
	{
		mPlayers.reserve(6);
	}

	villageScene::~villageScene()
	{
	}

	void villageScene::Initialize()
	{
		//�÷��̾�
		GameObject* player = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(800, 200));

		player->AddComponent<PlayerScript>();

		graphics::Texture* BlueAttackHatchatTex = Resources::Find<graphics::Texture>(L"BlueAttackHatchat");
		graphics::Texture* BlueDeadHatchatTex = Resources::Find<graphics::Texture>(L"BlueDeadHatchat");
		graphics::Texture* BlueDefenseHatchatTex = Resources::Find<graphics::Texture>(L"BlueDefenseHatchat");
		graphics::Texture* BlueHurtHatchatTex = Resources::Find<graphics::Texture>(L"BlueHurtHatchat");
		graphics::Texture* BlueRunHatchatTex = Resources::Find<graphics::Texture>(L"BlueRunHatchat");
		graphics::Texture* BlueStandHatchatTex = Resources::Find<graphics::Texture>(L"BlueStandHatchat");

		GameObject* playerAssembly = object::Instantiate<Player>(enums::eLayerType::Player, Vector2::Zero);
		Animator* playerAnimatorAssembly = playerAssembly->AddComponent<Animator>();


		////�÷��̾� ���ϸ����Ϳ� �÷��̾� �ִϸ����� ������ ����
		Animator* playerAnimator = player->AddComponent(playerAnimatorAssembly);

		playerAnimator->PlayAnimation(L"BlueAttackHatchat", true);


		//��¥ �÷��̾� 6��
		for (int i = 0; i < 6; i++)
		{
			float randX = rand() % 1600;
			float randY = rand() % 900;
			GameObject* player = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(randX, randY));
			player->AddComponent<FakePlayerScript>();
			player->AddComponent<Animator>();
			mPlayers.push_back(player);
		}

		LoadAnimation* loadAnimation;
		

		//��¥ �÷��̾� 1��
		auto iter = loadAnimation->mPlayerAnimators.find(L"RedBasic");
		if (iter == loadAnimation->mPlayerAnimators.end())
			assert(false);

		Animator* redBasicAnimator = iter->second;
		Animator* fakePlayer1 = mPlayers[0]->AddComponent(redBasicAnimator);
		fakePlayer1->PlayAnimation(L"RedStandBasic_F");

		//��¥ �÷��̾� 2��
		iter = loadAnimation->mPlayerAnimators.find(L"RedClub");
		if (iter == loadAnimation->mPlayerAnimators.end())
			assert(false);

		Animator* redClubAnimator = iter->second;
		Animator* fakePlayer2 = mPlayers[1]->AddComponent(redClubAnimator);
		fakePlayer2->PlayAnimation(L"RedStandClub_F");

		//��¥ �÷��̾� 3��
		iter = loadAnimation->mPlayerAnimators.find(L"RedHatchat");
		if (iter == loadAnimation->mPlayerAnimators.end())
			assert(false);

		Animator* redHatchatAnimator = iter->second;
		Animator* fakePlayer3 = mPlayers[2]->AddComponent(redHatchatAnimator);
		fakePlayer3->PlayAnimation(L"RedStandHatchat_F");

		//��¥ �÷��̾� 4��
		iter = loadAnimation->mPlayerAnimators.find(L"BlueBasic");
		if (iter == loadAnimation->mPlayerAnimators.end())
			assert(false);

		Animator* blueBasicAnimator = iter->second;
		Animator* fakePlayer4 = mPlayers[3]->AddComponent(blueBasicAnimator);
		fakePlayer4->PlayAnimation(L"BlueStandBasic_F");

		//��¥ �÷��̾� 5��
		iter = loadAnimation->mPlayerAnimators.find(L"BlueClub");
		if (iter == loadAnimation->mPlayerAnimators.end())
			assert(false);

		Animator* blueClubAnimator = iter->second;
		Animator* fakePlayer5 = mPlayers[4]->AddComponent(blueClubAnimator);
		fakePlayer5->PlayAnimation(L"BlueStandClub_F");

		//��¥ �÷��̾� 6��
		iter = loadAnimation->mPlayerAnimators.find(L"BlueHatchat");
		if (iter == loadAnimation->mPlayerAnimators.end())
			assert(false);

		Animator* blueHatchatAnimator = iter->second;
		Animator* fakePlayer6 = mPlayers[5]->AddComponent(blueHatchatAnimator);
		fakePlayer6->PlayAnimation(L"BlueStandHatchat_F");


		//ī�޶�
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		mCamera = cameraComp;

		cameraComp->SetTarget(player);			

		//���
		GameObject* bg = object::Instantiate<UI>(enums::eLayerType::BackGround, Vector2(0, 0));
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetName(L"SR");
		graphics::Texture* bgTex = Resources::Find<graphics::Texture>(L"Tile");
		bgSr->SetTexture(bgTex);

		Scene::Initialize();
	}

	void villageScene::Update()
	{
		Scene::Update();
	}
	void villageScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void villageScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void villageScene::OnEnter()
	{
		renderer::mainCamera = mCamera;
	}

	void villageScene::OnExit()
	{
		renderer::mainCamera = nullptr;
	}
}