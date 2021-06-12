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
#include<Windows.h>
#include<conio.h>

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
		int idr = 1;
		//Initializing Emerg Rover Queue
		for (int i = 0; i < EmergRovNum; i++) {
			Rover R(idr, 'E', CheckupDurEmerg, SpeedEmerg, NMissionsToCheckup);
			idr++;
			//Emerg_Rover.dequeue(R);
			Emerg_Rover.enqueue(R);
		}
		//Initializing Polar Rover Queue
		for (int i = 0; i < PolarRovNum; i++) {
			Rover R(idr, 'P', CheckupDurPol, SpeedPol, NMissionsToCheckup);
			idr++;
			Pol_Rover.enqueue(R);
		}
	}

	//Simulator function
	void SimulateDay() {
		Formulate();
		Execute();
		Complete();
		CheckUp();
		Maintenance();
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


	//String functions

	string CreateStringEmergW() {
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
		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;
	}
	string CreateStringPolW()
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
		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;

	}

	string CreateStringPolInE()
	{
		string EmerA = "";
		Mission M;
		Rover R;
		ArrQueue<Rover> tempR;
		ArrQueue<Mission> temp;
		InExecution.dequeue(M);
		Busy_Rovers.dequeue(R);
		if (M.getID() != 0)
		{
			temp.enqueue(M);
			tempR.enqueue(R);
			if (M.getTYP() == 'P')
			{
				//cout << "k" << M.getID() << endl;
				EmerA += to_string(M.getID());
				EmerA += "/";
				EmerA += to_string(R.getID());
			}
			while (InExecution.dequeue(M) && Busy_Rovers.dequeue(R)) {

				temp.enqueue(M);
				tempR.enqueue(R);
				if (M.getTYP() != 'E')
				{
					EmerA += ", ";
					EmerA += to_string(M.getID());
					EmerA += "/";
					EmerA += to_string(R.getID());
				}
			}
			while (temp.dequeue(M) && tempR.dequeue(R))
			{
				InExecution.enqueue(M);
				Busy_Rovers.enqueue(R);
			}
		}
		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;

	}

	string CreateStringEmergInE()
	{
		string EmerA = "";
		Mission M;
		Rover R;
		ArrQueue<Rover> tempR;
		ArrQueue<Mission> temp;
		InExecution.dequeue(M);
		Busy_Rovers.dequeue(R);
		if (M.getID() != 0)
		{
			temp.enqueue(M);
			tempR.enqueue(R);
			if (M.getTYP() == 'E')
			{
				//cout << "k" << M.getID() << endl;
				EmerA += to_string(M.getID());
				EmerA += "/";
				EmerA += to_string(R.getID());
			}
			while (InExecution.dequeue(M) && Busy_Rovers.dequeue(R)) {

				temp.enqueue(M);
				tempR.enqueue(R);
				if (M.getTYP() != 'P')
				{
					EmerA += ", ";
					EmerA += to_string(M.getID());
					EmerA += "/";
					EmerA += to_string(R.getID());
				}
			}
			while (temp.dequeue(M) && tempR.dequeue(R))
			{
				InExecution.enqueue(M);
				Busy_Rovers.enqueue(R);
			}
		}
		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;

	}

	string CreateStringce()
	{
		string EmerA = "";
		Mission M;
		ArrQueue<Mission> temp;

		while (CompletedMissions.dequeue(M))
		{
			if (M.getTYP() == 'E')
			{
				temp.enqueue(M);
				EmerA += ", ";
				EmerA += to_string(M.getID());
			}
			else
				temp.enqueue(M);

		}
		while (temp.dequeue(M))
			CompletedMissions.enqueue(M);

		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;
	}

	string CreateStringcp()
	{
		string EmerA = "";
		Mission M;
		ArrQueue<Mission> temp;

		while (CompletedMissions.dequeue(M))
		{
			if (M.getTYP() == 'P')
			{
				temp.enqueue(M);
				EmerA += ", ";
				EmerA += to_string(M.getID());
			}
			else
				temp.enqueue(M);

		}

		while (temp.dequeue(M))
			CompletedMissions.enqueue(M);

		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;
	}

	string CreateStringPA()
	{
		string EmerA = "";
		Rover R;
		ArrQueue<Rover> temp;

		while (Pol_Rover.dequeue(R))
		{
			temp.enqueue(R);
			EmerA += ", ";
			EmerA += to_string(R.getID());
		}

		while (temp.dequeue(R))
			Pol_Rover.enqueue(R);

		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}

		return EmerA;
	}

	string CreateStringEA()
	{
		string EmerA = "";
		Rover R;
		ArrQueue<Rover> temp;

		while (Emerg_Rover.dequeue(R))
		{
			temp.enqueue(R);
			EmerA += ", ";
			EmerA += to_string(R.getID());
		}
		while (temp.dequeue(R))
			Emerg_Rover.enqueue(R);

		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;
	}

	string CreateStringEIC()
	{
		string EmerA = "";
		Rover R;
		ArrQueue<Rover> temp;

		while (InCheckup_Emerg.dequeue(R))
		{
			temp.enqueue(R);
			EmerA += ", ";
			EmerA += to_string(R.getID());
		}
		while (temp.dequeue(R))
			InCheckup_Emerg.enqueue(R);

		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;
	}

	string CreateStringPIC()
	{
		string EmerA = "";
		Rover R;
		ArrQueue<Rover> temp;

		while (InCheckup_Pol.dequeue(R))
		{
			temp.enqueue(R);
			EmerA += ", ";
			EmerA += to_string(R.getID());
		}
		while (temp.dequeue(R))
			InCheckup_Pol.enqueue(R);

		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;
	}

	string CreateStringEIM()
	{
		string EmerA = "";
		Rover R;
		ArrQueue<Rover> temp;

		while (InMaintenance.dequeue(R))
		{
			if (R.getTYP() == 'E')
			{
				temp.enqueue(R);
				EmerA += ", ";
				EmerA += to_string(R.getID());
			}
			else
				temp.enqueue(R);

		}

		while (temp.dequeue(R))
			InMaintenance.enqueue(R);

		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;
	}

	string CreateStringPIM()
	{
		string EmerA = "";
		Rover R;
		ArrQueue<Rover> temp;

		while (InMaintenance.dequeue(R))
		{
			if (R.getTYP() == 'P')
			{
				temp.enqueue(R);
				EmerA += ", ";
				EmerA += to_string(R.getID());
			}
			else
				temp.enqueue(R);

		}

		while (temp.dequeue(R))
			InMaintenance.enqueue(R);

		if (EmerA[0] == ',') {
			EmerA.erase(EmerA.begin());
			EmerA.erase(EmerA.begin());
		}
		return EmerA;
	}
	bool CheckForExit() {
		bool check = true;
		if (CompletedMissions.getCount() == EventSize && InCheckup_Emerg.isempty() && InCheckup_Pol.isempty() && InMaintenance.isempty())
			check = false;
		return check;
	}
	void Run()
	{
		ui.ProgramMode();
		int Mode = ui.getProgMode();
		while(CheckForExit())
		{
			
			SimulateDay();
			if (Mode != 3) {
				string EmerW = CreateStringEmergW();
				string PolW = CreateStringPolW();
				string PolI = CreateStringPolInE();
				string EmerI = CreateStringEmergInE();
				string EmerC = CreateStringce();
				string PolC = CreateStringcp();
				string EmerA = CreateStringEA();
				string PolA = CreateStringPA();
				string EmerIC = CreateStringEIC();
				string PolIC = CreateStringPIC();
				string EmerIM = CreateStringEIM();
				string PolIM = CreateStringPIM();
				ui.Interactive(day, PolarWaiting_Mission.getCount() + EmergWaiting_Mission.getCount(), EmerW, PolW, InExecution.getCount(), EmerI, PolI, Pol_Rover.getCount() + Emerg_Rover.getCount(), EmerA, PolA, InCheckup_Emerg.getCount() + InCheckup_Pol.getCount(), EmerIC, PolIC, InMaintenance.getCount(), EmerIM, PolIM, CompletedMissions.getCount(), EmerC, PolC);
				if (Mode == 2)
					Sleep(1000);
				else {
					char inp = _getch();
					while (inp != 32)
						inp = _getch();
				}
			}
			else
				ui.Silent();
		}
	
	}
	Mission GetMax(ArrQueue<Mission>& Q)
	{
		Mission MaxMission;
		Mission M;
		ArrQueue<Mission> Temp;
		int max = -99999999999;
		while (Q.dequeue(M))
		{
			if (M.getKey() > max)
			{
				max = M.getKey();
				MaxMission = M;
			}
			Temp.enqueue(M);
		}
		while (Temp.dequeue(M))
			Q.enqueue(M);

		while (Q.dequeue(M))
		{
			if (M.getKey() != max)
				Temp.enqueue(M);
		}
		while (Temp.dequeue(M))
			Q.enqueue(M);
		return MaxMission;
	}

};


