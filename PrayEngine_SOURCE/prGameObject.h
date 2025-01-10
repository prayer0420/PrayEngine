#pragma once
#include "CommonInclude.h"
#include "prComponent.h"
#include "prAnimator.h"

namespace pr
{
	class GameObject 
	{
	public :
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);


		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->SetOwner(this);
			comp->Initialize();
			mComponents[(UINT)comp->GetType()] = comp;
			return comp;
		}
		
		template<typename T>
		T* AddComponent(T* animator)
		{
			T* comp = animator;
			comp->SetOwner(this);
			comp->Initialize();
			mComponents[(UINT)comp->GetType()] = comp;
			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}
	private:
		void initializeTransform();

	private:
		std::vector<Component*> mComponents;
	};
}