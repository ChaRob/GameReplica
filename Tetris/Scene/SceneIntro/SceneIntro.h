#pragma once
#include "../../pch.h"
#include "../../Object/Object.h"
#include "../Scene.h"

using namespace std;

class SceneIntro : public Scene
{
public:
	SceneIntro();
	~SceneIntro();

private:

public:
	// Scene�� �����ϴ� object���� �⺻ �Լ����� ȣ���մϴ�.
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void LateUpdate();
	virtual void Exit();
};