void MarsStation::Formulate() {
	bool check = true;
	while (check) {
		// if the mission is to be formulated today, 
		/*int Debug = EventList.peek().getED();*/
		if (EventList.peek().getED() == day && !EventList.isempty() ) {
			if (EventList.peek().getTYP() == 'P') {
				Mission M(EventList.peek().getED(), 'P', EventList.peek().getID(), EventList.peek().getTLOC(), EventList.peek().getMDUR(), EventList.peek().getSIG());
				PolarWaiting_Mission.enqueue(M);
				EventList.dequeue(); //dequeue from eventlist after formulation
			}
			else if(EventList.peek().getTYP() ==  'E'){
				Mission M(EventList.peek().getED(), 'E', EventList.peek().getID(), EventList.peek().getTLOC(), EventList.peek().getMDUR(), EventList.peek().getSIG());
				int Priority = (2*M.getTLOC()+ M.getMDUR()) + M.getSIG();
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
		if (Pol_Rover.peek().getID() == 0)
			Pol_Rover.dequeue();
		if (!Pol_Rover.isempty() && Pol_Rover.peek().getID() > 0 && !PolarWaiting_Mission.isempty()) {
			int Priority;
			Mission M;
			PolarWaiting_Mission.dequeue(M);
			Rover R;
			Pol_Rover.dequeue(R);
			Priority = day + (2 * (M.getTLOC() / R.getSpeed()) / 25) + M.getMDUR();
			M.setKey(Priority);
			InExecution.enqueue(M);
			//Priority = day + 2 * (M.getTLOC() / R.getSpeed()) + M.getMDUR();
			R.setKey(Priority);
			Busy_Rovers.enqueue(R);
		}
		else
			check = false;
	}
	check = true;
	while (check) {
		//Checking if theres any available rover & if theres a mission waiting for it
		if (!Emerg_Rover.isempty() && Emerg_Rover.peek().getID() > 0 && !EmergWaiting_Mission.isempty()) {
			Mission M;
			M = GetMax(EmergWaiting_Mission);
			int Priority;
			Rover R;
			Emerg_Rover.dequeue(R);
			Priority = day + (2 * (M.getTLOC() / R.getSpeed())/25) + M.getMDUR();
			//Priority = (M.getSIG() * (1 / M.getFD()) * (M.getMDUR() * M.getTLOC())) / 1000;
			M.setKey(Priority);
			InExecution.enqueue(M);
			//Priority = day + 2 * (M.getTLOC() / R.getSpeed()) + M.getMDUR();
			//Priority = (M.getSIG() * (1 / M.getFD()) * (M.getMDUR() * M.getTLOC()));
			R.setKey(Priority);
			Busy_Rovers.enqueue(R);
		}
		else {
			check = false;
		}
	}
}

Mission GetMax(ArrQueue<Mission>& Q)
{
	Mission MaxMission;
	Mission M;
	ArrQueue<Mission> Temp;
	int max = -99999999999;
	while (Q.dequeue(M))
	{
		if (M.getKey() > max)
		{
			max = M.getKey();
			MaxMission = M;
		}
		Temp.enqueue(M);
	}
	while (Temp.dequeue(M))
		Q.enqueue(M);

	while (Q.dequeue(M))
	{
		if (M.getKey() != max)
		Temp.enqueue(M);
	}
	while (Temp.dequeue(M))
		Q.enqueue(M);
	return MaxMission;
}

void MarsStation::Complete() {
	int key;
	Mission M;
	ArrQueue<Mission> temp;
	while (InExecution.dequeue(M)) {
		key = M.getKey();
		if (key == day) {
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
			temp.enqueue(M);
	}
	while (temp.dequeue(M))
		InExecution.enqueue(M);
}

bool MarsStation::CheckUpCheck(Rover &r) {
	if (r.getMissionNO() % NMissionsToCheckup == 0) {
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
			Pol_Rover.enqueue(R1);
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
		r.setKey(RandominMaintenanceDay);
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