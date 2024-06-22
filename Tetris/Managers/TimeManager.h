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
	// LARGE_INTEGER�� ū ������ ���ڸ� ����ϱ� ���� ���ȴ�.
	// �����Ϸ��� 32��Ʈ�� �����Ѵٸ� ���ڸ� ����� �����Ѵ�.
	// 64��Ʈ�� �����ϸ� 64��Ʈ�� ������ ������ �����Ѵ�.
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