#ifndef __SDL_WRAPPER_H__
#define __SDL_WRAPPER_H__
#include <SDL2/SDL.h>

void window_init(unsigned int width, unsigned int height,const unsigned short splash[]);

void window_cleanup(void);

void window_refresh(void);

#endif  //__SDL_WRAPPER_H__
