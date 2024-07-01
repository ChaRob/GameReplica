#pragma once

#ifndef __DEF_GAME_MANAGER__
#define __DEF_GAME_MANAGER__

#include "../pch.h"
#include "../Resource/Texture/Texture.h"

using namespace std;

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
	HWND m_hwnd;			// ���� ������ �ڵ�
	POINT m_ptResolution;	// ���� ������ �ػ�
	HDC m_hDC;				// ���� ������ Draw�� DC

	// ȭ���� �׸��� ���� �귯��, ��, �׸��� �Լ��� �����մϴ�.
	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];
	void CreateBrushPen();

	// ȭ�鿡 ��Ʈ�� ������ ���� ������ �����մϴ�.
	// ���Ŀ� �ؽ��� ����� �������� �ٲ� �����Դϴ�.
	HBITMAP m_hBit;				// ��Ʈ�� ����
	HDC m_memDC;				// ����ϰ� ���� DC��
	Texture* m_pBufferTexture;	// ����� �ؽ���

	// ��� Resource�� ����Ǵ� �����ο� ����θ� �����մϴ�.
	wchar_t m_resourcePath[500];
	wchar_t m_relativePath[500];

public:
	// ���� ������ �ڵ�� ������ �ػ�, ��ü Manager�� �ʱ�ȭ �մϴ�.
	int InitManager(HWND _hwnd, POINT _ptResolution);
	void ChangeWindowSize(Vector2 _vec);
	
	// �� Manager�� ������ �� ���� ������ �ڵ带 �̰��� �����մϴ�.
	void Update();
	// ȭ���� �׸� �Լ� ó���� �̰��� �����մϴ�.
	void Render();
	// �̺�Ʈ ó�� �� ���� �������� ������Ʈ �ؾ� �� �������� �̰��� �����մϴ�.
	void LateUpdate();

	// �ܺο��� �ʿ��� �Ӽ����� �����ϴ� �Լ��� ���⿡ ��Ƶ׽��ϴ�.
	HWND GetMainHwnd() const { return m_hwnd; }
	HDC GetMainhDC() const { return m_hDC; }

	// Resource���� ����Ǿ� �ִ� �����θ� ��ȯ�մϴ�.
	const wchar_t* GetResourcePath() const { return m_resourcePath; }
	// Resource���� ����Ǿ� �ִ� ����θ� ��ȯ�մϴ�.
	wstring GetRelativePath(const wchar_t* _filePath);
};

#endif // !__DEF_GAME_MANAGER__