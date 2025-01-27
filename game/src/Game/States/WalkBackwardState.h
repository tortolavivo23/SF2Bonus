#pragma once
#include "CharacterState.h"

class GameCharacter;

class WalkBackwardState : public CharacterState
{
public:
	void enter(GameCharacter* character);
	void updateState(GameCharacter* character);
	void exit(GameCharacter* character) {}
	static CharacterState& getInstance();

private:
	WalkBackwardState() {}
	WalkBackwardState(const WalkBackwardState& other);
	WalkBackwardState& operator=(const WalkBackwardState& other);
};