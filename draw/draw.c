#include "draw.h"


//画大小为width*height的同色矩阵，5reds+6greens+5blues
void
drawRect_rgb16 (int x0, int y0, int width, int height, int color)
{
	color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);


    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(y == 0 || x == 0 || y == (height - 1) || x == (width - 1))
                dest[x] = color16;
        }
        dest += stride;
    }
}


void drawRect (int x0, int y0, int width, int height, int color)
{
    drawRect_rgb16 (x0, y0, width, height, color);
}
