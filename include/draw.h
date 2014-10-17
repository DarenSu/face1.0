 /*************************************************************************
	> File Name: draw.h
	> Author: he.yang
	> Mail: yanghe9012@126.com
	> Created Time: 2014年09月30日 星期二 10时17分45秒
  *************************************************************************/

#ifndef _DRAW_H
#define _DRAW_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>

#define NUMX 2
#define NUMY 16

extern short color16;


extern struct fb_var_screeninfo vinfo;
extern struct fb_fix_screeninfo finfo;
extern unsigned short *frameBuffer;
extern unsigned short stride;

extern int rgb32_to_rgb16(int color);

extern void drawRect (int x0, int y0, int width, int height, int color);

extern void draw_yang(int x0,int y0,int color);
extern void draw_he (int x0, int y0, int color);
extern void draw_shang (int x0, int y0, int color);
extern void draw_hai (int x0, int y0, int color);
extern void draw_hua (int x0, int y0, int color);
extern void draw_li (int x0, int y0, int color);
extern void draw_chuang (int x0, int y0, int color);
extern void draw_tong (int x0, int y0, int color);
extern void draw_0 (int x0, int y0, int color);
extern void draw_1 (int x0, int y0, int color);
extern void draw_2 (int x0, int y0, int color);
extern void draw_3 (int x0, int y0, int color);
extern void draw_4 (int x0, int y0, int color);
extern void draw_5 (int x0, int y0, int color);
extern void draw_6 (int x0, int y0, int color);
extern void draw_7 (int x0, int y0, int color);
extern void draw_8 (int x0, int y0, int color);
extern void draw_9 (int x0, int y0, int color);

extern void draw0 (int x0, int y0, int width, int height, int color);
extern void draw1 (int x0, int y0, int width, int height, int color);
extern void draw2 (int x0, int y0, int width, int height, int color);
extern void draw3 (int x0, int y0, int width, int height, int color);
extern void draw4 (int x0, int y0, int width, int height, int color);
extern void draw5 (int x0, int y0, int width, int height, int color);
extern void draw6 (int x0, int y0, int width, int height, int color);
extern void draw7 (int x0, int y0, int width, int height, int color);
extern void draw8 (int x0, int y0, int width, int height, int color);
extern void draw9 (int x0, int y0, int width, int height, int color);














#endif
