/*************************************************************************
*   > File Name: font.h
*   > Author: he.yang
*   > Mail: yanghe9012@126.com
*   > Created Time: 2014年10月14日 星期二 12时06分01秒
**************************************************************************/
#ifndef __FONT_H__
#define __FONT_H__

#define GET_CZ(cz) (cz)-0xa0    
#define GET_BC(bc) (bc)-0xa0    
#define GET_OFFSET(cz, bc) (94*(cz-1)+(bc-1))*32; 
#define DEFAULT_HZK_FONT "HZK16"
#define DEFAULT_ASC_FONT "ASC16"
#define FONT_BUF_SIZE 32
#define FONT_NAME_SIZE 128
#define TYPE_ASC   1
#define TYPE_HZK   0

typedef struct _Font Font;

struct _Font
{
    int type; // 0 hzk16 |  1 ASC16.
    int buf_size;
    int font_size;
    int offset;
    int line_num; // line feed.
    char data[FONT_BUF_SIZE];      // 保存字库数据. 
    char name[FONT_NAME_SIZE]; // 保存字库名. 
};

extern void show_font(const char *str, Font *font, int x0, int y0, int color, unsigned short *p_font);

#endif
