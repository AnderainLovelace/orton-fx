#ifndef H_GAME
#define H_GAME

#include "level.h"

#define sng(x) (x<0?-1:x>0?1:0)

#define MAX_JUMP 6
#define FALLING_MAX_SPEED 5
#define MESSAGE_DEFAULT_TIME 60
#define MAX_BULLETS 32
#define MAX_STONES 32
#define TIME_ORTON_CHANGE_POSITION 2
#define TIME_STONE_DX_SLEEP 20
#define TIME_THROWER_SLEEP 8
#define TIME_LINE_SLEEP 4
#define TIME_MOVING_WALL_SLEEP 50
#define BULLET_SPEED 6

typedef struct
{
	int x, y;
} Camera;

typedef enum {STOP, RUN1, RUN2, RUN3, RUN4, JUMP} Position;
typedef enum {LEFT, RIGHT} Direction;

typedef struct
{
	int x, y, dx, dy;
	Direction direction;
	Position position;
	char can_jump, counter_jump, counter_change_position;
} Character;

typedef struct
{
	int x, y, dx, dy;
	Thrower_direction direction;
} Bullet;

typedef struct
{
	int x, y, dx, dy;
} Stone;

void fade(int type);
int game(Level* level);
void dialog(Level* level);
static void draw_message(Level* level, Character* orton, int nb_death);
void pause();

#endif
