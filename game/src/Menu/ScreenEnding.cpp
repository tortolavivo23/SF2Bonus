#include "ScreenEnding.h"
#include "Game/Managers/GameManager.h"

#include "raylib.h"

#include <string>


ScreenEndingState& ScreenEndingState::getInstance()
{
	static ScreenEndingState singleton;
	return singleton;
}


void ScreenEndingState::InitScreen(void)
{
	framesCounter = 0;
	finishScreen = 0;
}

void ScreenEndingState::UpdateScreen(float deltaTime)
{
	if (IsKeyPressed(KEY_ENTER) )
	{
		finishScreen = 1; // GAMEPLAY

	}
	if (IsKeyPressed(KEY_O))
	{
		finishScreen = 2;   // OPTIONS
	}
}

void ScreenEndingState::DrawScreen(void)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
	GameManager& GameInst = GameManager::GetGameManager();

	AudioManager audioManager = GameInst.getAudioManager();

	// Write this in case of win
	if (GameInst.GetVictory()) {
		DrawText("YOU WIN!", (GetScreenWidth() / 2.f) - (MeasureText("YOU WIN!", 100) / 2), (GetScreenHeight() / 2.f) - 150, 100, WHITE);
	}
	else {
		DrawText("GAME OVER", (GetScreenWidth() / 2.f) - (MeasureText("GAME OVER", 100) / 2), (GetScreenHeight() / 2.f) - 150, 100, RED);
	}

	

	DrawText("Press Enter for Playing", (GetScreenWidth() / 2.f) - (MeasureText("Press Enter for Playing", 25) / 2), (GetScreenHeight() / 2.f) + 50, 25, WHITE);
	DrawText("Press 'O' for Instructions", (GetScreenWidth() / 2.f) - (MeasureText("Press 'O' for Instructions", 25) / 2), (GetScreenHeight() / 2.f) + 100, 25, WHITE);

}

void ScreenEndingState::UnloadScreen(void)
{
	//Let's unload all the enemies lines
	GameManager& GameInst = GameManager::GetGameManager();

}

int  ScreenEndingState::FinishScreen(void)
{
	return finishScreen;
}