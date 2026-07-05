#include <iostream>
#include <vector>
using namespace std;

/**
 * Variation For Climing Stairs
 * 
*/

int climbing_stairs_ways_Tabulation(int n){
    vector<int> f(n + 1, 0);

    f[0] = 1;
    
    for(int i=1; i<=n; i++){
        int i1 = i - 1 >= 0 ? f[i - 1] : 0;
        int i2 = i - 2 >= 0 ? f[i - 2] : 0;
        int i3 = i - 3 >= 0 ? f[i - 3] : 0;
        f[i] = i1 + i2 + i3;
    }

    return f[n];
}

int main(){
    int n  = 4;
    vector<int> f(n+1, 0);
    int result = climbing_stairs_ways_Tabulation(n);
    cout<<result<<endl;
}