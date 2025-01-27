#include "MediumPunchState.h"
#include "IdleState.h"

void MediumPunchState::enter(GameCharacter* character)
{
	character->SetCharSpriteState(CharSpriteDirection::State_MediumPunch);
}

void MediumPunchState::updateState(GameCharacter* character)
{
	if (character->GetAnimEnd() > 1) {
		character->setState(IdleState::getInstance());
	}
}

void MediumPunchState::exit(GameCharacter* character)
{
	character->SetAnimEnd(-1);
}

CharacterState& MediumPunchState::getInstance()
{
	static MediumPunchState singleton;
	return singleton;
}


