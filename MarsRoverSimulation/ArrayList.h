template <class T>
class ArrayList {
private:
	int count;
	int maxCount;
	T* array;
public:
	//Initializations
	ArrayList(int inMax);

	//Adds an item to the end of the list
	bool addItem(T& iItem);

	//Gets the item in the input position
	T getItemPos(int pos) {
		return array[pos];
	}

	//Returns the position of a certain item
	int getPos(T& item);

	//Returns the number of elements in the list
	int getCount() {
		return count;
	}

	//Deletes the entry of a certain position
	bool delPos(int pos);
};

//Implentations

template <class T>
ArrayList<T> :: ArrayList(int inMax) {
	count = 0;
	maxCount = inMax;
	array = new T[maxCount];
}

template <class T>
bool ArrayList<T> :: addItem(T& iItem) {
	if (count == maxCount) return false;

	array[count++] = iItem;
	count++;
	return true;
}

template<class T>
int ArrayList<T> :: getPos(T& item) {
	for (int i = 0; i < count; i++) {
		if (array[i] == item)
			return i;
	}
	return -1;
}

template<class T>
bool ArrayList<T> :: delPos(int pos) {
	if (pos >= count) //If positon has nothing in it.
		return false;
	else if (pos == count - 1) { //If the positon entered is the last position
		array[pos] = NULL;
		return true
	}
	for (int i = pos; i < count; i++) { //Shifting all elements to the left
		array[i] = array[i + 1];
		return true;
	}
}