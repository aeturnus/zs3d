#include "platform/interface.h"
#include "brandonware/btypes.h"
#include "brandonware/bbufman.h"

#define DISPLAY_WIDTH 160
#define DISPLAY_HEIGHT 128

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
    BM_BufferInit_16(&interface->bufman, interface->buffer, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    return interface;
}

void Interface_Done( Interface interface )
{
    free(interface);
}
