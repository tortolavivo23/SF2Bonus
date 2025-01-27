#pragma once
#include "CharacterState.h"

class GameCharacter;

class JumpUpState : public CharacterState
{
public:
	void enter(GameCharacter* character);
	void updateState(GameCharacter* character);
	void exit(GameCharacter* character) {}
	static CharacterState& getInstance();

private:
	JumpUpState() {}
	JumpUpState(const JumpUpState& other);
	JumpUpState& operator=(const JumpUpState& other);
};