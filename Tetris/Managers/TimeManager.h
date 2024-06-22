#pragma once

#ifndef __DEF_TIME_MANAGER__
#define __DEF_TIME_MANAGER__

#include "../pch.h"

class TimeManager
{
private:
	TimeManager();
	~TimeManager();
	static TimeManager instance;

public:
	static TimeManager* GetInstance() {
		return &instance;
	}

private:
	// LARGE_INTEGER는 큰 단위의 숫자를 계산하기 위해 사용된다.
	// 컴파일러가 32비트만 지원한다면 숫자를 나누어서 저장한다.
	// 64비트를 지원하면 64비트용 정수형 변수에 저장한다.
	LARGE_INTEGER m_CurCounter;
	LARGE_INTEGER m_PrevCounter;
	LARGE_INTEGER m_Frequency;

	double m_deltaTime;
	double m_timeAcc;
	UINT m_callCount;
	UINT m_FPS;

public:
	void InitManager();
	void Update();
	double GetDeltaTime() const { return m_deltaTime; }
	float GetDeltaTimeF() const { return static_cast<float>(m_deltaTime); }
};

#endif // !__DEF_TIME_MANAGER__