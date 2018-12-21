#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

	void DFS() {
		vector<bool> visited(count);
		for (int i = 0; i < count; i++) {
			visited[i] = false;
		}

		for (int i = 0; i < count; i++) {
			if (!visited[i]) {
				DFS_recursive(i, visited);
			}
		}
	}

	void BFS() {
		queue<int> que;
		vector<bool> visited(count);
		for (int i = 0; i < count; i++) {
			visited[i] = false;
		}
		
		for(int i = 0; i < count; i++) {
			if(!visited[i]) {
				que.push(i);
				while(!que.empty()) {
					int current = que.front();
					que.pop();
					if(!visited[current]) {
						cout << current << " ";
						visited[current] = true;
						for(int j = 0; j < count; j++) {
							if(adj[i][j]==true) {
								que.push(j);
							}
						}
					}
				}
			}
		}
	}
	void print_matrix() {
		cout << "  ";
		for (int i = 0; i < count; i++) {
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < count; i++) {
			cout << i << " ";
			for (int j = 0; j < count; j++) {
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}

private:
	void DFS_recursive(int& vertex, vector<bool> &visited) {
		cout << vertex << " ";    // Visit vertex!
		visited[vertex] = true;
		for (int j = 0; j < count; j++) {
			if (adj[vertex][j] && !visited[j]) {
				DFS_recursive(j, visited);
			}
		}
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
	cout << "*******************" << endl;
	g.print_matrix();
	cout << "*******************" << endl;

	cout << "DFS: ";
	g.DFS();
	
	cout << "BFS: ";
	g.BFS();

	return 0;
}
