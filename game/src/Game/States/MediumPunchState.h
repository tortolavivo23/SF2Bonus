#pragma once
#include "CharacterState.h"

class GameCharacter;

class MediumPunchState : public CharacterState
{
public:
	void enter(GameCharacter* character);
	void updateState(GameCharacter* character);
	void exit(GameCharacter* character);
	static CharacterState& getInstance();

private:
	MediumPunchState() {}
	MediumPunchState(const MediumPunchState& other);
	MediumPunchState& operator=(const MediumPunchState& other);
};