#pragma once

#ifndef __DEF_GAME_MANAGER__
#define __DEF_GAME_MANAGER__

#include "../pch.h"

class GameManager
{
private:
	GameManager();
	~GameManager();
	static GameManager* instance;
public:
	static GameManager* GetInstance() {
		if (instance == nullptr) {
			instance = new GameManager();
		}
		return instance;
	}
private:
	HWND m_hwnd;			// ���� ������ �ڵ�
	POINT m_ptResolution;	// ���� ������ �ػ�
	HDC m_hDC;				// ���� ������ Draw�� DC

public:
	// ���� ������ �ڵ�� ������ �ػ�, ��ü Manager�� �ʱ�ȭ �մϴ�.
	int InitManager(HWND _hwnd, POINT _ptResolution);
	void ChangeWindowSize(Vector2 _vec);
};

#endif // !__DEF_GAME_MANAGER__