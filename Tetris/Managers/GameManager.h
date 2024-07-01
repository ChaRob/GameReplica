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
	HWND m_hwnd;			// 메인 윈도우 핸들
	POINT m_ptResolution;	// 메인 윈도우 해상도
	HDC m_hDC;				// 메인 윈도우 Draw용 DC

	// 화면을 그리기 위한 브러쉬, 펜, 그리고 함수를 정의합니다.
	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];
	void CreateBrushPen();

	// 화면에 비트맵 정보를 넣을 변수를 정의합니다.
	// 이후에 텍스쳐 기반의 형식으로 바뀔 예정입니다.
	HBITMAP m_hBit;				// 비트맵 정보
	HDC m_memDC;				// 기억하고 있을 DC값
	Texture* m_pBufferTexture;	// 백버퍼 텍스쳐

	// 모든 Resource가 저장되는 절대경로와 상대경로를 정의합니다.
	wchar_t m_resourcePath[500];
	wchar_t m_relativePath[500];

public:
	// 메인 윈도우 핸들과 윈도우 해상도, 전체 Manager를 초기화 합니다.
	int InitManager(HWND _hwnd, POINT _ptResolution);
	void ChangeWindowSize(Vector2 _vec);
	
	// 각 Manager가 루프를 돌 동안 실행할 코드를 이곳에 정리합니다.
	void Update();
	// 화면을 그릴 함수 처리를 이곳에 정리합니다.
	void Render();
	// 이벤트 처리 등 가장 마지막에 업데이트 해야 할 정보들을 이곳에 정리합니다.
	void LateUpdate();

	// 외부에서 필요한 속성값을 전달하는 함수를 여기에 모아뒀습니다.
	HWND GetMainHwnd() const { return m_hwnd; }
	HDC GetMainhDC() const { return m_hDC; }

	// Resource들이 저장되어 있는 절대경로를 반환합니다.
	const wchar_t* GetResourcePath() const { return m_resourcePath; }
	// Resource들이 저장되어 있는 상대경로를 반환합니다.
	wstring GetRelativePath(const wchar_t* _filePath);
};

#endif // !__DEF_GAME_MANAGER__