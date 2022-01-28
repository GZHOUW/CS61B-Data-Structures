#include <vector>
using namespace std;

class UnionFind {
private:
	vector<int> parent;
	vector<int> size;

	int getRoot(int i) {
		int root = i;
		while (parent[root] != -1) {
			root = parent[root];
		}
		return root;
	}
public:
	UnionFind(int s) {
		// initially each element is in a set of size 1
		parent = vector<int>(s, -1);
		size = vector<int>(s, 1);
	}

	void connect(int x, int y) {
		// determine which set has a larger size
		int x_root = getRoot(x), y_root = getRoot(y);

		if (size[x] > size[y]) {
			parent[y_root] = x_root;
		}
		else {
			parent[x_root] = y_root;
		}
	}

	bool isConnected(int x, int y) {
		int x_root = getRoot(x), y_root = getRoot(y);
		return x_root == y_root;
	}

};