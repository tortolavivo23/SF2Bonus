#pragma once
#include "CharacterState.h"

class GameCharacter;

class LightPunchState : public CharacterState
{
public:
	void enter(GameCharacter* character);
	void updateState(GameCharacter* character);
	void exit(GameCharacter* character);
	static CharacterState& getInstance();

private:
	LightPunchState() {}
	LightPunchState(const LightPunchState& other);
	LightPunchState& operator=(const LightPunchState& other);
};