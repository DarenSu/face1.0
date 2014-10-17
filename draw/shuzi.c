#include "draw.h"

short color16;

//32位颜色转16位颜色
int rgb32_to_rgb16(int color)
{
    const int red = (color & 0xff0000) >> (16 + 3);
    const int green = (color & 0xff00) >> (8 + 2);
    const int blue = (color & 0xff) >> 3;
    color16 = blue | (green << 5) | (red << (5 + 6));
	return color16;
}

//数字0
void draw0 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(y == 0 || x == 0 || y == (height - 1) || x == (width - 1))
			{
				dest[x] = color16;
			}   
        }
        dest += stride;
    }
}

//数字1
void draw1 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(x == 0)
                dest[x] = color16;
        }
        dest += stride;
    }
}

//数字2
void draw2 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(y == 0 || y == (height - 1) || y == (height/2) || ((x ==0) && ((height/2) <= y) && ((height -1) >= y)) || ((x == (width -1)) && (0 <= y) && ((height/2) >= y)))
                dest[x] = color16;
        }
        dest += stride;
    }
}

//数字3
void draw3 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(y == 0 || y == (height - 1) || y == (height/2) || x == (width - 1))
                dest[x] = color16;
        }
        dest += stride;
    }
}

//数字4
void draw4 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(y == (height/2) || x == (width - 1) || ((x == 0) && (0 <= y) && ((height/2) >= y)))
                dest[x] = color16;
        }
        dest += stride;
    }
}
//数字5
void draw5 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(y == 0 || y == (height - 1) || y == (height/2) || ((x ==0) && ((height/2) >= y) && (0 <= y)) || ((x == (width -1)) && ((height - 1) >= y) && ((height/2) <= y)))
                dest[x] = color16;
        }
        dest += stride;
    }
}

//数字6
void draw6 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(y == 0 || y == (height - 1) || y == (height/2) || x == 0 ||((x == (width -1)) && ((height - 1) >= y) && ((height/2) <= y)))
                dest[x] = color16;
        }
        dest += stride;
    }
}

//数字7
void draw7 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(x == (width - 1) || y == 0)
                dest[x] = color16;
        }
        dest += stride;
    }
}

//数字8
void draw8 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(y == 0 || x == 0 || y == (height - 1) || x == (width - 1) || y == (height/2))
                dest[x] = color16;
        }
        dest += stride;
    }
}

//数字9
void draw9 (int x0, int y0, int width, int height, int color)
{
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            if(y == 0 || y == (height - 1) || x == (width - 1) || y == (height/2) || ((x ==0) && ((height/2) >= y) && (0 <= y)))
                dest[x] = color16;
        }
        dest += stride;
    }
}


void draw_0 (int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 7; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}

void draw_1 (int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x08,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 8; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}

void draw_2 (int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x20,0x20,0x10,0x08,0x04,0x42,0x7E,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 8; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}

void draw_3 (int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x3C,0x42,0x42,0x20,0x18,0x20,0x40,0x40,0x42,0x22,0x1C,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 8; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}

void draw_4(int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x20,0x30,0x28,0x24,0x24,0x22,0x22,0x7E,0x20,0x20,0x78,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 8; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}

void draw_5(int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x7E,0x02,0x02,0x02,0x1A,0x26,0x40,0x40,0x42,0x22,0x1C,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 8; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}

void draw_6(int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x38,0x24,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x24,0x18,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 8; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}

void draw_7(int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x7E,0x22,0x22,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 8; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}

void draw_8(int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 8; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}

void draw_9(int x0, int y0, int color)
{
	int drawpoint[NUMY] = {0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x64,0x58,0x40,0x40,0x24,0x1C,0x00,0x00};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for (b = 1,k = 0; k < 8; ++k)
		{
			if ((drawpoint[i] & b))
			{	
				x = k;
				dest[x] = color16;
			}
			b = 1 << (k + 1);
		}
		dest += stride;
	}
}





