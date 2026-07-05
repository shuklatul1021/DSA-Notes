#include <iostream>
#include <vector>
using namespace std;

int matrix_chain_multiplication_dp(vector<int> &arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int len = 2; len <= n; len++){
        for(int i = 1; i <= n - len + 1; i++){
            int j = i + len - 1;
            dp[i][j] = INT16_MAX;
            for(int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main(){
    vector<int> matrix_array = {1, 2, 3, 4, 3};
    int total_cost = matrix_chain_multiplication_dp(matrix_array, matrix_array.size() - 1);
    cout << "Total : " << total_cost << endl;
}  