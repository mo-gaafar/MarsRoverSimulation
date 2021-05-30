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
public:
	MarsStation() {
		day = 0;
	}

	void Initialize(char* Arr1, char* Arr2, int* Arr3, int* Arr4, int* Arr5, int* Arr6, int* Arr7, int size) {
		ArrQueue<Event> EventList(size);
		for (int i = 0; i < size; i++) {
			Event E(Arr1[i], Arr2[i], Arr3[i], Arr4[i], Arr5[i], Arr6[i], Arr7[i]);
			EventList.enqueue(E);
		}
	}
};