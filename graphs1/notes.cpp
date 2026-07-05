//                          Graph
/**
 * Edges :
 * Unidirectional : 1 -> 2
 * Bidirectional : 1 <-> 2
 * UnDirected : 1 -- 2
 * Weighted : 1 --(5)--> 2
 */
/**
 * Storing Graph :
 * 1. Adjacency Matrix : 2D array where matrix[i][j] is true if there is an edge from vertex i to vertex j.
 * 2. Most Popular - Adjacency List : An array of lists where each index represents a vertex and the list at that index contains the adjacent vertices.
 *  *                       0    2
 *                           \ /  \
 *                            1 -- 3                                  
 *              0 -> ({0,1})        dist[0]
 *              1 -> ({1,0}, {1,2}, {1,3})  dist[1]
 *              2 -> ({2,1}, {2,3})     dist[2]
 *              3 -> ({3,1}, {3,2})     dist[3]
 * 
 * 
 * 3. Edge List : A list of all edges in the graph, where each edge is represented as a pair of vertices (and possibly a weight).
 * 4. 2D Vector : Similar to an adjacency matrix but can store weights or other information instead of just true/false.
 */

//                          GRAPH
/**
 * Graph Is network Of Nodes
 * Nodes => Vertex
 * Lines => Edges
 * ====>Types Of Edges
 *      1> Unidirectional
 *      2> Bi-directional/undirectional
 * ====>Types WRT Weight
 *      1>Weighted
 *      2>un-Weighted
 */
/**
 * Storing Graph
 * 1->Adjecncy List => List Of List
 * 2->Adjecncy Matrix
 * 3->Edge List
 * 4->2D Matrix
 */

// Implemantaion of the Graph With Adjecncy List
#include <iostream>
#include <vector>
using namespace std;

class Edge{
public:
    int src;
    int dest;
    Edge(int source, int destination){
        src = source;
        dest = destination;
    }
};

int main(void){
    vector<vector<Edge>> Graph(4);
    Graph[0].push_back(Edge(0,2));
    Graph[1].push_back(Edge(1,2));
    Graph[1].push_back(Edge(1,3));
    Graph[2].push_back(Edge(2,0));
    Graph[2].push_back(Edge(2,1));
    Graph[2].push_back(Edge(2,3));
    Graph[3].push_back(Edge(3,1));
    Graph[3].push_back(Edge(3,2));
    for(int i=0; i<Graph.size(); i++){
        for(const Edge &e: Graph[i]){
            cout << "Edge from " << e.src << " to " << e.dest << endl;
        }
    }
}


// Now The Weighted Graph Using Adjacency Matrix
#include <iostream>
#include <vector>
using namespace std;

class Edgew{
public:
    int src;
    int dest;
    int weight;
    Edgew(int source, int destination, int wei){
        src = source;
        dest = destination;
        weight = wei;
    }
};

int main(void){
    vector<vector<Edgew>> Graph(4);
    Graph[0].push_back(Edgew(0,2,2));
    Graph[1].push_back(Edgew(1,2,10));
    Graph[1].push_back(Edgew(1,3,0));
    Graph[2].push_back(Edgew(2,0,2));
    Graph[2].push_back(Edgew(2,1,10));
    Graph[2].push_back(Edgew(2,3,-1));
    Graph[3].push_back(Edgew(3,1,0));
    Graph[3].push_back(Edgew(3,2,-1));
    for(const Edgew &e: Graph[2]){
        cout << "Edge from " << e.src << " to " << e.dest<<" Weight "<< e.weight << endl;
    }
}

//Graph Using Adjacency Matrix
/**
 * Not Efficent
 * Waste Of Memory : Space - O(v.v)
 * Neighbour : O(v)
 */

// Graph Using Edge List
/**
 * Efficent Way To Find The Minimum Spaning Tree
 * Easly Acsessed
 */

// Graph Using Implicit Graph
/**
 * Given The Graph in Form OF 2-D Matrix
 * And The value Are Implicit
 */


//                          Graph Traversals
/**
 * Breadth First Search(BFS) : 
 * Level Order Trivarsal
 * Go to Immiediate neighbour First
 * Inorder Level order Trivarsal
 * Data Structure = Queue
 *                  Rear = Add
 *                  Front = Remove
 * 
 * Depth First Search (DFS)
 * Depth Order Trivarsl
 * Keep Going To First Neighbour 
 */


