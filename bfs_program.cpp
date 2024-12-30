#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// Breadth First Search (BFS)
void bfs(const vector<vector<int>>& graph, int start) {
    set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    cout << "BFS Traversal (Energy Distribution):" << endl;
    vector<vector<int>> graph = {
        {1, 2}, // Resource 0 connected to 1 and 2
        {0, 3}, // Resource 1 connected to 0 and 3
        {0, 3}, // Resource 2 connected to 0 and 3
        {1, 2}  // Resource 3 connected to 1 and 2
    };
    bfs(graph, 0);

    return 0;
}
