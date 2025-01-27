#pragma once

#include "raylib.h"

#include "Menu/StateMachineMngr.h" 
#include "TexturesManager.h"
#include "AudioManager.h"

using namespace std;

enum Level
{
	Title = 0,
	Level1 = 1,
	Level2 = 2,
	End = 3,
};


class GameManager
{
private:


public:
	GameManager();

	void InitGame();						// Initialize game
	void UpdateFrame(float deltaTime);      // Update game (one frame)
	void DrawFrame(void);                    // Draw game (one frame)
	void UnloadGame(void);

	void ClearGameVar();

	Font& GetFont() { return font; }

	int GetScore() { return score; }
	void SetScore(int newValue) { score = newValue; }

	int GetSeconds() { return seconds; }
	void SetSeconds(int newValue) { seconds = newValue; }

	void IncreaseScore(int newValue) { score += newValue; }
	void DecreaseScore(int newValue) { score -= newValue; }

	bool GetDebug() { return debug; }
	void SetDebug(bool b) { debug = b; }

	//Maps Progression
	void MapsForwardProgression();
	void MapsBackwardProgression();

	TextureManager getTextureManager() { return textureManager; };
	AudioManager getAudioManager() { return audioManager; };

	bool GetVictory() { return victory; }
	void SetVictory(bool v) { victory = v; }

	static GameManager& GetGameManager();

private:
	//----------------------------------------------------
	//TODO to move to ScreensMngr?
	void ChangeToScreen(int screen);     // Change to screen, no transition effect

	void TransitionToScreen(int screen); // Request transition to next screen
	void UpdateTransition(void);         // Update transition effect
	void DrawTransition(void);           // Draw transition effect (full-screen rectangle)


	float transAlpha = 0.0f;
	bool onTransition = false;
	bool transFadeOut = false;
	int transFromScreen = -1;
	int transToScreen = -1;

	int score = 0;
	int seconds = 0;

	Level NumLevel = Level::Title;

private:

	static GameManager *GameMngr;

	TextureManager textureManager;

	AudioManager audioManager;

	//------------

	Font font = { 0 };
	Music music = { 0 };
	Sound fxCoin = { 0 };

	StateMachineMngr* ScreenState;

	bool debug = false;

	bool victory;

};