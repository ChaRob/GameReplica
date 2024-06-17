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
	// ���� ������ �ڵ��� GameManager�� ���� �ֵ��� ��.
	m_hwnd = _hwnd;

	// �ػ󵵿� �µ��� ������ ũ�⸦ �����Ѵ�.
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
