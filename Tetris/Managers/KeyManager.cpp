#include "KeyManager.h"

KeyManager KeyManager::instance;

KeyManager::KeyManager() {}
KeyManager::~KeyManager() {}

// 각 array에서 키의 상태를 체크하기 위한 global 변수
// window api 함수의 GetAsyncKeyState를 사용
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
	// 현재 윈도우를 포커싱(화면을 보고 있는 상태, 활성화 상태)중인지 확인한다.
	// 포커싱이 안되어 있다면, nullptr을 반환한다. 이때 키 상태를 다음 상태로 변경한다.
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

	// 전체 키 상태를 갱신한다.
	for (size_t i = 0; i < static_cast<size_t>(KEYTYPE::LAST); i++)
	{
		// 키가 눌렸는지 안눌렸는지 비동기로 확인하는 함수.
		// 키 값(VK_UP과 같은)을 인자로 넘겨주면 상태비트값을 넘겨준다.
		switch (GetAsyncKeyState(g_arrKeyVK[i]))
		{
		// 0x8000 : 이전에 누른적이 없고, 현재 누른 상태
		case 0x8000:
			m_vecKeyState[i] = { KEY_STATE::KEY_DOWN, true };
			break;
		// 0x8001 : 이전에 누른적이 있고, 현재 누른 상태
		case 0x8001:
			m_vecKeyState[i] = { KEY_STATE::KEY_HOLD, true };
			break;
		// 0x0000 ; 이전에 누른적이 없고, 현재 누르지 않은 상태
		case 0x0000:
			m_vecKeyState[i] = { KEY_STATE::KEY_NONE, false };
			break;
		// 0x0001 : 이전에 누른적이 있고, 현재 누르지 않은 상태
		case 0x0001:
			m_vecKeyState[i] = { KEY_STATE::KEY_UP, false };
			break;
		default:
			break;
		}
	}
}
