
#pragma once

#include "ScreenGameplay.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"
#include "Game/GlobalGameDefines.h"

#include <string>


ScreenGameplayState::ScreenGameplayState()
{
}

ScreenGameplayState& ScreenGameplayState::getInstance()
{
	static ScreenGameplayState singleton;
	return singleton;
}

void ScreenGameplayState::InitScreen(void)
{
	framesCounter = 0;
	finishScreen = 0;
	TraceLog(LOG_INFO, "ScreenGameplay::InitScreen");

	GameManager& GameInst = GameManager::GetGameManager();
	textureManager = GameInst.getTextureManager();
	audioManager = GameInst.getAudioManager();

	audioManager.PlayGameMusic(true);

	GameInst.SetVictory(false);

	player.InitGameCharacter();
	player.SetPosition(GetScreenWidth() / 2, GetScreenHeight() * 4 / 7);
	player.SetGround(GetScreenHeight() * 4 / 7);

	car.InitGameCharacter();
	car.SetPosition(GetScreenWidth()/15, GetScreenHeight() * 5 / 8);

	time = 38;

	characters.push_back(&player);
	characters.push_back(&car);

}

void ScreenGameplayState::UpdateScreen(float deltaTime)
{
	GameManager& GameInst = GameManager::GetGameManager();
	EvaluateInput();
	audioManager.UpdateGameMusic();
	if (left) player.AdvanceLeft(deltaTime, characters);
	if (right) player.AdvanceRight(deltaTime, characters);
	player.UpdateGameCharacter(deltaTime);
	player.MakeHit(&car);
	car.UpdateGameCharacter(deltaTime);
	if (car.Death()) {
		finishScreen = 4;
		GameInst.SetVictory(true);
		audioManager.PlaySoundEffect(SoundType::Victory);
		audioManager.PlayGameMusic(false);
	}
	time -= deltaTime;
	if (time < 0) {
		finishScreen = 4;
		GameInst.SetVictory(false);
		audioManager.PlaySoundEffect(SoundType::Lose);
		audioManager.PlayGameMusic(false);
	}
	
}

void ScreenGameplayState::DrawScreen(void)
{

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	DrawTexture(textureManager.GetTexture(TextureType::Wallpaper), 0, 0, RAYWHITE);

	int timer = (int)time;
	float posYTimer = 30;
	if (timer >= 10) {
		textureManager.DrawNumber(timer % 10, { float(GetScreenWidth() / 2), posYTimer });
		textureManager.DrawNumber(timer / 10, { float(GetScreenWidth() / 2 - 62), posYTimer });
	}
	else {
		textureManager.DrawNumber(timer, { float(GetScreenWidth() / 2 - 31), posYTimer });
	}
	

	GameManager& GameInst = GameManager::GetGameManager();

	player.DrawGameCharacter();
	car.DrawGameCharacter();


}

void ScreenGameplayState::UnloadScreen(void)
{
	player.UnloadGameCharacter();
	car.UnloadGameCharacter();
}

int  ScreenGameplayState::FinishScreen(void)
{
	return finishScreen;
}

void ScreenGameplayState::EvaluateInput()
{

	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 4;   // END SCREEN
		audioManager.PlayGameMusic(false);
	}
	if (IsKeyPressed(KEY_UP))
	{
		player.Jump();
	}
	left = IsKeyDown(KEY_LEFT);
	right = IsKeyDown(KEY_RIGHT);
	if (IsKeyPressed(KEY_D)) {
		GameManager& GameInst = GameManager::GetGameManager();
		GameInst.SetDebug(!GameInst.GetDebug());
	}
}

void ScreenGameplayState::DebugOptions()
{

}

void ScreenGameplayState::DrawDebug()
{
	GameManager& GameInst = GameManager::GetGameManager();

}