#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph {
private:
	//If want to store strings, use a map to map an integer to a string.
	//unordered_map<int, string> m;
	vector<vector<int>> adjacency;  // adjacency list
	int n_nodes, n_edges;

public:
	//Create empty graph with V nodes.
	Graph(int V) {
		n_nodes = V;
		n_edges = 0;
		adjacency = vector<vector<int>>(V, vector<int>(0, 0));// V empty lists

	}

	// Add an edge v - w
	void addEdge(int v, int w) {
		adjacency[v].push_back(w);
	}

	//Get the nodes that are adjacent to v
	vector<int> getAdj(int v) {
		return adjacency[v];
	}

	//Number of vertices
	int V() {
		return n_nodes;
	}
	//Number of edges
	int E() {
		return n_edges;
	}
};

class DepthFirstSearch {
private:
	vector<bool> visited;
	vector<int> cameFrom; //path goes from cameFrom[i] to i
	int start;

	void dfs(Graph G, int v) {
		visited[v] = true;
		for (int w : G.getAdj(v)) {
			if (!visited[w]) {
				cameFrom[w] = v;
				dfs(G, w);
			}
		}
	}
public:
	DepthFirstSearch(Graph G, int s) {
		start = s;
		// initialize visited
		visited = vector<bool>(G.V(), false);
		visited[start] = true;

		// initialize parent
		cameFrom = vector<int>(G.V(), 0);
		
		// call the dfs function in constructor
		dfs(G, start);
	}

	// check whether there is a path to v from start
	bool hasPathTo(int v) {
		return visited[v];
	}

	// get the path to v from start
	vector<int> getPathTo(int v) {
		if (!hasPathTo(v)) {
			return {};
		}
		vector<int> path = {};
		for (int x = v; x != start; x = cameFrom[x]) {
			path.push_back(x);
		}
		path.push_back(start);
		reverse(path.begin(), path.end());
		return path;
	}
};

class BreadthFirstSearch {
private:
	vector<bool> visited;
	vector<int> cameFrom; //path goes from cameFrom[i] to i
	int start;

	void bfs(Graph G, int s) {
		queue<int> frontier;
		visited[s] = true;

		while (!frontier.empty()) {
			int v = frontier.front();
			frontier.pop();
			for (int w: G.getAdj(v)){
				if (!visited[w]) {
					frontier.push(w);
					visited[w] = true;
					cameFrom[w] = v;
				}
			}
		}
	}

public:
	BreadthFirstSearch(Graph G, int s) {
		start = s;
		// initialize visited
		visited = vector<bool>(G.V(), false);
		visited[start] = true;

		// initialize parent
		cameFrom = vector<int>(G.V(), 0);

		// call the dfs function in constructor
		bfs(G, start);
	}

	// check whether there is a path to v from start
	bool hasPathTo(int v) {
		return visited[v];
	}

	// get the path to v from start
	vector<int> getPathTo(int v) {
		if (!hasPathTo(v)) {
			return {};
		}
		vector<int> path = {};
		for (int x = v; x != start; x = cameFrom[x]) {
			path.push_back(x);
		}
		path.push_back(start);
		reverse(path.begin(), path.end());
		return path;
	}
};
