#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// -------------------------
// Edge
// -------------------------
class Edge {
public:
    int src;
    int dest;
    int weight;

    Edge(int source, int destination, int wei) {
        src = source;
        dest = destination;
        weight = wei;
    }
};


// -------------------------
// DSU
// -------------------------
vector<int> parent;
vector<int> rankValue;

void initDSU(int vertices) {
    parent.resize(vertices);
    rankValue.assign(vertices, 0);

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    }

    // Path compression
    return parent[x] = find(parent[x]);
}

void getUnion(int x, int y) {
    int parentX = find(x);
    int parentY = find(y);

    // Already in the same set
    if (parentX == parentY) {
        return;
    }

    // Union by rank
    if (rankValue[parentX] == rankValue[parentY]) {
        parent[parentX] = parentY;
        rankValue[parentY]++;
    }
    else if (rankValue[parentX] < rankValue[parentY]) {
        parent[parentX] = parentY;
    }
    else {
        parent[parentY] = parentX;
    }
}


// -------------------------
// Kruskal Algorithm
// -------------------------
int kruskalAlgorithm(vector<vector<Edge>>& graph, int vertices) {

    // Convert adjacency list into edge list
    vector<Edge> edges;

    for (int i = 0; i < vertices; i++) {
        for (Edge edge : graph[i]) {
            edges.push_back(edge);
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    // Initialize DSU
    initDSU(vertices);

    int mstWeight = 0;
    int edgesUsed = 0;

    for (Edge edge : edges) {
        int parentSrc = find(edge.src);
        int parentDest = find(edge.dest);

        if (parentSrc != parentDest) {
            mstWeight += edge.weight;
            edgesUsed++;

            getUnion(edge.src, edge.dest);
            if (edgesUsed == vertices - 1) {
                break;
            }
        }
    }

    cout << "\nTotal MST Weight: " << mstWeight << endl;

    return mstWeight;
}


// -------------------------
// Main
// -------------------------
int main() {

    int vertices = 6;

    vector<vector<Edge>> Graph(vertices);

    Graph[0].push_back(Edge(0, 1, 2));
    Graph[0].push_back(Edge(0, 2, 4));

    Graph[1].push_back(Edge(1, 3, 7));
    Graph[1].push_back(Edge(1, 2, 1));

    Graph[2].push_back(Edge(2, 4, 3));

    Graph[3].push_back(Edge(3, 5, 1));

    Graph[4].push_back(Edge(4, 3, 2));
    Graph[4].push_back(Edge(4, 5, 5));

    kruskalAlgorithm(Graph, vertices);

    return 0;
}