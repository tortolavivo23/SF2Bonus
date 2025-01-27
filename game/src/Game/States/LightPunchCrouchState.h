#pragma once
#include "CharacterState.h"

class GameCharacter;

class LightPunchCrouchState : public CharacterState
{
public:
	void enter(GameCharacter* character);
	void updateState(GameCharacter* character);
	void exit(GameCharacter* character);
	static CharacterState& getInstance();

private:
	LightPunchCrouchState() {}
	LightPunchCrouchState(const LightPunchCrouchState& other);
	LightPunchCrouchState& operator=(const LightPunchCrouchState& other);
};