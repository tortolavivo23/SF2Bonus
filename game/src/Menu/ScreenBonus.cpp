#include "ScreenBonus.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"

ScreenBonusState& ScreenBonusState::getInstance()
{
	static ScreenBonusState singleton;
	return singleton;
}


void ScreenBonusState::InitScreen(void)
{
	framesCounter = 0;
	finishScreen = 0;
	TraceLog(LOG_INFO, "ScreenBonusState::InitScreen");

	// Use this to access to the Game instance
	GameManager& GameInst = GameManager::GetGameManager();

	seconds = 0;

	AudioManager audioManager = GameInst.getAudioManager();
	audioManager.PlayKenMusic(true);
}

void ScreenBonusState::UpdateScreen(float deltaTime)
{
	GameManager& GameInst = GameManager::GetGameManager();
	seconds += deltaTime;
	AudioManager audioManager = GameInst.getAudioManager();
	audioManager.UpdateKenMusic();
	if (seconds >= 3) {
		finishScreen = 1;
		audioManager.PlayKenMusic(false);
	}



}

void ScreenBonusState::DrawScreen(void)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();

	Texture2D image = GameInst.getTextureManager().GetTexture(TextureType::KenBonus);

	DrawTexture(image, (GetScreenWidth() / 2.f) - image.width / 2.f, (GetScreenHeight() / 2.f) - image.height / 2.f, RAYWHITE);
}

void ScreenBonusState::UnloadScreen(void)
{
	GameManager& GameInst = GameManager::GetGameManager();

}

int ScreenBonusState::FinishScreen(void)
{
	return finishScreen;
}