//           Implemenation OF the Breadth First Search(BFS) 
/**
 * Go to immiediate neighbour First
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge{
public:
    int src;
    int dest;
    Edge(int source, int destination){
        src = source;
        dest = destination;
    }
};

void BFS(vector<vector<Edge>>& Graph, int startNode){
    int n = Graph.size();
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(Edge e: Graph[curr]){
            if(!visited[e.dest]){
                visited[e.dest] = true;
                q.push(e.dest);
            }
        }
    }
}

int main(void){
    vector<vector<Edge>> Graph(7);
    //    1 ---- 3
    //   /       | \
    //  0        |  5 --- 6
    //   \       | /
    //    2 ---- 4

    Graph[0].push_back(Edge(0,1));
    Graph[0].push_back(Edge(0,2));

    Graph[1].push_back(Edge(1,0));
    Graph[1].push_back(Edge(1,3));

    Graph[2].push_back(Edge(2,4));
    Graph[2].push_back(Edge(2,0));
    
    Graph[3].push_back(Edge(3,1));
    Graph[3].push_back(Edge(3,4));
    Graph[3].push_back(Edge(3,5));

    Graph[4].push_back(Edge(4,2));
    Graph[4].push_back(Edge(4,5));

    Graph[5].push_back(Edge(5,3));
    Graph[5].push_back(Edge(5,4));

    Graph[6].push_back(Edge(6,5));
    BFS(Graph,0);
}



//          Implemenation OF the Depth First Search (DFS):
// Keep Going To First Neighbour
// Use Recursion Method
void DFS(vector<vector<Edge>>& Graph, int curr, vector<bool>& visited){
    cout<<curr<<" ";
    visited[curr] = true;
    for(Edge e : Graph[curr]){
        if(!visited[e.dest]){
            DFS(Graph,e.dest, visited);
        }
    }
}

int main(void){
    vector<vector<Edge>> Graph(7);
    //    1 ---- 3
    //   /       | \
    //  0        |  5 --- 6
    //   \       | /
    //    2 ---- 4
    Graph[0].push_back(Edge(0,1));
    Graph[0].push_back(Edge(0,2));

    Graph[1].push_back(Edge(1,0));
    Graph[1].push_back(Edge(1,3));

    Graph[2].push_back(Edge(2,4));
    Graph[2].push_back(Edge(2,0));
    
    Graph[3].push_back(Edge(3,1));
    Graph[3].push_back(Edge(3,4));
    Graph[3].push_back(Edge(3,5));

    Graph[4].push_back(Edge(4,2));
    Graph[4].push_back(Edge(4,5));

    Graph[5].push_back(Edge(5,3));
    Graph[5].push_back(Edge(5,4));
    Graph[5].push_back(Edge(5,6));

    Graph[6].push_back(Edge(6,5));
    int n = Graph.size();
    vector<bool> visited(n,false);
    //if We Get The Graph Non-Connected this loop will handle it
    for(int i=0; i<n; i++){
        if(visited[i]==false){
            DFS(Graph,i,visited);
        }
    }   
}


// All Path Form Source To Target 
void PrintAllPathDFS(vector<vector<Edge>>& Graph, int curr, vector<bool>& visited, string path, int target){
    if(curr==target){
        cout<<path<<endl;
        return;
    }
    visited[curr] = true;

    for(Edge e : Graph[curr]){
        if(!visited[e.dest]){    
            PrintAllPathDFS(Graph, e.dest, visited, path + "->" + to_string(e.dest), target);   
        }
    }
    visited[curr] = false;
}

int main(void){
    vector<vector<Edge>> Graph(7);
    Graph[0].push_back(Edge(0,1));
    Graph[0].push_back(Edge(0,2));

    Graph[1].push_back(Edge(1,0));
    Graph[1].push_back(Edge(1,3));

    Graph[2].push_back(Edge(2,4));
    Graph[2].push_back(Edge(2,0));
    
    Graph[3].push_back(Edge(3,1));
    Graph[3].push_back(Edge(3,4));
    Graph[3].push_back(Edge(3,5));

    Graph[4].push_back(Edge(4,2));
    Graph[4].push_back(Edge(4,5));
    Graph[4].push_back(Edge(4,3));
 
    Graph[5].push_back(Edge(5,3));
    Graph[5].push_back(Edge(5,4));
    Graph[5].push_back(Edge(5,6));

    Graph[6].push_back(Edge(6,5));
    int n = Graph.size();
    vector<bool> visited(n,false);
    PrintAllPathDFS(Graph,0,visited,"0",5);
}




//                      CYCLE DETECTION 
/**
 * For Directed Graph : 
 * ->Modified DFS : It is Only valid For Directed Garph
 * ->
 * 
 * 
 * For Undirected Graph :  
 */


