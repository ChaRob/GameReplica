#pragma once

#ifndef __DEF_KEY_MANAGER__
#define __DEF_KEY_MANAGER__

#include "../pch.h"

// ���� Ű�� ���¸� �˷��ִ� enum
enum class KEY_STATE {
	KEY_NONE,			// �ƹ� ���µ� �ƴ�
	KEY_PUSH,			// �� ���� ����
	KEY_HOLD,			// ������ �ִ� ����
	KEY_UP,				// �����ٰ� �� ����
};

enum class KEYTYPE {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,
	ENTER,
	CTRL,
	ALT,
	SPACE,
	LSHIFT,
	TAP,
	ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,ZERO,
	ESC,

	LMOUSEBTN,
	RMOUSEBTN,

	LAST		// Ű�� ��
};

struct KeyInfo {
	KEY_STATE nState;	// ���� Ű�� ���� Ȯ��
	bool preBtn;		// ������ �������� Ȯ��
};

class KeyManager
{
private:
	KeyManager();
	~KeyManager();
	static KeyManager instance;

public:
	static KeyManager* GetInstance() {
		return &instance;
	}

private:
	std::vector<KeyInfo> m_vecKeyState;

public:
	void InitManager();
	void Update();
};

#endif