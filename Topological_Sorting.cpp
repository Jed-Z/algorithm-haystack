#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Digraph {
public:
	int count;    // Number of vertices
	vector<vector<bool>> adj;

	Digraph(int n) :count(n) {
		adj.resize(n);
		for (auto it = adj.begin(); it != adj.end(); it++) {
			it->resize(n);
		}
	}

	list<int> toposort_depth() {
		list<int> order;

		vector<bool> visited(count);
		for (int i = 0; i < count; i++) visited[i] = false;
		for (int i = 0; i < count; i++) {
			if (!visited[i]) {
				toposort_depth_recursive(i, visited, order);
			}
		}

		return order;
	}

private:
	void toposort_depth_recursive(int current, vector<bool> &visited, list<int> &order) {
		visited[current] = true;
		for (int j = 0; j < count; j++) {
			if (adj[current][j] && !visited[j]) {
				toposort_depth_recursive(j, visited, order);
			}
		}
		order.push_front(current);
	}
};

int main()
{
	int n;
	cin >> n;
	Digraph g(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool temp;
			cin >> temp;
			g.adj[i][j] = temp;
		}
	}

	list<int> topological_order = g.toposort_depth();

	for (auto it = topological_order.begin(); it != topological_order.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
