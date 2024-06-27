#pragma once
#include "../pch.h"
#include "../Object/Object.h"

using namespace std;

class Scene
{
public:
	Scene();
	~Scene();

private:
	// Scene���� ������ ��� object vector�� �����մϴ�.
	vector<Object*> m_arrOjb[(UINT)GROUP_TYPE::END];

public:
	// Scene�� �����ϴ� object���� Update�� Render�� ȣ���մϴ�.
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	// Scene�� ����, Ż��� ȣ���ϵ��� �����Լ��� �����մϴ�.
	// �̋� ���������Լ��� ���� �ݵ�� ��ӹ��� Scene���� �ش� �Լ��� �����ϵ��� �մϴ�.
	virtual void Enter() = 0;
	virtual void Exit() = 0;
};