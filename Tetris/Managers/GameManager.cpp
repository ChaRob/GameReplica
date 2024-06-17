#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() :
	m_hDC(0),
	m_hwnd(0),
	m_ptResolution(POINT())
{
}

GameManager::~GameManager()
{
}

int GameManager::InitManager(HWND _hwnd, POINT _ptResolution)
{
	// 전역 윈도우 핸들을 GameManager가 갖고 있도록 함.
	m_hwnd = _hwnd;

	// 해상도에 맞도록 윈도우 크기를 조절한다.
	m_ptResolution = _ptResolution;
	ChangeWindowSize(m_ptResolution);

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

}
