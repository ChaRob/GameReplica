#include "GameManager.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

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
	m_arrPen{},
	m_hBit(0),
	m_memDC(0),
	m_relativePath(),
	m_resourcePath(),
	m_pBufferTexture(0)
{}

GameManager::~GameManager()
{
	// Window API�� �̿��Ͽ� ���� ������ �ڵ�� ���� ������ DC�� �޸𸮸� �����մϴ�.
	ReleaseDC(m_hwnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);

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

	// Device Context �ʱ�ȭ �� ȣ��
	// �޼��� ����� �ƴ�, ���Ҷ� �׸��� �׷� ���� �� �ֵ��� �մϴ�.
	m_hDC = GetDC(m_hwnd);

	// ����� �뵵�� ��Ʈ�ʰ� DC�� �����մϴ�.
	

	// ���� DC�� ȣȯ���ְ� �����ϵ��� �ϴ� �Լ��� ��Ʈ�� ������ �����մϴ�.
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	// m_memDC�� ������ ����Ű�� �ִ� bitmap�� ������� �����Ƿ� �����մϴ�.
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBitmap);

	// ���� ���α׷��� ����� ��θ� �޾ƿɴϴ�.
	GetCurrentDirectory(500, m_resourcePath);

	// Release�� Debug�� ����Ǵ� ��� ���� ������ �����ϱ� ���� ������ �����մϴ�.
	size_t pathLen = wcslen(m_resourcePath);
	for (int i = pathLen - 1; i >= 0; i--)
	{
		// ��ο��� '\\'�� ������ null ���ڸ� �־� �ش� ��α����� ���� ��θ� ����ϴ�.
		if (m_resourcePath[i] == '\\') {
			m_resourcePath[i] = '\0';
			break;
		}
	}
	// resource�� ����ִ� ��θ� �����մϴ�.
	wcscat_s(m_resourcePath, 500, L"\\resource\\");

	// Manager���� �ʱ�ȭ �Լ��� �̰��� �ۼ��մϴ�.
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
	// Manager���� Update���� �̰��� �ۼ��մϴ�.
	KeyManager::GetInstance()->Update();
	SceneManager::GetInstance()->Update();
	TimeManager::GetInstance()->Update();
}

void GameManager::Render()
{
	// �׸� �׸��� �� ��ü ȭ�� û��
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y);

	// �ӽ� �׽�Ʈ�� �׸�
	// SelectObject(m_memDC, m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW]);
	// SelectObject(m_memDC, m_arrPen[(UINT)PEN_TYPE::RED]);
	Rectangle(m_memDC, 10, 10, 110, 110);

	// �̰����� Manager���� �����ϴ� Render�Լ��� ȣ���մϴ�.
	SceneManager::GetInstance()->Render();

	// m_memDC�� �׸� �׸��� �����ؼ� m_hDC�� �Ű��ݴϴ�.
	// �� �۾��� CPU�� ����ϰ� ������, �Ŀ� DirectX�� ���� GPU�� �۾��ϰ� �Ǹ� �ӵ��� �� ����ø� �� �ֽ��ϴ�.
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
}

void GameManager::LateUpdate()
{
	// �̰����� Manager���� LateUpdate���� �ۼ��մϴ�.
	SceneManager::GetInstance()->LateUpdate();
}

wstring GameManager::GetRelativePath(const wchar_t* _filePath)
{
	// wstring���� ��ȯ�� ��, m_resourcePath�� ���� �����ϰ� ��ȯ�մϴ�.
	wstring strFilePath = _filePath;

	size_t lastPos = strFilePath.find(m_resourcePath);

	return strFilePath.substr(lastPos + wcslen(m_resourcePath));
}