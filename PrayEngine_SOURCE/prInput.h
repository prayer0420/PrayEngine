#pragma once
#include <CommonInclude.h>

namespace pr
{

	//���ڸ� ���ڷ� �ٲ��ִ� ����
	enum class eKeyState
	{
		Down,		//0
		Pressed,	//1
		Up,			//2
		None,		//3
	};


	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	};

	//�������� : Ŭ���� ���ο��� �������� ���� ����
	//			Ŭ������ ���ؼ��� ������ ���� ����
	//			�ν��Ͻ��� ������ ���� �� ���������� Data������ 
	//			���� 1�� ���� Ŭ�����̸�::���������̸� ���θ� �Ҵ��(���Ҵ� ���� ����)
	//			���α׷��� ����Ǿ�� �����

	class Input
	{
	public:
		struct Key				//Ű �ϳ��� ������ �ִ� ����
		{
			//char keyCode;		
			eKeyCode keyCode;	//���� � Ű ����
			eKeyState state;	//� ��������
			bool bPressed;		//�����ִ���
		};

		static void Initialize();
		static void Update();	//�������Ӹ��� Ű���� ���� üũ

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }

	private:
		static void CreateKeys();
		static void UpdateKeys();
		static bool IsKeyDown(eKeyCode code);
		static void UpdateKey(Input::Key& key);
		static void UpdateKeyDown(Input::Key& key);
		static void UpdateKeyUp(Input::Key& key);

	private:
		//���ڷ� �ع����� �ٸ������ �˼� ����
		//int mState; //0 1 2  
		static std::vector<Key> mKeys; //Ű���� �������ִ� ���� vector



	};

}

