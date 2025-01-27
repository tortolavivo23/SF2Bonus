#include "Character.h"

#include "Game/Managers/GameManager.h"
#include "Game/States/CharacterState.h"

#include "raylib.h"

GameCharacter::GameCharacter()
{
}

void GameCharacter::InitGameCharacter ()
{
	currentFrame = 0;

	framesCounter = 0;
	framesSpeed = 8;
}

void GameCharacter::UpdateGameCharacter(float deltaTime)
{

}

void GameCharacter::DrawGameCharacter()
{
}

void GameCharacter::UnloadGameCharacter()
{

}

void GameCharacter::Jump()
{
}

void GameCharacter::AdvanceLeft(float deltaTime, vector<GameCharacter*>& characters)
{
}

void GameCharacter::AdvanceRight(float deltaTime, vector<GameCharacter*>& characters)
{
}

void GameCharacter::MakeHit(GameCharacter* hitted)
{
}

bool GameCharacter::CheckCollision(Rectangle rec1, Rectangle rec2)
{
	return CheckCollisionRecs(rec1, rec2);
}




// State Machines
void GameCharacter::setState(CharacterState& newState)
{
	currentState->exit(this);  // do something before we change state
	currentState = &newState;  // change state
	currentState->enter(this); // do something after we change state
	framesCounter = 0;
}

void GameCharacter::updateState()
{
	// Delegate the task of determining the next state to the current state!
	currentState->updateState(this);
}