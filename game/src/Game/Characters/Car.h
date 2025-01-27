#ifndef Car_CHAR_H
#define Car_CHAR_H

#pragma once

#include <map>
#include <string>

#include "Game/Characters/Character.h"


class Car : public GameCharacter
{
public:

	virtual void InitGameCharacter() override;
	virtual void UpdateGameCharacter(float deltaTime) override;
	virtual void DrawGameCharacter() override;
	virtual void UnloadGameCharacter() override;
	virtual void SetPosition(float x, float y) override;

	virtual void LoseHp(int p) override;


private:
	Texture2D sprites;

	int state;
};

#endif
