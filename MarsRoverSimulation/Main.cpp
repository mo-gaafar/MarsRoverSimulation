#include<iostream>
//#include"MarsStation.h"
#include "PrioQueue.h"
int main() {
	PrioQueue<int> Test;
	
	Test.enqueue(1);
	Test.enqueue(10);
	Test.enqueue(1);
	Test.enqueue(1);


	Test.printQueue();

}