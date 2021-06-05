#include"ArrayList.h"
#include"ArrQueue.h"
#include"LinkedList.h"
#include"LinkedStack.h"
#include"PrioQueue.h"
#include"Rover.h"
#include"Mission.h"
#include"Event.h"
#include<iostream>

using namespace std;

class MarsStation {
private:
	int day;
	int EventSize;
	int EmergRovNum;
	int PolarRovNum;
	int NMissionsToCheckup;

	//Main Data Structures
	//_________________________//
	//---------Rovers----------//
	
	//Available Rovers
	PrioQueue<Rover> Pol_Rover;
	PrioQueue<Rover> Emerg_Rover;

	//Busy Rovers
	PrioQueue<Rover> Busy_Rovers;
	
	//InCheckup
	ArrQueue<Rover> InCheckup_Emerg;
	ArrQueue<Rover> InCheckup_Pol;

	//InMaintenance
	PrioQueue<Rover> InMaintenance;
	//____________________________//
	//----------Missions----------//
	
	//Waiting Missions
	ArrQueue<Mission> PolarWaiting_Mission;
	PrioQueue<Mission> EmergWaiting_Mission;
	//Completed Missions
	ArrQueue<Mission> CompletedMissions;
	//In Execution Missions
	PrioQueue<Mission> InExecution;
	


public:
	MarsStation(char* F_Arr, char* TYP_Arr, int* ED_Arr, int* ID_Arr, int* TLOC_Arr, int* MDUR_Arr, int* SIG_Arr, int EventSizein,
		int CheckupDurPol, int SpeedPol, int CheckupDurEmerg, int SpeedEmerg, int NMissionsToCheckup) {
		day = 0;
		EventSize = EventSizein;

		/*char* F_Arr,char* TYP_Arr;
		int* ED_Arr, int* ID_Arr, int* TLOC_Arr, int* MDUR_Arr, int* SIG_Arr;

		int CheckupDurPol, SpeedPol, CheckupDurEmerg, SpeedEmerg;*/

		ArrQueue<Event> EventList(EventSize);
		Initialize(F_Arr, TYP_Arr, ED_Arr, ID_Arr, TLOC_Arr, MDUR_Arr, SIG_Arr, EventSize, EventList, CheckupDurPol, SpeedPol,
			Pol_Rover, CheckupDurEmerg, SpeedEmerg, Emerg_Rover, NMissionsToCheckup);

	}
	
	//Getting EventList and Rover Queues Ready
	void Initialize(char* F_Arr, char* TYP_Arr, int* ED_Arr, int* ID_Arr, int* TLOC_Arr, int* MDUR_Arr,int* SIG_Arr, ArrQueue<Event> &EventList,
		int CheckupDurPol, int SpeedPol, PrioQueue<Rover> & Polar_Rovers, int CheckupDurEmerg, int SpeedEmerg, PrioQueue<Rover>& Emerg_Rovers, int NMissionsToCheckup)
	{
		//Initializing Events List
		for (int i = 0; i < EventSize; i++) {
			Event E(F_Arr[i], TYP_Arr[i], ED_Arr[i], ID_Arr[i], TLOC_Arr[i], MDUR_Arr[i], SIG_Arr[i]);
			EventList.enqueue(E);
		}
		//Initializing Emerg Rover Queue
		for (int i = 0; i < EmergRovNum; i++) {
			Rover R('E', CheckupDurEmerg, SpeedEmerg, NMissionsToCheckup);
			Emerg_Rovers.enqueue(R, SpeedEmerg);
		}
		//Initializing Polar Rover Queue
		for (int i = 0; i < PolarRovNum; i++) {
			Rover R('P', CheckupDurPol, SpeedPol,NMissionsToCheckup);
			Polar_Rovers.enqueue(R, SpeedPol);
		}
	}
	//Setters and getters
	
	
	//

	void SimulateDay(ArrQueue<Event> &EventList) {
		Formulate(EventList);
		Execute();
		Complete();
		CheckUp();
		Maintenance();
		day++;
	}

	void Formulate(ArrQueue<Event> &EventList);
	void Execute();
	void Complete();
	bool CheckUpCheck(Rover &r);
	void CheckUp();
	bool MaintenanceCheck(Rover &r);
	void Maintenance();



	//   GETTERS FOR UI   //
	int GetDay();
	ArrQueue<Mission> GetPolarWaiting_Mission();
	PrioQueue<Mission> GetEmergWaiting_Mission();
	void GetBusy_Rovers(PrioQueue<Rover>& Emerg, PrioQueue<Rover>& Polar);
	void GetInExecution(PrioQueue<Mission>& Emerg, PrioQueue<Mission>& Polar);
	PrioQueue<Rover> GetAvailablePol_Rover();
	PrioQueue<Rover> GetAvailableEmerg_Rover();
	ArrQueue<Rover> GetInCheckup_Emerg();
	ArrQueue<Rover> GetInCheckup_Pol();
	void GetCompletedMissions(ArrQueue<Mission>& Emerg, ArrQueue<Mission>& Polar);

};


