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
	struct LER_cell_s * * cells;
};

enum LER_ori_e {
	NORTH,
	EAST,
	SOUTH,
	WEST,
};

enum LER_rot_e {
	CW,
	CCW,
};

struct LER_robot_s {
	int x;
	int y;
	struct LER_field_s * field;
	enum LER_ori_e ori;
};

// Typedefs!!
typedef struct LER_cell_s LER_cell_t;
typedef struct LER_field_s LER_field_t;
typedef enum LER_ori_e LER_ori_t;
typedef enum LER_rot_e LER_rot_t;
typedef struct LER_robot_s LER_robot_t;

int LER_init(void/*??*/);
LER_field_t * LER_create_field(unsigned int width, unsigned int height);
LER_robot_t * LER_spawn_robot(unsigned int x, unsigned int y, LER_field_t * field);
void LER_go(LER_robot_t * robot);
//void LER_wall_handler(/*a pointer to function to be run when a robot collides into a wall. Possible parameters: x, y, field, robot*/);
void LER_turn(LER_robot_t * robot, LER_rot_t rot);


#endif /*ifndef LER_MAIN_H*/

