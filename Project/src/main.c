#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

#include "headerP.h"

char system_state;
/*
 System_states
 a. Turn on the vehicle engine
 b. Turn off the vehicle engine
 c. Quit the system
 */

char sensors;
/*
 a. Turn off the engine
 b. Set the traffic light color.
 c. Set the room temperature (Temperature Sensor)
 d. Set the engine temperature (Engine Temperature Sensor)
 */

char traffic_lights;
/*
 i. If the traffic light is ‘G’ set vehicle speed to 100 km/hr
 ii. If the traffic light is ‘O’ set vehicle speed to 30 km/hr
 iii. If the traffic light is ‘R’ set vehicle speed to 0 km/h
 */

int room_temp;
/*
 i. If temperature less than 10, Turn AC ON and set temperature to 20
 ii. If temperature is greater than 30, Turn AC ON and set temperature to 20
 iii. If temperature is otherwise, Turn AC OFF
 */

int speed;

int ac;
int ac_temp;

int engine_temp;
int temp_control;
int temp_to_engine;


int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	setvbuf(stderr, NULL, _IONBF, 0);

//1-
	start(&system_state);

	while (system_state == 'b') {
		puts("Turning off the engine , what else?");
		start(&system_state);
	}
	switch (system_state) {
	case 'a':
		puts("The system is on");
		break;

	case 'c':
		puts("The system is quitting");
		return 0;
	}
//2-

	Sensors_set_menu(&system_state, &sensors, &traffic_lights, &speed,
			&room_temp, &ac, &ac_temp, &engine_temp, &temp_control,
			&temp_to_engine);



//	traffic(&sensors,&traffic_lights,&speed);
//
//
//	room_temperature(&sensors,&Temp,&AC);

	return EXIT_SUCCESS;
}
