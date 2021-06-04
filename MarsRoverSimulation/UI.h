#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;
template <typename T>
class UI
{
private:
	int Mode;
public:
	UI()
	{

	};







	// OUTPUT

	void ProgramMode()   // ASKS USER FOR DESIRED SIM MODE
	{
		cout << "Please choose simulation mode: " << endl;
		cout << "1. Interactive " << endl;
		cout << "2. Step-by-step " << endl;
		cout << "3. Silent " << endl;
		cin >> Mode;
	}


	void Interactive()   // RUNS INTERACTIVE
	{
		cout << "Current Day: " << Day << endl;  ////// VARIABLE DAY
		cout << WaitingMissions << " Waiting Missions: " << "[" << WaitingEmergency.print() << "] " << "(" << Waitingpolar.print() << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		//cout << InExecution << "In-Execution Missions/Rovers: " << "[" << "/*Waiting emergency??*/" << "] " << "(" << "/*Waiting polar??*/" << ") " << "{" << "/*Waiting mountainous??*/" << "} " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << AvailableRovers << "Available Rovers: " << "[" << AvailableEmergency.print() << "] " << "(" << AvailablePolar.print() << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << InCheckup << "In-Checkup Rovers: " << "[" << InCheckupEmergency.print() << "] " << "(" << InCheckupPolar.print() << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		//cout << Completed << "In-Execution Missions/Rovers: " << "[" << "/*Waiting emergency??*/" << "] " << "(" << "/*Waiting polar??*/" << ") " << "{" << "/*Waiting mountainous??*/" << "} " << endl;
	}

};