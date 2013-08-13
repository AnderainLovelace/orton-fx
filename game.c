#include <stdlib.h> //for strlen, rand and abs
#include <fxlib.h> //for Bdisp_AllClr_VRAM, Bdisp_PutDisp_DD, PrintMini and GetKey
#include "draw.h"
#include "game.h"
#include "key.h"
#include "level.h"
#include <setjmp.h>


int game(Level* level)
{
	int i, j, nb_death=0;
	char run=1, dead=0, begin=1;
	Character orton, orton_start;
	Camera camera;
	Bullet bullet[MAX_BULLETS];
	Stone stone[MAX_STONES];
	int nb_bullets=0, nb_stones=0, stone_dx_sleep=0, thrower_sleep=0, thrower_freq_pos=0, moving_line_sleep=0, moving_wall_sleep=TIME_MOVING_WALL_SLEEP;
	
	if(!level) return 0;
	if(level->type == DIALOG)
	{
		dialog(level);
		return 0;
	}
/** Initialization **/
	camera.x = 8;
	camera.y = 8;
	for(i=1 ; i<level->height-1 ; i++)
	{
		for(j=1 ; j<level->width-1 ; j++)
		{
			if(level->map[i*level->width+j] == START)
			{
				orton.x = 8*j;
				orton.y = 8*i;
				level->map[i*level->width+j] = EMPTY;
			}
		}
	}
	orton.direction = RIGHT;
	orton.position = STOP;
	orton.counter_jump = orton.dx = orton.dy = 0;
	orton.can_jump = 1;
	orton.counter_change_position = TIME_ORTON_CHANGE_POSITION;
	orton_start = orton;
	
	camera.x = orton.x-60;
	camera.y = orton.y-28;
	
/** Main loop **/
	while(run)
	{
/** Movements **/
		/** Orton **/
		if(!dead)
		{
			if(IsKeyDown(KEY_CHAR_0)) pause();
			if(IsKeyDown(KEY_CTRL_LEFT))
			{
				orton.direction = LEFT;
				if(orton.dx > -2)
					orton.dx--;
			}
			else if(IsKeyDown(KEY_CTRL_RIGHT))
			{
				orton.direction = RIGHT;
				if(orton.dx < 2)
					orton.dx++;
			}
			else orton.dx /= 2;
			while(level->map[orton.y/8*level->width + (orton.x+orton.dx+1)/8]==WALL || level->map[(orton.y+5)/8*level->width + (orton.x+orton.dx+1)/8]==WALL)
				orton.dx++;
			while(level->map[orton.y/8*level->width + (orton.x+orton.dx+6)/8]==WALL || level->map[(orton.y+5)/8*level->width + (orton.x+orton.dx+6)/8]==WALL)
				orton.dx--;
			if(orton.dx)
			{
				if(orton.counter_change_position > TIME_ORTON_CHANGE_POSITION-1)
				{
					orton.position = orton.position%4+1;
					orton.counter_change_position = 0;
				}
				else orton.counter_change_position++;
			} else {
				orton.position = STOP;
				orton.counter_change_position = TIME_ORTON_CHANGE_POSITION;
			}
			if((IsKeyDown(KEY_CTRL_UP) || IsKeyDown(KEY_CTRL_SHIFT)) && (orton.dy<=0 || orton.can_jump) && orton.counter_jump < MAX_JUMP)
			{
				if(orton.can_jump) orton.dy = -2;
				else orton.dy-=2;
				orton.counter_jump++;
			}
			orton.x += orton.dx;
			orton.y += orton.dy/2;
			if(orton.dy < FALLING_MAX_SPEED*2) orton.dy++;
		}

		/** Moving lines **/
		moving_line_sleep = (moving_line_sleep+1)%TIME_LINE_SLEEP;
		for(i=0 ; i<level->nb_lines ; i++)
		{
			if(moving_line_sleep%(TIME_LINE_SLEEP/level->line[i].dx)==0) level->line[i].x += sng(level->line[i].dx);
			if(moving_line_sleep%(TIME_LINE_SLEEP/level->line[i].dy)==0) level->line[i].y += sng(level->line[i].dy);
		}
		
		/** Moving walls **/
		if(moving_wall_sleep) moving_wall_sleep--;
		else
		{
			for(i=0 ; i<level->nb_walls ; i++)
			{
				switch(level->wall[i].direction)
				{
					case W_LEFT: level->wall[i].x--; break;
					case W_RIGHT: level->wall[i].x++; break;
					case W_UP: level->wall[i].y--; break;
					case W_DOWN: level->wall[i].y++; break;
				}
			}
		}
		
		/** Bullets **/
		for(i=0 ; i<nb_bullets ; i++)
		{
			bullet[i].x += bullet[i].dx;
			bullet[i].y += bullet[i].dy;
		}
		
		/** Stones **/
		stone_dx_sleep = (stone_dx_sleep+1)%TIME_STONE_DX_SLEEP;
		for(i=0 ; i<nb_stones ; i++)
		{
			if(stone[i].dx)
			{
				if(stone_dx_sleep%(TIME_STONE_DX_SLEEP/abs(stone[i].dx))==0 && level->map[stone[i].y/8*level->width+(stone[i].x+1+2*sng(stone[i].dx))/8] != WALL)
					stone[i].x += sng(stone[i].dx);
			}
			stone[i].y += stone[i].dy/6;
			if(stone[i].dy < FALLING_MAX_SPEED*4) stone[i].dy++;
		}
		
		/** Throwers **/
		thrower_sleep = (thrower_sleep+1)%TIME_THROWER_SLEEP;
		if(thrower_sleep == 0)
		{
			thrower_freq_pos = (thrower_freq_pos+1)%SIZE_FREQ_ARRAY;
			for(i=0 ; i<level->nb_throwers ; i++)
			{
				if(level->thrower[i].freq[thrower_freq_pos])
				{
					switch(level->thrower[i].type)
					{
						case T_BULLET:
							if(nb_bullets == MAX_BULLETS)
							{
								for(j=0 ; j<MAX_BULLETS-1 ; j++)
									bullet[j] = bullet[j+1];
								nb_bullets--;
							}
							bullet[nb_bullets].direction = level->thrower[i].direction;
							bullet[nb_bullets].x = level->thrower[i].x*8+3;
							bullet[nb_bullets].y = level->thrower[i].y*8+3;
							bullet[nb_bullets].dx = bullet[nb_bullets].dy = 0;
							switch(bullet[nb_bullets].direction)
							{
								case T_LEFT:	bullet[nb_bullets].dx = -BULLET_SPEED; break;
								case T_RIGHT:	bullet[nb_bullets].dx = BULLET_SPEED; break;
								case T_UP:  	bullet[nb_bullets].dy = -BULLET_SPEED; break;
								case T_DOWN:	bullet[nb_bullets].dy = BULLET_SPEED; break;
							}
							nb_bullets++;
							break;
						case T_STONE:
							if(nb_stones == MAX_STONES)
							{
								for(j=0 ; j<MAX_STONES-1 ; j++)
									stone[j] = stone[j+1];
								nb_stones--;
							}
							stone[nb_stones].x = level->thrower[i].x*8+2;
							stone[nb_stones].y = level->thrower[i].y*8;
							stone[nb_stones].dx = rand()%9-4;
							stone[nb_stones].dy = 0;
							nb_stones++;
							break;
					}
				}
			}
		}

/** Collisions **/
		if(!dead)
		{
			/** Orton & Princess **/
			if(level->map[(orton.y+1)/8*level->width+(orton.x+1)/8] == GOAL ||
			   level->map[(orton.y+1)/8*level->width+(orton.x+6)/8] == GOAL ||
			   level->map[(orton.y+6)/8*level->width+(orton.x+1)/8] == GOAL ||
			   level->map[(orton.y+6)/8*level->width+(orton.x+6)/8] == GOAL)
				run = 0;

			orton.can_jump = 0;
			/** Orton & ceiling **/
			if(level->map[orton.y/8*level->width + (orton.x+1)/8]==WALL || level->map[orton.y/8*level->width + (orton.x+6)/8]==WALL)
			{
				orton.y = (orton.y>>3<<3)+8;
				if(orton.dy<0) orton.dy = 1;
			}

			/** Orton & ground **/
			else if(level->map[(orton.y/8+1)*level->width + (orton.x+1)/8]==WALL || level->map[(orton.y/8+1)*level->width + (orton.x+6)/8]==WALL)
			{
				orton.can_jump = 1;
				orton.counter_jump = 0;
				orton.dy = 0;
				orton.y = orton.y>>3<<3;
			}

			/** Orton & moving lines **/
			else
			{
				for(i=0 ; i<level->nb_lines ; i++)
				{
					if(orton.dy >= 0 &&
					   orton.x+6>=level->line[i].x && orton.x+1<=level->line[i].x+level->line[i].width-1 &&
					   orton.y+8 - level->line[i].y>=0 && orton.y+8 - level->line[i].y <= orton.dy/2-
					   (moving_line_sleep%(TIME_LINE_SLEEP/level->line[i].dy) ? 0 : sng(level->line[i].dy)))
					{
						orton.can_jump = 1;
						orton.counter_jump = 0;
						orton.y = level->line[i].y-8;
						if(level->map[orton.y/8*level->width + (orton.x+1+level->line[i].dx)/8]!=WALL &&
						   level->map[orton.y/8*level->width + (orton.x+6+level->line[i].dx)/8]!=WALL &&
						   level->map[(orton.y+7)/8*level->width + (orton.x+1+level->line[i].dx)/8]!=WALL &&
						   level->map[(orton.y+7)/8*level->width + (orton.x+6+level->line[i].dx)/8]!=WALL &&
						   moving_line_sleep%(TIME_LINE_SLEEP/level->line[i].dx)==0)
							orton.x += sng(level->line[i].dx);
					}
				}
			}

			/** Orton & moving walls **/
			for(i=0 ; i<level->nb_walls ; i++)
			{
				switch(level->wall[i].direction)
				{
					case W_LEFT:
						if(orton.y+7>=level->wall[i].y && orton.y+1<=level->wall[i].y+level->wall[i].size*8-1 && orton.x+6>=level->wall[i].x-2)
							dead = 1;
						break;
					case W_RIGHT:
						if(orton.y+7>=level->wall[i].y && orton.y+1<=level->wall[i].y+level->wall[i].size*8-1 && orton.x+1<=level->wall[i].x+9)
							dead = 1;
						break;
					case W_UP:
						if(orton.x+6>=level->wall[i].x && orton.x+1<=level->wall[i].x+level->wall[i].size*8-1 && orton.y+6<=level->wall[i].y-2)
							dead = 1;
						break;
					case W_DOWN:
						if(orton.x+6>=level->wall[i].x && orton.x+1<=level->wall[i].x+level->wall[i].size*8-1 && orton.y<=level->wall[i].y+9)
							dead = 1;
						break;
				}
			}

			/** Orton & fake princesses **/
			if(level->map[(orton.y+1)/8*level->width+(orton.x+1)/8] == FAKE_PRINCESS ||
			   level->map[(orton.y+1)/8*level->width+(orton.x+6)/8] == FAKE_PRINCESS ||
			   level->map[(orton.y+6)/8*level->width+(orton.x+1)/8] == FAKE_PRINCESS ||
			   level->map[(orton.y+6)/8*level->width+(orton.x+6)/8] == FAKE_PRINCESS)
			{
				dead = 1;
				if(level->map[(orton.y+1)/8*level->width+(orton.x+1)/8] == FAKE_PRINCESS) level->map[(orton.y+1)/8*level->width+(orton.x+1)/8] = EMPTY;
				if(level->map[(orton.y+1)/8*level->width+(orton.x+6)/8] == FAKE_PRINCESS) level->map[(orton.y+1)/8*level->width+(orton.x+6)/8] = EMPTY;
				if(level->map[(orton.y+6)/8*level->width+(orton.x+1)/8] == FAKE_PRINCESS) level->map[(orton.y+6)/8*level->width+(orton.x+1)/8] = EMPTY;
				if(level->map[(orton.y+6)/8*level->width+(orton.x+6)/8] == FAKE_PRINCESS) level->map[(orton.y+6)/8*level->width+(orton.x+6)/8] = EMPTY;
			}

			/** Orton & spikes **/
			if(orton.x%8<2 && (
			   level->map[orton.y/8*level->width+orton.x/8] == SPIKE_LEFT ||
			   level->map[(orton.y+7)/8*level->width+orton.x/8] == SPIKE_LEFT))
				dead = 1;
			if((orton.x+1)%8<2 && (
			   level->map[orton.y/8*level->width+(orton.x+1)/8] == SPIKE_RIGHT ||
			   level->map[(orton.y+7)/8*level->width+(orton.x+1)/8] == SPIKE_RIGHT))
				dead = 1;
			if(orton.y%8<2 && (
			   level->map[orton.y/8*level->width+(orton.x+1)/8] == SPIKE_UP ||
			   level->map[orton.y/8*level->width+(orton.x+6)/8] == SPIKE_UP))
				dead = 1;
			if(orton.y%8<2 && (
			   level->map[orton.y/8*level->width+(orton.x+1)/8] == SPIKE_DOWN ||
			   level->map[orton.y/8*level->width+(orton.x+6)/8] == SPIKE_DOWN))
				dead = 1;

			/** Orton & bullets **/
			for(i=0 ; i<nb_bullets ; i++)
			{
				if(abs(orton.x-bullet[i].x+3)<=4 && abs(orton.y-bullet[i].y+3)<=4)
					dead = 1;
			}

			/** Orton & stones **/
			for(i=0 ; i<nb_stones ; i++)
			{
				if(stone[i].dy > 1)
				{
					if(stone[i].x+2>=orton.x+1 && stone[i].x<=orton.x+6 && stone[i].y+2>=orton.y && stone[i].y<=orton.y+7)
					{
						orton.dy = 2;
						stone[i].dy = -1;
						stone[i].y = orton.y-2;
					}
				}
				else if(stone[i].x+2>=orton.x+2 && stone[i].x<=orton.x+5 && stone[i].y>=orton.y+5 && stone[i].y<=orton.y+8)
				{
					orton.y = stone[i].y-8;
					orton.can_jump = 1;
					orton.counter_jump = 0;
					orton.dy = 0;
				}
				else if(stone[i].x+2>=orton.x && stone[i].x<=orton.x+7 && stone[i].y>=orton.y && stone[i].y<=orton.y+5)
				{
					stone[i].dx += orton.dx*TIME_STONE_DX_SLEEP;
					orton.dx /= 2;
				}
			}

			if(!orton.can_jump) orton.position = JUMP;
		}

		/** Moving lines **/
		if(moving_line_sleep == 0)
		{
			for(i=0 ; i<level->nb_lines ; i++)
			{
				if(moving_line_sleep%(TIME_LINE_SLEEP/level->line[i].dx)==0 && (level->line[i].x <= level->line[i].x1 || level->line[i].x >= level->line[i].x2)) level->line[i].dx *= -1;
				if(moving_line_sleep%(TIME_LINE_SLEEP/level->line[i].dy)==0 && (level->line[i].y <= level->line[i].y1 || level->line[i].y >= level->line[i].y2)) level->line[i].dy *= -1;
			}
		}

		/** Bullets **/
		for(i=0 ; i<nb_bullets ; i++)
		{
			if(level->map[bullet[i].y/8*level->width+bullet[i].x/8] == WALL)
			{
				for(j=i ; j<nb_bullets-1 ; j++)
					bullet[j] = bullet[j+1];
				nb_bullets--;
				i--;
			}
		}

		/** Stones **/
		for(i=0 ; i<nb_stones ; i++)
		{
			if(level->map[(stone[i].y+3)/8*level->width+stone[i].x/8] == WALL)
			{
				if(level->map[stone[i].y/8*level->width+stone[i].x/8] == WALL)
					stone[i].y = (stone[i].y&(~7))+-3;
				else 
					stone[i].y = (stone[i].y&(~7))+5;
				stone[i].dy = 0;
				stone[i].dx /= rand()%2+1;
			}
		}


/** Moving camera **/
		i = orton.x-60-camera.x;
		j = orton.y-28-camera.y;
		if(abs(i)>FALLING_MAX_SPEED || abs(j)>FALLING_MAX_SPEED)
		{
			if(abs(i) > abs(j))
			{
				camera.x += 5*sng(i);
				camera.y += 5*j/abs(i);
			} else {
				camera.y += 5*sng(j);
				if(j) camera.x += 5*i/abs(j);
			}
		} else {
			camera.x = orton.x-60;
			camera.y = orton.y-28;
		}
		if(camera.x < 8) camera.x = 8;
		if(camera.x > level->width*8-136) camera.x = level->width*8-136;
		if(camera.y < 8) camera.y = 8;
		if(camera.y > level->height*8-72) camera.y = level->height*8-72;
		if(dead)
		{
			camera.x += rand()%7-3;
			camera.y += rand()%7-3;
			dead++;
			if(dead == 12)
			{
				dead = 0;
				nb_death++;
				orton = orton_start;
				moving_wall_sleep = TIME_MOVING_WALL_SLEEP;
				for(i=0 ; i<level->nb_walls ; i++)
				{
					level->wall[i].x = level->wall[i].begin_x;
					level->wall[i].y = level->wall[i].begin_y;
				}
				if(level->id == NB_LEVELS)
				{
					return 1;
				}
			}
		}

/** Drawing **/
		allclr_vbuf();
		Bdisp_AllClr_VRAM();
		/** Map **/
		for(i=0 ; i<9 ; i++)
		{
			for(j=0 ; j<17 ; j++)
			{
				if(j+camera.x/8>=0 && j+camera.x/8<level->width && i+camera.y/8>0 && i+camera.y/8<level->height)
				{
					Bmp b = level->map[(i+camera.y/8)*level->width+j+camera.x/8];
					if(b==WALL &&
					   level->map[(i-1+camera.y/8)*level->width+j+camera.x/8]!=WALL &&
					   level->map[(i-1+camera.y/8)*level->width+j+camera.x/8]!=FAKE_WALL)
						draw_bmp(WALL_TOP, 8*j-camera.x%8, 8*i-camera.y%8);
					else
						draw_bmp(b, 8*j-camera.x%8, 8*i-camera.y%8);
				}
			}
		}
		/** Moving lines **/
		for(i=0 ; i<level->nb_lines ; i++)
			draw_horizontal_line(level->line[i].y-camera.y, level->line[i].x-camera.x, level->line[i].x+level->line[i].width-1-camera.x);
		/** Moving walls **/
		for(i=0 ; i<level->nb_walls ; i++)
		{
			for(j=0 ; j<level->wall[i].size ; j++)
			{
				switch(level->wall[i].direction)
				{
					case W_LEFT:
						draw_bmp(WALL, level->wall[i].x-camera.x, level->wall[i].y+j*8-camera.y);
						draw_bmp(SPIKE_LEFT, level->wall[i].x-8-camera.x, level->wall[i].y+j*8-camera.y);
						break;
					case W_RIGHT:
						draw_bmp(WALL, level->wall[i].x-camera.x, level->wall[i].y+j*8-camera.y);
						draw_bmp(SPIKE_RIGHT, level->wall[i].x+8-camera.x, level->wall[i].y+j*8-camera.y);
						break;
					case W_UP:
						draw_bmp(WALL, level->wall[i].x-camera.x, level->wall[i].y+j*8-camera.y);
						draw_bmp(SPIKE_UP, level->wall[i].x-camera.x, level->wall[i].y+j*8-8-camera.y);
						break;
					case W_DOWN:
						draw_bmp(WALL, level->wall[i].x-camera.x, level->wall[i].y+j*8-camera.y);
						draw_bmp(SPIKE_DOWN, level->wall[i].x-camera.x, level->wall[i].y+j*8+8-camera.y);
						break;
				}
			}
		}
		/** Bullets **/
		for(i=0 ; i<nb_bullets ; i++)
		{
			draw_bmp(bullet[i].direction+BULLET_LEFT, bullet[i].x-camera.x, bullet[i].y-camera.y);
			draw_bmp(bullet[i].direction+BULLET_LEFT, bullet[i].x+bullet[i].dx-camera.x, bullet[i].y+bullet[i].dy-camera.y);
		}
		/** Stones **/
		for(i=0 ; i<nb_stones ; i++)
			draw_bmp(STONE, stone[i].x-camera.x, stone[i].y-camera.y);
		/** Orton **/
		if(dead) draw_bmp(dead/4+EXPLOSION1, orton.x-camera.x, orton.y-camera.y);
		else draw_bmp(orton.position+6*orton.direction+ORTON_STOP_LEFT, orton.x-camera.x, orton.y-camera.y);
		putdispvram_vbuf();
		/** Messages **/
		draw_message(level, &orton, nb_death);
		Bdisp_PutDisp_DD();
		if(begin)
		{
			begin = 0;
		}
/** Delay **/
		Sleep(30);
	}
	return 0;
}

