#pragma once
#include "..\\PrayEngine_SOURCE\\prScene.h"

namespace pr
{
	class CharacterSelectScene : public Scene
	{
	public:
		CharacterSelectScene();
		~CharacterSelectScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}