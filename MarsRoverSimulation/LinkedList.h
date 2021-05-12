#include "Node.h"

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;

public:

	LinkedList()
	{
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll();
	}


	void InsertEnd(const T& data)
	{
		if (!Head)
		{
			Node<T>* N = new Node<T>(data);
			Head = N;
			return;
		}

		Node<T>* P = Head;

		while (P)
		{
			if (!P->getNext())
			{
				Node<T>* N = new Node<T>(data);
				P->setNext(N);
			}
			P = P->getNext();
		}
	}



	void InsertBeg(const T& data)
	{
		if (!Head)
		{
			Node<T>* N = new Node<T>(data);
			Head = N;
			return;
		}

		Node<T>* P = Head;
		Node<T>* N = new Node<T>(data);
		N->setNext(P);
		Head = N;
	}


	void DeleteItem(const T& value)
	{
		if (!Head)
			return;

		Node<T>* P = Head;
		Node<T>* current = P->getNext();

		if (P->getItem == value)
		{
			Head = current;
			delete P;
			return;
		}

		while (current)
		{
			if (current->getItem() == value)
			{
				P->setNext(current->getNext());
				delete current;
				//current = P->getNext(); if we need to del recurring items
				return;
			}

			current = current->getNext();
			P = P->getNext();
		}

	}



	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}
};