#include <iostream>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

class Edge {
public:
    int src;
    int des;
    Edge(int s, int d){
        this->src = s;
        this->des = d;
    }
};

void tarjanAlgorithm(vector<vector<Edge>>& Graph, vector<bool> &visited, int curr, int parent, vector<int> &dt, vector<int> &ldt, int time){
    visited[curr] = true;
    dt[curr] = ldt[curr] = ++time;
  
    for(Edge e : Graph[curr]){
        if(e.des == parent) continue;

        if(!visited[e.des]){
            tarjanAlgorithm(Graph, visited, e.des, curr, dt, ldt, time);
            ldt[curr] = min(ldt[curr], ldt[e.des]);

            if(dt[curr] < ldt[e.des]){
                cout << "Bridge Found : " << curr << " - " << e.des << endl;
            }
        } else {
            ldt[curr] = min(ldt[curr], dt[e.des]);
        }
    }
}

int main(){
    vector<vector<Edge>> Graph(4);
    vector<bool> visited(4, false);
    vector<int> dt(4, 0);
    vector<int> ldt(4, 0);
    int time = 0;
    Graph[0].push_back(Edge(0,1));
    Graph[0].push_back(Edge(0,2));

    Graph[1].push_back(Edge(1,0));
    Graph[1].push_back(Edge(1,2));
    Graph[1].push_back(Edge(1,3));

    Graph[2].push_back(Edge(2,0));
    Graph[2].push_back(Edge(2,1));

    Graph[3].push_back(Edge(3,1));


    tarjanAlgorithm(Graph, visited, 0, -1, dt, ldt, time);
}