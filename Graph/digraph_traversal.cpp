#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Digraph {
  public:
    int vertexNum;             // Number of vertices
    vector<vector<bool>> adj;  // Adjacency matrix presentation, unweighted directed graph

    Digraph(int n) : vertexNum(n) {
        adj.resize(n);
        for (auto it = adj.begin(); it != adj.end(); it++) {
            it->resize(n);
        }
    }

    void BFS();  // Print in BFS order
    void DFS();  // Print in DFS order

  private:
    void DFS_recursive(int& vertex, vector<bool>& visited);
};

void Digraph::BFS() {
    queue<int> que;
    vector<bool> visited(vertexNum, false);

    for (int i = 0; i < vertexNum; i++) {  // In case the graph is not connected
        if (!visited[i]) {
            que.push(i);
            while (!que.empty()) {
                int current = que.front();
                que.pop();
                if (!visited[current]) {
                    cout << current << " ";  // Visit the vertex
                    visited[current] = true;
                    for (int j = 0; j < vertexNum; j++) {
                        if (adj[current][j] == true && !visited[j]) {
                            que.push(j);
                        }
                    }
                }
            }
        }
    }
}

void Digraph::DFS() {
    vector<bool> visited(vertexNum, false);

    for (int i = 0; i < vertexNum; i++) {  // In case the graph is not connected
        if (!visited[i]) {
            DFS_recursive(i, visited);
        }
    }
}

void Digraph::DFS_recursive(int& current, vector<bool>& visited) {
    cout << current << " ";  // Visit the vertex
    visited[current] = true;
    for (int j = 0; j < vertexNum; j++) {
        if (adj[current][j] && !visited[j]) {
            DFS_recursive(j, visited);
        }
    }
}

int main() {
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

    cout << endl;
    cout << "DFS: ";
    g.DFS();
    cout << endl;
    cout << "BFS: ";
    g.BFS();
    cout << endl;

    system("pause");
    return 0;
}
