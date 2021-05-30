#pragma once
#include"Node.h"
template<typename T>
class LinkedStack {
private:
	Node<T>* top = nullptr;
public:
	LinkedStack() {
	}

	bool push(T& value) {

		Node<T>* new_NODE = new Node<T>;
		new_NODE->setItem(value);
		if (top == nullptr) {
			new_NODE->setNext(nullptr);
			return false;
		}
		else
		{
			new_NODE->setNext(top);
			return true
		}
		top = new_NODE;
	}
	bool pop(T& topentry) {
		if (top == nullptr)
			return false;
		else
		{
			Node<T>* Temp = top;
			top = top->getNext();
			topentry = Temp;
			delete Temp;
			return true;
		}
	}
	bool peek(T& topentry) {
		if (top == nullptr)
			return false;
		else
		{

			topentry = top;
			return true;
		}
	}
};