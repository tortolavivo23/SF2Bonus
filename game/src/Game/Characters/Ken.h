#ifndef Ken_CHAR_H
#define Ken_CHAR_H

#pragma once

#include <map>
#include <string>

#include "Game/Characters/Character.h"


class Ken : public GameCharacter
{
public:

	virtual void InitGameCharacter() override;
	virtual void UpdateGameCharacter(float deltaTime) override;
	virtual void DrawGameCharacter() override;
	virtual void UnloadGameCharacter() override;

	virtual void Jump() override;
	virtual void AdvanceLeft(float deltaTime, std::vector<GameCharacter*>& characters) override;
	virtual void AdvanceRight(float deltaTime, std::vector<GameCharacter*>& characters) override;

	virtual void MakeHit(GameCharacter* hitted) override;

	//State Machine
	virtual void updateState();
	// This will get called by the current state
	virtual void setState(CharacterState& newState) override;



	float GetKenJumpSpeed() { return m_KenJump_Speed; }
	float GetKenHorzontalSpeed() { return m_Ken_Horizontal_Speed; }
	float GetKenVerticalSpeed() { return m_Ken_Vertical_Speed; }

	float GetKenCurrentSpeed() { return m_Speed; }
	void  SetKenCurrentSpeed(float newSpeed) { m_Speed = newSpeed; }

	bool GetKenCanJump() { return m_bcanJump; }
	void SetKenCanJump(bool newCanJump) { m_bcanJump = newCanJump; }

	void SetCanHit(bool b) { canHit = b; };

private:
	bool CanWalk();
	bool CanJump();
	int GetDamage();

private:

	const float m_KenJump_Speed = 600.f;
	const float m_Ken_Horizontal_Speed = 300.f;
	const float m_Ken_Vertical_Speed = 100.f;

	float m_Speed = {0.f};
	bool m_bcanJump = true;

	bool falling = false;

	Texture2D sprites;
	Texture2D punchSprites;

	bool canHit;
};

#endif
