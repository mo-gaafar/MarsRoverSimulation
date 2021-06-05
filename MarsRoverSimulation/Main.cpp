#include<iostream>
//#include"MarsStation.h"
#include "PrioQueue.h"
#include "MarsStation.h"
int main() {
	int EventSize = 9, ArrQueue<Event> EventList;
	char* F_Arr, char* TYP_Arr, int* ED_Arr, int* ID_Arr, int* TLOC_Arr, int* MDUR_Arr, int* SIG_Arr;

	int EventArrInput[9][7] =
	{
	{'F', 'P',1, 1, 100, 4, 5},
	{'F', 'E',1, 2, 100, 4, 5},
	{'F', 'E',1, 3, 100, 4, 5},
	{'F', 'P',1, 4, 100, 4, 5},
	{'F', 'E',1, 5, 100, 4, 5},
	{'F', 'P',1, 6, 100, 4, 5},
	{'F', 'E',1, 7, 100, 4, 5},
	{'F', 'E',1, 8, 100, 4, 5},
	{'F', 'E',1, 9, 100, 4, 5},

	};
	for (int i = 0; i < EventSize; i++)
	{
		F_Arr[i] = EventArrInput[i][0];
		TYP_Arr[i] = EventArrInput[i][1];
		ED_Arr[i] = EventArrInput[i][2];
		ID_Arr[i] = EventArrInput[i][3];
		TLOC_Arr[i] = EventArrInput[i][4];
		MDUR_Arr[i] = EventArrInput[i][5];
		SIG_Arr[i] = EventArrInput[i][6];
	}
	

	int CheckupDurPol = 3, int SpeedPol = 10;
	PrioQueue<Rover> Polar_Rovers;
	int CheckupDurEmerg = 2, int SpeedEmerg = 12;
	PrioQueue<Rover> Emerg_Rovers;
	int NMissionsToCheckup = 2;

	//Constructing the mars station
	MarsStation TestStation(F_Arr, TYP_Arr, ED_Arr, ID_Arr, TLOC_Arr, MDUR_Arr, SIG_Arr, EventSize, EventList,
		CheckupDurPol, SpeedPol, Polar_Rovers, CheckupDurEmerg,SpeedEmerg, Emerg_Rovers, NMissionsToCheckup);


}