#include "Texture.h"
#include "../../Managers/GameManager.h"

Texture::Texture() :
	m_dc(0), m_hBit(0), m_bitInfo({})
{
}

Texture::~Texture()
{
	// �����ϴ� ����������� �����մϴ�.
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void Texture::Create(UINT _width, UINT _height)
{
	// ������ GameManager�� ������ �ִ� main DC�� �����ɴϴ�.
	HDC mainDC = GameManager::GetInstance()->GetMainhDC();

	// ���� DC�� ȣȯ���ְ� �����ϵ��� �ϴ� �Լ��� ��Ʈ�� ������ �����մϴ�.
	m_hBit = CreateCompatibleBitmap(mainDC, _width, _height);
	m_dc = CreateCompatibleDC(mainDC);

	// ������ ������ �ִ� bitmap�� ������� �����Ƿ� �����մϴ�.
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hOldBitmap);

	// ��Ʈ�� ������ ��ȯ�մϴ�.
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}

void Texture::Load(const wstring& _strFilePath)
{
}
