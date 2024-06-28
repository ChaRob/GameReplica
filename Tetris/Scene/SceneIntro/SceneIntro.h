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
	// Scene에 존재하는 object들의 기본 함수들을 호출합니다.
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void LateUpdate();
	virtual void Exit();
};