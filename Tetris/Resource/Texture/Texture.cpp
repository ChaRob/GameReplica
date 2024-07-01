#include "Texture.h"
#include "../../Managers/GameManager.h"

Texture::Texture() :
	m_dc(0), m_hBit(0), m_bitInfo({})
{
}

Texture::~Texture()
{
	// 참조하는 멤버변수들을 제거합니다.
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void Texture::Create(UINT _width, UINT _height)
{
	// 기존의 GameManager가 가지고 있는 main DC를 가져옵니다.
	HDC mainDC = GameManager::GetInstance()->GetMainhDC();

	// 기존 DC와 호환성있게 동작하도록 하는 함수로 비트맵 정보를 정의합니다.
	m_hBit = CreateCompatibleBitmap(mainDC, _width, _height);
	m_dc = CreateCompatibleDC(mainDC);

	// 기존에 가지고 있던 bitmap은 사용하지 않으므로 제거합니다.
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hOldBitmap);

	// 비트맵 정보를 반환합니다.
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}

void Texture::Load(const wstring& _strFilePath)
{
}
