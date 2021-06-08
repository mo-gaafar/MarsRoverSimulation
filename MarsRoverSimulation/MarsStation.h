#pragma once
#include"ArrayList.h"
#include"ArrQueue.h"
#include"LinkedList.h"
#include"LinkedStack.h"
#include"Rover.h"
#include"Mission.h"
#include"Event.h"
#include "UI.h"
#include <string>
#include "string.h"
#include <string.h>


using namespace std;

class MarsStation {
private:
	int day;
	int EventSize;
	int EmergRovNum;
	int PolarRovNum;
	ArrQueue<Event> temp;


	//Main Data Structures
	int NMissionsToCheckup;

	//Main Data Structures
	
	//Formulation Events
	ArrQueue<Event> EventList;
	//_________________________//
	//---------Rovers----------//
	
	//Available Rovers
	ArrQueue<Rover> Pol_Rover;
	ArrQueue<Rover> Emerg_Rover;

	//Busy Rovers
	ArrQueue<Rover> Busy_Rovers;
	
	//InCheckup
	ArrQueue<Rover> InCheckup_Emerg;
	ArrQueue<Rover> InCheckup_Pol;


	//InMaintenance
	ArrQueue<Rover> InMaintenance;

	//____________________________//
	//----------Missions----------//
	
	//Waiting Missions
	ArrQueue<Mission> PolarWaiting_Mission;
	ArrQueue<Mission> EmergWaiting_Mission;
	//Completed Missions

	ArrQueue<Mission> CompletedMissions;

	//In Execution Missions
	ArrQueue<Mission> InExecution;

	UI ui;
	


public:

	//MarsStation() {
	//	day = 0;
	//	
	//	//---------------------Initialization Stage---------------------//
	//	UI UserInterface; // interface object which reads from input file on construction

	//	this->EmergRovNum = UserInterface.getEmRoverCount();
	//	this->PolarRovNum = UserInterface.getPolarRoverCount();
	//	this->NMissionsToCheckup = UserInterface.getCheckCount();
	//	this->EventSize = UserInterface.getNumberOFEvents();

	//	//initializing F_Arr (useless event type array)
	//	char* F_Arr = new char[EventSize];
	//	for (int i = 0; i < EventSize; i++)
	//	{
	//		F_Arr[i] = 'F';//formulation event type
	//	}

	//	Initialize(F_Arr, UserInterface.getMissionType(), UserInterface.getEventDay(), UserInterface.getID(), UserInterface.getLocation(), 
	//		UserInterface.getDuration(), UserInterface.getSignifiance(), UserInterface.getPolarCheck(), UserInterface.getPolarSpeed(),
	//		UserInterface.getEmCheck(), UserInterface.getEmSpeed(), UserInterface.getCheckCount());

	//	//---------------------Run Simulation---------------------//
	//	UserInterface.ProgramMode();


	//}

	MarsStation(char* F_Arr, char* TYP_Arr, int* ED_Arr, int* ID_Arr, int* TLOC_Arr, int* MDUR_Arr, int* SIG_Arr, int EventSizein,
		int CheckupDurPol, int SpeedPol, int CheckupDurEmerg, int SpeedEmerg, int NMissionsToCheckup, int EmergRovNum, int PolarRovNum) {
		day = 0;
		EventSize = EventSizein;
		this->EmergRovNum = EmergRovNum;
		this-> PolarRovNum = PolarRovNum;
		this->NMissionsToCheckup = NMissionsToCheckup;

		//ArrQueue<Event> EventList(EventSize);
		Initialize(F_Arr, TYP_Arr, ED_Arr, ID_Arr, TLOC_Arr, MDUR_Arr, SIG_Arr, CheckupDurPol, SpeedPol,
			CheckupDurEmerg, SpeedEmerg,  NMissionsToCheckup);
		Rover R;
		ArrQueue<Rover> Temp;
		int idp = 0;
		int ide = 0;
		while (Pol_Rover.dequeue(R))
		{
			R.setID(idp + 1);
			idp++;
			Temp.enqueue(R);
		}
		while (Temp.dequeue(R))
			Pol_Rover.enqueue(R);
	}
	
