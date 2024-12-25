#include "prInput.h"

namespace pr
{
	//����� InputŬ���� �ٱ� ���� �����̱⶧���� Ǯ�������� �ۼ�
	//���������̱� ������ ���� �������� ���� 1�� �ʱ�ȭ ������� ��
	std::vector<Input::Key> Input::Keys = {};

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
		createKeys();
	}

	void pr::Input::Update()
	{
		//1. ��ȸ
		//2. Ű ���ȴ��� üũ
		//3. ���� Ű ���¿� ���� Ű ���¸� ���Ͽ� ���� ������Ʈ
		updateKeys();

	}
	void Input::createKeys()
	{
		//eKeyCode�� ������ŭ �ݺ�(�� �� �ʱ�ȭ)
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}
	void Input::updateKeys()
	{

		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKey(Input::Key& key)
	{
		//key�� ���� ���� �������� �˻�
		if (isKeyDown(key.keyCode))
		{
			updateKeyDown(key);
		}
		else //key�� ���� �ȴ��� ���¶��
		{
			updateKeyUp(key);
		}
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		//�������� ���� ���¶�� ��� �������ִ� ����
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else //������ �ȴ��� ���¶�� Ű�� ���� �� ���� ����
			key.state = eKeyState::Down;

		//��¶�� ���� Ű�� ���� ����
		key.bPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
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