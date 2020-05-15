#include <SDL2/SDL.h>
#include "platform/interface.h"
#include "sdl.h"

#define getR_RGB(x) ((x&0xF800)>> 8)
#define getG_RGB(x) ((x&0x07E0)>> 3)
#define getB_RGB(x) ((x&0x001F)<< 2)

// GG ST7735 for having BGR565
#define getB_BGR(x) ((x&0xF800)>> 8)
#define getG_BGR(x) ((x&0x07E0)>> 3)
#define getR_BGR(x) ((x&0x001F)<< 2)

#define DISPLAY_WIDTH LCD_WIDTH * SCALE_FACTOR
#define DISPLAY_HEIGHT LCD_HEIGHT * SCALE_FACTOR

static int sdl_initialized = 0;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

int SCALE_FACTOR = 6;
void sdl_init(void)
{
    if(!sdl_initialized)
    {
        if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) < 0 )
            fprintf(stderr,"Error: could not initialized SDL\n");
        else
            sdl_initialized = 1;
    }
}

// 2019: thank god for https://stackoverflow.com/questions/21890627/drawing-a-rectangle-with-sdl2
void window_init(const unsigned short splash[])
{
    if(!window)
    {
        printf("Created a window!\n");
        window = SDL_CreateWindow("zs3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DISPLAY_WIDTH, DISPLAY_HEIGHT, SDL_WINDOW_SHOWN);
        //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC);

        // draw splash
        SDL_Rect brush = {0,0,SCALE_FACTOR,SCALE_FACTOR};
        for( int y = 0; y < LCD_HEIGHT; y++ )
        {
            brush.y = y * SCALE_FACTOR;
            for( int x = 0; x < LCD_WIDTH; x++ )
            {
                int pixel = splash[ (LCD_HEIGHT-1-y) * LCD_WIDTH + x];
                brush.x = x * SCALE_FACTOR;
                SDL_SetRenderDrawColor(renderer, getR_BGR(pixel), getG_BGR(pixel), getB_BGR(pixel), 255);
                SDL_RenderFillRect(renderer, &brush);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

void window_cleanup(void)
{
    if(window)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        renderer = NULL;
        window = NULL;
    }
}

void window_clear(void)
{
    SDL_RenderClear(renderer);
}

void window_refresh(void)
{
    SDL_RenderPresent(renderer);
}

void window_draw_buffer(buffer16 * bufman, int32_t x, int32_t y)
{
    SDL_Rect brush = {0,0,SCALE_FACTOR,SCALE_FACTOR};
    uint16_t * buffer = bufman->buffer;
    uint32_t width = bufman->width;
    uint32_t height = bufman->height;
    for( int r = 0; r < height; r++ )
    {
        //brush.y = (r + (LCD_HEIGHT-y)) * SCALE_FACTOR;
        brush.y = r * SCALE_FACTOR;
        for( int c = 0; c < width; c++ )
        {
            int pixel = buffer[(height-1-r) * width + c];
            brush.x = c * SCALE_FACTOR;
            SDL_SetRenderDrawColor(renderer, getR_BGR(pixel), getG_BGR(pixel), getB_BGR(pixel), 255);
            SDL_RenderFillRect(renderer, &brush);
        }
    }
}

void window_fill_rect(int32_t x, int32_t y, uint32_t w, uint32_t h, uint16_t color)
{
    SDL_Rect brush = {x*SCALE_FACTOR,y*SCALE_FACTOR,w*SCALE_FACTOR,h*SCALE_FACTOR};
    SDL_SetRenderDrawColor(renderer, getR_BGR(color), getG_BGR(color), getB_BGR(color), 255);
    SDL_RenderFillRect(renderer, &brush);
}
