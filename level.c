#include <stdlib.h> //for malloc, free and memcpy
#include <string.h> //for strlen and strcpy
#include "level.h"

Level* load_level(int n)
{
	Level* level;
	
	level = malloc(sizeof(Level));
	level->id = n;
	level->type = GAME;
	level->width = 0;
	level->height = 0;
	level->map = 0;
	level->line = 0;
	level->nb_lines = 0;
	level->wall = 0;
	level->nb_walls = 0;
	level->message = 0;
	level->nb_messages = 0;
	level->thrower = 0;
	level->nb_throwers = 0;
	if(n == 0)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 18;
		level->height = 10;
		level->map = malloc(18*10);
		memcpy(level->map, m, 18*10);
		level->nb_messages = 2;
		level->message = malloc(2*sizeof(Message));
		level->message[0] = load_message("Use the arrow keys to move.", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("Yay ! Now, go kiss\nthat princess !", TOP, X, AFTER, 64, 0, 0);
	}
	else if(n == 1)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,12, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0,11, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 23;
		level->height = 12;
		level->map = malloc(23*12);
		memcpy(level->map, m, 23*12);
		level->nb_messages = 2;
		level->message = malloc(2*sizeof(Message));
		level->message[0] = load_message("Press SHIFT to jump\nlike a plumber.", TOP, X, AFTER, 32, 0, 0);
		level->message[1] = load_message("Fantastic ! Mario would\nbe proud of you !", TOP, X, AFTER, 92, 0, 0);
	}
	else if(n == 2)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 0,11, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 0, 0, 0,12, 5, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 26;
		level->height = 11;
		level->map = malloc(26*11);
		memcpy(level->map, m, 26*11);
		level->nb_messages = 3;
		level->message = malloc(3*sizeof(Message));
		level->message[0] = load_message("In this game you can\nwalk through spikes\nwithout getting killed !", TOP, X, AFTER, 25, 0, 0);
		level->message[1] = load_message("I lied.", TOP, DEATH, 1, 0, 0, 0);
		level->message[2] = load_message("Hmm... It's going\nto be hard for you.", TOP, DEATH, 3, 0, 0, 0);
		
	}
	else if(n == 3)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0,12, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0,11, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 5, 0, 0, 5, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 28;
		level->height = 12;
		level->map = malloc(28*12);
		memcpy(level->map, m, 28*12);
		level->nb_messages = 3;
		level->message = malloc(3*sizeof(Message));
		level->message[0] = load_message("Now let's try something\na bit more difficult...", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("And... you failed.", TOP, Y, AFTER, 65, 0, 0);
		level->message[2] = load_message("Come on...\nThis is not that difficult.", TOP, DEATH, 3, 0, 0, 0);
	}
	else if(n == 4)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1,12, 5, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 5, 5, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 5, 5, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0,11, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 5, 5, 1, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 17;
		level->height = 19;
		level->map = malloc(17*19);
		memcpy(level->map, m, 17*19);
		level->nb_messages = 6;
		level->message = malloc(6*sizeof(Message));
		level->message[0] = load_message("Howdy !\nThis should be interesting", BOTTOM, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("I like it when you fall down.", TOP, XY, 56, 96, 105, 128);
		level->message[2] = load_message("Wrong side, mate.", TOP, XY, 31, 41, 105, 128);
		level->message[3] = load_message("Almost there !", BOTTOM, XY, 52, 60, 48, 48);
		level->message[4] = load_message("Having troubles ?", TOP, DEATH, 3, 0, 0, 0);
		level->message[5] = load_message("This is fun, isn't it?", TOP, DEATH, 6, 0, 0, 0);
	}
	else if(n == 5)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12, 1, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		Moving_line line[2] = {{60, 24, 32, 0, 2, 60, 24, 60, 55}, {104, 40, 16, 2, 0, 104, 40, 151, 40}};
		level->width = 26;
		level->height = 10;
		level->map = malloc(26*10);
		memcpy(level->map, m, 26*10);
		level->nb_lines = 2;
		level->line = malloc(2*sizeof(Moving_line));
		memcpy(level->line, line, 2*sizeof(Moving_line));
		level->nb_messages = 3;
		level->message = malloc(3*sizeof(Message));
		level->message[0] = load_message("Moving platforms ?\nThat's new...", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("I think you're in trouble.", TOP, XY, 108, 124, 48, 48);
		level->message[2] = load_message("Three tries ? Really ?", TOP, DEATH, 3, 0, 0, 0);
	}
	else if(n == 6)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 5, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 1,
			1, 1, 1, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 4, 0, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0,11, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,12, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		Moving_line line = {156, 40, 16, 0, 2, 156, 40, 156, 88};
		level->width = 29;
		level->height = 16;
		level->map = malloc(29*16);
		memcpy(level->map, m, 29*16);
		level->nb_lines = 1;
		level->line = malloc(sizeof(Moving_line));
		level->line[0] = line;
		level->nb_messages = 2;
		level->message = malloc(2*sizeof(Message));
		level->message[0] = load_message("Do you know my uncle Benny ?", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("That was fun.\nDo it again, please !", TOP, Y, AFTER, 98, 0, 0);
	}
	else if(n == 7)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 3, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 4, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 3, 1, 0, 1, 0, 1, 3, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 3, 1, 1,
			1, 1, 4, 1, 0, 1, 5, 1, 0, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 3, 1, 1,
			1, 1, 0, 1, 0, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 3, 1, 1, 1,
			1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 5, 5, 0, 0, 0, 5, 5, 1, 1,
			1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 6, 6, 6, 0, 6, 6, 6, 1, 1,
			1, 1, 0, 5, 0,12, 0, 5, 5, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		Moving_line line[] = {
			{32, 176, 8, 0, 2, 32, 176, 32, 215},
			{47, 184, 8, 0, 1, 47, 176, 47, 208},
			{63, 192, 8, 0, 2, 63, 176, 63, 200},
			{73, 139, 15, 0, 4, 73, 139, 73, 184},
			{92, 139, 8, 0, 2, 92, 139, 92, 200},
			{104, 176, 8, 0, -2, 104, 144, 104, 176},
			{120, 107, 40, 0, 2, 120, 107, 120, 160},
			{128, 32, 24, 0, 2, 128, 32, 128, 64}
		};
		level->width = 23;
		level->height = 30;
		level->map = malloc(23*30);
		memcpy(level->map, m, 23*30);
		level->nb_lines = 8;
		level->line = malloc(8*sizeof(Moving_line));
		memcpy(level->line, line, 8*sizeof(Moving_line));
		level->nb_messages = 9;
		level->message = malloc(9*sizeof(Message));
		level->message[0] = load_message("What a mess...", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("What are you doing here ?", TOP, XY, 143, 154, 168, 168);
		level->message[2] = load_message("Wich path will you take ?", TOP, XY, 80, 88, 16, 24);
		level->message[3] = load_message("Try again.", TOP, XY, 63, 65, 32, 40);
		level->message[4] = load_message("Not this one.", TOP, XY, 47, 49, 32, 40);
		level->message[5] = load_message("Very risky path...", TOP, XY, 15, 17, 32, 40);
		level->message[6] = load_message("You shouldn't drink while\nplaying this game, you know...", TOP, DEATH, 4, 0, 0, 0);
		level->message[7] = load_message("Don't you have a life ?", TOP, DEATH, 8, 0, 0, 0);
		level->message[8] = load_message("My god, you are patient.", TOP, DEATH, 12, 0, 0, 0);
	}
	else if(n == 8)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0,10, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0,12, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1,
			1, 1, 0,11, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 26;
		level->height = 13;
		level->map = malloc(26*13);
		memcpy(level->map, m, 26*13);
		level->nb_throwers = 7;
		level->thrower = malloc(7*sizeof(Thrower));
		level->thrower[0] = load_thrower(8, 2, T_BULLET, T_DOWN, 8);
		level->thrower[1] = load_thrower(13, 2, T_BULLET, T_DOWN, 8);
		level->thrower[2] = load_thrower(18, 2, T_BULLET, T_DOWN, 8);
		level->thrower[3] = load_thrower(2, 3, T_BULLET, T_RIGHT, 8);
		level->thrower[4] = load_thrower(11, 4, T_BULLET, T_LEFT, 8);
		level->thrower[5] = load_thrower(15, 4, T_BULLET, T_RIGHT, 8);
		level->thrower[6] = load_thrower(4, 8, T_BULLET, T_LEFT, 8);
		level->nb_messages = 5;
		level->message = malloc(5*sizeof(Message));
		level->message[0] = load_message("New toys for you !\nI'm sure you'll like it.", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("Nah, I won't say a thing.\nI'll juste watch.", TOP, XY, 79, 108, 41, 56);
		level->message[2] = load_message("Is this princess\nreally worth it ?", TOP, XY, 109, 129, 41, 56);
		level->message[3] = load_message("My little sister plays\nbetter than you.", TOP, XY, 159, 185, 41, 72);
		level->message[4] = load_message("So, have you met\nmy uncle Benny ?", TOP, DEATH, 7, 0, 0, 0);
	}
	else if(n == 9)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 0,12, 0, 0, 0, 0, 7, 1, 1, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 8, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 0,11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 17;
		level->height = 15;
		level->map = malloc(17*15);
		memcpy(level->map, m, 17*15);
		level->nb_throwers = 7;
		level->thrower = malloc(7*sizeof(Thrower));
		level->thrower[0] = load_thrower(8, 2, T_BULLET, T_DOWN, 8);
		level->thrower[1] = load_thrower(7, 4, T_BULLET, T_LEFT, 8);
		level->thrower[2] = load_thrower(5, 5, T_BULLET, T_RIGHT, 8);
		level->thrower[3] = load_thrower(5, 6, T_BULLET, T_RIGHT, 4);
		level->thrower[4] = load_thrower(5, 7, T_BULLET, T_RIGHT, 5);
		level->thrower[5] = load_thrower(5, 8, T_BULLET, T_RIGHT, 4);
		level->thrower[6] = load_thrower(5, 9, T_BULLET, T_RIGHT, 8);
		level->nb_messages = 5;
		level->message = malloc(5*sizeof(Message));
		level->message[0] = load_message("Same old story...", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("The princess is await you,\nhurry !", BOTTOM, Y, BEFORE, 32, 0, 0);
		level->message[2] = load_message("You are going crazy,\naren't you ?", TOP, DEATH, 4, 0, 0, 0);
		level->message[3] = load_message("You sould take a break.\nReally.", TOP, DEATH, 9, 0, 0, 0);
		level->message[4] = load_message("You are my hero.", TOP, DEATH, 13, 0, 0, 0);
	}
	else if(n == 10)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,13, 1, 1,
			1, 1, 1, 1, 1, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,13, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 7, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 7, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 7, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 0,12, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		Moving_line line = {73, 30, 16, 2, 0, 73, 30, 119, 30};
		level->width = 25;
		level->height = 15;
		level->map = malloc(25*15);
		memcpy(level->map, m, 25*15);
		level->nb_lines = 1;
		level->line = malloc(sizeof(Moving_line));
		level->line[0] = line;
		level->nb_throwers = 6;
		level->thrower = malloc(6*sizeof(Thrower));
		level->thrower[0] = load_thrower(9, 4, T_BULLET, T_RIGHT, 2);
		level->thrower[1] = load_thrower(16, 5, T_BULLET, T_LEFT, 3);
		level->thrower[2] = load_thrower(9, 6, T_BULLET, T_RIGHT, 1);
		level->thrower[3] = load_thrower(16, 7, T_BULLET, T_LEFT, 6);
		level->thrower[4] = load_thrower(9, 8, T_BULLET, T_RIGHT, 1);
		level->thrower[5] = load_thrower(16, 9, T_BULLET, T_LEFT, 1);
		level->nb_messages = 3;
		level->message = malloc(3*sizeof(Message));
		level->message[0] = load_message("Look for secrets.", BOTTOM, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("It's easier this way,\nisn't it ?", TOP, XY, 175, 177, 24, 32);
		level->message[2] = load_message("Some walls aren't what\nthey appear to be...", BOTTOM, DEATH, 4, 0, 0, 0);
	}
	else if(n == 11)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 3, 1, 4, 0, 0, 0, 1, 1, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12, 1, 1,
			1, 1, 1, 1, 1, 1,14,14, 1, 1,14,14, 1, 1,14,14, 1, 1, 1,14,14, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1,13,13, 1, 1,13,13, 1, 1,13,13, 1, 1, 1,13,13, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1,13,13, 1, 1,13,13, 1, 1,13,13, 1, 1, 1,13,13, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1,13,13, 1, 1,13,13, 1, 1,13,13, 1, 1, 1,13,13,13,13,13, 1, 1,
			1, 1, 1, 1, 1, 1,13,13, 1, 1,13,13, 1, 1,13,13, 1, 1, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 1, 1, 1, 1,13,13, 1, 1,13,13, 1, 1,13,13, 1, 1, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 1, 1, 1, 1,13,13, 1, 1,13,13, 1, 1,13,13, 1, 1, 1, 1, 1, 1, 1,13, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 26;
		level->height = 20;
		level->map = malloc(26*20);
		memcpy(level->map, m, 26*20);
		level->nb_throwers = 1;
		level->thrower = malloc(sizeof(Thrower));
		level->thrower[0] = load_thrower(17, 2, T_BULLET, T_DOWN, 8);
		level->nb_messages = 6;
		level->message = malloc(6*sizeof(Message));
		level->message[0] = load_message("Lets crab some popcorn...", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("Oops, I forgot to tell you\nabout the traps...", TOP, Y, AFTER, 49, 0, 0);
		level->message[2] = load_message("Fate can be cruel sometimes.\nI don't think you have a choice...", TOP, XY, 79, 97, 136, 136);
		level->message[3] = load_message("I think you're starting to\nlike this, aren't you ?", TOP, XY, 111, 121, 56, 64);
		level->message[4] = load_message("You found my secret room !", TOP, XY, 151, 161, 56, 64);
		level->message[5] = load_message("Or not.", TOP, XY, 183, 185, 81, 89);
	}
	else if(n == 12)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 6, 6, 6, 6, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,10, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
			1, 1, 0,11, 0, 0, 0, 0, 0, 0,15, 0,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13, 0, 0,12, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 32;
		level->height = 10;
		level->map = malloc(32*10);
		memcpy(level->map, m, 32*10);
		level->nb_throwers = 1;
		level->thrower = malloc(sizeof(Thrower));
		level->thrower[0] = load_thrower(28, 2, T_BULLET, T_DOWN, 4);
		level->nb_messages = 3;
		level->message = malloc(3*sizeof(Message));
		level->message[0] = load_message("You should run. Fast.", BOTTOM, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("This was a fake princess !\nYou've been fooled, kiddo.", TOP, DEATH, 1, 0, 0, 0);
		level->message[2] = load_message("Here is your princess !", TOP, X, AFTER, 192, 0, 0);
	}
	else if(n == 13)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1,
			1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 7, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,15, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 5, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,12, 1, 1,
			1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
			1, 1, 8, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,15, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,15, 1, 1,
			1, 1, 0,11, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 5, 0, 0, 0, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		Moving_line line = {136, 48, 24, 0, 2, 136, 48, 136, 96};
		level->width = 26;
		level->height = 15;
		level->map = malloc(26*15);
		memcpy(level->map, m, 26*15);
		level->nb_lines = 1;
		level->line = malloc(sizeof(Moving_line));
		level->line[0] = line;
		level->nb_throwers = 3;
		level->thrower = malloc(3*sizeof(Thrower));
		level->thrower[0] = load_thrower(2, 2, T_BULLET, T_RIGHT, 16);
		level->thrower[1] = load_thrower(8, 4, T_BULLET, T_LEFT, 8);
		level->thrower[2] = load_thrower(2, 9, T_BULLET, T_RIGHT, 9);
		level->nb_messages = 4;
		level->message = malloc(4*sizeof(Message));
		level->message[0] = load_message("This is like a supermarket !", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("You made it !\nNow make your choice.\nWhich one is the nicest ?", TOP, X, AFTER, 88, 0, 0);
		level->message[2] = load_message("You really thought there was\na secret here, don't you ?", TOP, XY, 186, 192, 15, 16);
		level->message[3] = load_message("Fourth times is the good one,\nlike my uncle Benny says", TOP, DEATH, 3, 0, 0, 0);
	}
	else if(n == 14)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,10,  0,0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 6, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 6, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 5, 5, 1, 1, 0, 0, 0, 0,11, 1, 1, 1, 5, 0, 0, 0, 0,12, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 27;
		level->height = 20;
		level->map = malloc(27*20);
		memcpy(level->map, m, 27*20);
		level->nb_throwers = 3;
		level->thrower = malloc(3*sizeof(Thrower));
		level->thrower[0] = load_thrower(3, 2, T_BULLET, T_DOWN, 8);
		level->thrower[1] = load_thrower(21, 2, T_BULLET, T_DOWN, 8);
		level->thrower[2] = load_thrower(13, 4, T_STONE, T_DOWN, 2);
		level->nb_messages = 4;
		level->message = malloc(4*sizeof(Message));
		level->message[0] = load_message("Met your new friend :\nthe Garbage Thrower.", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("Woops.", TOP, XY, 55, 65, 48, 56);
		level->message[2] = load_message("That was the stupidest\nway you could die.", TOP, DEATH, 2, 0, 0, 0);
		level->message[3] = load_message("You're better than that !", TOP, DEATH, 4, 0, 0, 0);
	}
	else if(n == 15)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 3, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 6, 0,10,10, 0, 0, 0,10, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 5, 1, 1, 1, 1, 0, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1,
			1, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,10,10, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 1, 8, 0, 0,12, 1, 1,
			1, 1, 1, 1, 1, 5, 5, 1, 5, 5, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		Moving_wall wall = {W_RIGHT, 8, 8, 8, 8, 7};
		level->width = 44;
		level->height = 10;
		level->map = malloc(44*10);
		memcpy(level->map, m, 44*10);
		level->nb_walls = 1;
		level->wall = malloc(sizeof(Moving_wall));
		level->wall[0] = wall;
		level->nb_throwers = 9;
		level->thrower = malloc(9*sizeof(Thrower));
		level->thrower[0] = load_thrower(15, 1, T_BULLET, T_DOWN, 4);
		level->thrower[1] = load_thrower(29, 3, T_BULLET, T_DOWN, 4);
		level->thrower[2] = load_thrower(30, 3, T_BULLET, T_DOWN, 4);
		level->thrower[3] = load_thrower(34, 3, T_BULLET, T_DOWN, 4);
		level->thrower[4] = load_thrower(22, 4, T_BULLET, T_UP, 4);
		level->thrower[5] = load_thrower(25, 5, T_BULLET, T_LEFT, 4);
		level->thrower[6] = load_thrower(14, 6, T_BULLET, T_DOWN, 4);
		level->thrower[7] = load_thrower(15, 6, T_BULLET, T_DOWN, 4);
		level->thrower[8] = load_thrower(38, 6, T_BULLET, T_RIGHT, 4);
		level->nb_messages = 9;
		level->message = malloc(9*sizeof(Message));
		level->message[0] = load_message("You should hurry,\nmy friend Benny is here !", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("What ? Already ?", TOP, XY, 39, 49, 49, 56);
		level->message[2] = load_message("You should be\nashamed of yourself.", TOP, XY, 63, 73, 49, 56);
		level->message[3] = load_message("Be careful. The easiest way\nisn't always the best one.", TOP, XY, 112, 120, 48, 56);
		level->message[4] = load_message("Told you.", TOP, XY, 152, 160, 56, 56);
		level->message[5] = load_message("Are you sure this\nis the right way ?", BOTTOM, XY, 184, 192, 8, 8);
		level->message[6] = load_message("Yep, definitely not\nthe right way.", BOTTOM, XY, 296, 304, 8, 16);
		level->message[7] = load_message("Wrong way. Or is it ?", TOP, XY, 248, 256, 48, 56);
		level->message[8] = load_message("Run rabbit, run !", TOP, XY, 264, 272, 23, 32);
	}
	else if(n == 16)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0,27, 0, 0,12, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->type = DIALOG;
		level->width = 16;
		level->height = 9;
		level->map = malloc(16*9);
		memcpy(level->map, m, 16*9);
		level->nb_messages = 5;
		level->message = malloc(5*sizeof(Message));
		level->message[0] = load_message("Hellooo !", TOP, 0, 0, 0, 0, 0);
		level->message[1] = load_message("Why are you following\nme like this, sir ?", BOTTOM, 0, 0, 0, 0, 0);
		level->message[2] = load_message("You're ugly, your head is\nshaped like a square.", BOTTOM, 0, 0, 0, 0, 0);
		level->message[3] = load_message("Sorry, my heart goes\nto circle heads !", BOTTOM, 0, 0, 0, 0, 0);
		level->message[4] = load_message("   ...   ", TOP, 0, 0, 0, 0, 0);
	}
	else if(n == 17)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1,13,13,13,13,13,13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			12,13,13,13,13,13,13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, 7, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->width = 18;
		level->height = 26;
		level->map = malloc(18*26);
		memcpy(level->map, m, 18*26);
		level->nb_throwers = 2;
		level->thrower = malloc(2*sizeof(Thrower));
		level->thrower[0] = load_thrower(7, 22, T_BULLET, T_RIGHT, 4);
		level->thrower[1] = load_thrower(15, 22, T_BULLET, T_LEFT, 4);
		level->nb_messages = 2;
		level->message = malloc(2*sizeof(Message));
		level->message[0] = load_message("I think that the\nlast thing to do.", TOP, BEGIN, 0, 0, 0, 0);
		level->message[1] = load_message("Oh god, you found a secret !", TOP, XY, 48, 54, 128, 136);
	}
	else if(n == 18)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 0,10, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
			1, 1, 7, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 5, 5, 1, 1, 1, 1, 1, 1,
			1, 1, 0, 0, 0, 0, 6, 0, 0,10, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 3, 1, 1, 1, 1, 0, 0, 0, 0, 6, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 4, 0, 0, 3, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 5, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 6, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 3, 1, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,10, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 6, 1, 1, 1, 1, 0, 0, 0, 0, 3, 1, 0, 0, 0, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0,12, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 3, 1, 4, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
			1, 1, 0,11, 0, 0, 0, 0, 0, 5, 5, 0, 1, 1, 1, 1, 5, 1, 5, 5, 5, 5, 5, 5, 5, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		Moving_line line[] = {
			{76, 27, 8, 0, 2, 76, 27, 76, 55},
			{85, 19, 8, 0, 2, 85, 19, 85, 55},
			{94, 24, 16, 0, 2, 94, 24, 94, 32}
		};
		level->width = 27;
		level->height = 26;
		level->map = malloc(27*26);
		memcpy(level->map, m, 27*26);
		level->nb_lines = 3;
		level->line = malloc(3*sizeof(Moving_line));
		memcpy(level->line, line, 3*sizeof(Moving_line));
		level->nb_throwers = 6;
		level->thrower = malloc(6*sizeof(Thrower));
		level->thrower[0] = load_thrower(24, 2, T_BULLET, T_LEFT, 16);
		level->thrower[1] = load_thrower(3, 7, T_BULLET, T_DOWN, 8);
		level->thrower[2] = load_thrower(2, 10, T_BULLET, T_LEFT, 4);
		level->thrower[3] = load_thrower(4, 10, T_BULLET, T_LEFT, 4);
		level->thrower[4] = load_thrower(9, 11, T_STONE, T_DOWN, 2);
		level->thrower[5] = load_thrower(17, 18, T_BULLET, T_DOWN, 4);
		level->nb_messages = 1;
		level->message = malloc(sizeof(Message));
		level->message[0] = load_message("Final step. Be careful.", TOP, BEGIN, 0, 0, 0, 0);
	}
	else if(n == 19)
	{
		char m[] = {
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			1, 0, 0, 0, 0, 0,27, 0, 0,12, 0, 0, 0, 0, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
		};
		level->type = DIALOG;
		level->width = 16;
		level->height = 9;
		level->map = malloc(16*9);
		memcpy(level->map, m, 16*9);
		level->nb_messages = 4;
		level->message = malloc(4*sizeof(Message));
		level->message[0] = load_message("Hellooo !", TOP, 0, 0, 0, 0, 0);
		level->message[1] = load_message("Be my wife !", TOP, 0, 0, 0, 0, 0);
		level->message[2] = load_message("   ...   ", BOTTOM, 0, 0, 0, 0, 0);
		level->message[3] = load_message("Yeah, ok. Wathever.", BOTTOM, 0, 0, 0, 0, 0);
	}
	else return 0;
	return level;
}

