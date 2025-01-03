#include "prAnimation.h"
#include "prTime.h"
#include "prTransform.h"
#include "prGameObject.h"
#include "prAnimator.h"
#include "prRenderer.h"

namespace pr
{
	Animation::Animation()
		:Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{

	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (mbComplete)
			return;

		//�ð� ī��Ʈ
		mTime += Time::DeltaTime();

		//ī��Ʈ�� �ð��� ���� ������� index�� sprite�� ���ݽð����� ũ�ٸ�
		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			//���� �����ؾ��� sprite�� ���� ��쿡�� ��� ++����
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else //�� �����ߴٸ� Complete!
				mbComplete = true;
		}
	}

	void Animation::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Sprite sprite = mAnimationSheet[mIndex];

		//ī�޶� �ִٸ� ī�޶� �������� �ٲ������
		if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);

		graphics::Texture::eTextureType type = mTexture->GetTextureType();
		if (type == graphics::Texture::eTextureType::Bmp)
		{

			HDC imgHdc = mTexture->GetHdc();

			TransparentBlt(hdc
				, pos.x
				, pos.y
				, sprite.size.x * 1.5
				, sprite.size.y * 1.5
				, imgHdc
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, RGB(255, 0, 255));

			//Alpha�� �ʿ� �� ��

			//BLENDFUNCTION func = {};
			//func.BlendOp = AC_SRC_OVER;
			//func.BlendFlags = 0;
			//func.AlphaFormat = AC_SRC_ALPHA;
			//func.SourceConstantAlpha = 255; //0(transparent)~255(Opaque)

			/*AlphaBlend(hdc
				, pos.x
				, pos.y
				, sprite.size.x
				, sprite.size.y
				, imgHdc
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, func);*/
		}

		else if (type == graphics::Texture::eTextureType::Png)
		{
			//���� ���ϴ� �ȼ��� ����ȭ ��ų �� (�ʿ��Ҷ���!)
			Gdiplus::ImageAttributes imgAtt = {};
			//����ȭ ��ų �ȼ��� �� ����(100,100,100~255,255,255���� ����ȭ ��Ű�ڴ�)
			imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 2555, 255));

			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x, pos.y
					, sprite.size.x, sprite.size.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel //����ȭ ��Ű�ڴٴ� �ɼ�
				, nullptr/*&imgAtt*/
			);
		}
	}

	void Animation::CreateAnimation(const std::wstring& name
		, graphics::Texture* spriteSheet
		, Vector2 leftTop
		, Vector2 size
		, Vector2 offset
		, UINT spriteLength
		, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i); //0,0 -> 100,0 -> 200,0 -> ...
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}