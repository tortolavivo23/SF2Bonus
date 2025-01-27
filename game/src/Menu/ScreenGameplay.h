#pragma once
#include "StateMachineMngr.h"
#include "../Game/Managers/TexturesManager.h"
#include "../Game/Managers/AudioManager.h"
#include <Game/Characters/Ken.h>
#include <Game/Characters/Car.h>

class ScreenGameplayState : public StateMachineMngr
{
public:

	void enter(Screen* screen) {}
	void toggle(Screen* screen) {};
	void exit(Screen* screen) {};

	virtual void InitScreen(void);
	virtual void UpdateScreen(float deltaTime);
	virtual void DrawScreen(void);
	virtual void UnloadScreen(void);
	virtual int FinishScreen(void);

	int getScreenId() { return (int)ScreenState::GAMEPLAY; }

	static ScreenGameplayState& getInstance();

private:
	ScreenGameplayState();
	ScreenGameplayState(const ScreenGameplayState& other);
	ScreenGameplayState& operator= (const ScreenGameplayState& other);

	void EvaluateInput();
	
	void DebugOptions();
	void DrawDebug();

	int framesCounter = 0;
	int finishScreen = 0;
	bool mb_ReplayLevel = false;

	bool debug_floor = false;
	bool debug_stairs = false;

	TextureManager textureManager;
	AudioManager audioManager;

	Ken player;

	Car car;

	std::vector<GameCharacter*> characters;

	bool left = false;
	bool right = false;

	float time;

};