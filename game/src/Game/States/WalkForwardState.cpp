#include "WalkForwardState.h"
#include "IdleState.h"
#include "WalkBackwardState.h"
#include "JumpUpState.h"
#include "CrouchState.h"

void WalkForwardState::enter(GameCharacter* character)
{
	character->SetCharSpriteState(CharSpriteDirection::State_WalkForward);
}

void WalkForwardState::updateState(GameCharacter* character)
{
	if (IsKeyPressed(KEY_UP)) {
		character->setState(JumpUpState::getInstance());
	}
	else if (IsKeyPressed(KEY_DOWN)) {
		character->setState(CrouchState::getInstance());
	}
	else if (IsKeyReleased(KEY_LEFT) && IsKeyDown(KEY_RIGHT)) {
		character->setState(WalkBackwardState::getInstance());
	}
	else if (IsKeyReleased(KEY_LEFT))
	{
		character->setState(IdleState::getInstance());
	}
}

CharacterState& WalkForwardState::getInstance()
{
	static WalkForwardState singleton;
	return singleton;
}