	//Getting EventList and Rover Queues Ready
	void Initialize(char* F_Arr, char* TYP_Arr, int* ED_Arr, int* ID_Arr, int* TLOC_Arr, 
		int* MDUR_Arr,int* SIG_Arr, 
		int CheckupDurPol, int SpeedPol, 
		int CheckupDurEmerg, int SpeedEmerg, 
		int NMissionsToCheckup)
	{
		//Initializing Events List
		for (int i = 0; i < EventSize; i++) {
			Event E(F_Arr[i], TYP_Arr[i], ED_Arr[i], ID_Arr[i], TLOC_Arr[i], MDUR_Arr[i], SIG_Arr[i]);
			EventList.enqueue(E);
		}
		//Initializing Emerg Rover Queue
		for (int i = 0; i < EmergRovNum; i++) {
			Rover R(i+1, 'E', CheckupDurEmerg, SpeedEmerg, NMissionsToCheckup);
			//Emerg_Rover.dequeue(R);
			Emerg_Rover.enqueue(R);
		}
		//Initializing Polar Rover Queue
		for (int i = 0; i < PolarRovNum; i++) {
			Rover R(i+1, 'P', CheckupDurPol, SpeedPol, NMissionsToCheckup);
			Pol_Rover.enqueue(R);
		}
	}
	//Setters and getters
	
	
	//

	void SimulateDay() {
		Formulate();
		Execute();
		Complete();
		CheckUp();
		Maintenance();
		Rover R;
		ArrQueue<Rover> Temp;
		while (Emerg_Rover.dequeue(R))
		{
			cout << R.getSpeed() << endl;
			Temp.enqueue(R);
		}
		while (Temp.dequeue(R))
			Emerg_Rover.enqueue(R);
		day++;
	}

	void Formulate();
	void Execute();
	void Complete();
	bool CheckUpCheck(Rover &r);
	void CheckUp();
	bool MaintenanceCheck(Rover &r);
	void Maintenance();



	//   GETTERS FOR UI   //
	int GetDay();
	void GetPolarWaiting_Mission(ArrQueue<Mission>& m);
	ArrQueue<Mission> GetEmergWaiting_Mission();
	void GetBusy_Rovers(ArrQueue<Rover>& Emerg, ArrQueue<Rover>& Polar);
	ArrQueue<Mission> GetEmergInExecution();
	ArrQueue<Mission> GetPolarInExecution();
	ArrQueue<Rover> GetAvailablePol_Rover();
	ArrQueue<Rover> GetAvailableEmerg_Rover();
	void GetInCheckup_Emerg(ArrQueue<Rover> &r);
	void GetInCheckup_Pol(ArrQueue<Rover> &r);
	void GetCompletedMissions(ArrQueue<Mission>& Emerg, ArrQueue<Mission>& Polar);
	int GetPolarRovNum();
	int GetEmergRovNum();



	/*void OutputParameters()
	{
		NumberOfWaiting = PolarWaiting_Mission.getCount() + EmergWaiting_Mission.getCount();
		NumberOfInExecution = GetIn.getCount() + InExecutionPolar.getCount();
		NumberOfAvailable = AvailableEmerg_Rover.getCount() + AvailablePol_Rover.getCount();
		NumberOfInCheckup = InCheckup_Emerg.getCount() + InCheckup_Pol.getCount();
		NumberOfCompleted = CompletedEmerg.getCount() + CompletedPolar.getCount();

	}*/
	string CreateStringEmergW(ArrQueue<Mission>& M)
	{
		string EmerA = "";
		Mission R;
		ArrQueue<Mission> temp;
		EmergWaiting_Mission.dequeue(R);
		if (R.getID() != 0)
		{
			temp.enqueue(R);

			EmerA += to_string(R.getID());
			while (EmergWaiting_Mission.dequeue(R)) {

				temp.enqueue(R);
				EmerA += ", ";
				EmerA += to_string(R.getID());
			}
			while (temp.dequeue(R))
				EmergWaiting_Mission.enqueue(R);
		}
		return EmerA;
	}
	string CreateStringPolW(ArrQueue<Mission>& M)
	{
		string EmerA = "";
		Mission R;
		ArrQueue<Mission> temp;
		PolarWaiting_Mission.dequeue(R);
		if (R.getID() != 0)
		{
			temp.enqueue(R);

			EmerA += to_string(R.getID());
			while (PolarWaiting_Mission.dequeue(R)) {

				temp.enqueue(R);
				EmerA += ", ";
				EmerA += to_string(R.getID());
			}
			while (temp.dequeue(R))
				PolarWaiting_Mission.enqueue(R);
		}
		return EmerA;

	}
	void Run()
	{
		//ui.ProgramMode();
		for (int i = 0; i < 20; i++)
		{
			
			SimulateDay();
			string EmerA = CreateStringEmergW(EmergWaiting_Mission);
			string PolA = CreateStringPolW(PolarWaiting_Mission);
			//PrioQueue <Mission> EI = GetEmergInExecution();
			ui.Interactive(day, PolarWaiting_Mission.getCount() + EmergWaiting_Mission.getCount(), EmerA, PolA, InExecution.getCount(), InExecution, InExecution, Pol_Rover.getCount() + Emerg_Rover.getCount(), Emerg_Rover, Pol_Rover, InCheckup_Emerg.getCount() + InCheckup_Pol.getCount(), InCheckup_Emerg, InCheckup_Pol, CompletedMissions.getCount(), CompletedMissions, CompletedMissions);
		}
	}


};