void MarsStation::Formulate(ArrQueue<Event> &EventList) {
	bool check = true;
	while (check) {
		if (EventList.peek().getED() == day) {
			if (EventList.peek().getET() == 'P') {
				Mission M(EventList.peek().getED(), 'P', EventList.peek().getTLOC(), EventList.peek().getMDUR(), EventList.peek().getSIG());
				PolarWaiting_Mission.enqueue(M);
			}
			else if(EventList.peek().getET() ==  'E'){
				Mission M(EventList.peek().getED(), 'E', EventList.peek().getTLOC(), EventList.peek().getMDUR(), EventList.peek().getSIG());
				EmergWaiting_Mission.enqueue(M, M.getSIG());
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
		if (!Pol_Rover.isEmpty()) {
			Mission M;
			M = PolarWaiting_Mission.dequeue();
			InExecution.enqueue(M, day + M.getMDUR());
			Rover R;
			R = Pol_Rover.dequeue(key);
			Busy_Rovers.enqueue(R, day + M.getMDUR());
		}
		else
			check = false;
	}
	check = true;
	while (check) {
		if (!Emerg_Rover.isEmpty()) {
			Mission M;
			M = EmergWaiting_Mission.dequeue(key);
			InExecution.enqueue(M, day + M.getMDUR());
			Rover R;
			R = Emerg_Rover.dequeue(key);
			Busy_Rovers.enqueue(R, day + M.getMDUR());
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
		InExecution.peek(key);
		if (key == day) {
			Mission M;
			M = InExecution.dequeue(key);
			CompletedMissions.enqueue(M);
			Rover R;
			R = Busy_Rovers.dequeue(key);
			bool check2 = CheckUpCheck(R);
			if (check2) {
				R.incrementMissions();
				char type = R.getTYP();
				if (type == 'P')
					Pol_Rover.enqueue(R, R.getSpeed());
				else if (type == 'E')
					Emerg_Rover.enqueue(R, R.getSpeed());
			}
		}
	}
}

bool MarsStation::CheckUpCheck(Rover &r) {
	if (r.getMissionNO() == NMissionsToCheckup) {
		char type = r.getTYP();
		if (type == 'P') {
			r.setInCheckDays(day + r.getCDUR());
			InCheckup_Pol.enqueue(r);
		}
		else if (type == 'E') {
			r.setInCheckDays(day + r.getCDUR());
			InCheckup_Emerg.enqueue(r);
		}
		return false;
	}
	return true;
}

void MarsStation::CheckUp() {
	bool check = true;
	while (check) {
		if (InCheckup_Pol.peek().getInCheckDays() == day) {
			Rover R;
			R = InCheckup_Pol.dequeue();
			MaintenanceCheck(R);
			R.setInCheckDays(-1);
			Pol_Rover.enqueue(R, R.getSpeed());
		}
		if (InCheckup_Emerg.peek().getInCheckDays() == day) {
			Rover R;
			R = InCheckup_Emerg.dequeue();
			bool check2 = MaintenanceCheck(R);
			if (check2) {
				R.setInCheckDays(-1);
				Emerg_Rover.enqueue(R, R.getSpeed());
			}
		}
	}
}

bool MarsStation::MaintenanceCheck(Rover &r) {
	int prob = rand() % 9;
	if (prob <= 4) {
		r.setinMaintenanceDay(day + (1 + rand() % 20));
		InMaintenance.enqueue(r, r.getinMaintenanceDay());
		return false;
	} 
	return true;
}

void MarsStation::Maintenance() {
	bool check = true;
	int key;
	while (check) {
		if (InMaintenance.peek(key).getinMaintenanceDay() == day) {
			Rover R;
			R = InMaintenance.dequeue(key);
			R.setInCheckDays(-1);
			R.setinMaintenanceDay(-1);
			char type = R.getTYP();
			if (type == 'P')
				Pol_Rover.enqueue(R, R.getSpeed());
			else if (type == 'E')
				Emerg_Rover.enqueue(R, R.getSpeed());
		}
	}
}






//    GETTERS    //

int MarsStation::GetDay()
{
	return day;
}


ArrQueue<Mission> MarsStation::GetPolarWaiting_Mission()
{
	return PolarWaiting_Mission;
}


PrioQueue<Mission> MarsStation::GetEmergWaiting_Mission()
{
	return EmergWaiting_Mission;
}

void MarsStation::GetBusy_Rovers(PrioQueue<Rover>& E, PrioQueue<Rover>& P)
{
	Rover Item;
	int Key;
	while (Busy_Rovers.dequeue(Item, Key))
	{
		if (Item.getTYP() == 'E')
			E.enqueue(Item, Key);
		else if (Item.getTYP() == 'P')
			P.enqueue(Item, Key);
	}
}

void MarsStation::GetInExecution(PrioQueue<Mission>& E, PrioQueue<Mission>& P)  // GETS INEXECUTION MISSIONS BUT SEPARATES THEM ACCORDING TO TYPE
{
	Mission Item;
	int Key;
	while (InExecution.dequeue(Item, Key))
	{
		if (Item.getTYP() == 'E')
			E.enqueue(Item, Key);
		else if (Item.getTYP() == 'P')
			P.enqueue(Item, Key);
	}
}

PrioQueue<Rover> MarsStation::GetAvailablePol_Rover()
{
	return Pol_Rover;
}
PrioQueue<Rover> MarsStation::GetAvailableEmerg_Rover()
{
	return Emerg_Rover;
}

ArrQueue<Rover> MarsStation::GetInCheckup_Emerg()
{
	return InCheckup_Emerg;
}

ArrQueue<Rover> MarsStation::GetInCheckup_Pol()
{
	return InCheckup_Pol;
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