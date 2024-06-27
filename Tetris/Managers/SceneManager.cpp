#include "SceneManager.h"

SceneManager SceneManager::instance;

SceneManager::SceneManager():
	m_curScene(nullptr), m_arrScene{}
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
	m_curScene->Update();
}

void SceneManager::Render()
{
	m_curScene->Render();
}

void SceneManager::LateUpdate()
{
	m_curScene->LateUpdate();
}

void SceneManager::SetCurrentScene(SCENE_TYPE _scene)
{
	m_curScene->Exit();
	m_curScene = m_arrScene[(UINT)_scene];
	m_curScene->Enter();
}
