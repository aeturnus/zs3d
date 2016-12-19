#include <SDL2/SDL.h>
#include "platform/interface.h"
#include "sdl.h"

#define getR_RGB(x) ((x&0xF800)>>11)
#define getG_RGB(x) ((x&0x07E0)>> 5)
#define getB_RGB(x) ((x&0x001F)>> 0)

// GG ST7735 for having BGR565
#define getB_BGR(x) ((x&0xF800)>>11)
#define getG_BGR(x) ((x&0x07E0)>> 5)
#define getR_BGR(x) ((x&0x001F)>> 0)

#define DISPLAY_WIDTH LCD_WIDTH * SCALE_FACTOR
#define DISPLAY_HEIGHT LCD_HEIGHT * SCALE_FACTOR

static int sdl_initialized = 0;

static SDL_Window *window = NULL;

int SCALE_FACTOR = 4;
void sdl_init(void)
{
    if(!sdl_initialized)
    {
        if( SDL_Init(SDL_INIT_VIDEO) < 0 )
            fprintf(stderr,"Error: could not initialized SDL\n");
        else
            sdl_initialized = 1;
    }
}

void window_init(const unsigned short splash[])
{
    if(!window)
    {
        printf("Created a window!\n");
        window = SDL_CreateWindow("zs3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISPLAY_WIDTH, DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);

        // draw splash
        SDL_Surface *surface = SDL_GetWindowSurface(window);
        SDL_PixelFormat *format = surface->format;
        SDL_Rect brush = {0,0,SCALE_FACTOR,SCALE_FACTOR};
        for( int y = 0; y < LCD_HEIGHT; y++ )
        {
            brush.y = y * SCALE_FACTOR;
            for( int x = 0; x < LCD_WIDTH; x++ )
            {
                int pixel = splash[ (LCD_HEIGHT-1-y) * LCD_WIDTH + x];
                brush.x = x * SCALE_FACTOR;
                SDL_FillRect( surface, &brush, SDL_MapRGB(format,getR_BGR(pixel),getG_BGR(pixel),getB_BGR(pixel)) );
            }
        }
        SDL_UpdateWindowSurface(window);
    }
}

void window_cleanup(void)
{
    if(window)
    {
        SDL_DestroyWindow(window);
        window = NULL;
    }
}

void window_refresh(void)
{
    SDL_UpdateWindowSurface(window);
}
