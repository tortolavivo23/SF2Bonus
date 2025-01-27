#include "LightPunchCrouchState.h"
#include "CrouchState.h"

void LightPunchCrouchState::enter(GameCharacter* character)
{
	character->SetCharSpriteState(CharSpriteDirection::State_LightPunchCrouch);
}

void LightPunchCrouchState::updateState(GameCharacter* character)
{
	if (character->GetAnimEnd() > 1) {
		character->setState(CrouchState::getInstance());
	}
}

void LightPunchCrouchState::exit(GameCharacter* character)
{
	character->SetAnimEnd(-1);
	character->currentFrame = 2;
}

CharacterState& LightPunchCrouchState::getInstance()
{
	static LightPunchCrouchState singleton;
	return singleton;
}


