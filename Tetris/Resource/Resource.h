#pragma once
#include "../pch.h"

using namespace std;

class Resource
{
public:
	Resource();
	virtual ~Resource(); // 자식 소멸자가 호출될 수 있도록 가상함수로 구현

private:
	wstring m_key;				// resource를 불러올 때 가리키는 key값
	wstring m_relativePath;		// resource의 상대 경로

public:
	const wstring& GetKey() const { return m_key; }
	void SetKey(const wstring& _newKey) { m_key = _newKey; }
	const wstring& GetRelativePath() const { return m_relativePath; }
	void SetRelativePath(const wstring& _newPath) { m_relativePath = _newPath; }
};