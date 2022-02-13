#include <vector>
#include <queue>
#include "Graph.cpp"
using namespace std;

class Dijkstra {
private:
	priority_queue<pair<int, int>> q;
	vector<int> dist_to; // from start
	vector<int> cameFrom; //path goes from cameFrom[i] to i
	int start, goal;
	Graph* graph;

	vector<int> searchShortest() {
		// add all nodes to pq
		for (int i = 0; i < graph->V(); i++) {
			if (i == start) {
				q.push({ start, 0 });
			}
			else {
				q.push({ i, INT_MAX });
			}
		}

		while (!q.empty()) {
			// pop the node with smallest cost
			pair<int, int> cur_pair = q.top();
			int cur = cur_pair.first;
			q.pop();

			// update all edges from cur
			for (int child : graph->getAdj(cur)) {
				int w = graph->getWeight(cur, child);
				int new_cost = w + dist_to[cur];
				if (new_cost < dist_to[child]) {
					dist_to[child] = new_cost;
					cameFrom[child] = cur;
					q.push({ child, new_cost });
				}
			}	
		}
		vector<int>path = {};
		for (int x = goal; x != start; x = cameFrom[x]) {
			path.push_back(x);
		}
		path.push_back(start);
		reverse(path.begin(), path.end());
		return path;
	}

public:

	Dijkstra(int s, int g, Graph* G) {
		start = s;
		goal = g;
		graph = G;
		vector<int> path = searchShortest();
	}
};
