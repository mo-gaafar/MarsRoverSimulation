//#include"ArrayList.h"
//#include"ArrQueue.h"
//#include"LinkedList.h"
//#include"LinkedStack.h"
//#include"PrioQueue.h"
//#include"Rover.h"
//#include"Mission.h"
//#include"Event.h"
//#include<iostream>
//
//using namespace std;
//
//class MarsStation {
//private:
//	int day;
//	int EventSize;
//	int EmergRovNum;
//	int PolarRovNum;
//
//	//Main Data Structures
//	//_________________________//
//	//---------Rovers----------//
//	
//	//Available Rovers
//	PrioQueue<Rover> Pol_Rover;
//	PrioQueue<Rover> Emerg_Rover;
//
//	//Busy Rovers
//	PrioQueue<Rover> Busy_Rovers;
//	
//	//InCheckup
//	ArrQueue<Rover> InCheckup_Emerg;
//	ArrQueue<Rover> InCheckup_Pol;
//	//____________________________//
//	//----------Missions----------//
//	
//	//Waiting Missions
//	ArrQueue<Mission> PolarWaiting_Mission;
//	PrioQueue<Mission> EmergWaiting_Mission;
//	//Completed Missions
//	LinkedStack<Mission> CompletedMissions;
//	//In Execution Missions
//	PrioQueue<Mission> InExecution;
//	
//
//
//public:
//	MarsStation() {
//		day = 0;
//		ArrQueue<Event> EventList(EventSize);
//		PrioQueue<Rover> Emerg_Rovers(EmergRovNum);
//		PrioQueue<Rover> Polar_Rovers(PolarRovNum);
//		Initialize(F_Arr, TYP_Arr, ED_Arr, ID_Arr, TLOC_Arr, MDUR_Arr, SIG_Arr, EventSize, EventList, CheckupDurPol, SpeedPol,
//			Polar_Rovers, CheckupDurEmerg, SpeedEmerg, Emerg_Rovers, NMissionsToCheckup);
//
//	}
//	//Getting EventList and Rover Queues Ready
//	void Initialize(char* F_Arr, char* TYP_Arr, int* ED_Arr, int* ID_Arr, int* TLOC_Arr, int* MDUR_Arr,int* SIG_Arr,  int EventSize, ArrQueue<Event> &EventList,
//		int CheckupDurPol, int SpeedPol, PrioQueue<Rover> & Polar_Rovers, int CheckupDurEmerg, int SpeedEmerg, PrioQueue<Rover>& Emerg_Rovers, int NMissionsToCheckup)
//	{
//		//Initializing Events List
//		for (int i = 0; i < EventSize; i++) {
//			Event E(F_Arr[i], TYP_Arr[i], ED_Arr[i], ID_Arr[i], TLOC_Arr[i], MDUR_Arr[i], SIG_Arr[i]);
//			EventList.enqueue(E);
//		}
//		//Initializing Emerg Rover Queue
//		for (int i = 0; i < EmergRovNum; i++) {
//			Rover R('E', CheckupDurEmerg, SpeedEmerg, NMissionsToCheckup);
//			Emerg_Rovers.dequeue(R);
//		}
//		//Initializing Polar Rover Queue
//		for (int i = 0; i < PolarRovNum; i++) {
//			Rover R('P', CheckupDurPol, SpeedPol,NMissionsToCheckup);
//			Polar_Rovers.dequeue(R);
//		}
//	}
//
//	void SimulateDay(int& CurrDay,  ) {
//		Formulate();
//		Execute();
//		Complete();
//		CheckUpCheck();
//		MaintenanceCheck();
//	}
//
//	void Formulate();
//	void Execute();
//	void Complete();
//	void CheckUpCheck();
//	void MaintenanceCheck();
//
//};
//
//
//void MarsStation::Formulate() {
//
//}
//
//void MarsStation::Execute() {
//
//}
//
//void MarsStation::Complete() {
//
//}
//
//void MarsStation::CheckUpCheck() {
//
//}
//
//void MarsStation::MaintenanceCheck() {
//
//}