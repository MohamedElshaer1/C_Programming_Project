/*
 * function.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Asus
 */
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include <stdbool.h>
#include "headerP.h"

void start(char *system_state) {
	puts("a. Turn on the vehicle engine");
	puts("b. Turn off the vehicle engine");
	puts("c. Quit the system");
	scanf(" %c", system_state);

}

void Sensors_set_menu(char *system_state, char *sensor, char *traffic_light,
		int *speed, int *room_temp, int *ac, int *ac_temp, int *engine_temp,
		int *temp_control, int *temp_to_engine) {

	if (*system_state == 'a') {
		puts("a. Turn off the engine");
		puts("b. Set the traffic light color");
		puts("c. Set the room temperature (Temperature Sensor)");
		puts("d. Set the engine temperature (Engine Temperature Sensor)");
		scanf(" %c", sensor);

		if (*sensor == 'b')
			traffic(traffic_light, speed);
		else if (*sensor == 'c')
			room_temperature(room_temp, ac, ac_temp);
		else if (*sensor == 'd')
			#if (WITH_ENGINE_TEMP_CONTROLLER==1)
				engine_temperature(engine_temp, temp_control, temp_to_engine);
			#endif

		else if(*sensor=='a')
			start(system_state);

		if(*speed==30){
			*ac=1;
			*room_temp=(*room_temp* (5/4))+1;

			#if (WITH_ENGINE_TEMP_CONTROLLER==1)
				*temp_control=1;
				*temp_to_engine=(*temp_to_engine *(5/4))+1;
			#endif

		}


		display(system_state,ac,speed,room_temp,temp_control,temp_to_engine);

		Sensors_set_menu(system_state, sensor, traffic_light, speed, room_temp,
				ac, ac_temp, engine_temp, temp_control, temp_to_engine);
	}
	else
		return;
}
void traffic(char *traffic_lights, int *speed) {
	puts("If the traffic light is green enter ‘g’ ");
	puts("If the traffic light is orange enter‘o’ ");
	puts("If the traffic light is red enter ‘r’ ");
	scanf(" %c", traffic_lights);
	switch (*traffic_lights) {
	case 'g':
		*speed = 100;
		break;
	case 'o':
		*speed = 30;
		break;
	case 'r':
		*speed = 0;
		break;
	}
}
void room_temperature(int *room_temp, int *ac, int *ac_temp) {
	puts("Enter the room_temp");
	scanf(" %d", room_temp);
	if (*room_temp < 10) {
		*ac_temp = 20;
		*ac = 1;
	} else if (*room_temp > 30) {
		*ac_temp = 20;
		*ac = 1;
	} else {
		*ac_temp = 0;
		*ac = 0;
	}
}

void engine_temperature(int *engine_temp, int *temp_control,int *temp_to_engine) {
	puts("Enter the engine_temp");
	scanf(" %d", engine_temp);
	if (*engine_temp < 100) {
		*temp_to_engine = 125;
		*temp_control = 1;
	} else if (*engine_temp > 150) {
		*temp_to_engine = 125;
		*temp_control = 1;
	} else {
		*temp_control = 0;
	}
}

void display(char *system_state,int *ac,int *speed,int *room_temp,
		int *temp_control,int *temp_to_engine){

	if(*system_state=='a')
		puts("Engine ON");
	else
		puts("Engine OFF");

	if(*ac==1)
		puts("Ac ON");
	else
		puts("Ac OFF");

	printf("The speed is %d \n",*speed);

	printf("The Room Temp is %d \n",*room_temp);

	#if (WITH_ENGINE_TEMP_CONTROLLER==1)
		if(*temp_control==1)
			puts("Engine Temp Control ON");
		else
			puts("Engine Temp Control OFF");

		printf("Engine Temp is %d \n",*temp_to_engine);
	#endif

}
