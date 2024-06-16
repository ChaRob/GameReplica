#pragma once

#ifndef __DEF_GAME_MANAGER__
#define __DEF_GAME_MANAGER__

class GameManager
{
private:
	GameManager();
	~GameManager();
	static GameManager* instance;
public:
	static GameManager* GetInstance() {
		if (instance == nullptr) {
			instance = new GameManager();
		}
		return instance;
	}
	int InitManager();
};

#endif // !__DEF_GAME_MANAGER__