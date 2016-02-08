/*
 * main.c: the main file
 */

#include "main.h"

#include <stdbool.h>	// Booleans
#include <stdlib.h>		// Malloc etc.

int LER_init(void) {
//	LER_wall_handler(NULL);		// set the default handler to be null //FIXME: NYI
	return 0;
}


LER_field_t * LER_create_field(unsigned int width, unsigned int height) {
	LER_field_t * field = malloc(sizeof(LER_field_t));
	field->width = width;
	field->height = height;

	// Allocate the cells
	field->cells = malloc(width*sizeof(LER_cell_t *));
	int i;
	for ( i=0 ; i<width ; i++ ) {
		field->cells[i] = malloc(height*sizeof(LER_cell_t));
		int j;
		for ( j=0 ; j<height ; j++) {
			field -> cells[i][j].x = i;
			field -> cells[i][j].y = j;
			field -> cells[i][j].wall = false;
		}
	}

	return field;
}

LER_robot_t * LER_spawn_robot(unsigned int x, unsigned int y, LER_field_t * field) {
	LER_robot_t * robot = malloc(sizeof(LER_robot_t));
	robot->x = x;
	robot->y = y;
	robot->field = field;
	robot->ori = NORTH;

	return robot;
}

void LER_go(LER_robot_t * robot) {
	switch (robot->ori) {
		case NORTH:
			robot->y++;
		break;
		case EAST:
			robot->x++;
		break;
		case SOUTH:
			robot->y--;
		break;
		case WEST:
			robot->x--;
		break;
	}

	//Check the bounds and walls, NYI (call the function to handle wall crashes)
	/*
	if (x < 0) ...
	if (y < 0) ...
	if (x > robot->field->width) ...
	if (y > robot->field->height) ...
	if ( robot->field->cells[robot->x][robot->y].wall == true ) ...
	*/

	return;
}

void LER_turn(LER_robot_t * robot, LER_rot_t rot) {
	if (rot == CW) {
		switch (robot->ori) {
			case NORTH: robot->ori = EAST; break;
			case EAST: robot->ori = SOUTH; break;
			case SOUTH: robot->ori = WEST; break;
			case WEST: robot->ori = NORTH; break;
		}
	} else if (rot == CCW) {
		switch (robot->ori) {
			case NORTH: robot->ori = WEST; break;
			case EAST: robot->ori = NORTH; break;
			case SOUTH: robot->ori = EAST; break;
			case WEST: robot->ori = SOUTH; break;
		}
	}

	return;
}

