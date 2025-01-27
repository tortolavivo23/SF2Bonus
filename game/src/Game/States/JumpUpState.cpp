#include "JumpUpState.h"
#include "IdleState.h"
#include "WalkBackwardState.h"
#include "WalkForwardState.h"

void JumpUpState::enter(GameCharacter* character)
{
	character->SetCharSpriteState(CharSpriteDirection::State_JumpUp);
}

void JumpUpState::updateState(GameCharacter* character)
{
	if (character->OnGround()) {
		if (IsKeyDown(KEY_LEFT))
		{
			character->setState(WalkForwardState::getInstance());
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			character->setState(WalkBackwardState::getInstance());
		}
		else {
			character->setState(IdleState::getInstance());
		}


	}
	
}

CharacterState& JumpUpState::getInstance()
{
	static JumpUpState singleton;
	return singleton;
}