void dialog(Level* level)
{
	int i, j, n, key, x, width, height, begin_line, line_lenght;
	for(n=0 ; n<level->nb_messages ; n++)
	{
		Bdisp_AllClr_VRAM();
		for(i=1 ; i<9 ; i++)
		{
			for(j=0 ; j<16 ; j++)
			{
				Bmp b = level->map[i*level->width+j];
				if(b==WALL && level->map[(i-1)*level->width+j]!=WALL)
					draw_bmp(WALL_TOP, 8*j, 8*i-8);
				else
					draw_bmp(b, 8*j, 8*i-8);
			}
		}
		width = 0;
		begin_line = 0;
		height = level->message[n].nb_lines * 6;
		for(i=0 ; i<level->message[n].nb_lines ; i++)
		{
			line_lenght = strlen(level->message[n].str + begin_line);
			if(line_lenght*4 > width) width = line_lenght*4;
			begin_line += line_lenght+1;
		}
		if(level->message[n].place == BOTTOM) x = 112-width/2;
		else x = 16+width/2;
		draw_rectangle(x-width/2, 24-height/2, x+width/2, 24+height/2);

		begin_line = 0;
		for(i=0 ; i<level->message[n].nb_lines ; i++)
		{
			line_lenght = strlen(level->message[n].str + begin_line);
			PrintMini(x+1-line_lenght*2, 25-height/2+i*6, level->message[n].str + begin_line, MINI_REV);
			begin_line += line_lenght+1;
		}
		
		key = 0;
		Bdisp_PutDisp_DD();
		IsKeyDown(KEY_CTRL_EXE);
		while(key != KEY_CTRL_EXE) GetKey(&key);
	}
}

