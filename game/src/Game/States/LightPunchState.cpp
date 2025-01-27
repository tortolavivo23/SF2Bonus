#include "LightPunchState.h"
#include "IdleState.h"

void LightPunchState::enter(GameCharacter* character)
{
	character->SetCharSpriteState(CharSpriteDirection::State_LightPunch);
}

void LightPunchState::updateState(GameCharacter* character)
{
	if (character->GetAnimEnd() > 1) {
		character->setState(IdleState::getInstance());
	}
}

void LightPunchState::exit(GameCharacter* character)
{
	character->SetAnimEnd(-1);
}

CharacterState& LightPunchState::getInstance()
{
	static LightPunchState singleton;
	return singleton;
}


