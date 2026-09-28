/**
 * Disjoint Set Union 
 *  Union Find 
 * 
 * The Disjoint Set Union (DSU) is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. It provides two primary operations:
 * 1. Find: Determine which subset a particular element is in.
 * 2. Union: Join two subsets into a single subset.
 * 
 * This implementation uses path compression and union by rank for efficient operations.
 * 
*/


#include <iostream>
#include <vector>
using namespace std;

vector<int> parent(7);
vector<int> voidrank(7, 0);

void init(){
    for(int i = 0; i < 7; i++){
        parent[i] = i;
    }
}

int find(int x){
    if(x == parent[x]){
        return x;
    }

    // Path compression
    return parent[x] = find(parent[x]);
}

void getunion(int x, int y){
    int parentx = find(x);
    int parenty = find(y);


    if(voidrank[parentx] == voidrank[parenty]){
        parent[parentx] = parenty;
        voidrank[parenty]++;
    }
    else if(voidrank[parentx] < voidrank[parenty]){
        parent[parentx] = parenty;
    }
    else{
        parent[parenty] = parentx;
    }
}

int main(){
    init();

    getunion(1, 3);
    cout << find(3) << endl;

    getunion(2, 4);
    getunion(3, 6);
    getunion(1, 4);

    cout << find(3) << endl;
}