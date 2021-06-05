#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "MarsStation.h"
#include <fstream>
using namespace std;

template <typename T>
class UI
{
private:
	int Mode;
	int day;
	ArrQueue<Mission> PolarWaiting_Mission;
	PrioQueue<Mission> EmergWaiting_Mission;
	PrioQueue<Mission> InExecutionEmerg;
	PrioQueue<Mission> InExecutionPolar;
	PrioQueue<Rover> Busy_RoversEmerg;
	PrioQueue<Rover> Busy_RoversPolar;

	int NumberOfWaiting;
	int NumberOfInExecution;
public:
	UI(MarsStation& InputStation)
	{
		day = InputStation.GetDay();
		PolarWaiting_Mission = InputStation.GetPolarWaiting_Mission();
		EmergWaiting_Mission = InputStation.GetEmergWaiting_Mission();
		InputStation.GetInExecution(InExecutionEmerg, InExecutionPolar);
		InputStation.GetBusy_Rovers(Busy_RoversEmerg, Busy_RoversPolar);
		NumberOfWaiting = 0;
	}






	// OUTPUT


	//-----------------------------  PRINT FUNCTIONS  -----------------------------------------//


	//    ArrQueue ROVER PRINT   //
	void printID(ArrQueue<Rover>& Q)
	{
		Rover Item;

		Q.dequeue(Item);
		cout << Item.getID();

		while (Q.dequeue(Item))
			cout << "," << Item.getID();
	}


	//    PrioQueue ROVER PRINT   //
	void printID(PrioQueue<Rover>& Q)
	{
		Rover Item;

		Q.dequeue(Item);
		cout << Item.getID();

		while (Q.dequeue(Item))
			cout << "," << Item.getID();
	}


	//    ArrQueue MISSION PRINT    //
	void printID(ArrQueue<Mission>& Q)
	{
		Mission Item;

		Q.dequeue(Item);
		cout << Item.getID();

		while (Q.dequeue(Item))
			cout << "," << Item.getID();
	}


	//   PrioQueue MISSION PRINT   //
	void printID(PrioQueue<Mission>& Q)
	{
		Mission Item;

		Q.dequeue(Item);
		cout << Item.getID();

		while (Q.dequeue(Item))
			cout << "," << Item.getID();
	}

	// END OF PRINT FUNCTIONS //
	//-------------------------------------------------------------------------------------------------------------------------------------//



	//-----------------------------  COUNTER FUNCTIONS  -----------------------------------------//
	int count(ArrQueue<Rover>& Q)
	{
		Rover Item;
		int count = 0;

		while (Q.dequeue(Item))
			count++;
		return count;
	}

	int count(PrioQueue<Rover>& Q)
	{
		Rover Item;
		int count = 0;

		while (Q.dequeue(Item))
			count++;
		return count;
	}

	int count(ArrQueue<Mission>& Q)
	{
		Mission Item;
		int count = 0;

		while (Q.dequeue(Item))
			count++;
		return count;
	}

	int count(PrioQueue<Mission>& Q)
	{
		Mission Item;
		int count = 0;

		while (Q.dequeue(Item))
			count++;
		return count;
	}
	
	//---------------------------------------------------------------------------------------------------------------//



	void ProgramMode()   // ASKS USER FOR DESIRED SIM MODE
	{
		cout << "Please choose simulation mode: " << endl;
		cout << "1. Interactive " << endl;
		cout << "2. Step-by-step " << endl;
		cout << "3. Silent " << endl;
		cin >> Mode;
	}


	void OutputParameters()
	{
		NumberOfWaiting = count(PolarWaiting_Mission) + count(EmergWaiting_Mission);

		NumberOfInExecution = count(InExecutionEmerg) + count(InExecutionPolar);
	}



	void Interactive()   // RUNS INTERACTIVE
	{
		cout << "Current Day: " << day << endl;
		cout << NumberOfWaiting << " Waiting Missions: " << "[";  printID(EmergWaiting_Mission); cout << "] " << "("; printID(PolarWaiting_Mission); cout << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << NumberOfInExecution << "In-Execution Missions/Rovers: " << "[" << "/*Waiting emergency??*/" << "] " << "(" << "/*Waiting polar??*/" << ") " << "{" << "/*Waiting mountainous??*/" << "} " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << AvailableRovers << "Available Rovers: " << "[" << AvailableEmergency.print() << "] " << "(" << AvailablePolar.print() << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << InCheckup << "In-Checkup Rovers: " << "[" << InCheckupEmergency.print() << "] " << "(" << InCheckupPolar.print() << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		//cout << Completed << "In-Execution Missions/Rovers: " << "[" << "/*Waiting emergency??*/" << "] " << "(" << "/*Waiting polar??*/" << ") " << "{" << "/*Waiting mountainous??*/" << "} " << endl;
	}

};