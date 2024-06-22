#include "TimeManager.h"
#include "GameManager.h"

TimeManager TimeManager::instance;

TimeManager::TimeManager() :
	m_CurCounter{},
	m_PrevCounter{},
	m_Frequency{},
	m_deltaTime(0.1f),
	m_timeAcc(0.0),
	m_callCount(0),
	m_FPS(0)
{}
TimeManager::~TimeManager() {}


void TimeManager::InitManager()
{
	QueryPerformanceCounter(&m_PrevCounter);	// 현재 CPU의 Tick값을 가져온다(=GetTickCount).
	QueryPerformanceFrequency(&m_Frequency);	// PerformanceCounter의 빈도를 계산한다.
}

void TimeManager::Update()
{
	QueryPerformanceCounter(&m_CurCounter);

	m_deltaTime = static_cast<double>(m_CurCounter.QuadPart - m_PrevCounter.QuadPart) / static_cast<double>(m_Frequency.QuadPart);
	m_PrevCounter = m_CurCounter;

#if _DEBUG
	m_callCount++;
	m_timeAcc += m_deltaTime;
	if (m_timeAcc >= 1.0) {
		m_FPS = m_callCount;
		m_callCount = 0;
		m_timeAcc = 0;

		wchar_t szBuffer[255];
		swprintf_s(szBuffer, L"FPS : %d  /   DT : %f", m_FPS, m_deltaTime);
		SetWindowText(GameManager::GetInstance()->GetMainHwnd(), szBuffer);
	}
#endif
}