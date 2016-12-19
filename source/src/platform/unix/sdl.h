#ifndef __SDL_WRAPPER_H__
#define __SDL_WRAPPER_H__
#include <SDL2/SDL.h>

/*
 * This serves as a virtual interface to a 160x128 LCD display
 * This will abstract away all the scaling needed to actually
 * be usable on higher DPI screens
 */

void window_init(const unsigned short splash[]);

void window_cleanup(void);

void window_refresh(void);

#endif  //__SDL_WRAPPER_H__