void MarsStation::Formulate() {
	bool check = true;
	while (check) {
		// if the mission is to be formulated today, 
		int Debug = EventList.peek().getED();
		if (EventList.peek().getED() == day && !EventList.isempty() ) {
			if (EventList.peek().getTYP() == 'P') {
				Mission M(EventList.peek().getED(), 'P', EventList.peek().getID(), EventList.peek().getTLOC(), EventList.peek().getMDUR(), EventList.peek().getSIG());
				PolarWaiting_Mission.enqueue(M);
				EventList.dequeue(); //dequeue from eventlist after formulation
			}
			else if(EventList.peek().getTYP() ==  'E'){
				Mission M(EventList.peek().getED(), 'E', EventList.peek().getID(), EventList.peek().getTLOC(), EventList.peek().getMDUR(), EventList.peek().getSIG());
				int Priority = M.getSIG();
				M.setKey(Priority);
				EmergWaiting_Mission.enqueue(M);
				EventList.dequeue(); //dequeue from eventlist after formulation
			}
		}
		else {
			check = false;
		}
	}

}

void MarsStation::Execute() {
	bool check = true;
	int key;
	while (check) {
		//Checking if theres any available rover & if theres a mission waiting for it
		if (Pol_Rover.peek().getID() > 0 && !PolarWaiting_Mission.isempty()) {
			int Priority;
			Mission M;
			M = PolarWaiting_Mission.dequeue();
			Rover R;
			Pol_Rover.dequeue(R);
			Priority = day + 2 * (M.getTLOC() / R.getSpeed()) + M.getMDUR();
			M.setKey(Priority);
			InExecution.enqueue(M);
			Priority = day + 2 * (M.getTLOC() / R.getSpeed()) + M.getMDUR();
			R.setKey(Priority);
			Busy_Rovers.enqueue(R);
		}
		else
			check = false;
	}
	check = true;
	while (check) {
		//Checking if theres any available rover & if theres a mission waiting for it
		if (Emerg_Rover.peek().getID() > 0 && !EmergWaiting_Mission.isempty()) {
			int Priority;
			Mission M;
			EmergWaiting_Mission.dequeue(M);
			Rover R;
			Emerg_Rover.dequeue(R);
			Priority = day + 2 * (M.getTLOC() / R.getSpeed()) + M.getMDUR();
			M.setKey(Priority);
			InExecution.enqueue(M);
			Priority = day + 2 * (M.getTLOC() / R.getSpeed()) + M.getMDUR();
			R.setKey(Priority);
			Busy_Rovers.enqueue(R);
		}
		else {
			check = false;
		}
	}
}

void MarsStation::Complete() {
	bool check = true;
	int key;
	while (check) {
		key = InExecution.peek().getKey();
		if (key == day) {
			int Priority; //Define Priority variable
			Mission M;
			InExecution.dequeue(M);
			CompletedMissions.enqueue(M);
			Rover R;
			Busy_Rovers.dequeue(R);
			bool check2 = CheckUpCheck(R);
			if (check2) {
				R.incrementMissions();
				char type = R.getTYP();
				if (type == 'P')
				{
					Pol_Rover.enqueue(R);
				}
				else {
					if (type == 'E')
					{
						Emerg_Rover.enqueue(R);
					}
				}
			}
		}
		else
			check = false; //bug fix needs review
	}
}

bool MarsStation::CheckUpCheck(Rover &r) {
	if (r.getMissionNO() == NMissionsToCheckup) {
		int CheckDays;
		char type = r.getTYP();
		if (type == 'P') {
			CheckDays = day + r.getCDUR();
			r.setKey(CheckDays);
			InCheckup_Pol.enqueue(r);
		}
		else if (type == 'E') {
			CheckDays = day + r.getCDUR();
			r.setKey(CheckDays);
			InCheckup_Emerg.enqueue(r);
		}
		return false;
	}
	return true;
}

