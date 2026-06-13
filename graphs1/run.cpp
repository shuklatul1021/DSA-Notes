#include <iostream>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

class Edge {
public:
    int src;
    int des;
    int weight;
    Edge(int s, int d, int w){
        this->src = s;
        this->des = d;
        this->weight = w;
    }
};

class Pair{
public:
    int node;
    int dist;
    Pair(int n, int d){
        this->node = n;
        this->dist = d;
    }

    bool operator<(const Pair& ot) const {
        return dist > ot.dist;
    }
};


void DjistraAlgorithum(vector<vector<Edge>>& Graph, int src, int n){
    priority_queue<Pair> pq;
    vector<bool> visited(n, false);
    vector<int> destination(n, INT_MAX);

    destination[src] = 0;
    pq.push(Pair(src,0));

    while(!pq.empty()){
        Pair curr = pq.top();
        pq.pop();

        if (visited[curr.node]) continue;
        visited[curr.node] = true;

        for(Edge e : Graph[curr.node]){
            int u = e.src;
            int v = e.des;
            int wei = e.weight;

            if(destination[u] + wei < destination[v]){
                destination[v] = destination[u] + wei;
                pq.push(Pair(v, destination[v]));
            }
        }
    }

    cout<<"The Shortest : "<<endl;
    for(int i = 0; i < n; i++){
        cout<<destination[i]<<" ";
    }cout<<endl;
}

int main(){
    vector<vector<Edge>> Graph(6);

    Graph[0].push_back(Edge(0,1,2));
    Graph[0].push_back(Edge(0,2,4));

    Graph[1].push_back(Edge(1,3,7));
    Graph[1].push_back(Edge(1,2,1));

    Graph[2].push_back(Edge(2,4,3));

    Graph[3].push_back(Edge(3,5,1));

    Graph[4].push_back(Edge(4,3,2));
    Graph[4].push_back(Edge(4,5,5));

    DjistraAlgorithum(Graph,0,6);
}