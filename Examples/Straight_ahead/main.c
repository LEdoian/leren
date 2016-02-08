#include "../../main.h"		//FIXME: This is obviously wrong.... (It works, but you have to make the environment and then the example)

#define WIDTH 10
#define HEIGHT 10

int main(void) {
	LER_init();
	LER_field_t * field = LER_create_field(WIDTH, HEIGHT); //FIXME: Should typedef it somewhere
	LER_robot_t * robot = LER_spawn_robot(0,0,field);
	while (1) {
		LER_go(robot);
	}
	return 0;		// Never happens
}
