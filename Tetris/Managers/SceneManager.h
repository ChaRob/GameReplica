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
	Scene* m_curScene;							// ���� Scene�� ����Ű�� ����
	Scene* m_arrScene[(UINT)SCENE_TYPE::END];	// ��� Scene�� ����� �����ϴ� �迭����

public:
	// �� Scene�� �ش��ϴ� �Լ����� �̰��� �����մϴ�.
	void Update();
	void Render();
	void LateUpdate();

	// �� Scene�� ���� � Scene�� �ε��ǰ� �ִ��� Ȯ���ϱ� ���� �Լ��� �����մϴ�.
	Scene* GetCurrentScene() const { return m_curScene; }
	void SetCurrentScene(SCENE_TYPE _scene);
};

#endif // !__DEF_SCENE_MANAGER__