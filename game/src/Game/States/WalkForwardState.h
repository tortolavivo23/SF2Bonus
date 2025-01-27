#pragma once
#include "CharacterState.h"

class GameCharacter;

class WalkForwardState : public CharacterState
{
public:
	void enter(GameCharacter* character);
	void updateState(GameCharacter* character);
	void exit(GameCharacter* character) {}
	static CharacterState& getInstance();

private:
	WalkForwardState() {}
	WalkForwardState(const WalkForwardState& other);
	WalkForwardState& operator=(const WalkForwardState& other);
};