void MarsStation::CheckUp() {
	Rover R1;
	while (InCheckup_Pol.checkKey(day, R1)) {
		InCheckup_Pol.dequeue(R1);
		bool check2 = MaintenanceCheck(R1);
		if (check2) {
			R1.setInCheckDays(-1);
			Emerg_Rover.enqueue(R1);
		}
	}
	Rover R2;
	while (InCheckup_Emerg.checkKey(day, R2)) {
		InCheckup_Emerg.dequeue(R2);
		bool check2 = MaintenanceCheck(R2);
		if (check2) {
			R2.setInCheckDays(-1);
			Emerg_Rover.enqueue(R2);
		}
	}
}

bool MarsStation::MaintenanceCheck(Rover &r) {
	int prob = rand() % 9;
	if (prob <= 4) {
		int RandominMaintenanceDay = day + (1 + rand() % 20);
		r.setinMaintenanceDay(RandominMaintenanceDay);
		InMaintenance.enqueue(r);
		return false;
	} 
	return true;
}

void MarsStation::Maintenance() {
	Rover R;
	while (InMaintenance.checkKey(day, R)) {
		InMaintenance.dequeue(R);
		R.setInCheckDays(-1);
		R.setinMaintenanceDay(-1);
		char type = R.getTYP();
		if (type == 'P') {
			Pol_Rover.enqueue(R);
		}
		else if (type == 'E') {
				Emerg_Rover.enqueue(R);
		}
	}
}



//    GETTERS    //

int MarsStation::GetDay()
{
	return day;
}


void MarsStation::GetPolarWaiting_Mission(ArrQueue<Mission> &m)
{
	m = PolarWaiting_Mission;
}


ArrQueue<Mission> MarsStation::GetEmergWaiting_Mission()
{
	return EmergWaiting_Mission;
}

void MarsStation::GetBusy_Rovers(ArrQueue<Rover>& E, ArrQueue<Rover>& P)
{
	Rover Item;
	int Key;
	while (Busy_Rovers.dequeue(Item))
	{
		if (Item.getTYP() == 'E')
			E.enqueue(Item);
		else if (Item.getTYP() == 'P')
			P.enqueue(Item);
	}
}

ArrQueue<Mission> MarsStation::GetEmergInExecution()  // GETS INEXECUTION MISSIONS BUT SEPARATES THEM ACCORDING TO TYPE
{
	ArrQueue<Mission> Q;
	ArrQueue<Mission> Temp;
	Mission Item;
	while (InExecution.dequeue(Item))
	{
		if (Item.getTYP() == 'E')
			Q.enqueue(Item);
		Temp.enqueue(Item);
	}
	while (Temp.dequeue(Item))
		InExecution.enqueue(Item);
	return Q;
}
ArrQueue<Mission> MarsStation::GetPolarInExecution()  // GETS INEXECUTION MISSIONS BUT SEPARATES THEM ACCORDING TO TYPE
{
	ArrQueue<Mission> Q;
	ArrQueue<Mission> Temp;
	Mission Item;
	int Key;
	while (InExecution.dequeue(Item))
	{
		if (Item.getTYP() == 'P')
			Q.enqueue(Item);
		Temp.enqueue(Item);
	}
	while (Temp.dequeue(Item))
		InExecution.enqueue(Item);
	return Q;
}

ArrQueue<Rover> MarsStation::GetAvailablePol_Rover()
{
	return Pol_Rover;
}
ArrQueue<Rover> MarsStation::GetAvailableEmerg_Rover()
{
	return Emerg_Rover;
}

void MarsStation::GetInCheckup_Emerg(ArrQueue<Rover> &r)
{
	r = InCheckup_Emerg;
}

void MarsStation::GetInCheckup_Pol(ArrQueue<Rover> &r)
{
	r = InCheckup_Pol;
}

void MarsStation::GetCompletedMissions(ArrQueue<Mission>& E, ArrQueue<Mission>& P)
{
	Mission Item;
	int Key;
	while (InExecution.dequeue(Item))
	{
		if (Item.getTYP() == 'E')
			E.enqueue(Item);
		else if (Item.getTYP() == 'P')
			P.enqueue(Item);
	}
}

int MarsStation::GetPolarRovNum()
{
	return PolarRovNum;
}

int MarsStation::GetEmergRovNum()
{
	return EmergRovNum;
}