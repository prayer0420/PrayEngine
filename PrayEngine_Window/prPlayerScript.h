#pragma once
#include "..\\PrayEngine_SOURCE\\prScript.h"


namespace pr
{
	class PlayerScript : public Script
	{
	public:

		enum class eState
		{
			Idle,
			Walk,
			Attack,
			Dead,
			Hurt,
			Guard,
			UsingItem,
			ChangingPet,
			Escape
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:

		void idle();
		void walk();
		void attack();
		void dead();
		void hurt();
		void guard();
		void usingItem();
		void changingPet();
		void escape();

		void keyboardMove();

	private:
		bool battling;
		eState mState;
		class Animator* mAnimator;
	};
}
