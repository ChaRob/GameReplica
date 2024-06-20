#include "GameManager.h"

GameManager GameManager::instance;

GameManager::GameManager() :
	m_hDC(0),
	m_hwnd(0),
	m_ptResolution(POINT())
{}

GameManager::~GameManager()
{
	// Window API�� �̿��Ͽ� ���� ������ �ڵ�� ���� ������ DC�� �޸𸮸� �����մϴ�.
	ReleaseDC(m_hwnd, m_hDC);
}

int GameManager::InitManager(HWND _hwnd, POINT _ptResolution)
{
	// ���� ������ �ڵ��� GameManager�� ���� �ֵ��� �մϴ�.
	m_hwnd = _hwnd;

	// �ػ󵵿� �µ��� ������ ũ�⸦ �����մϴ�.
	m_ptResolution = _ptResolution;
	ChangeWindowSize(m_ptResolution);

	// Manager���� �ʱ�ȭ �Լ��� �̰��� �ۼ��մϴ�.

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
	// Manager���� Update���� �̰��� �ۼ��մϴ�.

}
