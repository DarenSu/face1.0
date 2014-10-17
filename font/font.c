/*************************************************************************
 *   > File Name: font.c
 *   > Author: he.yang
 *   > Mail: yanghe9012@126.com
 *   > Created Time: 2014年10月14日 星期二 12时06分08秒
 *************************************************************************/


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
#include "font.h"
#include "type.h"
#include "draw.h"

//struct fb_var_screeninfo vinfo;
//struct fb_fix_screeninfo finfo;
//char *frameBuffer = 0;

short color16;
//32位颜色转16位颜色
int inline rgb32_to_rgb16(int color)
{
    const int red = (color & 0xff0000) >> (16 + 3);
    const int green = (color & 0xff00) >> (8 + 2);
    const int blue = (color & 0xff) >> 3;
    color16 = blue | (green << 5) | (red << (5 + 6));
	return color16;
}
static inline int gb2312_to_buffer(Font *font, const char *incode, char *buffer)
{
    FILE *fp = NULL;
    unsigned char cz, bc;
    unsigned long offset;
    unsigned long read_size = 32;
    
    if (NULL == (fp = fopen(font->name, "rb"))){
        perror("open HZK error!");
        return FALSE;
    }

    if (font->type == TYPE_ASC){
        offset = (incode[0] * 16) + 1;
        read_size = 16;
    }else{
        cz = GET_CZ(incode[0]);
        bc = GET_BC(incode[1]);
        offset = GET_OFFSET(cz, bc);
        read_size = 32;
    }
    
    font->offset = offset;
    font->buf_size = read_size;
    fseek(fp, offset, SEEK_SET);
    fread(buffer, read_size, 1, fp);
    fclose(fp);
    return TRUE;
}

void inline font_show_test(Font *font)
{
	int i = 0;
	int j = 0;
	
	while(i< FONT_BUF_SIZE){
		for(j=0;j<8;j++){
			if(font->data[i] & (0x80>>j)){
				printf("*");
			}else{
				printf(" ");	
			}
		}
		if((++i % font->line_num)==0){
			printf("\n");
		}
	}
}

int inline str_is_ascii(const char *str)
{
    return (0 <= (int)str[0] && (int)str[0] <= 127)?TRUE:FALSE;
}

int get_font_data(Font *font, const char *str)
{
    if (str_is_ascii(str)){
        font->type = TYPE_ASC;
        font->line_num = 1;
        font->font_size = 16;
        strcpy(font->name, DEFAULT_ASC_FONT);
    }else{
        font->type = TYPE_HZK;
        font->line_num = 2;
        font->font_size = 16;
        strcpy(font->name, DEFAULT_HZK_FONT);
    }
    //printf("font:type %d %s\n", font->type, str);
    gb2312_to_buffer(font, str, font->data);

    return TRUE;
}
#if 1

extern unsigned long width;
static inline void show_font_tolcd(Font *font, int x0, int y0, int color, unsigned short *p)
{
    int i = 0;
    int j = 0;
    int x;
    const int bytesPerPixel = 2;
    const int stride = finfo.line_length / bytesPerPixel;
    color16 = rgb32_to_rgb16(color);
    //short *dest_font = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);
    unsigned short *dest_font = p + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);
	while(i < FONT_BUF_SIZE)
    {
		for(j = 0;j < 8; ++j)
        {
			if(font->data[i] & (0x80 >> j))
            {
                //printf("*");
                x = j;
                if ((i % font->line_num) == 1)
                   x = j + 8;
				dest_font[x] = color16;
			}
            //else
              //  printf(" ");
		}
		if((++i % font->line_num) == 0)
        {
			dest_font += width;
            //printf("\n");
		}
    }
}
#endif

#if 0
static void show_font_tolcd(Font *font, int x0, int y0, int color)
{
    int i = 0;
    int j = 0;
    int x;
    const int bytesPerPixel = 2;
    const int stride = finfo.line_length / bytesPerPixel;
    color16 = rgb32_to_rgb16(color);
    short *dest_font = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);
	while(i < FONT_BUF_SIZE)
    {
		for(j = 0;j < 8; ++j)
        {
			if(font->data[i] & (0x80 >> j))
            {
                //printf("*");
                x = j;
                if ((i % font->line_num) == 1)
                   x = j + 8;
				dest_font[x] = color16;
			}
            //else
              //  printf(" ");
		}
		if((++i % font->line_num) == 0)
        {
			dest_font += stride;
            //printf("\n");
		}
    }
}
#endif
#if 0
static void show_font_tolcd(Font *font, int x0, int y0, int color)
{
    int i = 0;
    int j = 0;
    //int x;
    const int bytesPerPixel = 2;
    const int stride = finfo.line_length / bytesPerPixel;
    color16 = rgb32_to_rgb16(color);
    short *dest_font = (short *) (frameBuffer) + (y0 + vinfo.yoffset) * stride + (x0 + vinfo.xoffset);
	while(i < FONT_BUF_SIZE)
    {
        //printf("data = 0x%x\n",font->data[i]);
		for(j = 0;j < 16; ++j)
        {
			if(font->data[i] & (0x8000 >> j))
            {
                //printf("*");
                //x = j;
                //if ((i % font->line_num) == 1)
                  // x = j + 8;
				dest_font[j] = color16;
			}
            //else
              //  printf(" ");
		}
		dest_font += stride;
        i++;
		//if((++i % font->line_num) == 0)
        //{
		//	dest_font += stride;
            //printf("\n");
		//}
    }
}
#endif 
void show_font(const char *str, Font *font, int x0, int y0, int color, unsigned short *p_font)
{
    int str_i = 0;
    for(str_i = 0;str_i < strlen(str); str_i += 2)
    {
        get_font_data(font,str + str_i);
        show_font_tolcd(font, x0 + 9 * str_i, y0, color,p_font);
    }
}


#if 0
int main (int argc, char **argv)
{
    const char *devfile = "/dev/fb0";
    long int screensize = 0;
    int fbFd = 0;
 	char *str_uu = "我就是你的神";
    Font font;
    
    /* Open the file for reading and writing */
    fbFd = open (devfile, O_RDWR);
    if (fbFd == -1)
    {
        perror ("Error: cannot open framebuffer device");
        exit (1);
    }


    //获取finfo信息并显示
    if (ioctl (fbFd, FBIOGET_FSCREENINFO, &finfo) == -1)
    {
        perror ("Error reading fixed information");
        exit (2);
    }
    //获取vinfo信息并显示
    if (ioctl (fbFd, FBIOGET_VSCREENINFO, &vinfo) == -1)
    {
        perror ("Error reading variable information");
        exit (3);
    }


    /* Figure out the size of the screen in bytes */
    screensize = finfo.smem_len;
    /* Map the device to memory */
    frameBuffer =
        (char *) mmap (0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED,fbFd, 0);
    if (frameBuffer == MAP_FAILED)
    {
        perror ("Error: Failed to map framebuffer device to memory");
        exit (4);
    }

    printf ("Will draw 0-2 rectangles on the screen!\n");
    printf("bbbbbbbb = %s\n",str_uu);
    show_font(str_uu,&font,50,100,0xffff);
    printf (" Done.\n");


    munmap (frameBuffer, screensize); //解除内存映射，与mmap对应


    close (fbFd);
    return 0;
}
#endif
#if 0
int main(int argc, const char *argv[])
{
    char *str = "我就是你的神";
    Font font;
    //get_font_data(&font, str); 
    //font_show_test(&font);
    show_font(str,&font,50,100,0xffff);
    return TRUE;
}
#endif
