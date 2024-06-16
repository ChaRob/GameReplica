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
	HWND m_hwnd;			// 메인 윈도우 핸들
	POINT m_ptResolution;	// 메인 윈도우 해상도
	HDC m_hDC;				// 메인 윈도우 Draw용 DC

public:
	// 메인 윈도우 핸들과 윈도우 해상도, 전체 Manager를 초기화 합니다.
	int InitManager(HWND _hwnd, POINT _ptResolution);
	void ChangeWindowSize(Vector2 _vec);
};

#endif // !__DEF_GAME_MANAGER__