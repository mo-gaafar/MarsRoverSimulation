#pragma once
#include <iostream>
#include <string>
#include "string.h"
#include <string.h>

//#include "../MarsRoverSimulation/MarsStation.h"
#include <fstream>
using namespace std;

class UI
{
private:

  //--------------Zeyad's Declarations- -------//
	int ProgMode;
	/*int day;
	ArrQueue<Mission> PolarWaiting_MissionUI;
	PrioQueue<Mission> EmergWaiting_MissionUI;
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

	int NumberOfEmergRovers;
	int NumberOfPolarRovers;*/
  
  //--------------------------Hassan's declarations-------------------------------//
  //MarsStation* marsstaion;
	int EmRoverCount, PolarRoverCount;
	int EmSpeed, PolarSpeed;
	int EmCheck, PolarCheck, CheckCount;
	int NumberOFEvents;
	char* EventType, * MissionType;
	int* EventDay, * ID, * location, * Duration, * Signifiance;


	//void createRovers();

public:
	void Read() {
		ifstream input;
		input.open("InputFile.txt");
		if (input.fail()) {
			cerr << "Could not open file!" << endl;
			exit(1);
		}
	//LINE 1
	input >> PolarRoverCount >> EmRoverCount;
	//LINE 2
	input >> PolarSpeed >> EmSpeed;
	//LINE 3
	input >> CheckCount >> PolarCheck >> EmCheck;
	//LINE 4
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
		/*else {
			MissionType[i] = 'x';
			EventDay[i] = -1;
			ID[i] = -1;
			location[i] = -1;
			Duration[i] = -1;
			Signifiance[i] = -1;
		}*/

		}
	input.close();
	}
	int getProgMode() {
		return ProgMode;
	}
	int  getEmRoverCount() const 
	{
		return EmRoverCount;
	}
	int getPolarRoverCount() const {
		return PolarRoverCount;
	}
	int getEmSpeed() const {
		return EmSpeed;
	}
	int getPolarSpeed() const {
		return PolarSpeed;
	}
	int getEmCheck() const {//------------------> is this checkup duration?????
		return EmCheck;
	}
	int getPolarCheck()const {
		return PolarCheck;
	}
	int getCheckCount()const
	{
		return CheckCount;
	}
	int getNumberOFEvents() const {
		return NumberOFEvents;
	}
	int* getID() const {
		return ID;
	}
	char* getMissionType() const {
		return MissionType;
	}
	char* getEventType() const {
		return EventType;
	}
	int* getEventDay()const {
		return EventDay;
	}
	int* getLocation() const {
		return location;
	}
	int* getDuration() const {
		return Duration;
	}
	int* getSignifiance()const {
		return Signifiance;
	}
	/*
	int EmRoverCount, PolarRoverCount;
	int EmSpeed, PolarSpeed;
	int EmCheck, PolarCheck, CheckCount;
	int NumberOFEvents;
	char* EventType, * MissionType;
	int* EventDay, * ID, * location, * Duration, * Signifiance;
	*/
	////Hands off input to the marsstation object
	//void getInitialInput(int & EmRoverCount,int &PolarRoverCount, int &EmSpeed, int& PolarSpeed,
	//	int &EmCheckup, int &PolarChekup, int &CheckupCount, int EventSize, ) const {


	//	}
  
  
	UI() //Default Constructor
	{
		Read();// fills the UI up for the first time
		//ProgramMode();
	}

	//void Refresh(MarsStation &InputStation) //refreshes data in UI to prepare for output
	//{
 //		day = InputStation.GetDay();
	//	InputStation.GetPolarWaiting_Mission(PolarWaiting_MissionUI);
	//	EmergWaiting_MissionUI = InputStation.GetEmergWaiting_Mission();
	//	InputStation.GetInExecution(InExecutionEmerg, InExecutionPolar);
	//	InputStation.GetBusy_Rovers(Busy_RoversEmerg, Busy_RoversPolar);
	//	AvailableEmerg_Rover = InputStation.GetAvailableEmerg_Rover();
	//	AvailablePol_Rover = InputStation.GetAvailablePol_Rover();
	//	InputStation.GetInCheckup_Emerg(InCheckup_Emerg);
	//	InputStation.GetInCheckup_Pol(InCheckup_Pol);
	//	InputStation.GetCompletedMissions(CompletedEmerg, CompletedPolar);

	//	NumberOfWaiting = 0;
	//	NumberOfInExecution = 0;
	//	NumberOfAvailable = 0;
	//	NumberOfInCheckup = 0;
	//	NumberOfCompleted = 0;
	//}


	// OUTPUT

	//---------------- OUTPUT FILE ---------------------//    INCOMPLETE
	/*void OutputFile()
	{
		ofstream Output;
		Mission Item;
		Output.open("bottom.txt");
		Output << "CD    ID    FD    WD    ED" << endl;
		for (int i = 0; i < NumberOfCompleted; i++)
		{
			CompletedEmerg.dequeue(Item);
			int FD = Item.getFD();
			int ID = Item.getID();
			int ED = Item.getMDUR();
			Output << ID << FD << ED << endl;
		}
		Output << "......................................................" << endl;
		Output << "Missions: " << NumberOfCompleted << " [P: " << count(CompletedPolar) << ", E: " << count(CompletedEmerg) << "]" << endl;
		Output << "Rovers: " << NumberOfEmergRovers + NumberOfPolarRovers << " [P: " << NumberOfPolarRovers << ", E: " << NumberOfEmergRovers << "]" << endl;
		Output.close();
	}*/


	//-----------------------------  PRINT FUNCTIONS  -----------------------------------------//


	
	
	//    ArrQueue ROVER PRINT   //
	void printID(ArrQueue<Rover>& Q)
	{
		ArrQueue <Rover> Temp;
		Rover Item;

		Q.dequeue(Item);
		cout << Item.getID();
		Temp.enqueue(Item);

		while (Q.dequeue(Item))
		{
			cout << "," << Item.getID();
			Temp.enqueue(Item);
		}
		while (Temp.dequeue(Item))
			Q.enqueue(Item);
	}


	

	//    ArrQueue MISSION PRINT    //
	void printID(ArrQueue<Mission>& Q)
	{
		ArrQueue <Mission> Temp;
		Mission Item;

		Q.dequeue(Item);
		cout << Item.getID();
		Temp.enqueue(Item);

		while (Q.dequeue(Item))
		{
			cout << "," << Item.getID();
			Temp.enqueue(Item);
		}
		while (Temp.dequeue(Item))
			Q.enqueue(Item);
	}


	// END OF PRINT FUNCTIONS //
	//-------------------------------------------------------------------------------------------------------------------------------------//



	//-----------------------------  COUNTER FUNCTIONS  -----------------------------------------//
	/*int count(ArrQueue<Rover>& Q)
	{
		Rover Item;
		int count = 0;
		ArrQueue<Rover> Temp;

		while (Q.dequeue(Item))
			count++;
		return count;
	}

	int count(PrioQueue<Rover>& Q)
	{
		Rover Item;
		int Key;
		PrioQueue<Rover> Temp;

		int count = 0;

		while (Q.dequeue(Item, Key))
		{
			Temp.enqueue(Item, Key);
			count++;
		}
		while (Temp.dequeue(Item, Key))
		{
			Q.enqueue(Item, Key);
		}
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
		int Key;
		int count = 0;
		PrioQueue<Mission> Temp;

		while (Q.dequeue(Item,Key))
		{
			Temp.enqueue(Item, Key);
			count++;
		}
		while (Temp.dequeue(Item, Key))
		{
			Q.enqueue(Item, Key);
		}
		return count;
	}*/
	
	//---------------------------------------------------------------------------------------------------------------//



	void ProgramMode()   // ASKS USER FOR DESIRED SIM MODE
	{
		cout << "Please choose simulation mode: " << endl;
		cout << "1. Interactive " << endl;
		cout << "2. Step-by-step " << endl;
		cout << "3. Silent " << endl;
		cin >> ProgMode;
	}


	/*void OutputParameters()
	{
		NumberOfWaiting = PolarWaiting_MissionUI.getCount() + EmergWaiting_MissionUI.getCount();
		NumberOfInExecution = InExecutionEmerg.getCount() + InExecutionPolar.getCount();
		NumberOfAvailable = AvailableEmerg_Rover.getCount() + AvailablePol_Rover.getCount();
		NumberOfInCheckup = InCheckup_Emerg.getCount() + InCheckup_Pol.getCount();
		NumberOfCompleted = CompletedEmerg.getCount() + CompletedPolar.getCount();

	}*/

	//void Interactive(int day, int waiting, PrioQueue<Mission> EmergW, ArrQueue<Mission> PolarW, int InExecution, PrioQueue<Mission> EmergI, PrioQueue<Mission> PolarI, int available, PrioQueue<Rover> EmergA, PrioQueue<Rover> PolarA, int InCheckup, ArrQueue<Rover> EmergIc, ArrQueue<Rover> PolarIc, int completed, ArrQueue<Mission> EmergC, ArrQueue<Mission> PolarC)   // RUNS INTERACTIVE
	//{
	//	OutputParameters();
	//	cout << endl;
	//	cout << "Current Day: " << day << endl;
	//	cout << NumberOfWaiting << " Waiting Missions: " << "[";  printID(EmergWaiting_MissionUI); cout << "] " << "("; printID(PolarWaiting_MissionUI); cout << ") " << endl;
	//	cout << "-------------------------------------------------------" << endl;
	//	cout << NumberOfInExecution << " In-Execution Missions/Rovers: " << "["; printID(InExecutionEmerg); cout << "] " << "(";  printID(InExecutionPolar); cout << ") " << endl; // Incomplete
	//	cout << "-------------------------------------------------------" << endl;
	//	cout << NumberOfAvailable << " Available Rovers: " << "["; printID(AvailableEmerg_Rover); cout << "] " << "("; printID(AvailablePol_Rover); cout << ") " << endl;
	//	cout << "-------------------------------------------------------" << endl;
	//	cout << NumberOfInCheckup << " In-Checkup Rovers: " << "["; printID(InCheckup_Emerg); cout << "] " << "("; printID(InCheckup_Pol); cout << ") " << endl;
	//	cout << "-------------------------------------------------------" << endl;
	//	cout << NumberOfCompleted << " Completed Missions: " << "["; printID(CompletedEmerg); cout << "] " << "("; printID(CompletedPolar); cout << ") " << endl;
	//}

	void Interactive(int Day, int waiting, string EmergW, string PolarW, int InExecution, string EmergI, string PolarI, int available, ArrQueue<Rover>& EmergA, ArrQueue<Rover>& PolarA, int InCheckup, ArrQueue<Rover>& EmergIc, ArrQueue<Rover>& PolarIc, int completed, string EmergC, string & PolarC)   // RUNS INTERACTIVE
	{
		//OutputParameters();
		cout << endl;
		cout << "Current Day: " << Day << endl;
		cout << waiting << " Waiting Missions: " << "[" <<  EmergW << "] " << "(" << PolarW << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << InExecution << " In-Execution Missions/Rovers: " << "[" << EmergI << "] " << "(" << PolarI << ") " << endl; // Incomplete
		cout << "-------------------------------------------------------" << endl;
		cout << available << " Available Rovers: " << "["; printID(EmergA); cout << "] " << "("; printID(PolarA); cout << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << InCheckup << " In-Checkup Rovers: " << "["; printID(EmergIc); cout << "] " << "("; printID(PolarIc); cout << ") " << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << completed << " Completed Missions: " << "[" << EmergC << "] " << "(" << PolarC << ") " << endl;
	}

	void Silent()
	{
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
	}


};