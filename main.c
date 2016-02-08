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
	LE_field_t * field = malloc(sizeof(LE_field_t));
	field->width = width;
	field->height = height;

	// Allocate the cells
	field->cells = malloc(width*sizeof(LER_cell_t *));
	int i;
	for ( i=0 ; i<width ; i++ ) {
		field->cells[i] = malloc(height*sizeof(LE_cell_t));
		int j;
		for ( j=0 ; j<height ; j++) {
			field -> cells[i][j].x = i;
			field -> cells[i][j].y = j;
			field -> cells[i][j].wall = false;
		}
	}

	return field;
}


