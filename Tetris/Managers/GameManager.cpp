#include "GameManager.h"

GameManager GameManager::instance;

GameManager::GameManager() :
	m_hDC(0),
	m_hwnd(0),
	m_ptResolution(POINT())
{}

GameManager::~GameManager()
{
	// Window API를 이용하여 메인 윈도우 핸들과 메인 윈도우 DC의 메모리를 해제합니다.
	ReleaseDC(m_hwnd, m_hDC);
}

int GameManager::InitManager(HWND _hwnd, POINT _ptResolution)
{
	// 전역 윈도우 핸들을 GameManager가 갖고 있도록 합니다.
	m_hwnd = _hwnd;

	// 해상도에 맞도록 윈도우 크기를 조절합니다.
	m_ptResolution = _ptResolution;
	ChangeWindowSize(m_ptResolution);

	// Manager들의 초기화 함수를 이곳에 작성합니다.

	return S_OK;
}

void GameManager::ChangeWindowSize(Vector2 _resolution)
{
	RECT rt = { 0,0,_resolution.x, _resolution.y };
	AdjustWindowRect(
		&rt, WS_OVERLAPPEDWINDOW,
		false
	);
	SetWindowPos(m_hwnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
}

void GameManager::Update()
{
	// Manager들의 Update문을 이곳에 작성합니다.

}
