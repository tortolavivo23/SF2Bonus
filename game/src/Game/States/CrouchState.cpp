#include "CrouchState.h"
#include "IdleState.h"
#include "LightPunchCrouchState.h"

void CrouchState::enter(GameCharacter* character)
{
	character->SetCharSpriteState(CharSpriteDirection::State_Crouch);
}

void CrouchState::updateState(GameCharacter* character)
{
	if (!IsKeyDown(KEY_DOWN)) {
		character->setState(IdleState::getInstance());
	}
	else if (IsKeyPressed(KEY_Q)) {
		character->setState(LightPunchCrouchState::getInstance());
	}
}

CharacterState& CrouchState::getInstance()
{
	static CrouchState singleton;
	return singleton;
}


