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
public:
	MarsStation() {
		day = 0;
		ArrQueue<Event> EventList(EventSize);
		PrioQueue<Rover> Emerg_Rovers(EmergRovNum);
		PrioQueue<Rover> Polar_Rovers(PolarRovNum);
		Initialize(Arr1, Arr2, Arr3, Arr4, Arr5, Arr6, Arr7, EventSize, EventList, cd1, s1, Emerg_Rovers, cd2, s2, Polar_Rovers);
	}

	void Initialize(char* Arr1, char* Arr2, int* Arr3, int* Arr4, int* Arr5, int* Arr6, int* Arr7, ArrQueue<Event> &EventList, int cd1, int s1, PrioQueue<Rover> &Emerg_Rovers, int cd2, int s2, PrioQueue<Rover>& Polar_Rovers) {
		for (int i = 0; i < EventSize; i++) {
			Event E(Arr1[i], Arr2[i], Arr3[i], Arr4[i], Arr5[i], Arr6[i], Arr7[i]);
			EventList.enqueue(E);
		}
		for (int i = 0; i < EmergRovNum; i++) {
			Rover R('E', cd1, s1);
			Emerg_Rovers.add(R);
		}
		for (int i = 0; i < PolarRovNum; i++) {
			Rover R('P', cd2, s2);
			Polar_Rovers.add(R);
		}
	}

	void SimulateDay() {
		Formulate();
		Execute();
		Complete();
		CheckUpCheck();
		MaintenanceCheck();
	}

	void Formulate();
	void Execute();
	void Complete();
	void CheckUpCheck();
	void MaintenanceCheck();

};


void MarsStation::Formulate() {

}

void MarsStation::Execute() {

}

void MarsStation::Complete() {

}

void MarsStation::CheckUpCheck() {

}

void MarsStation::MaintenanceCheck() {

}