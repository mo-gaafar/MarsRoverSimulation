#include<iostream>
//#include"MarsStation.h"
#include "PrioQueue.h"
int main() {
	PrioQueue<int> Test;
	Test.enqueue(1231,1);
	Test.enqueue(1224, 100);
	Test.enqueue(4224, 10);
	Test.enqueue(1234, 2);
	Test.enqueue(4512, 1);


	Test.printQueue();

}