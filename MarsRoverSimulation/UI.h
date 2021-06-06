
#pragma once
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

  //--------------Zeyad's Declarations- -------//
	int Mode;
	int day;
	ArrQueue<Mission> PolarWaiting_Mission;
	PrioQueue<Mission> EmergWaiting_Mission;
	PrioQueue<Mission> InExecutionEmerg;
	PrioQueue<Mission> InExecutionPolar;
	PrioQueue<Rover> Busy_RoversEmerg;
	PrioQueue<Rover> Busy_RoversPolar;
	PrioQueue<Rover> AvailablePol_Rover;
	PrioQueue<Rover> AvailableEmerg_Rover;
	ArrQueue<Rover> InCheckup_Emerg;
	ArrQueue<Rover> InCheckup_Pol;
	ArrQueue<Mission> CompletedEmerg;
	ArrQueue<Mission> CompletedPolar;

	int NumberOfWaiting;
	int NumberOfInExecution;
	int NumberOfAvailable;
	int NumberOfInCheckup;
	int NumberOfCompleted;
  
  //--------------------------Hassan's declarations-------------------------------//
  //MarsStation* marsstaion;
	int EmRoverCount, PolarRoverCount;
	int EmSpeed, PolarSpeed;
	int EmCheck, PolarCheck, CheckCount;
	int NumberOFEvents;
	char* EventType, * MissionType;
	int* EventDay, * ID, * location, * Duration, * Signifiance;


	void createRovers();

public:
	void Read(){
   ifstream input;
	input.open("Inputfile.txt");
	if (input.fail()) {
		cerr << "error opening file" << endl;
		exit(1);
	}
	//LINE 1
	input >> PolarRoverCount >> EmRoverCount;
	//LINE 2
	input >> PolarSpeed >> EmSpeed;
	//LINE 3
	input >> CheckCount >> PolarCheck >> EmCheck;
	//line 4
	input >> NumberOFEvents;
	EventType = new char[NumberOFEvents];//dynamic array
	MissionType = new char[NumberOFEvents];//dynamic array
	EventDay = new int[NumberOFEvents];//dynamic array
	ID = new int[NumberOFEvents];//dynamic array
	location = new int[NumberOFEvents];//dynamic array
	Duration = new int[NumberOFEvents];//dynamic array
	Signifiance = new int[NumberOFEvents];//dynamic array
	for (int i = 0; i < NumberOFEvents; i++) {//dynamic array
		input >> EventType[i];
		if (EventType[i] == 'F') {
			input >> MissionType[i];
			input >> EventDay[i];
			input >> ID[i];
			input >> location[i];
			input >> Duration[i];
			input >> Signifiance[i];
		}
		else {
			MissionType[i] = 'x';
			EventDay[i] = -1;
			ID[i] = -1;
			location[i] = -1;
			Duration[i] = -1;
			Signifiance[i] = -1;
		}


	}
	input.close();
  }
	int getEmRoverCount() {
		return EmRoverCount;
	}
	int getPolarRoverCount() {
		return PolarRoverCount;
	}
	int getEmSpeed() {
		return EmSpeed;
	}
	int getPolarSpeed() {
		return PolarSpeed;
	}
	int getEmCheck() {
		return EmCheck;
	}
	int getPolarCheck() {
		return PolarCheck;
	}
	int getCheckCount()
	{
		return CheckCount;
	}
	int getNumberOFEvents() {
		return NumberOFEvents;
	}
	int* getID() {
		return ID;
	}
	char* getMissionType() {
		return MissionType;
	}
	char* getEventType() {
		return EventType;
	}
	int* getEventDay() {
		return EventDay;
	}
	int* getlocation() {
		return location;
	}
	int* getDuration() {
		return Duration;
	}
	int* getSignifiance() {
		return Signifiance;
  
  
  
public:
	UI(MarsStation& InputStation) //Default constructor
	{
		day = InputStation.GetDay();
		PolarWaiting_Mission = InputStation.GetPolarWaiting_Mission();
		EmergWaiting_Mission = InputStation.GetEmergWaiting_Mission();
		InputStation.GetInExecution(InExecutionEmerg, InExecutionPolar);
		InputStation.GetBusy_Rovers(Busy_RoversEmerg, Busy_RoversPolar);
		AvailableEmerg_Rover = InputStation.GetAvailableEmerg_Rover();
		AvailablePol_Rover = InputStation.GetAvailablePol_Rover();
		InCheckup_Emerg = InputStation.GetInCheckup_Emerg();
		InCheckup_Pol = InputStation.GetInCheckup_Pol();
		InputStation.GetCompletedMissions(CompletedEmerg, CompletedPolar);

		NumberOfWaiting = 0;
		NumberOfInExecution = 0;
		NumberOfAvailable = 0;
		NumberOfInCheckup = 0;
		NumberOfCompleted = 0;
	}


	// OUTPUT

	//---------------- OUTPUT FILE ---------------------//    INCOMPLETE
	void OutputFile()
	{
		ofstream Output;
		Output.open("bottom.txt");
		Output << "CD   ID   FD   WD   ED" << endl;
		for (int i = 0; i < NumberOfCompleted; i++)
		{
			Output << << endl;
		}

		Output.close();
	}


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
		NumberOfAvailable = count(AvailableEmerg_Rover) + count(AvailablePol_Rover);
		NumberOfInCheckup = count(InCheckup_Emerg) + count(InCheckup_Pol);
		NumberOfCompleted = count(CompletedEmerg) + count(CompletedPolar);
	}



	void Interactive()   // RUNS INTERACTIVE
	{
		cout << "Current Day: " << day << endl;
		cout << NumberOfWaiting << " Waiting Missions: " << "[";  printID(EmergWaiting_Mission); cout << "] " << "("; printID(PolarWaiting_Mission); cout << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << NumberOfInExecution << "In-Execution Missions/Rovers: " << "["; printID(InExecutionEmerg); cout << "] " << "(";  printID(InExecutionPolar); cout << ") " << endl; // Incomplete
		cout << "-------------------------------------------------------" << endl;
		cout << NumberOfAvailable << "Available Rovers: " << "["; printID(AvailableEmerg_Rover); cout << "] " << "("; printID(AvailablePol_Rover); cout << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << NumberOfInCheckup << "In-Checkup Rovers: " << "["; printID(InCheckup_Emerg); cout << "] " << "("; printID(InCheckup_Pol); cout << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << NumberOfCompleted << "Completed Missions: " << "["; printID(CompletedEmerg); cout << "] " << "("; printID(CompletedPolar); cout << ") " << endl;
	}

	void Silent()
	{
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
	}
};