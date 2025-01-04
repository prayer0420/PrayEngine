#include "prPetShopScene.h"
#include "prGameObject.h"
#include "prNPC.h"
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


namespace pr
{
	PetShopScene::PetShopScene()
		:mCamera(nullptr)
	{
	}

	PetShopScene::~PetShopScene()
	{
	}
	void PetShopScene::Initialize()
	{
		//NPC
		for (int i = 0; i < 2; i++)
		{
			GameObject* npc = object::Instantiate<NPC>(enums::eLayerType::Npc, Vector2({ 300 + (i * 200) , 350 + (i * -200) }));

			SpriteRenderer* sr = npc->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
		}

		//�÷��̾�
		GameObject* player = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(1300, 600));
		player->AddComponent<PlayerScript>();
		Animator* playerAnimator = player->AddComponent<Animator>();

		graphics::Texture* BlueAttackClubTex = Resources::Find<graphics::Texture>(L"BlueAttackClub");
		graphics::Texture* BlueDeadClubTex = Resources::Find<graphics::Texture>(L"BlueDeadClub");
		graphics::Texture* BlueDefenseClubTex = Resources::Find<graphics::Texture>(L"BlueDefenseClub");
		graphics::Texture* BlueHurtClubTex = Resources::Find<graphics::Texture>(L"BlueHurtClub");
		graphics::Texture* BlueRunClubTex = Resources::Find<graphics::Texture>(L"BlueRunClub");
		graphics::Texture* BlueStandClubTex = Resources::Find<graphics::Texture>(L"BlueStandClub");

		playerAnimator->CreateAnimation(L"BlueAttackClub", BlueAttackClubTex
			, Vector2(0.0f, 0.0f), Vector2(348.0f, 130.0f), Vector2::Zero, 6, 0.2f);
		playerAnimator->CreateAnimation(L"BlueDeadClub", BlueDeadClubTex
			, Vector2(0.0f, 0.0f), Vector2(110.0f, 130.0f), Vector2::Zero, 6, 0.2f);
		playerAnimator->CreateAnimation(L"BlueDefenseClub", BlueDefenseClubTex
			, Vector2(0.0f, 0.0f), Vector2(110.0f, 130.0f), Vector2::Zero, 2, 0.2f);
		playerAnimator->CreateAnimation(L"BlueHurtClub", BlueHurtClubTex
			, Vector2(0.0f, 0.0f), Vector2(110.0f, 130.0f), Vector2::Zero, 2, 0.2f);
		playerAnimator->CreateAnimation(L"BlueRunClub", BlueRunClubTex
			, Vector2(0.0f, 0.0f), Vector2(110.0f, 130.0f), Vector2::Zero, 6, 0.2f);
		playerAnimator->CreateAnimation(L"BlueStandClub", BlueStandClubTex
			, Vector2(0.0f, 0.0f), Vector2(110.0f, 130.0f), Vector2::Zero, 4, 0.2f);

		playerAnimator->PlayAnimation(L"BlueRunClub");

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

	void PetShopScene::OnEnter()
	{
		renderer::mainCamera = mCamera;
	}

	void PetShopScene::OnExit()
	{
		renderer::mainCamera = nullptr;
	}
}