#pragma once

#ifndef __DEF_SCENE_MANAGER__
#define __DEF_SCENE_MANAGER__

#include "../pch.h"
#include "../Scene/Scene.h"

class SceneManager
{
private:
	SceneManager();
	~SceneManager();
	static SceneManager instance;

public:
	static SceneManager* GetInstance() {
		return &instance;
	}
private:
	Scene* m_curScene;							// 현재 Scene을 가리키는 변수
	Scene* m_arrScene[(UINT)SCENE_TYPE::END];	// 모든 Scene의 목록을 저장하는 배열변수

public:
	// 각 Scene에 해당하는 함수들을 이곳에 정리합니다.
	void Update();
	void Render();
	void LateUpdate();

	// 각 Scene에 들어가고 어떤 Scene이 로딩되고 있는지 확인하기 위한 함수를 정의합니다.
	Scene* GetCurrentScene() const { return m_curScene; }
	void SetCurrentScene(SCENE_TYPE _scene);
};

#endif // !__DEF_SCENE_MANAGER__