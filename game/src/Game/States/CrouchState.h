#pragma once
#include "CharacterState.h"

class GameCharacter;

class CrouchState : public CharacterState
{
public:
	void enter(GameCharacter* character);
	void updateState(GameCharacter* character);
	void exit(GameCharacter* character) {}
	static CharacterState& getInstance();

private:
	CrouchState() {}
	CrouchState(const CrouchState& other);
	CrouchState& operator=(const CrouchState& other);
};