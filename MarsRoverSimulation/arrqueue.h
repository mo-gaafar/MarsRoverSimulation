#pragma once

#include <iostream>
using namespace std;

template<class T>
class ArrQueue {
private:
	T* items;
	int front;
	int rear;
	int arrsize;
public:
	//Copy Constructor
	ArrQueue( ArrQueue<T> & Copy) 
	{
		ArrQueue<T> Temp;
		T Item;
		while (dequeue(Item))
		{
			Copy.enqueue(Item);
			Temp.enqueue(Item);
		}
		while (dequeue(Item))
		{
			enqueue(Item);
		}
	}

	ArrQueue(int MaxSize) : arrsize(MaxSize)
	{
		items = new T[arrsize];
		front = -1;
		rear = -1;
	}
	ArrQueue() {
		arrsize= 100;
		items = new T[arrsize];
		front = -1;
		rear = -1;
	}

	ArrQueue<T>& operator = (ArrQueue<T>& q) {
		ArrQueue<T> temp;
		T st;
		while (dequeue(st))
			temp.enqueue(st);
		while (temp.dequeue(st)) {
			enqueue(st);
			q.enqueue(st);
		}
		return *this;
	}

	bool isempty() {
		if (rear == -1 && front == -1)
			return true;
		else
			return false;
	}
	bool isfull() {
		if (rear == arrsize - 1)return true;
		else return false;
	}
	bool enqueue(T& val) {
		if (isfull())return false;
		else if (isempty()) {
			front = rear = 0;
			items[rear] = val;
			return true;

		}
		else {
			rear++;
			items[rear] = val;
			return true;

		}
	}
	T const dequeue() {
		if (isempty()) 
		{
			//return false;
			T item;
			return item;
			
		}
		else {
			T item;
			if (front == rear) {
				item = items[front];
				front = rear = -1;
				return item;
			}
			else {
				item = items[front];
				front++;
				return item;
			}
		}

	}
	bool dequeue(T& Item) {
		if (isempty()) {
			return false;
		}
		else {
			T item;
			if (front == rear) {
				item = items[front];
				front = rear = -1;
				Item = item;
				return true;
			}
			else
			{
				item = items[front];
				front++;
				Item = item;
				return true;
			}
		}
	}

	

	T peek() {
		
		/*if (isempty())
			return ;
		else*/
		{
			return items[front];
		}
	}

};

