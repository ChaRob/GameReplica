#pragma once

#ifndef __DEF_KEY_MANAGER__
#define __DEF_KEY_MANAGER__

#include "../pch.h"

// 현재 키의 상태를 알려주는 enum
enum class KEY_STATE {
	KEY_NONE,			// 아무 상태도 아님
	KEY_PUSH,			// 막 누른 상태
	KEY_HOLD,			// 누르고 있는 상태
	KEY_UP,				// 눌렀다가 뗸 상태
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

	LAST		// 키의 끝
};

struct KeyInfo {
	KEY_STATE nState;	// 현재 키의 상태 확인
	bool preBtn;		// 이전에 눌렀는지 확인
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