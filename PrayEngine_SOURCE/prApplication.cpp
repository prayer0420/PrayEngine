#include "prApplication.h"

namespace pr
{
	Application::Application()
		:mHwnd(nullptr)
		, mHdc(nullptr)
	{}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayer.SetPoisition(0, 0);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
 	}


	void Application::Update()
	{
		mPlayer.Update();

		//mSpeed += 0.01f;
		//float x = mPlayer.GetPositionX();
		//float y = mPlayer.GetPositionY();
		//
		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	x -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	x += 0.01f;
		//}

		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	y -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	y += 0.01f;
		//}

		//mPlayer.SetPoisition(x, y);

	}

	void Application::LateUpdate()
	{
		mPlayer.LateUpdate();
	}
	 
	void Application::Render()
	{
		mPlayer.Render(mHdc);
		//HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		//HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);
		//
		//SelectObject(mHdc, oldPen);

		//float x = mPlayer.GetPositionX();
		//float y = mPlayer.GetPositionY();

		//Rectangle(mHdc, 100 + x, 100 + y, 200 + x, 200 + y);

		//SelectObject(mHdc, oldBrush);

		//DeleteObject(blueBrush);
		//DeleteObject(redPen);
	}
}