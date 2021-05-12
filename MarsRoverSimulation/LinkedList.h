#include "Node.h"

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;

public:


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
};