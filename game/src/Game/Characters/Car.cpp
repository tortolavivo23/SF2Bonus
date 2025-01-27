#pragma once

#include "Game/Characters/Character.h"
#include "Game/Characters/Car.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/GameManager.h"
#include "Game/States/IdleState.h"

#include <string>             // String manipulation functions: strrchr(), strcmp()

#include "raylib.h"


void Car::InitGameCharacter()
{
	sprites = LoadTexture("resources/Game/Sprites/Car/CarBouns.png");

	state = 1;

	hp = 100;

	CarSprites[0] = FrameRecPos{ {0,0,725,360}, {0.f, 0.f} };

	CarSprites[1] = FrameRecPos{ {0,360,725,360}, {-10.f, 30.f} };

	CarSprites[2] = FrameRecPos{ {0,688,725,360}, {-5.f, 30.f} };

	CarSprites[3] = FrameRecPos{ {725,688,680,360}, {-45.f, 30.f} };

	CarSprites[4] = FrameRecPos{ {35,1035,680,325}, {-50.f, 15.f} };

	CarSprites[5] = FrameRecPos{ {725,1035,680,325}, {-60.f, 7.f} };

	CarSprites[6] = FrameRecPos{ {35,1350,672,265}, {-55.f, -60.f} };

	CarSprites[7] = FrameRecPos{ {710,1350,672,265}, {-180.f, -60.f} };

}

void Car::UpdateGameCharacter(float deltaTime)
{
	if (hp > 85) state = 1;
	else if (hp > 70) state = 2;
	else if (hp > 50) state = 3;
	else if (hp > 35) state = 4;
	else if (hp > 25) state = 5;
	else if (hp > 15) state = 6;
	else if (hp > 5) state = 7;
	else state = 0;
}

void Car::DrawGameCharacter()
{
	TextureManager textureManager = GameManager::GetGameManager().getTextureManager();

	textureManager.DrawTextureOriginRec(sprites, CarSprites[0].frameRec, position, RAYWHITE, CarSprites[0].frameOrigin);
	textureManager.DrawTextureOriginRec(sprites, CarSprites[state].frameRec, position, RAYWHITE, CarSprites[state].frameOrigin);
	
	if (GameManager::GetGameManager().GetDebug()) {
		DrawRectangleRec(hitbox, GREEN);
	}
}

void Car::UnloadGameCharacter()
{
	UnloadTexture(sprites);
}

void Car::SetPosition(float x, float y)
{
	GameCharacter::SetPosition(x, y);
	hitbox = { position.x + 185, position.y + 25, 275, 330 };
}

void Car::LoseHp(int p)
{
	GameCharacter::LoseHp(p);
	if (p > 0) {
		AudioManager audioManager = GameManager::GetGameManager().getAudioManager();
		audioManager.PlaySoundEffect(SoundType::Hit);
	}
}


