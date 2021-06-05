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
	T dequeue() {
		if (isempty()) 
		{
			//return false;
			
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

