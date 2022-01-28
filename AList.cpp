#include <iostream>
using namespace std;

class AList {
private:
	int* items;
	int size;
	int max_size;
	// resize arrays by moving items to a new, larger array
	void resize(int capacity) {
		int* new_arr = new int[capacity];
		for (int i = 0; i < size; i++) {
			new_arr[i] = items[i];
		}
		items = new_arr;
		max_size *= 2;
	}

public:
	AList() {
		size = 0;
		max_size = 100;
		items = new int[max_size];
		//items[55] = 100;
		//cout << items[55] << endl;
	}

	void addLast(int x) {
		if (size == max_size) {
			resize(max_size * 2);
		}
		items[size] = x;
		size++;
	}

	int getLast() {
		return items[size - 1];
	}

	int removeLast() {
		int ret = items[size - 1];
		// no need to actually delete, just allow the last item to be replaced
		size -= 1;
		return ret;
	}

	int get(int index) {
		
		return items[index];
	}

	void print() {
		cout << size << endl;
		for (int i = 0; i < size; i++) {
			cout << items[i] << ' ' << endl;
		}
	}

};

