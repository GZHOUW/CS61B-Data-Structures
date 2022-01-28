
#include <iostream>
using namespace std;

class SLList{

private:
	// nested class, static because it never uses instance of SSList
	static class IntNode {
	public:
		int val;
		IntNode* next;
		IntNode(int x, IntNode* n) {
			val = x;
			next = n;
		}
	};
	// code outside the class cannot use it
	// its bad if: L.first.next.next = L.first.next
	IntNode* sentinel;
	int size;
	

public:	
	// constructor
	SLList(int x) {
		sentinel = new IntNode(999, nullptr);
		sentinel->next = new IntNode(x, nullptr);
		size = 1;
	}
	
	SLList() { // initialize empty list
		sentinel = new IntNode(999, nullptr); // data of sentinel does not matter
		size = 0;
	}
	// add x to the front of the list
	void addFirst(int x) {
		sentinel->next = new IntNode(x, sentinel->next);
		size++;
	}

	// return the first item of the list
	int getFirst() {
		return sentinel->next->val;
	}

	// add x to the last of the list
	void addLast(int x) {
		// need to consider the case that first is null
		// not a good solution because it introduces special case
		// and makes the method's implementation complex
		// better solution create a sentinel node that is always at the beginning of list
		/*
		if (!first) {
			first = new IntNode(x, nullptr);
			return;
		}*/

		// iterate until last, then add
		IntNode* p = sentinel;
		while (p->next) {
			p = p->next;
		}
		p->next = new IntNode(x, nullptr);
		size++;
	}

	// return the size of the current list
	int getSize() {
		return size;
	}
};
