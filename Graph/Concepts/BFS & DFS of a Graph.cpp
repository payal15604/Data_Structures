#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// BFS Implementation
void BFS(int start, vector<vector<int>> &adjList, vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// DFS Implementation
void DFS(int node, vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited);
        }
    }
}

// Driver Code
int main() {
    int nodes = 6;
    vector<vector<int>> adjList = {
        {1, 2},    // Node 0
        {0, 3, 4}, // Node 1
        {0, 4},    // Node 2
        {1, 5},    // Node 3
        {1, 2, 5}, // Node 4
        {3, 4}     // Node 5
    };

    vector<bool> visited(nodes, false);

    // BFS
    BFS(0, adjList, visited);

    // Reset visited for DFS
    fill(visited.begin(), visited.end(), false);
    cout << "DFS Traversal: ";
    DFS(0, adjList, visited);
    cout << endl;

    return 0;
}
