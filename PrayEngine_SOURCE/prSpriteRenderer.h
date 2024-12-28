#pragma once
#include "prEntity.h"
#include "prComponent.h"

namespace pr
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;
		void ImageLoad(const std::wstring& path); //ImageLoad�����ϰ� Render�� �׸�

	private:
		Gdiplus::Image* mImgae;
		UINT mWidth;
		UINT mHeight;

	};
}