#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// Minimum Spanning Tree (MST) using Kruskal's Algorithm
class Graph {
public:
    int vertices;
    vector<tuple<int, int, int>> edges; // (weight, u, v)

    Graph(int v) : vertices(v) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({weight, u, v});
    }

    int find(vector<int>& parent, int node) {
        if (parent[node] != node)
            parent[node] = find(parent, parent[node]);
        return parent[node];
    }

    void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end());
        vector<int> parent(vertices);
        vector<int> rank(vertices, 0);

        for (int i = 0; i < vertices; ++i)
            parent[i] = i;

        vector<tuple<int, int, int>> mst;

        for (auto& [weight, u, v] : edges) {
            if (find(parent, u) != find(parent, v)) {
                unionSets(parent, rank, u, v);
                mst.push_back({u, v, weight});
            }
        }

        cout << "Edge \tWeight" << endl;
        for (auto& [u, v, weight] : mst) {
            cout << u << " - " << v << " \t" << weight << endl;
        }
    }
};

int main() {
    cout << "Minimum Spanning Tree (Optimal Microgrid Layout):" << endl;
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
