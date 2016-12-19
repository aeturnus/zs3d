#include "platform/interface.h"
#include "brandonware/btypes.h"
#include "brandonware/bbufman.h"
#include "resources/image.h"

#define DISPLAY_WIDTH 160
#define DISPLAY_HEIGHT 128

#define BUFFER_WIDTH DISPLAY_WIDTH
#define BUFFER_HEIGHT 90

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

    uint16_t buffer[DISPLAY_WIDTH * DISPLAY_HEIGHT];
    buffer16 bufman;
} Interface_Rec;

Interface Interface_New( void )
{
    Interface interface = malloc(sizeof(Interface_Rec));
    BM_BufferInit_16(&interface->bufman, interface->buffer, BUFFER_WIDTH, BUFFER_HEIGHT);
    return interface;
}

void Interface_Done( Interface interface )
{
    free(interface);
}


void Interface_ClearScreen( Interface interface )
{
    BM_ClearBuffer_16(&interface->bufman);
}

void Interface_DrawBuffer( Interface interface )
{
    //TODO: SDL code here
}

void Interface_ClearBuffer( Interface interface )
{
    BM_ClearBuffer_16(&interface->bufman);
}

void Interface_DrawPixel( Interface interface, uint32_t x, uint32_t y, uint16_t color)
{
    BM_DrawPixel_16(x,y,color,&interface->bufman);
}

void Interface_DrawLine( Interface interface, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint16_t color)
{
    BM_DrawLine_16(x0, y0, x1, y1, color, &interface->bufman);
}

void Interface_FillRect( Interface interface, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint16_t color)
{
    BM_FillRect_16(x, y, w, h, color, &interface->bufman);
}

void Interface_DrawVLine(Interface interface, uint32_t x, uint32_t y0, uint32_t y1, uint16_t color)
{
    BM_DrawVLine_16(x,y0,y1,color,&interface->bufman);
}

void Interface_DrawHLine(Interface interface, uint32_t x0, uint32_t y, uint32_t x1, uint16_t color)
{
    BM_DrawHLine_16(x,y0,y1,color,&interface->bufman);
}

void Interface_DirectFillRect(Interface interface, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color) // need to figure out how to deal with this
{
    //TODO: SDL code
}

void Interface_SetCursor(Interface interface, uint32_t x, uint32_t y)
{
    //TODO: SDL code
}

void Interface_OutString(Interface interface, uint8_t* string)
{
    //TODO: SDL code
}

int32_t Interface_GetAnalog(Interface interface, uint8_t axis)
{
    int index = axis - 'x';
    return index < 1? interface->analog[index] : 0xDEADBEEF;
}

uint8_t Interface_GetDigital(Interface interface, uint8_t button)
{
    switch(button)
    {
    case 'a':
        return interface->a;
    case 'b':
        return interface->b;
    case 'x':
        return interface->x;
    case 'y':
        return interface->y;
    case 'l':
        return interface->l;
    case 'r':
        return interface->r;
    }
}

void Interface_GetInput( Interface interface )
{
    //TODO: SDL code here
}

void Interface_DrawBitmap( Interface interface, int32_t x,int32_t y, int32_t w, int32_t h, uint16_t index)
{
    BM_DrawBitmap_16(x, y, w, h, getBitmapPtr(index), &interface->bufman);
}

void Interface_DrawBitmapOver(Interface interface, int32_t x,int32_t y, int32_t w, int32_t h, uint16_t index)
{
    BM_DrawBitmapOver_16(x, y, w, h, getBitmapPtr(index), &interface->bufman);
}

void Interface_ScaleBitmap(Interface interface, int32_t x,int32_t y, int32_t w, int32_t h, ufixed32_3 scaleX, ufixed32_3 scaleY, uint16_t index)
{
    BM_ScaleBitmap_16(x, y, w, h, scaleX, scaleY, getBitmapPtr(index), &interface->bufman);
}

void Interface_ScaleBitmapOver(Interface interface, int32_t x,int32_t y, int32_t w, int32_t h, ufixed32_3 scaleX, ufixed32_3 scaleY, uint16_t index)
{
    BM_ScaleBitmapOver_16(x, y, w, h, scaleX, scaleY, getBitmapPtr(index), &interface->bufman);
}

void Interface_DrawSprite(Interface interface, int32_t x,int32_t y,uint16_t index)
{
    BM_DrawSprite_16(x, y, getSpritePtr(index), &interface->bufman);
}

void Interface_DrawSpriteOver(Interface interface, int32_t x,int32_t y,uint16_t index)
{
    BM_DrawSpriteOver_16(x, y, getSpritePtr(index), &interface->bufman);
}

void Interface_ScaleSprite(Interface interface, int32_t x,int32_t y,ufixed32_3 scaleX, ufixed32_3 scaleY,uint16_t index)
{
    BM_ScaleSprite_16(x, y, scaleX, scaleY, getSpritePtr(index), &interface->bufman);
}

void Interface_ScaleSpriteOver(Interface interface, int32_t x,int32_t y,ufixed32_3 scaleX, ufixed32_3 scaleY,uint16_t index)
{
    BM_ScaleSpriteOver_16(x, y, scaleX, scaleY, getSpritePtr(index), &interface->bufman);
}
