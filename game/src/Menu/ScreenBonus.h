
#pragma once
#include "StateMachineMngr.h"
#include "Screen.h"

class ScreenBonusState : public StateMachineMngr
{
public:

	void enter(Screen* screen){}
	void toggle(Screen* screen){};
	void exit(Screen* screen){};

	void InitScreen(void);
	void UpdateScreen(float deltaTime);
	void DrawScreen(void);
	void UnloadScreen(void);
	int FinishScreen(void);

	int getScreenId() { return (int)ScreenState::BONUS; }

	static ScreenBonusState& getInstance();

private:

	ScreenBonusState(){};
	ScreenBonusState(const ScreenBonusState& other);
	ScreenBonusState& operator= (const ScreenBonusState& other);

	int framesCounter = 0;
	int finishScreen = 0;

	float seconds = 0;

};