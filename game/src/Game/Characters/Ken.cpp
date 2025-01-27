#pragma once

#include "Game/Characters/Character.h"
#include "Game/Characters/Ken.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/GameManager.h"
#include "Game/States/IdleState.h"

#include <string>             // String manipulation functions: strrchr(), strcmp()

#include "raylib.h"


void Ken::InitGameCharacter()
{
	sprites = LoadTexture("resources/Game/Sprites/Ken/KenBasicMovementsSpritesClean.png");

	punchSprites = LoadTexture("resources/Game/Sprites/Ken/KenPunchMovementsSprites.png");

	spriteState = CharSpriteDirection::State_Idle;

	//Let's fill the vector KenSprtes Data
	
	//IDLE
	CharSprites_Counter[CharSpriteDirection::State_Idle] = 4;

	CharSprites_Idle[0] = FrameRecPos{ {4,4,260,386}, {0.f, 0.f} };
	CharSprites_Idle[1] = FrameRecPos{ {264,4,260,386}, {0.f, 0.f}};
	CharSprites_Idle[2] = FrameRecPos{ {524,4,260,386}, {0.f, 0.f}};
	CharSprites_Idle[3] = FrameRecPos{ {784,4,260,386}, {0.f, 0.f}};
	
	//WALK FORWARD
	CharSprites_Counter[CharSpriteDirection::State_WalkForward] = 5;

	CharSprites_WalkForward[0] = FrameRecPos{ {4,1493,260,386}, {0.f, 0.f} };
	CharSprites_WalkForward[1] = FrameRecPos{ {322,1493,260,386}, {0.f, 0.f}};
	CharSprites_WalkForward[2] = FrameRecPos{ {612,1493,260,386}, {0.f, 0.f}};
	CharSprites_WalkForward[3] = FrameRecPos{ {964,1493,260,386}, {0.f, 0.f}};
	CharSprites_WalkForward[4] = FrameRecPos{ {1237,1493,260,386}, {0.f, 0.f} };

	//WALK BACKWARDS
	CharSprites_Counter[CharSpriteDirection::State_WalkBackward] = 6;

	CharSprites_WalkBackward[0] = FrameRecPos{ {4,1878,260,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[1] = FrameRecPos{ {264,1878,260,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[2] = FrameRecPos{ {524,1878,260,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[3] = FrameRecPos{ {783,1878,321,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[4] = FrameRecPos{ {1107,1878,260,386}, {0.f, 0.f} };
	CharSprites_WalkBackward[5] = FrameRecPos{ {1367,1878,260,386}, {0.f, 0.f} };

	// JUMP UP
	CharSprites_Counter[CharSpriteDirection::State_JumpUp] = 6;

	CharSprites_JumpUp[0] = FrameRecPos{ {4,2718,260,446}, {0.f, 0.f} };
	CharSprites_JumpUp[1] = FrameRecPos{ {264,2718,260,446}, {0.f, 0.f} };
	CharSprites_JumpUp[2] = FrameRecPos{ {524,2718,260,384}, {0.f, 0.f} };
	CharSprites_JumpUp[3] = FrameRecPos{ {784,2718,260,384}, {0.f, 0.f} };
	CharSprites_JumpUp[4] = FrameRecPos{ {1044,2718,260,384}, {0.f, 0.f} };
	CharSprites_JumpUp[5] = FrameRecPos{ {1304,2718,260,446}, {0.f, 0.f} };

	// CROUCH
	CharSprites_Counter[CharSpriteDirection::State_Crouch] = 3;

	CharSprites_Crouch[0] = FrameRecPos{ {4,842,260,386}, {0.f, 0.f} };
	CharSprites_Crouch[1] = FrameRecPos{ {264,842,321,386}, {0.f, 0.f} };
	CharSprites_Crouch[2] = FrameRecPos{ {586,842,320,386}, {0.f, 0.f} };

	// LIGHT PUNCH
	CharSprites_Counter[CharSpriteDirection::State_LightPunch] = 2;
	CharSprites_LightPunch[0] = FrameRecPos{ {4,4,260,386}, {0.f, 0.f} };
	CharSprites_LightPunch[1] = FrameRecPos{ {374,4,450,386}, {125.f, 0.f } };

	// MEDIUM PUNCH
	CharSprites_Counter[CharSpriteDirection::State_MediumPunch] = 3;

	CharSprites_MediumPunch[0] = FrameRecPos{ {4,390,322,382}, {0.f, 0.f} };
	CharSprites_MediumPunch[1] = FrameRecPos{ {328,390,317,382}, {0.f, 0.f} };
	CharSprites_MediumPunch[2] = FrameRecPos{ {652,390,508,382}, {170.f, 0.f} };

	// LIGHT PUNCH CROUCH
	CharSprites_Counter[CharSpriteDirection::State_LightPunchCrouch] = 2;

	CharSprites_LightPunchCrouch[0] = FrameRecPos{ {4,2134,277,249}, {0.f, -125.f} };
	CharSprites_LightPunchCrouch[1] = FrameRecPos{ {347,2134,387,249}, {125.f, -125.f} };

	//init State
	currentState = &IdleState::getInstance();

}

void Ken::UpdateGameCharacter(float deltaTime)
{
	if (jump) {
		if (falling) {
			position.y += m_KenJump_Speed * deltaTime;
		}
		else {
			position.y -= m_KenJump_Speed * deltaTime;
		}
		if (position.y < groundY - 220) {
			position.y = groundY - 220;
			falling = true;
		}
		else if (position.y > groundY) {
			position.y = groundY;
			jump = false;
			m_bcanJump = true;
		}
	}
	//Update State Machine
	updateState();

	// add here the updateframe logic to be able to see all the sprites from one state
	framesCounter++;
	if (framesCounter >= (60 / framesSpeed)) 
	{
		framesCounter = 0;
		currentFrame++;

		//TODO make it generic for every state, this is only valid for Idle
		int totalNumFrames = CharSprites_Counter[spriteState];

		if (currentFrame > totalNumFrames - 1)
		{
			if (spriteState == CharSpriteDirection::State_LightPunch ||
				spriteState == CharSpriteDirection::State_MediumPunch ||
				spriteState == CharSpriteDirection::State_LightPunchCrouch) {
				endAnim++;
				currentFrame = totalNumFrames - 1;
			}
			else if (spriteState != CharSpriteDirection::State_JumpUp &&
				spriteState != CharSpriteDirection::State_Crouch)
				currentFrame = 0;
			else currentFrame = totalNumFrames - 1;
		}
	}
	hitbox = { position.x + 70, position.y + 50, 120, 286 };
	if (spriteState == CharSpriteDirection::State_LightPunchCrouch || spriteState == CharSpriteDirection::State_Crouch) {
		hitbox.y = position.y + 125 + 50;
		hitbox.height = 161;
	}

	punchHitbox = { -1, -1, -1, -1 };
	if (spriteState == CharSpriteDirection::State_LightPunch ||
		spriteState == CharSpriteDirection::State_MediumPunch ||
		spriteState == CharSpriteDirection::State_LightPunchCrouch &&
		CharSprites_Counter[spriteState] - 1 == currentFrame) {

		punchHitbox = {hitbox.x - 190, hitbox.y + 15, 190, 60};
	}
}

void Ken::DrawGameCharacter()
{
	TextureManager textureManager = GameManager::GetGameManager().getTextureManager();
	char* state = "no state";
	switch (spriteState) {
		case CharSpriteDirection::State_Idle:
			textureManager.DrawTextureOriginRec(sprites, CharSprites_Idle[currentFrame].frameRec, position, WHITE,CharSprites_Idle[currentFrame].frameOrigin);
			state = "Idle";
			break;
		case CharSpriteDirection::State_WalkForward:
			textureManager.DrawTextureOriginRec(sprites, CharSprites_WalkForward[currentFrame].frameRec, position, WHITE, CharSprites_WalkForward[currentFrame].frameOrigin);
			state = "WalkForward";
			break;
		case CharSpriteDirection::State_WalkBackward:
			textureManager.DrawTextureOriginRec(sprites, CharSprites_WalkBackward[currentFrame].frameRec, position, WHITE, CharSprites_WalkBackward[currentFrame].frameOrigin);
			state = "WalkBackward";
			break;
		case CharSpriteDirection::State_JumpUp:
			textureManager.DrawTextureOriginRec(sprites, CharSprites_JumpUp[currentFrame].frameRec, position, WHITE, CharSprites_JumpUp[currentFrame].frameOrigin);
			state = "JumpUp";
			break;
		case CharSpriteDirection::State_Crouch:
			textureManager.DrawTextureOriginRec(sprites, CharSprites_Crouch[currentFrame].frameRec, position, WHITE, CharSprites_Crouch[currentFrame].frameOrigin);
			state = "Crouch";
			break;
		case CharSpriteDirection::State_LightPunch:
			textureManager.DrawTextureOriginRec(punchSprites, CharSprites_LightPunch[currentFrame].frameRec, position, WHITE, CharSprites_LightPunch[currentFrame].frameOrigin);
			state = "LightPunch";
			break;
		case CharSpriteDirection::State_MediumPunch:
			textureManager.DrawTextureOriginRec(punchSprites, CharSprites_MediumPunch[currentFrame].frameRec, position, WHITE, CharSprites_MediumPunch[currentFrame].frameOrigin);
			state = "MediumPunch";
			break;
		case CharSpriteDirection::State_LightPunchCrouch:
			textureManager.DrawTextureOriginRec(punchSprites, CharSprites_LightPunchCrouch[currentFrame].frameRec, position, WHITE, CharSprites_LightPunchCrouch[currentFrame].frameOrigin);
			state = "LightPunchCrouch";
			break;
	}
	if (GameManager::GetGameManager().GetDebug()) {
		DrawRectangleRec(hitbox, YELLOW);
		if (punchHitbox.x >= 0) {
			DrawRectangleRec(punchHitbox, RED);
		}
		DrawText(state, 20, 20, 20, RED);
		DrawText(to_string(currentFrame).c_str(), 20, 40, 20, RED);
	}
}

void Ken::UnloadGameCharacter()
{
	UnloadTexture(sprites);
	UnloadTexture(punchSprites);
}

bool Ken::CanJump() {
	return m_bcanJump &&
		spriteState != CharSpriteDirection::State_Crouch &&
		spriteState != CharSpriteDirection::State_LightPunch &&
		spriteState != CharSpriteDirection::State_LightPunchCrouch &&
		spriteState != CharSpriteDirection::State_MediumPunch;
}

void Ken::Jump()
{
	if (CanJump()) {
		jump = true;
		m_bcanJump = false;
		falling = false;
	}
	
}

bool Ken::CanWalk() {
	return (spriteState != CharSpriteDirection::State_Crouch &&
		spriteState != CharSpriteDirection::State_LightPunch &&
		spriteState != CharSpriteDirection::State_LightPunchCrouch &&
		spriteState != CharSpriteDirection::State_MediumPunch);
}

void Ken::AdvanceLeft(float deltaTime, vector<GameCharacter*>& characters)
{
	float futureHitboxX = hitbox.x - m_Ken_Horizontal_Speed * deltaTime;
	bool check = CanWalk() && futureHitboxX >= 0;
	for (GameCharacter* other : characters) {
		if (other == this) continue;
		check &= !GameCharacter::CheckCollision({ futureHitboxX, hitbox.y, hitbox.width, hitbox.height }, other->GetHitbox());
	}
	if (check) {
		position.x -= m_Ken_Horizontal_Speed * deltaTime;
	}
}

void Ken::AdvanceRight(float deltaTime, vector<GameCharacter*>& characters)
{
	float futureHitboxX = hitbox.x + m_Ken_Horizontal_Speed * deltaTime;
	bool check = CanWalk() && futureHitboxX <= GetScreenWidth() - hitbox.width;
	for (GameCharacter* other : characters) {
		if (other == this) continue;
		check &= !GameCharacter::CheckCollision({ futureHitboxX, hitbox.y, hitbox.width, hitbox.height}, other->GetHitbox());
	}
	if (check) {
		position.x += m_Ken_Horizontal_Speed * deltaTime;
	}
}

void Ken::MakeHit(GameCharacter* hitted)
{
	if (canHit && punchHitbox.x >= 0 && GameCharacter::CheckCollision(punchHitbox, hitted->GetHitbox())) {
		canHit = false;
		hitted->LoseHp(GetDamage());
	}
}

int Ken::GetDamage()
{
	switch (spriteState) {
		case CharSpriteDirection::State_LightPunch: return 5;
		case CharSpriteDirection::State_LightPunchCrouch: return 5;
		case CharSpriteDirection::State_MediumPunch: return 10;
		default: return 0;
	}
}

// State Machines
void Ken::setState(CharacterState& newState)
{
	currentFrame = 0;
	canHit = true;

	currentState->exit(this);  // do something before we change state
	currentState = &newState;  // change state
	currentState->enter(this); // do something after we change state
	if (spriteState == CharSpriteDirection::State_LightPunch ||
		spriteState == CharSpriteDirection::State_MediumPunch ||
		spriteState == CharSpriteDirection::State_LightPunchCrouch)
	{
		AudioManager audioManager = GameManager::GetGameManager().getAudioManager();
		audioManager.PlaySoundEffect(SoundType::Punch);
	}
}

void Ken::updateState()
{
	// Delegate the task of determining the next state to the current state!
	currentState->updateState(this);
}

