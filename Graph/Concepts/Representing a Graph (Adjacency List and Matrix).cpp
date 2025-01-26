#include <iostream>
#include <vector>

using namespace std;

// Function to represent a graph using adjacency list
void adjacencyList(int nodes, vector<pair<int, int>> edges) {
    vector<vector<int>> adjList(nodes);

    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        adjList[u].push_back(v); // For undirected, also do adjList[v].push_back(u);
    }

    cout << "Adjacency List Representation:\n";
    for (int i = 0; i < nodes; ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

// Function to represent a graph using adjacency matrix
void adjacencyMatrix(int nodes, vector<pair<int, int>> edges) {
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));

    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        adjMatrix[u][v] = 1; // For undirected, also do adjMatrix[v][u] = 1;
    }

    cout << "Adjacency Matrix Representation:\n";
    for (auto row : adjMatrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}
