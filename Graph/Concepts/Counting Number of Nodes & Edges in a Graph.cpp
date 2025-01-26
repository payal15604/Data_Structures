#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to count nodes and edges in an undirected graph
void countNodesEdges(int nodes, vector<pair<int, int>> edges) {
    set<int> uniqueNodes; // To ensure unique nodes are counted
    int edgeCount = edges.size();

    for (auto edge : edges) {
        uniqueNodes.insert(edge.first);
        uniqueNodes.insert(edge.second);
    }

    cout << "Number of Nodes: " << uniqueNodes.size() << endl;
    cout << "Number of Edges: " << edgeCount << endl;
}
