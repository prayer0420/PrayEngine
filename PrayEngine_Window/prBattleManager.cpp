#include "prBattleManager.h"
#include "prSceneManager.h"

namespace pr
{
	pr::BattleManager::BattleManager()
		:mPlayer{}
		, mMyPet{}
		, mEnemyPet{}
		, mPlayerNumber(0)
		, mEnemyNumber(0)
	{
		mPlayer.reserve(1);
		mMyPet.reserve(5);
		mEnemyPet.reserve(5);
	}

	pr::BattleManager::~BattleManager()
	{
	}

	void pr::BattleManager::Battle()
	{
		while (true)
		{
			//�÷��̾� & �� �� Ȱ��
			PlayerTurn();

			//��Ʋ ���� ����
			BattleStateCheck();

			//�� �� �ൿ
			EnemyTurn();

			//��Ʋ ���� ����
			BattleStateCheck();
		}

		//��Ʋ ����Ǹ� ���������� ��ȯ
		SceneManager::LoadScene(L"vilageScene");
	}

	void pr::BattleManager::BattleStateCheck()
	{
		//ĳ���� �� ����
		//ĳ���� �� �� 0���� ���ų������� ����
		if (mPlayerNumber <= 0)
		{
			return;
		}

		//�� �� ����
		//�� ���� 0���� ���ų������� ����
		if (mEnemyNumber <= 0)
		{
			return;
		}
	}

	void pr::BattleManager::PlayerTurn()
	{

	}

	void pr::BattleManager::EnemyTurn()
	{

	}
}