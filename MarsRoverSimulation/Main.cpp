#include<iostream>
//#include"MarsStation.h"
#include "PrioQueue.h"
#include "MarsStation.h"
#include "ArrayList.h"
int main() {
	int EventSize = 9;
	ArrQueue<Event> EventList;
	char F_Arr[9];
	char TYP_Arr[9];
	int ED_Arr[9];
	int ID_Arr[9];
	int TLOC_Arr[9];
	int MDUR_Arr[9];
	int SIG_Arr[9];

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
	
	int EmergRovNum = 5;
	int PolarRovNum = 4;


	int CheckupDurPol = 3;
	int SpeedPol = 10;
	PrioQueue<Rover> Polar_Rovers;
	int CheckupDurEmerg = 2;
	int SpeedEmerg = 12;
	PrioQueue<Rover> Emerg_Rovers;
	int NMissionsToCheckup = 2;

	//Constructing the mars station
	MarsStation TestStation(F_Arr, TYP_Arr, ED_Arr, ID_Arr, TLOC_Arr, MDUR_Arr, SIG_Arr, EventSize,
		CheckupDurPol, SpeedPol, CheckupDurEmerg,SpeedEmerg, NMissionsToCheckup,
		EmergRovNum,PolarRovNum);
	


}