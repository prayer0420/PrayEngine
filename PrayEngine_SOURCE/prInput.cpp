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
		/*'Left', 'Down', 'Up',*/
	};


	void pr::Input::Initialize()
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

	void pr::Input::Update()
	{
		//mKeys�� ������ŭ �ݺ�(�� �� üũ)
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			//���� Ű�� ���ȴ�
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				//�������� ���ȴٸ� ��� �������ִ� ����
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				else //������ �ȴ��ȴٸ� Ű�� ó�� ���� ����
				{
					mKeys[i].state = eKeyState::Down;
				}
				//���� Ű �ȴ��ȴٰ� üũ
				mKeys[i].bPressed = true; 
			}
			else  //���� Ű�� �ȴ��ȴ�.
			{
				//������ ���ȴٸ� ����� Ű�� �� ����
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Up;
				}
				else //�������� �ȴ��ȴٸ� �ƹ��͵� �ƴ�
				{
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
}