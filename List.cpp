#include <iostream>
using namespace std;

// a super class that AList and SList inherit
template <class T>
class List {
public:
	// has all the method signatures that the subclasses inherit but no implementation 
	virtual void addFirst(T x) = 0;
	virtual void addLast(T x) = 0;
	virtual T* removeFirst() = 0;
	virtual T* removeLast() = 0;
	virtual T* get(int index) = 0;
	virtual int getSize() = 0;

	// not a pure virtual function, implement here
	virtual void print() {
		cout << "calling List print()" << endl;
		for (int i = 0; i < getSize(); i++) {
			cout << *get(i) << ' '; // Get returns pointer, need to dereference
		}
		cout << endl;
	}
};


template <typename T>
class DLList : public List<T> {
private:
	// NESTED CLASS	
	template <typename U>
	class Node {
	public:
		U val;
		Node<U>* next;
		Node<U>* prev;
		Node(U x, Node<U>* p, Node<U>* n) {
			val = x;
			prev = p;
			next = n;
		}
	};
	Node<T>* sentinel;
	int size;

public:
	// constructor
	DLList(T x) {
		sentinel = new Node<T>(999, nullptr, nullptr);
		Node<T>* first = new Node<T>(x, sentinel, sentinel); // circular sentinel
		sentinel->next = first;
		sentinel->prev = first;
		size = 1;
	}

	DLList() { // initialize empty list
		sentinel = new Node<T>(999, nullptr, nullptr); // data of sentinel does not matter
		sentinel->next = sentinel;
		sentinel->prev = sentinel;
		size = 0;
	}

	// Returns true if deque is empty, false otherwise
	bool isEmpty() {
		return sentinel->next == sentinel;
	}

	// add x to the front of the list
	void addFirst(T x) override {
		sentinel->next = new Node<T>(x, sentinel, sentinel->next);
		sentinel->next->next->prev = sentinel->next; // works when list is empty
		size++;
	}

	// add x to the last of the list
	void addLast(T x) override {
		sentinel->prev = new Node<T>(x, sentinel->prev, sentinel);
		sentinel->prev->prev->next = sentinel->prev;
		size++;
	}

	// Removes and returns the item at the front of the list
	T* removeFirst() override {
		if (isEmpty()) {
			return nullptr;
		}
		T first = sentinel->next->val;
		Node<T>* second = sentinel->next->next;// the second element
		sentinel->next = second;
		second->prev = sentinel;
		return &first;
	}

	// Removes and returns the item at the back of the list
	T* removeLast() override {
		if (isEmpty()) {
			return nullptr;
		}
		T last = sentinel->prev->val;
		Node<T>* secondLast = sentinel->prev->prev;// the second to last element
		sentinel->prev = secondLast;
		secondLast->next = sentinel;
		return &last;
	}

	T* get(int index) override {
		if (index >= size) {
			return nullptr;
		}
		Node<T>* p = sentinel->next;
		int i = 0;
		while (i < index) {
			p = p->next;
			i++;
		}
		return &(p->val);
	}

	// return the size of the current list
	int getSize() override {
		return size;
	}

	// the print() implemented in List is inefficient, override it
	void print() override {
		cout << "calling DLList print()" << endl;
		if (isEmpty()) {
			return;
		}
		Node<T>* p = sentinel->next;
		while (p != sentinel) {
			cout << p->val << ' ';
			p = p->next;
		}
		cout << endl;
	}
	// Returns whether the parameter o is equal to the list
	bool equals(DLList* o) {
		int o_size = o->getSize();
		if (o_size != getSize()) {
			return false;
		}
		Node<T>* p = sentinel->next;
		for (int i = 0; i < size; i++) {
			if (get(i) != o->get(i)) {
				return false;
			}
		}
		return true;
	}
};

int main() { 

	//SLList* L = new SLList(6);

	DLList<char> DL = DLList<char>('B');
	DL.addFirst('A');
	DL.addLast('C');

	DL.print();
	//DL.removeFirst();
	//DL.print();

	//DL.removeLast();
	//DL.print();
	
	/*
	DLList<char>* DL = new DLList<char>('B');
	DL->print();
	DL->addFirst('A');
	DL->addLast('C');

	DL->print();
	DL->removeFirst();
	DL->print();

	DL->removeLast();
	DL->print();



	DL->addFirst('x');
	DL->print();
	DL->addLast('y');
	DL->print();

	AList* AL = new AList();
	int i = 0;
	while (i < 10) {
		AL->addLast(i);
		i++;
	}
	AL->print();
	*/
}