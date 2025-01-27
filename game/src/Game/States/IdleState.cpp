#include "IdleState.h"
#include "WalkForwardState.h"
#include "WalkBackwardState.h"
#include "JumpUpState.h"
#include "CrouchState.h"
#include "LightPunchState.h"
#include "MediumPunchState.h"


void IdleState::enter(GameCharacter* character) 
{
	character->SetCharSpriteState(CharSpriteDirection::State_Idle);
}

void IdleState::updateState(GameCharacter* character)
{
	if (IsKeyPressed(KEY_UP))
	{
		character->setState(JumpUpState::getInstance());
	}
	else if (IsKeyPressed(KEY_Q)) {
		character->setState(LightPunchState::getInstance());
	}
	else if (IsKeyPressed(KEY_W)) {
		character->setState(MediumPunchState::getInstance());
	}
	else if (IsKeyDown(KEY_DOWN)) {
		character->setState(CrouchState::getInstance());
	}
	else if (IsKeyDown(KEY_LEFT))
	{
		character->setState(WalkForwardState::getInstance());
	}
	else if (IsKeyDown(KEY_RIGHT))
	{
		character->setState(WalkBackwardState::getInstance());
	}
	

	// add more states

}

CharacterState& IdleState::getInstance()
{
	static IdleState singleton;
	return singleton;
}

