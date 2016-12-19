#ifndef __MUSIC_H__
#define __MUSIC_H__
#include <stdint.h>

void Music_Init(void);
void Music_Reset(void);
void Music_LoadSong(uint8_t songIndex);
void Music_PlaySong(void);
void Music_PauseSong(void);
void Music_PlaySound(uint8_t soundIndex);

#endif
