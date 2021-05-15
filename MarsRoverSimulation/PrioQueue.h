#pragma once
#include "Node.h"
template<class T>
//Using array heap implementation to save the overhead of a node class
//This is a MaxHeap, with the largest element at the top
class PrioQueue {
private:
	Node<T>* root;
	Node<T>* lastLeaf;
	int capacity;//Still Haven't decided on the best capacity
	int size = 0;
	T* Items = new T[capacity]; //Dynamically allocated array of elements

	int getParentIndex() {

	}
	//NOTE:Is this considered manipulation of pointers?
	//Swaps elements, given two index values
	void swap(int Index1, int Index2) {
		T Temp = Items[Index2];
		Items[Index2] = Items[Index1];
		Items[Index1] = Temp;
	}

	//NOTE: Might need to overload reheap functions with ones that can reheap starting from a certain element in the middle of the array?
	void reHeapUp() {
		int index = size - 1; //starts at the last element
		while ()//checks if this index has a parent && the parent > the item
		{
			swap(index, getParentIndex())
		}

	}

	//Walking from up to down the heap and fixing
	void reHeapDown() {

	}

public:
	PrioQueue<T>(int Capacity = 100)
		//Constructor with certain capacity
	{
		capacity = Capacity; //assume user enters a capacity above 0
	}
	//To view the element at the top without editing it
	T peek() {
		if (size == 0) { return NULL; }
		return Items[0]; // Returns first element
	}

	// Adds new item
	void add(T item) {
		//check if capacity is full
		Items[size] = item; //insert at last 
		size++;
		reHeapUp(); //Reorders the item into the heap
	}
	//Searches and removes item?? is that legal
	void remove(T item) {

	}
	//Removes last item
	T dequeue() {

	}
};