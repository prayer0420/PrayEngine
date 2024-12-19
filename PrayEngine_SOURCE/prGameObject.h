#pragma once
#include "CommonInclude.h"

namespace pr
{
	class GameObject
	{
	public :
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPoisition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() {return mX;}
		float GetPositionY() {return mY;}

	private:
		//���ӿ�����Ʈ�� ��ǥ
		float mX;
		float mY;
	};

}

