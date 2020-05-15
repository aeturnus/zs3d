#ifndef __SDL_WRAPPER_H__
#define __SDL_WRAPPER_H__
#include <stdint.h>

#include <SDL2/SDL.h>
#include <brandonware/bbufman.h>

/*
 * This serves as a virtual interface to a 160x128 LCD display
 * This will abstract away all the scaling needed to actually
 * be usable on higher DPI screens
 *
 * In addition, it also provides other SDL funcionality
 */

void sdl_init(void);

void window_init(const unsigned short splash[]);

void window_cleanup(void);

void window_clear(void);

void window_refresh(void);

void window_draw_buffer(buffer16 * bufman, int32_t x, int32_t y);

void window_fill_rect(int32_t x, int32_t y, uint32_t w, uint32_t h, uint16_t color);

#endif  //__SDL_WRAPPER_H__
