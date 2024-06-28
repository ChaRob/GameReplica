#pragma once
#include "../pch.h"

using namespace std;

class Resource
{
public:
	Resource();
	virtual ~Resource(); // �ڽ� �Ҹ��ڰ� ȣ��� �� �ֵ��� �����Լ��� ����

private:
	wstring m_key;				// resource�� �ҷ��� �� ����Ű�� key��
	wstring m_relativePath;		// resource�� ��� ���

public:
	const wstring& GetKey() const { return m_key; }
	void SetKey(const wstring& _newKey) { m_key = _newKey; }
	const wstring& GetRelativePath() const { return m_relativePath; }
	void SetRelativePath(const wstring& _newPath) { m_relativePath = _newPath; }
};