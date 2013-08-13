#include <fxlib.h>
#include <string.h>
#include "draw.h"

#define VRAM_SIZE 1024
unsigned char vbuf[VRAM_SIZE];

void allclr_vbuf()
{
	memset(vbuf,0,VRAM_SIZE);
}

void putdispvram_vbuf ()
{
	DISPGRAPH dg;

	dg.x					= 0;
	dg.y					= 0;
	dg.GraphData.width		= 128;
	dg.GraphData.height		= 64;
	dg.GraphData.pBitmap	= vbuf;
	dg.WriteModify			= 0;
	dg.WriteKind			= IMB_WRITEKIND_OR;

	Bdisp_WriteGraph_VRAM(&dg);
}

void write_graph(int x,int y,int width,int height,unsigned char * pGraph)
{
	DISPGRAPH dg;

	dg.x					= x;
	dg.y					= y;
	dg.GraphData.width		= width;
	dg.GraphData.height		= height;
	dg.GraphData.pBitmap	= pGraph;
	dg.WriteModify			= 0;
	dg.WriteKind			= IMB_WRITEKIND_OVER;

	Bdisp_WriteGraph_VRAM(&dg);
}


static char wall[] = {255,255,255,255,255,255,255,255};
static char wall_top[] = {255,221,187,255,255,255,255,255};

static char spike_up[] = {0,0,0,0,0,0,68,238};
static char spike_down[8], spike_left[8], spike_right[8];

static char thrower_up[] = {0,0,0,0,0,60,126,126};
static char thrower_down[8], thrower_left[8], thrower_right[8];
static char bullet_left[] = {64,192,64,0,0,0,0,0};
static char bullet_right[] = {128,192,128,0,0,0,0,0};
static char bullet_up[] = {64,224,0,0,0,0,0,0};
static char bullet_down[] = {224,64,0,0,0,0,0,0};
static char stone[] = {224,160,224,0,0,0,0,0};

static char orton_run1_right[] = {0,126,66,86,66,66,126,40};
static char orton_run2_right[] = {0,126,66,86,66,66,126,34};
static char orton_run3_right[] = {126,66,86,66,66,127,128,0};
static char orton_run4_right[] = {126,66,86,66,66,254,1,0};
static char orton_stop_right[] = {0,126,66,86,66,66,126,66};
static char orton_jump_right[] = {126,66,86,66,66,255,0,0};
static char orton_run1_left[8], orton_run2_left[8], orton_run3_left[8], orton_run4_left[8], orton_stop_left[8], orton_jump_left[8];

static char explosion1[] = {0,44,82,74,129,110,48,0};
static char explosion2[] = {6,105,66,136,2,33,132,99};
static char explosion3[] = {8,65,16,132,0,0,17,130};

static char* bitmap[] = {
	0,
	wall, wall_top,
	spike_left, spike_right, spike_up, spike_down,
	thrower_left, thrower_right, thrower_up, thrower_down,
	0, orton_run1_left,
	wall, wall_top,
	orton_run1_left,
	bullet_left, bullet_right, bullet_up, bullet_down,
	stone,
	orton_stop_left,
	orton_run1_left, orton_run2_left, orton_run3_left, orton_run4_left,
	orton_jump_left,
	orton_stop_right,
	orton_run1_right, orton_run2_right, orton_run3_right, orton_run4_right,
	orton_jump_right,
	explosion1, explosion2, explosion3
};

void draw_init()
{
	vertical_symmetry(orton_run1_right, orton_run1_left);
	vertical_symmetry(orton_run2_right, orton_run2_left);
	vertical_symmetry(orton_run3_right, orton_run3_left);
	vertical_symmetry(orton_run4_right, orton_run4_left);
	vertical_symmetry(orton_stop_right, orton_stop_left);
	vertical_symmetry(orton_jump_right, orton_jump_left);

	rotated_90_degrees(spike_up, spike_right);
	rotated_90_degrees(spike_right, spike_down);
	rotated_90_degrees(spike_down, spike_left);

	rotated_90_degrees(thrower_up, thrower_right);
	rotated_90_degrees(thrower_right, thrower_down);
	rotated_90_degrees(thrower_down, thrower_left);
}

static void vertical_symmetry(char* source, char* destination)
{
	int i, j;
	memset(destination, 0, 8);
	for(i=0 ; i<8 ; i++)
	{
		for(j=0 ; j<8 ; j++)
		{
			if(source[i]&1<<j)
				destination[i] |= 1<<7-j;
		}
	}
}

static void rotated_90_degrees(char* source, char* destination)
{
	int i, j;
	memset(destination, 0, 8);
	for(i=0 ; i<8 ; i++)
	{
		for(j=0 ; j<8 ; j++)
		{
			if(source[i]&1<<7-j)
				destination[j] |= 1<<i;
		}
	}
}


void draw_bmp(Bmp bmp, int x, int y)
{
	draw_bmp_8_or_cl(bitmap[bmp], x, y);
}

void draw_bmp_8_or_cl(unsigned char *bmp, int x, int y)
{
	unsigned short line;
	char i, shift, begin=0, end=8, bool1=1, bool2=1, *screen, *p=(char*)&line;
	if(!bmp || x<-7 || x>127 || y<-7 || y>63) return;
	if(y < 0) begin = -y;
	if(y > 56) end = 64-y;
	shift = 8-(x&7);
	if(x < 0) bool1 = 0;
	if(x>120 || shift==8) bool2 = 0;
	screen = vbuf+(y+begin<<4)+(x>>3);
	for(i=begin ; i<end ; i++)
	{
		line = bmp[i]<<shift;
		if(bool1) screen[0] |= *p;
		if(bool2) screen[1] |= *(p+1);
		screen += 16;
	}
}

void draw_horizontal_line(int y, int x1, int x2)
{
    int i;
    char* vram = vbuf;
    if(y<0 || y>63 || (x1<0 && x2<0) || (x1>127 && x2>127)) return;
    if(x1 < 0) x1 = 0;
    if(x2 > 127) x2 = 127;
	if(x1>>3 != x2>>3)
	{
		vram[(y<<4)+(x1>>3)] |= 255 >> (x1&7);
		vram[(y<<4)+(x2>>3)] |= 255 << 7-(x2&7);
		for(i=(x1>>3)+1 ; i<x2>>3 ; i++)
			vram[(y<<4) + i] = 255;
	}
	else vram[(y<<4)+(x1>>3)] |= (255>>(x1%8 + 7-x2%8))<<(7-(x2&7));
}

void draw_rectangle(int x1, int y1, int x2, int y2)
{
	int i;
	for(i=y1 ; i<=y2 ; i++)
		draw_horizontal_line(i, x1, x2);
}
