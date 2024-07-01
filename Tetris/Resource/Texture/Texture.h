#pragma once
#include "../../pch.h"
#include "../Resource.h"

using namespace std;

class Texture : public Resource
{
public:
	Texture();
	virtual ~Texture();

private:
	HDC m_dc;
	HBITMAP m_hBit;
	BITMAP m_bitInfo;

public:
	// texture의 DC와 bitmap 정보를 제공하는 함수를 정의합니다.
	const HDC& GetDC() const { return m_dc; }
	UINT GetBitmapWidth() const { return m_bitInfo.bmWidth; }
	UINT GetBitmapHeigth() const { return m_bitInfo.bmHeight; }

	// texture의 생성과 불러오기 기능을 정의합니다.
	void Create(UINT _width, UINT _height);
	void Load(const wstring& _strFilePath);
};