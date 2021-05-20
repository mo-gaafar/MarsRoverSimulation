#pragma once
//#include "Node.h"
template<class T>
//Using array heap implementation to save the overhead of a node class
//This is a MaxHeap, with the largest element at the top
class PrioQueue {
private:

	int capacity= 100;//Still Haven't decided on the best capacity
	int size = 0;
	T* Items = new T[capacity]; //Dynamically allocated array of elements

	int getParentIndex(int child) { return (index - 1) / 2 }
	bool hasParent(int index) { return getParentIndex(index) >= 0;} //checks if the parent index isnt negative
	int getLeftChildIndex(int parent){return 2(parent +1) }
	bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }//checks if the left child is within the array
	int getRightChildIndex(int parent){return 2(parent +2) }
	bool hasRightChild(int index) { return getRightChildIndex(index) < size; }//checks if right child within array


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
		while (hasParent(index) && Items[getParentIndex(index)] > Items[index])//checks if this index has a parent && the parent > the item
		{
			swap(index, getParentIndex(index));
			index = getParentIndex(index);
		}

	}

	//Walking from up to down the heap and fixing
	void reHeapDown() {
		int index = 0;
		while (hasLeftChild(index)) 
			//no need to check right because if theres no left theres no right
		{
			int smallChildIndex = getLeftChildIndex(index);
			if (hasRightChild(index) && Items[getRightChildIndex(index)] < Items[getLeftChildIndex(index)])
			{
				 smallChildIndex = getRightChildIndex(index); //if right child smaller
			}
			// now that we found the smallest child if the parent index is smaller do nothing
			//if the parent index is larger then swap
			if (Items[index] < Items[smallChildIndex]) {
				break;
			}
			else {
				swap(index, smallChildIndex);
			}
			index = smallChildIndex;// move down
		}
	}

public:
	PrioQueue<T>(int Capacity = 100)
		//Constructor with certain capacity
	{
		capacity = Capacity; //assume user enters a capacity above 0
	}
	//Returns root element and removes it from queue
	T poll() {
		T Item = Items[0];
		Items[0] = Items[size - 1];// exchanges last element with root
		size--; //shrink array
		reHeapDown();//fixes queue
		return Item;
	}
	//To view the element at the top without editing it
	T peek() {
		if (size == 0) { return NULL; }
		return Items[0]; // Returns first element
	}

	// Adds new item
	void add(T item) {
		//check if capacity is full?
		Items[size] = item; //insert at last 
		size++;
		reHeapUp(); //Reorders the item into the heap
	}
	//Searches and removes item?? is that legal
	//void remove(T item) {

	//}
	//Removes last item
	T dequeue() {
		T Item = Items[size];
		size--;
		return Item;
	}
	bool IsEmpty() {
		if (size != 0) {
			return true;
		}
		return false;
	}

};