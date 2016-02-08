/*
 * main.c: the main file
 */

#include "main.h"

#include <stdbool.h>	// Booleans
#include <stdlib.h>		// Malloc etc.
#include <err.h>

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

	//Check the bounds and walls
	//TODO: Use some more modualr function, not errx
	if (robot->x < 0) errx(2, "Too much west. There is no reason for a robot to go there, there is no gold left on Alaska.");
	if (robot->y < 0) errx(2, "Too much south. It really isn't a good idea to go there. If your robot carried on long enough, it would drown in the ocean. You don't want that!");
	if (robot->x >= robot->field->width) errx(2, "Too much east. There are too high mountains for your robot.");
	if (robot->y >= robot->field->height) errx(2, "Too much north. It's cold there, your robot could freeze.");
	if (robot->field->cells[robot->x][robot->y].wall == true ) errx(1, "It's silly of you to crash your robots into a wall. You shouldn't do that, the robot was really expensive.");

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

