#pragma once
#include "prGameObject.h"

namespace pr
{
	class Application
	{
	public:
		Application();

		~Application();

	public:
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer;

	};

}