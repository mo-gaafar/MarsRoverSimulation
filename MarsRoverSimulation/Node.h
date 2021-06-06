#pragma once
template <typename T>
class Node {
private:
	T item;
	Node<T>* next;
	int key;
public:
	// Node class initializations
	Node() {
		next = nullptr;
		key = 0;
	}
	Node(T& iItem) {
		item = iItem;
		next = nullptr;
		key = 0;
	}
	Node(T& iItem, int Key) {
		item = iItem;
		key = Key;
	}
	

	//Setters
	void setItem(T& nItem) {
		item = nItem;
		return;
	}
	void setNext(Node<T>* nextN) {
		next = nextN;
		return;
	}
	void setKey(int& nKey) {
		key = nKey;
	}

	//Getters
	T getItem() {
		return item;
	}
	Node<T>* getNext() {
		return next;
	}
	int getKey() {
		return key;
	}

	//Operator overloading
	bool operator>(Node<T>& Other)
	{
		return key > Other.key;
	}
	bool operator<(Node<T>& Other)
	{
		return key < Other.key;
	}
};