// For Cycle Detection For Directed Graph
bool ModifiedDFS(vector<vector<Edge>>& Graph, int curr, vector<bool>& visited, vector<bool>& recursion){
    visited[curr] = true;
    recursion[curr] = true;
    for(Edge e : Graph[curr]){
        if(recursion[e.dest]) return true;
        else if(!visited[e.dest]){
            if(ModifiedDFS(Graph,e.dest, visited,recursion)){
                return true;
            }
        }
    }
    recursion[curr] = false;
    return false;
}

int main(void){
    vector<vector<Edge>> Graph(7);
    Graph[0].push_back(Edge(0,2));

    Graph[1].push_back(Edge(1,0));

    Graph[2].push_back(Edge(2,3));
    
    Graph[3].push_back(Edge(3,0));

    int n = Graph.size();
    vector<bool> visited(n,false);
    vector<bool> recursion(n,false);
    for(int i=0; i<n; i++){
        if(visited[i]==false){
            cout<<ModifiedDFS(Graph,0,visited,recursion)<<endl;
            return 0;
        }
    }   
}

 
//              Topological Sorting
/**
 * (Only Perform For)Directed Acyclic Graph(DAC) Is a Directed with no Cycles.
 * It Is A Linear Order Of Vertex Such That Every Directed edge u->v , The Vertex u Comes Before v in the order.
 * It tells The Dependency Of the Program
 */ 

void TopologicalModifiedDFS(vector<vector<Edge>>& Graph, int curr, vector<bool>& visited, stack<int>& s){
    visited[curr] = true;
    for(Edge e : Graph[curr]){
        if(!visited[e.dest]){
            TopologicalModifiedDFS(Graph,e.dest, visited,s);
        }
    }
    s.push(curr);
}

void topSort(vector<vector<Edge>>& Graph, int n){
    vector<bool> visited(n,false);
    stack<int> s;
    for(int i=0; i<n; i++){
        if(visited[i]==false){
            TopologicalModifiedDFS (Graph,i,visited,s);
        }
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}

int main(void){
    vector<vector<Edge>> Graph(6);

    Graph[2].push_back(Edge(2,3));

    Graph[3].push_back(Edge(3,1));

    Graph[4].push_back(Edge(4,0));
    Graph[4].push_back(Edge(4,1));

    Graph[5].push_back(Edge(5,0));
    Graph[5].push_back(Edge(5,2));
    

    int n = Graph.size(); 
    topSort(Graph,n);
}




// For Cycle Detection For Undirected Graph
bool IscycleUndirectedDFS(vector<vector<Edge>>& Graph, int curr, vector<bool>& visited, int parent){
    visited[curr] = true;
    for(Edge e : Graph[curr]){
        if(!visited[e.dest]){
            if(IscycleUndirectedDFS(Graph,e.dest, visited,curr)){
                return true;
            }
        }
        else if(e.dest != parent){
            return true;
        }
    }
    return false;
}


int main(void){
    vector<vector<Edge>> Graph(6);

    Graph[0].push_back(Edge(0,1));
    Graph[0].push_back(Edge(0,4));

    Graph[1].push_back(Edge(1,0));
    Graph[1].push_back(Edge(1,2));

    Graph[2].push_back(Edge(2,1));
    Graph[2].push_back(Edge(2,3));

    Graph[3].push_back(Edge(3,2));

    Graph[4].push_back(Edge(4,0));
    Graph[4].push_back(Edge(4,1));
    Graph[4].push_back(Edge(4,5));

    Graph[5].push_back(Edge(5,4));

    vector<bool> visited(6,false);
    int n = Graph.size(); 
    bool hasCycle = false;
    for (int i = 0; i < 6; i++) {
        if (!visited[i]) {
            if (IscycleUndirectedDFS(Graph, i, visited, -1)) {
                hasCycle = true;
                break;
            }
        }
    }
    cout << (hasCycle ? "Cycle detected" : "No cycle detected") << endl;
}




//                  Shortest Path Algorithum (Dijkstra's Algorithm)
/**
 * Best Only For Positive Graph
 * Greedy Algorithum
 */
class Pair{
public:
    int node;
    int dist;
    Pair(int n, int d){
        node = n;
        dist = d;
    }
    bool operator<(const Pair& other) const {
        return dist > other.dist;
    }
};

void DijkstraAlgorithm(vector<vector<Edge>>& Graph,int src ,int n){
    priority_queue<Pair> pq;
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n,false);

    distance[src] = 0;
    pq.push(Pair(src,0));
 
    while(!pq.empty()){
        Pair curr = pq.top();
        pq.pop();
        if(visited[curr.node]) continue;
        visited[curr.node] = true;

        for(Edge e: Graph[curr.node]){
            int u = e.src;
            int v = e.dest;
            int weight = e.weight;

            if(distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
                pq.push(Pair(v, distance[v]));
            }
        }
    }
    cout << "Shortest distances from node " << src << ": ";
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX)
            cout << "INF ";
        else
            cout << distance[i] << " ";
    }
    cout << endl;
}