static void draw_message(Level* level, Character* orton, int nb_death)
{
	int i, sel=-1;
	static int current_message, time=0, id_level;
	if(level->id != id_level)
	{
		time = 0;
		id_level = level->id;
	}
	for(i=0 ; i<level->nb_messages ; i++)
	{
		if(level->message[i].seen == 0)
		{
			switch(level->message[i].trigger)
			{
				case BEGIN: sel = i; break;
				case DEATH:
					if(nb_death >= level->message[i].trigger_param[0])
						sel = i;
					break;
				case X:
					if((level->message[i].trigger_param[0]==BEFORE && orton->x<=level->message[i].trigger_param[1]) || (level->message[i].trigger_param[0]==AFTER && orton->x>=level->message[i].trigger_param[1]))
						sel = i;
					break;
				case Y:
					if((level->message[i].trigger_param[0] == BEFORE && orton->y <= level->message[i].trigger_param[1]) ||
					   (level->message[i].trigger_param[0] == AFTER && orton->y >= level->message[i].trigger_param[1]))
						sel = i;
					break;
				case XY:
					if(orton->x >= level->message[i].trigger_param[0] &&
					   orton->x <= level->message[i].trigger_param[1] &&
					   orton->y >= level->message[i].trigger_param[2] &&
					   orton->y <= level->message[i].trigger_param[3])
						sel = i;
					break;
			}
		}
	}
	if(sel != -1)
	{
		level->message[sel].seen = 1;
		current_message = sel;
		time = MESSAGE_DEFAULT_TIME;
	}

	if(time)
	{
		int width=0, height, y=2, begin_line=0, line_lenght;
		height = level->message[current_message].nb_lines * 6;
		for(i=0 ; i<level->message[current_message].nb_lines ; i++)
		{
			line_lenght = strlen(level->message[current_message].str + begin_line);
			if(line_lenght*4 > width) width = line_lenght*4;
			begin_line += line_lenght+1;
		}
		if(level->message[current_message].place == BOTTOM) y = 62-height;
		draw_rectangle(62-width/2, y-1, 65+width/2, y+height-1);

		begin_line = 0;
		for(i=0 ; i<level->message[current_message].nb_lines ; i++)
		{
			line_lenght = strlen(level->message[current_message].str + begin_line);
			PrintMini(63-line_lenght*2, y+i*6, level->message[current_message].str + begin_line, MINI_REV);
			begin_line += line_lenght+1;
		}
		time--;
	}
}

void pause()
{
	extern jmp_buf exit_jmp;
	longjmp(exit_jmp,1);
/*
	int i=0, j;
	char* vram = vram_adress();
	char bmp[] = {255, 255, 255, 255, 255, 255, 255, 255, 195, 140, 152, 67, 201, 36, 147, 207, 195, 4, 152, 199, 207, 36, 158, 79, 207, 38, 48, 195, 255, 255, 255, 255, 255, 255, 255, 255};
	for(i=0 ; i<9 ; i++)
	{
		for(j=0 ; j<4 ; j++)
			vram[(i+28<<4)+j+6] = bmp[(i<<2)+j];
	}
	IsKeyDown(KEY_CTRL_EXE);
	while(i != KEY_CTRL_EXE)
	{
		GetKey(&i);
	}*/
}
