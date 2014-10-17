#include "draw.h"
//汉字杨
void draw_yang (int x0, int y0, int color)
{
	int drawpoint[NUMY][NUMX] = {{0x08,0x00},{0xC8,0x1F},{0x08,0x08},{0x7F,0x04},{0x08,0x02},{0x08,0x01},{0x9C,0x3F},{0x2C,0x2A},{0x2A,0x29},{0x0A,0x25},{0x89,0x24},{0x48,0x22},{0x08,0x21},{0x88,0x20},{0x08,0x28},{0x08,0x10}};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,j,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for(j = 0; j < NUMX; ++j)
		{
			for (b = 1,k = 0; k < 8; ++k)
			{
				if ((drawpoint[i][j] & b))
				{
					x = k;
					if (j == 1)
						x = k + 8;
					dest[x] = color16;
				}
				b = 1 << (k + 1);
			}
		}
		dest += stride;
	}
}

//汉字贺
void draw_he (int x0, int y0, int color)
{
	int drawpoint[NUMY][NUMX] = {{0x10,0x00},{0xFE,0x3E},{0x90,0x22},{0x90,0x22},{0x88,0x3E},{0xA4,0x22},{0x42,0x00},{0xF0,0x0F},{0x10,0x08},{0x10,0x09},{0x10,0x09},{0x10,0x09},{0x90,0x02},{0x40,0x0C},{0x30,0x38},{0x0C,0x10}};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,j,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for(j = 0; j < NUMX; ++j)
		{
			for (b = 1,k = 0; k < 8; ++k)
			{
				if ((drawpoint[i][j] & b))
				{
					x = k;
					if (j == 1)
						x = k + 8;
					dest[x] = color16;
				}
				b = 1 << (k + 1);
			}
		}
		dest += stride;
	}
}

void draw_shang (int x0, int y0, int color)
{
	int drawpoint[NUMY][NUMX] = {{0x00,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x1F},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x20},{0xFE,0x7F},{0x00,0x00}};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,j,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for(j = 0; j < NUMX; ++j)
		{
			for (b = 1,k = 0; k < 8; ++k)
			{
				if ((drawpoint[i][j] & b))
				{
					x = k;
					if (j == 1)
						x = k + 8;
					dest[x] = color16;
				}
				b = 1 << (k + 1);
			}
		}
		dest += stride;
	}
}

void draw_hai (int x0, int y0, int color)
{
	int drawpoint[NUMY][NUMX] = {{0x84,0x00},{0x88,0x00},{0x88,0x7F},{0x40,0x00},{0xE9,0x1F},{0x4A,0x11},{0x4A,0x12},{0x48,0x10},{0xF4,0x7F},{0x44,0x11},{0x47,0x12},{0x44,0x10},{0xC4,0x7F},{0x04,0x10},{0x04,0x14},{0x04,0x08}};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,j,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for(j = 0; j < NUMX; ++j)
		{
			for (b = 1,k = 0; k < 8; ++k)
			{
				if ((drawpoint[i][j] & b))
				{
					x = k;
					if (j == 1)
						x = k + 8;
					dest[x] = color16;
				}
				b = 1 << (k + 1);
			}
		}
		dest += stride;
	}
}
void draw_hua (int x0, int y0, int color)
{
	int drawpoint[NUMY][NUMX] = {{0x10,0x01},{0x30,0x11},{0x08,0x39},{0x0C,0x07},{0xCA,0x01},{0x09,0x21},{0x08,0x21},{0x08,0x3E},{0x88,0x00},{0x80,0x00},{0xFE,0x7F},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x00}};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,j,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for(j = 0; j < NUMX; ++j)
		{
			for (b = 1,k = 0; k < 8; ++k)
			{
				if ((drawpoint[i][j] & b))
				{
					x = k;
					if (j == 1)
						x = k + 8;
					dest[x] = color16;
				}
				b = 1 << (k + 1);
			}
		}
		dest += stride;
	}
}

void draw_li (int x0, int y0, int color)
{
	int drawpoint[NUMY][NUMX] = {{0x80,0x00},{0x80,0x00},{0x80,0x00},{0x80,0x00},{0xFE,0x3F},{0x80,0x20},{0x80,0x20},{0x80,0x20},{0x80,0x20},{0x40,0x20},{0x40,0x20},{0x20,0x20},{0x20,0x20},{0x10,0x20},{0x08,0x14},{0x04,0x08}};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,j,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for(j = 0; j < NUMX; ++j)
		{
			for (b = 1,k = 0; k < 8; ++k)
			{
				if ((drawpoint[i][j] & b))
				{
					x = k;
					if (j == 1)
						x = k + 8;
					dest[x] = color16;
				}
				b = 1 << (k + 1);
			}
		}
		dest += stride;
	}
}

void draw_chuang (int x0, int y0, int color)
{
	int drawpoint[NUMY][NUMX] = {{0x10,0x40},{0x10,0x40},{0x28,0x48},{0xC8,0x48},{0x84,0x4B},{0x02,0x49},{0xFD,0x48},{0x84,0x48},{0x84,0x48},{0xA4,0x48},{0x44,0x48},{0x04,0x41},{0x04,0x41},{0x04,0x51},{0xF8,0x21},{0x00,0x00}};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,j,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for(j = 0; j < NUMX; ++j)
		{
			for (b = 1,k = 0; k < 8; ++k)
			{
				if ((drawpoint[i][j] & b))
				{
					x = k;
					if (j == 1)
						x = k + 8;
					dest[x] = color16;
				}
				b = 1 << (k + 1);
			}
		}
		dest += stride;
	}
}

void draw_tong (int x0, int y0, int color)
{
	int drawpoint[NUMY][NUMX] = {{0x02,0x00},{0xE4,0x1F},{0x04,0x09},{0x00,0x06},{0xE0,0x1F},{0x20,0x12},{0xE7,0x1F},{0x24,0x12},{0x24,0x12},{0xE4,0x1F},{0x24,0x12},{0x24,0x16},{0x24,0x0A},{0x0A,0x00},{0xF1,0x7F},{0x00,0x00}};
    color16 = rgb32_to_rgb16(color);
    short *dest = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);

    int x,i,j,b,k;
	for (i = 0; i < NUMY; ++i)
	{
		for(j = 0; j < NUMX; ++j)
		{
			for (b = 1,k = 0; k < 8; ++k)
			{
				if ((drawpoint[i][j] & b))
				{
					x = k;
					if (j == 1)
						x = k + 8;
					dest[x] = color16;
				}
				b = 1 << (k + 1);
			}
		}
		dest += stride;
	}
}