int main(void){
    vector<vector<Edge>> Graph(6);

    Graph[0].push_back(Edge(0,1,2));
    Graph[0].push_back(Edge(0,2,4));

    Graph[1].push_back(Edge(1,3,7));
    Graph[1].push_back(Edge(1,2,1));

    Graph[2].push_back(Edge(2,4,3));

    Graph[3].push_back(Edge(3,5,1));

    Graph[4].push_back(Edge(4,3,2));
    Graph[4].push_back(Edge(4,5,5));

    DijkstraAlgorithm(Graph,0,6);
}


//               Shortest Path Algorithum (BellmanFord Algorithm)
/**
 * It Can Work Solve The Problem Of Dijkstra's Algorithm of Negative Failure
 * Dynamic Programming Algorithum`
 * Time Complexcity : O(V.E)
 */

void BellmanFordAlgorithm(vector<vector<Edge>>& Graph, int src,int n){
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    for(int k=0; k<n-1; k++){
        for(int i=0; i<n; i++){
            for(Edge e : Graph[i]){
                int u = e.src;
                int v = e.dest;
                int w = e.weight;
                //Relexation Step
                if(distance[u] != INT_MAX && distance[u] + w < distance[v]){
                    distance[v] = distance[u] + w;
                }
            }
        }
    }

    // Check for negative weight cycles
    /**
     * IF A+B+C < 0 [-ve weight Graph]
     */
    for(int i=0; i<n; i++){
        for(Edge e : Graph[i]){
            int u = e.src;
            int v = e.dest;
            int w = e.weight;
            if(distance[u] != INT_MAX && distance[u]+w < distance[v]){
                cout<<"Graph contains a negative weight cycle!"<<endl;
                return;
            }
        }
    }

    cout << "Vertex distances from source " << src << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            cout << i << " : INF" << endl;
        } else {
            cout << i << " : " << distance[i] << endl;
        }
    }

}


int main(void){
    int n = 5;
    vector<vector<Edge>> Graph(n);

    Graph[0].push_back(Edge(0,1,2));
    Graph[0].push_back(Edge(0,2,4));

    Graph[1].push_back(Edge(1,2,-4));

    Graph[2].push_back(Edge(2,3,2));

    Graph[3].push_back(Edge(3,4,4));

    Graph[4].push_back(Edge(4,1,-1));

    BellmanFordAlgorithm(Graph,0,n);
}



