#include "GameManager.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

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
	m_arrPen{},
	m_hBit(0),
	m_memDC(0),
	m_relativePath(),
	m_resourcePath(),
	m_pBufferTexture(0)
{}

GameManager::~GameManager()
{
	// Window API를 이용하여 메인 윈도우 핸들과 메인 윈도우 DC의 메모리를 해제합니다.
	ReleaseDC(m_hwnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);

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

	// Device Context 초기화 및 호출
	// 메세지 기반이 아닌, 원할때 그림을 그려 넣을 수 있도록 합니다.
	m_hDC = GetDC(m_hwnd);

	// 백버퍼 용도의 비트맵과 DC를 생성합니다.
	

	// 기존 DC와 호환성있게 동작하도록 하는 함수로 비트맵 정보를 정의합니다.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	// m_memDC가 기존에 가리키고 있던 bitmap은 사용하지 않으므로 제거합니다.
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBitmap);

	// 현재 프로그램이 실행된 경로를 받아옵니다.
	GetCurrentDirectory(500, m_resourcePath);

	// Release나 Debug가 실행되는 경로 밖의 폴더를 지정하기 위한 로직을 실행합니다.
	size_t pathLen = wcslen(m_resourcePath);
	for (int i = pathLen - 1; i >= 0; i--)
	{
		// 경로에서 '\\'을 만나면 null 문자를 넣어 해당 경로까지의 절대 경로를 얻습니다.
		if (m_resourcePath[i] == '\\') {
			m_resourcePath[i] = '\0';
			break;
		}
	}
	// resource가 들어있는 경로를 지정합니다.
	wcscat_s(m_resourcePath, 500, L"\\resource\\");

	// Manager들의 초기화 함수를 이곳에 작성합니다.
	KeyManager::GetInstance()->InitManager();
	TimeManager::GetInstance()->InitManager();
	SceneManager::GetInstance()->InitManager();

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
	SceneManager::GetInstance()->Update();
	TimeManager::GetInstance()->Update();
}

void GameManager::Render()
{
	// 그림 그리기 전 전체 화면 청소
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y);

	// 임시 테스트용 그림
	// SelectObject(m_memDC, m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW]);
	// SelectObject(m_memDC, m_arrPen[(UINT)PEN_TYPE::RED]);
	Rectangle(m_memDC, 10, 10, 110, 110);

	// 이곳에서 Manager들이 관리하는 Render함수를 호출합니다.
	SceneManager::GetInstance()->Render();

	// m_memDC에 그린 그림을 복사해서 m_hDC로 옮겨줍니다.
	// 이 작업을 CPU가 담당하고 있지만, 후에 DirectX를 통해 GPU가 작업하게 되면 속도를 더 끌어올릴 수 있습니다.
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
}

void GameManager::LateUpdate()
{
	// 이곳에서 Manager들의 LateUpdate문을 작성합니다.
	SceneManager::GetInstance()->LateUpdate();
}

wstring GameManager::GetRelativePath(const wchar_t* _filePath)
{
	// wstring으로 변환한 후, m_resourcePath의 값을 제거하고 반환합니다.
	wstring strFilePath = _filePath;

	size_t lastPos = strFilePath.find(m_resourcePath);

	return strFilePath.substr(lastPos + wcslen(m_resourcePath));
}