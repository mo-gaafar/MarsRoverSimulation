#include<iostream>
//#include"MarsStation.h"
#include "PrioQueue.h"
int main() {
	PrioQueue<int> Test(100);
	Test.enqueue(1);
	Test.enqueue(10);
	Test.enqueue(19);
	Test.enqueue(2);
	Test.enqueue(29);

	Test.print();

}