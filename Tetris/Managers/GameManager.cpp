#include "GameManager.h"
#include "KeyManager.h"
#include "TimeManager.h"

// instance�� ������ �� �ֵ��� �������ֱ�.
// C++ǥ�ؿ����� �Ϲ� ������� ������ Ŭ���� ���ο��� �ʱ�ȭ�ϴ� ���� ������� �ʴ´�.
// static��� ������ Ŭ���� �ۿ��� �ʱ�ȭ�ؾ��Ѵ�.
// ������ C++17���ʹ� inline ������ �����Ͽ� Ŭ���� ���ο��� �����ϰ� �ʱ�ȭ�� �� �ִ�.
GameManager GameManager::instance;

GameManager::GameManager() :
	m_hDC(0),
	m_hwnd(0),
	m_ptResolution(POINT()),
	m_arrBrush{},
	m_arrPen{}
{}

GameManager::~GameManager()
{
	// Window API�� �̿��Ͽ� ���� ������ �ڵ�� ���� ������ DC�� �޸𸮸� �����մϴ�.
	ReleaseDC(m_hwnd, m_hDC);

	// CreatePen���� ������ Pen���� ��� �����մϴ�.
	for (UINT i = 0; i < (UINT)PEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}
}

int GameManager::InitManager(HWND _hwnd, POINT _ptResolution)
{
	// ���� ������ �ڵ��� GameManager�� ���� �ֵ��� �մϴ�.
	m_hwnd = _hwnd;

	// �ػ󵵿� �µ��� ������ ũ�⸦ �����մϴ�.
	m_ptResolution = _ptResolution;
	ChangeWindowSize(m_ptResolution);

	// ����� �귯���� ���� ����մϴ�.
	CreateBrushPen();

	// Manager���� �ʱ�ȭ �Լ��� �̰��� �ۼ��մϴ�.
	KeyManager::GetInstance()->InitManager();
	TimeManager::GetInstance()->InitManager();

	return S_OK;
}

void GameManager::ChangeWindowSize(Vector2 _resolution)
{
	RECT rt = { 0,0,static_cast<LONG>(_resolution.x), static_cast<LONG>(_resolution.y) };
	AdjustWindowRect(
		&rt, WS_OVERLAPPEDWINDOW,
		false
	);
	SetWindowPos(m_hwnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
}

void GameManager::CreateBrushPen()
{
	// Brush
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	// Pen
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}

void GameManager::Update()
{
	// Manager���� Update���� �̰��� �ۼ��մϴ�.
	KeyManager::GetInstance()->Update();
	TimeManager::GetInstance()->Update();
}
