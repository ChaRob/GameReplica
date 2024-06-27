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
	// Scene에서 관리할 모든 object vector를 선언합니다.
	vector<Object*> m_arrOjb[(UINT)GROUP_TYPE::END];

public:
	// Scene에 존재하는 object들의 Update와 Render를 호출합니다.
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	// Scene에 진입, 탈출시 호출하도록 가상함수로 설정합니다.
	// 이떄 순수가상함수로 만들어서 반드시 상속받은 Scene들이 해당 함수를 구현하도록 합니다.
	virtual void Enter() = 0;
	virtual void Exit() = 0;
};