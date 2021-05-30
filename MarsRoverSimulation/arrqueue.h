#pragma once

#include <iostream>
using namespace std;

template<typename T>
class queue {
private:
	T* items;
	int front;
	int rear;
	int arrsize;
public:

	queue(int MaxSize) : arrsize(MaxSize)
	{
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
	bool dequeue(T& item) {
		if (isempty())return false;
		else if (front == rear) {
			item = items[front];
			front = rear = -1;
			return true;

		}
		else {
			item = items[front];
			front++;
			return true;


		}
	}

	void frontvalue(T& value) {
		if (isempty())value = -1;
		else
		{
			value = items[front];
		}
	}
};

