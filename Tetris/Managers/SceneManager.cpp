#include "SceneManager.h"
#include "../Scene/SceneIntro/SceneIntro.h"

SceneManager SceneManager::instance;

SceneManager::SceneManager():
	m_curScene(nullptr), m_arrScene{}
{
}

SceneManager::~SceneManager()
{
	// ������ ��� Scene�� �����մϴ�.
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; i++)
	{
		if (m_arrScene[i] != nullptr) delete m_arrScene[i];
	}
}

void SceneManager::InitManager()
{
	m_arrScene[(UINT)SCENE_TYPE::INTRO] = new SceneIntro;
	//m_arrScene[(UINT)SCENE_TYPE::]

	// ó���� �����ϴ� Scene�� Intro Scene���� �����մϴ�.
	m_curScene = m_arrScene[(UINT)SCENE_TYPE::INTRO];
	m_curScene->Enter();
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
