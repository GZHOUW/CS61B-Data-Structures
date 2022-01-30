#include <vector>
using namespace std;

class MinPQ {
private:
	int treeSize;

	// index of nodes is the id of a node by level, nodes[i] is the value of the corresponding node
	vector<int> nodes;

	// given id of a node, return its parent's id
	int parent(int id) {
		// integer division automatically floors the result
		return id != 0 ? (id - 1) / 2 : -1; 
	}

	// given id of a node, return its left child's id
	int left(int id) {
		int left_id = 2 * id + 1;
		return left_id < nodes.size() ? left_id : -1;
	}

	// given id of a node, return its right child's id
	int right(int id) {
		int right_id = 2 * id + 2;
		return right_id < nodes.size() ? right_id : -1;
	}

	// swap the value of two nodes
	void swap(int id1, int id2) {
		int temp = nodes[id1];
		nodes[id1] = nodes[id2];
		nodes[id2] = temp;
	}

	// recursively move a node up to its right location
	void moveUp(int id) {
		if (nodes[parent(id)] > nodes[id]) {
			swap(id, parent(id));
			moveUp(parent(id));
		}
	}

	// recursively move a node down to its right location
	void moveDown(int id) {
		// get smallest child
		int smallest = left(id) < right(id) ? left(id) : right(id);
		if (nodes[smallest] < nodes[id]) {
			swap(id, smallest);
			moveDown(smallest);
		}
	}

public:
	MinPQ() {
		treeSize = 0;
		nodes = {};
	}

	// adds the item to the priority queue
	void add(int x) {
		// add to the end of tree
		nodes.push_back(x);
		treeSize++;

		// move up x
		moveUp(x);
	}

	// return the smallest item in the priority queue
	int getSmallest() {
		// the smallest element is always at the root of tree
		return nodes[0];
	}

	// removes the smallest item from the priority queue
	int removeSmallest() {
		int ret = nodes[0];

		// Delete the root and move the last item to root
		nodes[0] = nodes.back();
		nodes.pop_back();
		treeSize--;
		// move down the root
		moveDown(0);

		return ret;
	}

	// returns the size of the priority queue
	int size() {
		return treeSize;
	}
};
