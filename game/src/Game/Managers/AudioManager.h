#pragma once

#include "raylib.h"

enum class SoundType
{
	Victory = 0,
	Lose,
	Punch,
	Hit,
};

class AudioManager
{
public:
	AudioManager();

	void InitAudioFiles();
	void UnloadAudioFiles();

	//Functons For music 
	void PlayGameMusic(bool activate);
	void UpdateGameMusic();

	void PlayKenMusic(bool activate);
	void UpdateKenMusic();

	void PlaySoundEffect(SoundType sound);

private:
	Music GameMusic;
	Music KenMusic;

	Sound LoseSound;
	Sound VictorySound;
	Sound PunchSound;
	Sound HitSound;

};
