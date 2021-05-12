template <class T>
class ArrayList {
private:
	int count;
	int maxCount;
	T* array;
public:
	//Initializations
	ArrayList(int inMax) {
		count = 0;
		maxCount = inMax;
		array = new T[maxCount];
	}

	//Adds an item to the end of the list
	bool addItem(T& iItem) {
		if (count == maxCount) return false;

		array[count++] = iItem;
		return true;
	}

	//Gets the item in the input position
	T getItemPos(int pos) {
		return array[pos];
	}

	//Returns the position of a certain item
	int getPos(T& item) {
		for (int i = 0; i < count; i++) {
			if (array[i] == item)
				return i;
		}
		return -1;
	}

	//Returns the number of elements in the list
	int getCount() {
		return count;
	}
};