void free_level(Level* level)
{
	int i;
	if(!level) return;
	if(level->map) free(level->map);
	if(level->line) free(level->line);
	if(level->wall) free(level->wall);
	if(level->message)
	{
		for(i=0 ; i<level->nb_messages ; i++)
			free(level->message[i].str);
		free(level->message);
	}
	if(level->thrower) free(level->thrower);
	free(level);
}

static Message load_message(char* str, Message_place place, Message_trigger_type trigger, int param1, int param2, int param3, int param4)
{
	char* c;
	int i, *p;
	Message message;
	message.nb_lines = 1;
	message.str = malloc(strlen(str)+1);
	strcpy(message.str, str);
	for(c = message.str ; *c ; c++)
	{
		if(*c == '\n')
		{
			*c = 0;
			message.nb_lines++;
		}
	}
	message.place = place;
	message.trigger = trigger;
	message.trigger_param[0] = param1;
	message.trigger_param[1] = param2;
	message.trigger_param[2] = param3;
	message.trigger_param[3] = param4;
	message.seen = 0;
	return message;
}

static Thrower load_thrower(int x, int y, Thrower_type type, Thrower_direction direction, int freq_model)
{
	int i;
	Thrower thrower;
	thrower.x = x;
	thrower.y = y;
	thrower.type = type;
	if(type == T_BULLET) thrower.direction = direction;
	else thrower.direction = T_DOWN;
	switch(freq_model)
	{
		case 0: //never shoots
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = 0;
			break;
		case 1: //always shoots
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = 1;
			break;
		case 2: //shoots one out of two
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = i&1;
			break;
		case 3: //shoots one out of three
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = (i%3?0:1);
			break;
		case 4: //shoots one out of four
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = (i&3?0:1);
			break;
		case 5: //shoots one out of four (other one)
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = (i+2&3?0:1);
			break;
		case 6: //0,0,1,1,0,0,1,1...
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = i&2;
			break;
		case 7: //1,1,0,0,1,1,0,0...
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = i+2&2;
			break;
		case 8: //shoots one out of eight
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = (i&7?0:1);
			break;
		case 9: //shoots one out of eight (other one)
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = (i+4&7?0:1);
			break;
		case 16: //shoots one out of eight
			for(i=0 ; i<SIZE_FREQ_ARRAY ; i++)
				thrower.freq[i] = (i&15?0:1);
			break;
	}
	return thrower;
}
