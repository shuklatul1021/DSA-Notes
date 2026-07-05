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

/**
 * Articulation Points in Graph (Tarjan's Algorithm)
 * 
 * 
 */

void ArticulationAlgorithm(vector<vector<Edge>>& Graph, vector<bool> &visited, int curr, int parent, vector<int> &dt, vector<int> &ldt, int time){
    visited[curr] = true;
    dt[curr] = ldt[curr] = ++time;
  
    for(Edge e : Graph[curr]){
        if(e.des == parent) continue;-+*

        if(!visited[e.des]){
            ArticulationAlgorithm(Graph, visited, e.des, curr, dt, ldt, time);
            ldt[curr] = min(ldt[curr], ldt[e.des]);

            if(dt[curr] < ldt[e.des]){
                cout << "Articulation Point Found : " << curr << endl;
            }
        } else {
            ldt[curr] = min(ldt[curr], dt[e.des]);
        }
    }
    
   
}

int main(){
    vector<vector<Edge>> Graph(6);
    vector<bool> visited(6, false);
    vector<int> dt(6, 0);
    vector<int> ldt(6, 0);
    int time = 0;
    Graph[0].push_back(Edge(0,1));
    Graph[0].push_back(Edge(0,2));
    Graph[0].push_back(Edge(0,3));

    Graph[1].push_back(Edge(1,0));
    Graph[1].push_back(Edge(1,2));

    Graph[2].push_back(Edge(2,0));
    Graph[2].push_back(Edge(2,1));

    Graph[3].push_back(Edge(3,0));
    Graph[3].push_back(Edge(3,4));
    Graph[3].push_back(Edge(3,5));

    Graph[4].push_back(Edge(4,3));
    Graph[4].push_back(Edge(4,5));

    Graph[5].push_back(Edge(5,3));
    Graph[5].push_back(Edge(5,4));


    ArticulationAlgorithm(Graph, visited, 0, -1, dt, ldt, time);
}