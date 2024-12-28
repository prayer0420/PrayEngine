#pragma once
#include "..\\PrayEngine_SOURCE\\prSceneManager.h"

#include "prBeginnerDungeonScene.h"
#include "prCharacterCreateScene.h"
#include "prCharacterSelectScene.h"
#include "prFightScene.h"
#include "prItemShopScene.h"
#include "prPetShopScene.h"
#include "prTitleScene.h"
#include "prvillageScene.h"
#include "prHeadManHouseScene.h"

namespace pr
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<CharacterSelectScene>(L"CharacterSelectScene");
		SceneManager::CreateScene<CharacterCreateScene>(L"CharacterCreateScene");
		SceneManager::CreateScene<HeadManHouseScene>(L"HeadManHouseScene");
		SceneManager::CreateScene<villageScene>(L"villageScene");
		SceneManager::CreateScene<ItemShopScene>(L"ItemShopScene");
		SceneManager::CreateScene<PetShopScene>(L"PetShopScene");
		SceneManager::CreateScene<BeginnerDungeonScene>(L"BeginnerDungeonScene");
		SceneManager::CreateScene<FightScene>(L"FightScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}

//<�ε��>
//- Ÿ��Ʋ ��
//- ĳ���� ���� ��
//- ĳ���� ���� ��
//- ���� �� ��
//- ���� ��
//- ������ ���� ��
//- �� ���� ��
//- ���� ��
//- �ο� ��