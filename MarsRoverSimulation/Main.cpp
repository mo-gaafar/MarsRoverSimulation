#include<iostream>
//#include"MarsStation.h"
#include <Windows.h>
#include "PrioQueue.h"
#include "MarsStation.h"
#include "ArrayList.h"
#include "UI.h"
#include "arrqueue.h"
int main() {


	//---------------------Initialization Stage---------------------//
	UI UserInterface; // interface object which reads from input file on construction

	int EmergRovNum = UserInterface.getEmRoverCount();
	int PolarRovNum = UserInterface.getPolarRoverCount();
	int NMissionsToCheckup = UserInterface.getCheckCount();
	int EventSize = UserInterface.getNumberOFEvents();

	//initializing F_Arr (useless event type array)
	char* F_Arr = new char[EventSize];
	for (int i = 0; i < EventSize; i++)
	{
		F_Arr[i] = 'F';//formulation event type
	}
	
	//-----------------Constructing the mars station-------------------//
	MarsStation TestStation(F_Arr, UserInterface.getMissionType(), UserInterface.getEventDay(), 
		UserInterface.getID(), UserInterface.getLocation(),UserInterface.getDuration(), UserInterface.getSignifiance(), EventSize,
		UserInterface.getPolarCheck(), UserInterface.getPolarSpeed(), UserInterface.getEmCheck(),UserInterface.getEmSpeed(), NMissionsToCheckup,
		EmergRovNum, PolarRovNum);
	
	
	TestStation.Run();

	
	
}