/*
 * main.h: header file for main.c
 */

//TODO: Add Doxygen documentation

#ifndef LER_MAIN_H
#define LER_MAIN_H

#include <stdbool.h>

struct LER_cell_s {
	unsigned int x;		// redundant?
	unsigned int y;		// redundant?
	bool wall;
};

struct LER_field_s {
	unsigned int width;
	unsigned int height;
	struct LER_cell_s ** cells;
};

enum LER_ori_e {
	NORTH;
	EAST;
	SOUTH;
	WEST;
};

enum LER_rot_e {
	CW;
	CCW;
};

struct LER_robot_s {
	unsigned int x;
	unsigned int y;
	struct LER_field_s * field;
	enum LER_ori_e ori;
};

int LER_init(void/*??*/);
struct LER_field_s * LER_create_field(unsigned int width, unsigned int height);
struct LER_robot_s * LER_spawn_robot(unsigned int x, unsigned int y, struct LER_field_s * field);
void LER_go(struct LER_robot_s * robot);
void LER_wall_handler(/*a pointer to function to be run when a robot collides into a wall. Possible parameters: x, y, field, robot*/);
void LER_turn(struct LER_robot_s * robot, enum LER_rot_e rot);


#endif /*ifndef LER_MAIN_H*/
