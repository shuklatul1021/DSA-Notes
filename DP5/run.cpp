#include <iostream>
#include <vector>
using namespace std;

int mountain_range(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n ; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    for(int i = 0; i <= n ; i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
    return dp[n];
}

int main() {
    int result = mountain_range(4);
    cout << "Mountain Range For n=5: " << result << endl;
    return 0;
}