#include "prInput.h"

namespace pr
{
	//����� InputŬ���� �ٱ� ���� �����̱⶧���� Ǯ�������� �ۼ�
	//���������̱� ������ ���� �������� ���� 1�� �ʱ�ȭ ������� ��
	std::vector<Input::Key> Input::mKeys = {};

	//eKeyCode��ŭ�� �迭�� ����
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP
	};


	void pr::Input::Initialize()
	{
		CreateKeys();
	}

	void pr::Input::Update()
	{
		//1. ��ȸ
		//2. Ű ���ȴ��� üũ
		//3. ���� Ű ���¿� ���� Ű ���¸� ���Ͽ� ���� ������Ʈ
		UpdateKeys();

	}
	void Input::CreateKeys()
	{
		//eKeyCode�� ������ŭ �ݺ�(�� �� �ʱ�ȭ)
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}
	void Input::UpdateKeys()
	{
		//������ ó������  ������ ��ȸ
		//�� ��Ұ� �͸��Լ��� ���ڷ� ���޵�
		//�� �͸��Լ��� ����(���)�� ���������� �ް�, void�� ��ȯ
		//�͸��Լ� ���ο��� UpdateKey�� ȣ���Ͽ� key�� �� �Լ��� ���ڷ� ����(������)
		//=> ��� Ű ���� ���� ���� ���� �ٲ���
		std::for_each(mKeys.begin(), mKeys.end(),
			[](Key& key) -> void
			{
				UpdateKey(key);
			});
	}

	bool Input::IsKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::UpdateKey(Input::Key& key)
	{
		//key�� ���� ���� �������� �˻�
		if (IsKeyDown(key.keyCode))
		{
			UpdateKeyDown(key);
		}
		else //key�� ���� �ȴ��� ���¶��
		{
			UpdateKeyUp(key);
		}
	}

	void Input::UpdateKeyDown(Input::Key& key)
	{
		//�������� ���� ���¶�� ��� �������ִ� ����
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else //������ �ȴ��� ���¶�� Ű�� ���� �� ���� ����
			key.state = eKeyState::Down;

		//��¶�� ���� Ű�� ���� ����
		key.bPressed = true;
	}

	void Input::UpdateKeyUp(Input::Key& key)
	{
		//������ ���� ���¶�� ����� Ű�� �� ����
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else //�������� �ȴ��� ���¶�� ���ʿ� Ű�� �ȴ��� ����
			key.state = eKeyState::None;

		//��¶�� ���� Ű�� �ȴ��� ����
		key.bPressed = false;
	}
}