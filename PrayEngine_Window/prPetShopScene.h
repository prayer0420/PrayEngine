#pragma once
#include "..\\PrayEngine_SOURCE\\prScene.h"

namespace pr
{
	class PetShopScene : public Scene
	{
	public:
		PetShopScene();
		~PetShopScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}