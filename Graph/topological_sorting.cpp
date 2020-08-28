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

    list<int> toposort_depth();
    list<int> toposort_breadth();

  private:
    void toposort_depth_recursive(int current, vector<bool> &visited, list<int> &order);
};

list<int> Digraph::toposort_breadth() {
    list<int> order;
    vector<bool> visited(vertexNum, false);
    vector<int> indegree(vertexNum, 0);

    for (int i = 0; i < vertexNum; i++) {  // Make indegree table
        for (int j = 0; j < vertexNum; j++) {
            if (adj[i][j]) ++indegree[j];
        }
    }

    queue<int> que;  // Contains vertices whose indegree are 0
    for (int i = 0; i < vertexNum; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int current = que.front();
        order.push_back(current);
        visited[current] = true;
        que.pop();
        for (int j = 0; j < vertexNum; j++) {
            if (adj[current][j] && !visited[j]) {
                --indegree[j];
                if (indegree[j] == 0) {
                    que.push(j);
                }
            }
        }
    }

    return order;
}
list<int> Digraph::toposort_depth() {
    list<int> order;
    vector<bool> visited(vertexNum);
    for (int i = 0; i < vertexNum; i++) visited[i] = false;

    for (int i = 0; i < vertexNum; i++) {
        if (!visited[i]) {
            toposort_depth_recursive(i, visited, order);
        }
    }

    return order;
}

void Digraph::toposort_depth_recursive(int current, vector<bool> &visited, list<int> &order) {
    visited[current] = true;
    for (int j = 0; j < vertexNum; j++) {
        if (adj[current][j] && !visited[j]) {
            toposort_depth_recursive(j, visited, order);
        }
    }
    order.push_front(current);
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

    list<int> depthOrder = g.toposort_depth();
    cout << "Depth Order: ";
    for (auto it = depthOrder.begin(); it != depthOrder.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    list<int> breadthOrder = g.toposort_breadth();
    cout << "Breadth Order: ";
    for (auto it = breadthOrder.begin(); it != breadthOrder.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
