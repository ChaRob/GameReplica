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
	HWND m_hwnd;			// ���� ������ �ڵ�
	POINT m_ptResolution;	// ���� ������ �ػ�
	HDC m_hDC;				// ���� ������ Draw�� DC

	// ȭ���� �׸��� ���� �귯��, ��, �׸��� �Լ��� �����մϴ�.
	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];
	void CreateBrushPen();

public:
	// ���� ������ �ڵ�� ������ �ػ�, ��ü Manager�� �ʱ�ȭ �մϴ�.
	int InitManager(HWND _hwnd, POINT _ptResolution);
	void ChangeWindowSize(Vector2 _vec);
	
	// �� Manager�� ������ �� ���� ������ �ڵ带 �̰��� �����մϴ�.
	void Update();

	// �ܺο��� �ʿ��� �Ӽ����� �����ϴ� �Լ��� ���⿡ ��Ƶ׽��ϴ�.
	HWND GetMainHwnd() const { return m_hwnd; }
	HDC GetMainhDC() const { return m_hDC; }
};

#endif // !__DEF_GAME_MANAGER__