#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <stdint.h>
#include "brandonware/btypes.h"

typedef struct interface_str
{
    int present;
    int32_t analog[2];
    unsigned int a : 1;
    unsigned int b : 1;
    unsigned int x : 1;
    unsigned int y : 1;
    unsigned int l : 1;
    unsigned int r : 1;
} Interface;

void Interface_Init( Interface * interface );

void Interface_Reset( Interface * interface );

void Interface_Ping( Interface * interface );

int Interface_IsPresent( Interface * interface );

void Interface_ClearScreen( Interface * interface );

void Interface_DrawBuffer( Interface * interface );

void Interface_ClearBuffer( Interface * interface );

void Interface_DrawPixel( Interface * interface, uint32_t x, uint32_t y, uint16_t color);

void Interface_DrawLine( Interface * interface, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint16_t color);

void Interface_FillRect( Interface * interface, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint16_t color);

void Interface_GetInput( Interface * interface );

void Interface_DrawBitmap( Interface * interface, int32_t x,int32_t y, int32_t w, int32_t h, uint16_t index);

void Interface_DrawBitmapOver(Interface * interface, int32_t x,int32_t y, int32_t w, int32_t h, uint16_t index);

void Interface_ScaleBitmap(Interface * interface, int32_t x,int32_t y, int32_t w, int32_t h, ufixed32_3 scaleX, ufixed32_3 scaleY, uint16_t index);

void Interface_ScaleBitmapOver(Interface * interface, int32_t x,int32_t y, int32_t w, int32_t h, ufixed32_3 scaleX, ufixed32_3 scaleY, uint16_t index);

void Interface_DrawSprite(Interface * interface, int32_t x,int32_t y,uint16_t index);

void Interface_DrawSpriteOver(Interface * interface, int32_t x,int32_t y,uint16_t index);

void Interface_ScaleSprite(Interface * interface, int32_t x,int32_t y,ufixed32_3 scaleX, ufixed32_3 scaleY,uint16_t index);

void Interface_ScaleSpriteOver(Interface * interface, int32_t x,int32_t y,ufixed32_3 scaleX, ufixed32_3 scaleY,uint16_t index);

void Interface_DirectFillRect(Interface * interface, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color); // need to figure out how to deal with this

void Interface_SetCursor(Interface * interface, uint32_t x, uint32_t y);

void Interface_OutString(Interface * interface, uint8_t* string);

void Interface_DrawVLine(Interface * interface, uint32_t x, uint32_t y0, uint32_t y1, uint16_t color);

void Interface_DrawHLine(Interface * interface, uint32_t x0, uint32_t y, uint32_t x1, uint16_t color);

int32_t Interface_GetAnalog(Interface * interface, uint8_t axis);

uint8_t Interface_GetDigital(Interface * interface, uint8_t button);

#endif
