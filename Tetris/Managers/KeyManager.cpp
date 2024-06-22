#include "KeyManager.h"

KeyManager::KeyManager() {}
KeyManager::~KeyManager() {}

// �� array���� Ű�� ���¸� üũ�ϱ� ���� global ����
// window api �Լ��� GetAsyncKeyState�� ���
int g_keyArrVK[static_cast<size_t>(KEYTYPE::LAST)] = {
	VK_UP,
	VK_DOWN,
	VK_LEFT,
	VK_RIGHT,
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_RETURN,
	VK_CONTROL,
	VK_MENU,
	VK_SPACE,
	VK_LSHIFT,
	VK_TAB,
	'1','2','3','4','5','6','7','8','9','0',
	VK_ESCAPE,
	VK_LBUTTON,
	VK_RBUTTON
};

void KeyManager::InitManager()
{
	for (size_t i = 0; i < static_cast<size_t>(KEYTYPE::LAST); i++)
	{
		m_vecKeyState.push_back(KeyInfo{ KEY_STATE::KEY_NONE, false });
	}
}

void KeyManager::Update()
{

}
