#ifndef CHARACTER_H
#define CHARACTER_H
#endif 

#include "raylib.h"
#include <map>
#include <vector>

class CharacterState;
#pragma once

enum class CharSpriteDirection
{
	State_Idle = 0,
	State_WalkForward,
	State_WalkBackward,
	State_Crouch,
	State_JumpUp,
	State_LightPunch,
	State_MediumPunch,
	State_LightPunchCrouch,
};

struct FrameRecPos
{
	Rectangle frameRec;
	Vector2   frameOrigin;
};


class GameCharacter
{
public :
	GameCharacter();

	virtual void InitGameCharacter();
	virtual void UpdateGameCharacter(float deltaTime);
	virtual void DrawGameCharacter();
	virtual void UnloadGameCharacter();

	virtual void SetPosition(float x, float y) { position = { x, y }; }
	void SetGround(float y) { groundY = y; }

	bool OnGround() { return position.y == groundY; };

	virtual void Jump();
	virtual void AdvanceLeft(float deltaTime, std::vector<GameCharacter*>& characters);
	virtual void AdvanceRight(float deltaTime, std::vector<GameCharacter*>& characters);

	void SetCharSpriteState(CharSpriteDirection c) { spriteState = c; };

	float GetAnimEnd() { return endAnim; };
	void SetAnimEnd(float b) { endAnim = b; };

	Rectangle GetHitbox() { return hitbox; };

	virtual void MakeHit(GameCharacter* hitted);

	virtual void LoseHp(int p) { hp -= p; };

	virtual bool Death() { return hp <= 0; };

protected:
	static bool CheckCollision(Rectangle r1, Rectangle r2);
	
protected:

	std::map<CharSpriteDirection, int> CharSprites_Counter;
	
	std::map<int, FrameRecPos> CharSprites_Idle;
	std::map<int, FrameRecPos> CharSprites_WalkForward;
	std::map<int, FrameRecPos> CharSprites_WalkBackward;
	std::map<int, FrameRecPos> CharSprites_Crouch;
	std::map<int, FrameRecPos> CharSprites_JumpUp;
	std::map<int, FrameRecPos> CharSprites_LightPunch;
	std::map<int, FrameRecPos> CharSprites_MediumPunch;
	std::map<int, FrameRecPos> CharSprites_LightPunchCrouch;


	int CarSprites_Counter = 10;
	std::map<int, FrameRecPos> CarSprites;

	float groundY = 0;
	bool jump = false;


public:	
	int framesCounter = 0;
	int framesSpeed = 10;
	int currentFrame = 0;

	// State Mahines functions
	inline CharacterState* getCurrentState() const { return currentState; }
	// In here, we'll delegate the state transition to the currentState
	void updateState();
	// This will get called by the current state
	virtual void setState(CharacterState& newState);

protected:
		
	CharacterState* currentState;
	CharSpriteDirection spriteState;
	Vector2 position;

	Rectangle hitbox;
	Rectangle punchHitbox;

	float endAnim;

	int hp;
};


