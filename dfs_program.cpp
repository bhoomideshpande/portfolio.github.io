#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Depth First Search (DFS)
void dfsUtil(int node, const vector<vector<int>>& graph, set<int>& visited) {
    visited.insert(node);
    cout << node << " ";
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfsUtil(neighbor, graph, visited);
        }
    }
}

void dfs(const vector<vector<int>>& graph, int start) {
    set<int> visited;
    dfsUtil(start, graph, visited);
}

int main() {
    cout << "DFS Traversal (Connectivity Assessment):" << endl;
    vector<vector<int>> graph = {
        {1, 2}, // Resource 0 connected to 1 and 2
        {0, 3}, // Resource 1 connected to 0 and 3
        {0, 3}, // Resource 2 connected to 0 and 3
        {1, 2}  // Resource 3 connected to 1 and 2
    };
    dfs(graph, 0);

    return 0;
}
