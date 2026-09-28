#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;
    Edge(int source, int destination, int wei){
        src = source;
        dest = destination;
        weight = wei;
    }
};

class CityPair {
public:
    int node;
    int dis;
    CityPair(int n, int d){
        node = n;
        dis = d;
    }

    bool operator<(const CityPair& other) const {
        return dis > other.dis;
    }
};

int minimum_cost_connect_cities(vector<vector<Edge>>& g, int n){
    priority_queue<CityPair> pq;
    vector<bool> visited(n,false);
    int finalCost = 0;
    pq.push(CityPair(0,0));

    while(!pq.empty()){
        CityPair curr = pq.top();
        pq.pop();
        if(visited[curr.node]) continue;
        visited[curr.node] = true;
        finalCost += curr.dis;

        for(Edge e: g[curr.node]){
            if(!visited[e.dest]){
                pq.push(CityPair(e.dest, e.weight));
            }
        }
    }

    return finalCost;
}

int kruskalAlgo()


int main(void){
    int n = 5;
    vector<vector<int>> cities = {
        {0, 1, 2, 3, 4},
        {1, 0, 5, 0, 7},
        {2, 5, 0, 6, 0},
        {3, 0, 6, 0, 0},
        {4, 7, 0, 0, 0}
    };
    vector<vector<Edge>> Graph(n);

    for(int i = 0; i < cities.size(); i++){
        for(int j = 0; j < cities[0].size(); j++){
            if(cities[i][j] != 0){
                Graph[i].push_back(Edge(i, j, cities[i][j]));
            }
        }
    }
    
    cout << minimum_cost_connect_cities(Graph, n) << endl;
}