/*
 * headerP.h
 *
 *  Created on: Aug 20, 2022
 *      Author: Asus
 */

#ifndef HEADERP_H_
#define HEADERP_H_

#define WITH_ENGINE_TEMP_CONTROLLER 1
void start(char *system_state);
void Sensors_set_menu(char*system_state,char*sensors,char*traffic_lights
		,int*speed,int*room_temp,int*ac,int*ac_temp,int*engine_temp,int*temp_control,
		int*temp_to_engine);


void traffic(char*traffic_lights,int*speed);


void room_temperature(int*room_temp,int*ac,int*ac_temp);


void engine_temperature(int*engine_temp,int*temp_control,int*temp_to_engine);

void display(char *system_state,int *ac,int *speed,int *room_temp,
		int *temp_control,int *temp_to_engine);
#endif /* HEADERP_H_ */
