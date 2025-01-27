#include "WalkBackwardState.h"
#include "WalkForwardState.h"
#include "IdleState.h"
#include "JumpUpState.h"
#include "CrouchState.h"

void WalkBackwardState::enter(GameCharacter* character)
{
	character->SetCharSpriteState(CharSpriteDirection::State_WalkBackward);
}

void WalkBackwardState::updateState(GameCharacter* character)
{
	if (IsKeyPressed(KEY_UP)) {
		character->setState(JumpUpState::getInstance());
	}
	else if (IsKeyPressed(KEY_DOWN)) {
		character->setState(CrouchState::getInstance());
	}
	else if (IsKeyReleased(KEY_RIGHT) && IsKeyDown(KEY_LEFT)) {
		character->setState(WalkForwardState::getInstance());
	}
	else if (IsKeyReleased(KEY_RIGHT))
	{
		character->setState(IdleState::getInstance());
	}
}

CharacterState& WalkBackwardState::getInstance()
{
	static WalkBackwardState singleton;
	return singleton;
}


