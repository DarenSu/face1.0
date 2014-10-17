 /*************************************************************************
	> File Name: include/camera.h
	> Author: he.yang
	> Mail: yanghe9012@126.com
	> Created Time: 2014年10月10日 星期五 09时14分00秒
  *************************************************************************/

#ifndef _CAMERA_H
#define _CAMERA_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h> /* getopt_long() */
#include <fcntl.h> /* low-level i/o */
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h>
#include <termios.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <asm/types.h> /* for videodev2.h */
#include <linux/videodev2.h>

#define SCREEN_WIDTH    1920
#define SCREEN_HEIGHT   1080

typedef enum{
	PF_RGB565,
	PF_RGB888,
	PF_YUV420,
	PF_YUV420I,
	PF_YUV422
}PIXEL_FORMAT;
 
typedef enum{
	tp_video,
	tp_osd
}video_type;

typedef struct{
	video_type type;               
	int idev;       //v4l2 device handle
	int buf_count;  //display buffer number
	int buf_size;   
	int index;      //current display buffer id 
	unsigned char **buff;     //display buffer buffer addr 
	int *offsett;   //return by driver

	int pixel_format;//input pic pixel format
	int src_x;      //input pic width
	int src_y;      //input pic height

	int left;// Specifies the x-coordinate of the upper-left corner of the input pic on screen.
	int top; //Specifies the y-coordinate of the upper-left corner of the input pic on screen.
	int win_x;// Specifies the width of the input pic on screen.
	int win_y;// Specifies the height of the input pic on screen.
	int bpp;    //bits per pixel
	int pic_size;
}video, *p_video;

typedef struct{
	PIXEL_FORMAT format;
	int width;     //src picture width 
	int height;    //src picture height 
	int disp_top;  //ldc pic display position
	int disp_left; //ldc pic display position
	int disp_width; //ldc pic display width
	int disp_height; //ldc pic display height
	p_video pvideo; // camera used video
}cv_param;
 
#define CLEAR(x) memset (&(x), 0, sizeof (x))
 
typedef enum{
	IO_METHOD_READ,
	IO_METHOD_MMAP,
	IO_METHOD_USERPTR,
} io_method;

struct buffer_t{
	void *start;
	size_t length;
};

static void errno_exit(const char *s)
{
	fprintf(stderr, "%s error %d, %s\n", s, errno, strerror(errno));

	exit(EXIT_FAILURE);
}

static int xioctl(int fd,int request,void *arg)
{
	int r;
	r = ioctl(fd, request, arg);
	while (-1 == r && EINTR == errno);
	return r;
}




#endif
