template <class T>
class Node {
private:
	T item;
	Node<T>* next;
	int key;
public:
	// Node class initializations
	Node() {
		next = nullptr;
	}
	Node(T& iItem) {
		item = iItem;
		next = nullptr;
	}
	Node(T& iItem, Node<T>* nextN) {
		item = iItem;
		next = nextN;
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
};