#include "GameManager.h"
#include "KeyManager.h"
#include "TimeManager.h"

// instance를 참조할 수 있도록 선언해주기.
// C++표준에서는 일반 정적멤버 변수를 클래스 내부에서 초기화하는 것을 허용하지 않는다.
// static멤버 변수는 클래스 밖에서 초기화해야한다.
// 하지만 C++17부터는 inline 변수를 도입하여 클래스 내부에서 정의하고 초기화할 수 있다.
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
	// Window API를 이용하여 메인 윈도우 핸들과 메인 윈도우 DC의 메모리를 해제합니다.
	ReleaseDC(m_hwnd, m_hDC);

	// CreatePen으로 만들어둔 Pen들을 모두 제거합니다.
	for (UINT i = 0; i < (UINT)PEN_TYPE::END; i++)
	{
		DeleteObject(m_arrPen[i]);
	}
}

int GameManager::InitManager(HWND _hwnd, POINT _ptResolution)
{
	// 전역 윈도우 핸들을 GameManager가 갖고 있도록 합니다.
	m_hwnd = _hwnd;

	// 해상도에 맞도록 윈도우 크기를 조절합니다.
	m_ptResolution = _ptResolution;
	ChangeWindowSize(m_ptResolution);

	// 사용할 브러쉬와 펜을 등록합니다.
	CreateBrushPen();

	// Manager들의 초기화 함수를 이곳에 작성합니다.
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
	// Manager들의 Update문을 이곳에 작성합니다.
	KeyManager::GetInstance()->Update();
	TimeManager::GetInstance()->Update();
}
