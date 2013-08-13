#ifndef H_LEVEL
#define H_LEVEL

#define NB_LEVELS 17 //before fake ending
#define SIZE_FREQ_ARRAY 16

typedef enum {TOP, BOTTOM} Message_place;

typedef enum {BEFORE, AFTER} Message_coord_compare;

typedef enum {BEGIN, DEATH, X, Y, XY} Message_trigger_type;

typedef struct
{
	char* str;
	int nb_lines;
	Message_place place;
	Message_trigger_type trigger;
	int trigger_param[4];
	char seen;
	
} Message;



typedef struct
{
	int x, y, width, dx, dy, x1, y1, x2, y2;
} Moving_line;


typedef enum {W_LEFT, W_RIGHT, W_UP, W_DOWN} Moving_wall_direction;

typedef struct
{
	Moving_wall_direction direction;
	int begin_x, begin_y, x, y, size;
} Moving_wall;


typedef enum {T_BULLET, T_STONE} Thrower_type;

typedef enum {T_LEFT, T_RIGHT, T_UP, T_DOWN} Thrower_direction;

typedef struct
{
	int x, y;
	Thrower_type type;
	Thrower_direction direction;
	char freq[SIZE_FREQ_ARRAY];
} Thrower;


typedef enum {GAME, DIALOG} Level_type;

typedef struct
{
	int id;
	Level_type type;
	char* map;
	int width, height;
	Moving_line* line;
	int nb_lines;
	Moving_wall* wall;
	int nb_walls;
	Message* message;
	int nb_messages;
	Thrower* thrower;
	int nb_throwers;
} Level;


Level* load_level(int n);
void free_level(Level* level);
static Message load_message(char* str, Message_place place, Message_trigger_type trigger, int param1, int param2, int param3, int param4);
static Thrower load_thrower(int x, int y, Thrower_type type, Thrower_direction direction, int freq_model);

#endif
