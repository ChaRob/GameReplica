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
	HWND m_hwnd;			// 메인 윈도우 핸들
	POINT m_ptResolution;	// 메인 윈도우 해상도
	HDC m_hDC;				// 메인 윈도우 Draw용 DC

public:
	// 메인 윈도우 핸들과 윈도우 해상도, 전체 Manager를 초기화 합니다.
	int InitManager(HWND _hwnd, POINT _ptResolution);
	void ChangeWindowSize(Vector2 _vec);
	
	// 각 Manager가 루프를 돌 동안 실행할 코드를 이곳에 정리합니다.
	void Update();

	// 외부에서 필요한 속성값을 전달하는 함수를 여기에 모아뒀습니다.
	inline HWND GetMainHwnd() { return m_hwnd; }
	inline HDC GetMainhDC() { return m_hDC; }
};

#endif // !__DEF_GAME_MANAGER__