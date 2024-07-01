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
	// texture�� DC�� bitmap ������ �����ϴ� �Լ��� �����մϴ�.
	const HDC& GetDC() const { return m_dc; }
	UINT GetBitmapWidth() const { return m_bitInfo.bmWidth; }
	UINT GetBitmapHeigth() const { return m_bitInfo.bmHeight; }

	// texture�� ������ �ҷ����� ����� �����մϴ�.
	void Create(UINT _width, UINT _height);
	void Load(const wstring& _strFilePath);
};