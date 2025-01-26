//detectcycle 

bool isCycleUndirected(int node, int parent, vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (isCycleUndirected(neighbor, node, adjList, visited)) return true;
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool isCycleDirected(int node, vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (isCycleDirected(neighbor, adjList, visited, recStack)) return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }
    recStack[node] = false;
    return false;
}
