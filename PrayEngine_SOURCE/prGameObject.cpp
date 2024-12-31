#include "prGameObject.h"
#include "prInput.h"
#include "prTime.h"
#include "prTransform.h"

namespace pr
{
	GameObject::GameObject()
	{
		initializeTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Initialize();
		}
	}


	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Render(hdc);
		}
	}	
	
	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}
