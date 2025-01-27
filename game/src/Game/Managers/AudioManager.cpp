#include "AudioManager.h"



AudioManager::AudioManager()
{

}


void AudioManager::InitAudioFiles()
{
    InitAudioDevice();

    //Music
    GameMusic = LoadMusicStream("resources/Audio/Music/Street Fighter 2 - Bonus Stage OST.mp3");
    KenMusic = LoadMusicStream("resources/Audio/Music/1-05. Ken's Theme [CPS-1].mp3");

    //Sounds
    VictorySound = LoadSound("resources/Audio/Sounds/FightAnnouncer/SFII_14 - You win!.wav");
    LoseSound = LoadSound("resources/Audio/Sounds/FightAnnouncer/SFII_15 - You lose.wav");
    PunchSound = LoadSound("resources/Audio/Sounds/SFII_64 - Grunt2.wav");
    HitSound = LoadSound("resources/Audio/Sounds/SFII_45 - Short Hit.wav");

    SetMusicVolume(GameMusic, .3f);
}

void AudioManager::PlayGameMusic(bool activate)
{
    if(activate)
        PlayMusicStream(GameMusic);
    else
        StopMusicStream(GameMusic);
}

void AudioManager::UpdateGameMusic()
{
    UpdateMusicStream(GameMusic);
}

void AudioManager::PlayKenMusic(bool activate)
{
    if (activate)
        PlayMusicStream(KenMusic);
    else
        StopMusicStream(KenMusic);
}

void AudioManager::UpdateKenMusic()
{
    UpdateMusicStream(KenMusic);
}


void AudioManager::PlaySoundEffect(SoundType sound)
{
    switch (sound)
    {
    case SoundType::Victory:
        PlaySound(VictorySound);
        break;
    case SoundType::Lose:
        PlaySound(LoseSound);
        break;
    case SoundType::Punch:
        PlaySound(PunchSound);
        break;
    case SoundType::Hit:
        PlaySound(HitSound);
        break;
    default:
        break;
    }
}

void AudioManager::UnloadAudioFiles()
{
    UnloadSound(LoseSound);
    UnloadSound(VictorySound);
    UnloadSound(PunchSound);
    UnloadSound(HitSound);

    //CloseAudio
    CloseAudioDevice();

}


