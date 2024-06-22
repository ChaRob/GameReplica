#include "KeyManager.h"

KeyManager KeyManager::instance;

KeyManager::KeyManager() {}
KeyManager::~KeyManager() {}

// �� array���� Ű�� ���¸� üũ�ϱ� ���� global ����
// window api �Լ��� GetAsyncKeyState�� ���
int g_arrKeyVK[static_cast<size_t>(KEYTYPE::LAST)] = {
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
	// ���� �����츦 ��Ŀ��(ȭ���� ���� �ִ� ����, Ȱ��ȭ ����)������ Ȯ���Ѵ�.
	// ��Ŀ���� �ȵǾ� �ִٸ�, nullptr�� ��ȯ�Ѵ�. �̶� Ű ���¸� ���� ���·� �����Ѵ�.
	HWND l_hwnd = GetFocus();
	if (l_hwnd == nullptr) {
		for (size_t i = 0; i < static_cast<size_t>(KEYTYPE::LAST); i++)
		{
			m_vecKeyState[i].preBtn = false;
			if (m_vecKeyState[i].nState == KEY_STATE::KEY_DOWN ||
				m_vecKeyState[i].nState == KEY_STATE::KEY_HOLD) {
				m_vecKeyState[i].nState = KEY_STATE::KEY_UP;
			}
			else {
				m_vecKeyState[i].nState = KEY_STATE::KEY_NONE;
			}
		}
		return;
	}

	// ��ü Ű ���¸� �����Ѵ�.
	for (size_t i = 0; i < static_cast<size_t>(KEYTYPE::LAST); i++)
	{
		// Ű�� ���ȴ��� �ȴ��ȴ��� �񵿱�� Ȯ���ϴ� �Լ�.
		// Ű ��(VK_UP�� ����)�� ���ڷ� �Ѱ��ָ� ���º�Ʈ���� �Ѱ��ش�.
		switch (GetAsyncKeyState(g_arrKeyVK[i]))
		{
		// 0x8000 : ������ �������� ����, ���� ���� ����
		case 0x8000:
			m_vecKeyState[i] = { KEY_STATE::KEY_DOWN, true };
			break;
		// 0x8001 : ������ �������� �ְ�, ���� ���� ����
		case 0x8001:
			m_vecKeyState[i] = { KEY_STATE::KEY_HOLD, true };
			break;
		// 0x0000 ; ������ �������� ����, ���� ������ ���� ����
		case 0x0000:
			m_vecKeyState[i] = { KEY_STATE::KEY_NONE, false };
			break;
		// 0x0001 : ������ �������� �ְ�, ���� ������ ���� ����
		case 0x0001:
			m_vecKeyState[i] = { KEY_STATE::KEY_UP, false };
			break;
		default:
			break;
		}
	}
}
