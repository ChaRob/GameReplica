#pragma once

#ifndef __DEF_GAME_MANAGER__
#define __DEF_GAME_MANAGER__

#include "../pch.h"

class GameManager
{
private:
	GameManager();
	~GameManager();
	static GameManager instance;
public:
	static GameManager* GetInstance() {
		return &instance;
	}
private:
	HWND m_hwnd;			// ���� ������ �ڵ�
	POINT m_ptResolution;	// ���� ������ �ػ�
	HDC m_hDC;				// ���� ������ Draw�� DC

public:
	// ���� ������ �ڵ�� ������ �ػ�, ��ü Manager�� �ʱ�ȭ �մϴ�.
	int InitManager(HWND _hwnd, POINT _ptResolution);
	void ChangeWindowSize(Vector2 _vec);
	
	// �� Manager�� ������ �� ���� ������ �ڵ带 �̰��� �����մϴ�.
	void Update();

	// �ܺο��� �ʿ��� �Ӽ����� �����ϴ� �Լ��� ���⿡ ��Ƶ׽��ϴ�.
	inline HWND GetMainHwnd() { return m_hwnd; }
	inline HDC GetMainhDC() { return m_hDC; }
};

#endif // !__DEF_GAME_MANAGER__