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
public:
	MarsStation() {
		day = 0;
		ArrQueue<Event> EventList(EventSize);
		Initialize(Arr1, Arr2, Arr3, Arr4, Arr5, Arr6, Arr7, EventSize);
	}

	void Initialize(char* Arr1, char* Arr2, int* Arr3, int* Arr4, int* Arr5, int* Arr6, int* Arr7, int size, ArrQueue<Event> &EventList) {
		for (int i = 0; i < size; i++) {
			Event E(Arr1[i], Arr2[i], Arr3[i], Arr4[i], Arr5[i], Arr6[i], Arr7[i]);
			EventList.enqueue(E);
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