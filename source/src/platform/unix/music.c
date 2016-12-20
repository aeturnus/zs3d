#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "platform/music.h"
#include "resources/songs.h"
#include "resources/sounds.h"

#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
//static Mix_Chunk chunks[ARRALY_LEN(soundsList)];
static Mix_Chunk * chunks = NULL;

void Music_Init(void)
{
    Mix_Init(0);
    // tfw low sample rate and mono (lol)
    Mix_OpenAudio(11025,AUDIO_U8,1,1024);

    // setup our chunks from music.h
    int len = ARRAY_LEN(soundsList);
    chunks = malloc(sizeof(Mix_Chunk)*len);
    for(int i = 0; i < len; i++)
    {
        chunks[i].allocated = 0;    // manually allocated
        chunks[i].abuf = soundsList[i].soundPtr;
        chunks[i].alen = soundsList[i].length;
        chunks[i].volume = 128;
    }
}
#undef ARRAY_LEN

void Music_Reset(void)
{
    //TODO
}

void Music_LoadSong(uint8_t songIndex)
{
    //TODO
}

void Music_PlaySong(void)
{
    //TODO
}

void Music_PauseSong(void)
{
    //TODO
}

void Music_PlaySound(uint8_t soundIndex)
{
    // play sound on first unreserved channel w/ no loops
    Mix_PlayChannel(-1, &chunks[soundIndex], 0);
}
