#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "list.h"
#include "virtual_grid.h"

	int position[2];
	int orientation;
	list nodes_to_visit;
	char grid[GRID_NROWS*GRID_NCOLS];
task main()
{
	int cities_found;
	int i;

	bool exit;
	list_n test_node;

	list *aux;

	/********Initializing structures********/
	position[0] = 2;
	position[1] = 2;
	orientation = LESTE;
	for(i=0;i<GRID_NROWS*GRID_NCOLS;i++)
		grid[i] = '0';
	cities_found = 0;
	set_grid(grid,2,3,'0'); // GOAL
	set_grid(grid,position[0],position[1],'2');
	initialize_list(nodes_to_visit, QEUE);
	exit = false;
	/***************************************/

	// test_node.x = 5;
	// test_node.y = 0;
	// push(nodes_to_visit, test_node);
	// move_to_next_node(grid, position, &orientation, nodes_to_visit);
	// print_path(added_on_qeue);

	//do{
	//	if(!pop(bsf,test_node))
	//		break;
	//	writeDebugStream("%d,%d \t", test_node.x,test_node.y);
	//}while(true);
	while (cities_found < 3 && !exit){
		 //if(check_objective()){
			cities_found++;
		 //}
		check_surroundings(grid, position, orientation, nodes_to_visit);
		if(!move_to_next_node(grid,position, &orientation, nodes_to_visit))
			exit = true;
		set_grid(grid,position[0],position[1],'2');
		if (cities_found == 3)
			check_surroundings(grid, position, orientation, nodes_to_visit);
	}
	print_grid(grid);
	return;
}