//              MINIMUM SAPANING TREE
/**
 * A Minimun Spanning Tree Or Minimum Tree Spanning tree Is The Subset Of The Edges Of Connected, 
 * Edge-Weighted Undirected Graph-Weighted Undirected graph That Connnect All The Vertices Together
 * , Without Any Cycles And With The Minimum Possible Edges Weight.
 */ 
/**
 * Property
 * Undirected 
 * Connected
 * Weighted
 */
class Pair{
public:
    int node;
    int cost;
    Pair(int n, int c){
        node = n;
        cost = c;
    }
    bool operator<(const Pair& other) const {
        return cost > other.cost;
    }
}; 

void PrimsAlgorithm(vector<vector<Edge>>& Graph,int n){
    priority_queue<Pair> pq;
    vector<bool> visited(n,false);
    int finalCost = 0;
    pq.push(Pair(0,0));
    
    while(!pq.empty()){
        Pair curr = pq.top();
        pq.pop();
        if(visited[curr.node]) continue;
        visited[curr.node] = true;
        finalCost += curr.cost;

        for(Edge e: Graph[curr.node]){
            if(!visited[e.dest]){
                pq.push(Pair(e.dest, e.weight));
            }
        }
    }
    cout<<finalCost<<endl;
}


int main(void){
    vector<vector<Edge>> Graph(4);

    Graph[0].push_back(Edge(0,1,10));
    Graph[0].push_back(Edge(0,2,15));
    Graph[0].push_back(Edge(0,3,30));

    Graph[1].push_back(Edge(1,0,10));
    Graph[1].push_back(Edge(1,3,40));

    Graph[2].push_back(Edge(2,0,15));
    Graph[2].push_back(Edge(2,3,50));

    Graph[3].push_back(Edge(3,1,40));
    Graph[3].push_back(Edge(3,2,50));
    int n = Graph.size();
    PrimsAlgorithm(Graph,n);
}



//              Strogly Conncted Components
/**
 * Scc Is a component In Which We Can Reach Every Vertex Of
 * the Components From Every Other Vertex In the Components
 * Only For Directed Graph
 */
//              Kosaraju,s Algorithm
/**
 * STEPS
 * 1-> Get Node Of the Stack
 * Taranspose The Garph
 * Do DFS According To Stack Nodes On The Transpose Graph
 */
/**
 * Time Complexcity : O(V+E)
 *
 */
void DFS(vector<vector<Edge>>& Graph, int curr, vector<bool>& visited){
    visited[curr] = true;
    cout<<curr<<" ";
    for(Edge e: Graph[curr]){
        if(!visited[e.dest]){
            DFS(Graph,e.dest,visited);
        }
    }
}

void TopSort(vector<vector<Edge>>& Graph, int curr, vector<bool>& visited, stack<int>& st){
    visited[curr] = true;
    for(Edge e: Graph[curr]){
        if(!visited[e.dest]){
            TopSort(Graph,e.dest,visited,st);
        }
    }
    st.push(curr);
}

void KosarajuAlgorithm(vector<vector<Edge>>& Graph, int n){
    //Step 1: Topological Sort  [O(V+E)]
    stack<int> st;
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            TopSort(Graph,i,visited,st);
        }
    }
    //Step 2: Reverse The Graph  [O(V+E)]
    vector<vector<Edge>> reverseGraph(n);
    for(int i=0; i<n; i++){
        for(Edge e: Graph[i]){
            reverseGraph[e.dest].push_back(Edge(e.dest,e.src));
        }
    }
    //Step 3: DFS                [O(V+E)]
    vector<bool> NewVisited(n,false);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!NewVisited[curr]){
            DFS(reverseGraph,curr,NewVisited);    
            cout<<endl;     
        }
    } 
}

int main(void){
    vector<vector<Edge>> Graph(5);

    Graph[0].push_back(Edge(0,2));
    Graph[0].push_back(Edge(0,3));

    Graph[1].push_back(Edge(1,0));

    Graph[2].push_back(Edge(2,1));

    Graph[3].push_back(Edge(3,4));
    int n = Graph.size();

    KosarajuAlgorithm(Graph, n);
}


//              Bridge in Graph (Tarjan's Algorithm)

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


    tarjanAlgorithm(Graph, visited, 0, -1, dt, ldt, time);
}


//             Articulation Point in Graph 
