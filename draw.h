#ifndef H_DRAW
#define H_DRAW

typedef enum {
	EMPTY,
	WALL, WALL_TOP,
	SPIKE_LEFT, SPIKE_RIGHT, SPIKE_UP, SPIKE_DOWN,
	TROWER_LEFT, THROWER_RIGHT, THROWER_UP, THROWER_DOWN,
	START, GOAL,
	FAKE_WALL, FAKE_WALL_TOP,
	FAKE_PRINCESS,
	BULLET_LEFT, BULLET_RIGHT, BULLET_UP, BULLET_DOWN,
	STONE,
	ORTON_STOP_LEFT,
	ORTON_RUN1_LEFT, ORTON_RUN2_LEFT, ORTON_RUN3_LEFT, ORTON_RUN4_LEFT,
	ORTON_JUMP_LEFT,
	ORTON_STOP_RIGHT,
	ORTON_RUN1_RIGHT, ORTON_RUN2_RIGHT, ORTON_RUN3_RIGHT, ORTON_RUN4_RIGHT,
	ORTON_JUMP_RIGHT,
	EXPLOSION1, EXPLOSION2, EXPLOSION3
} Bmp;


void draw_init();
static void vertical_symmetry(char* source, char* destination);
static void rotated_90_degrees(char* source, char* destination);
void draw_bmp(Bmp bmp, int x, int y);

void draw_bmp_8_or_cl(unsigned char *bmp, int x, int y);
void draw_horizontal_line(int y, int x1, int x2);
void draw_rectangle(int x1, int y1, int x2, int y2);

void allclr_vbuf();
void putdispvram_vbuf ();

void write_graph(int,int,int,int,unsigned char*);
#endif
