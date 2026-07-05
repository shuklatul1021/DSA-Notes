/**
 * Matrix Chain Multiplication
 * In this problem, we are given a sequence of matrices and we need to find the most efficient way to multiply these matrices together. 
 * The problem is not actually to perform the multiplications, but merely to decide the sequence of the matrix multiplications involved.
 * We have many options to multiply a chain of matrices. For example, if we have four matrices A, B, C, and D, we can multiply them in different ways:
 * 1. ((AB)C)D
 * 2. (A(BC))D
 * 3. (AB)(CD)
 * 4. A((BC)D)
 * 5. A(B(CD))
 * 
 * 
 */
// Recursive Approach
#include <iostream>
#include <vector>
using namespace std;

int matrix_chain_multiplication(vector<int> &arr, int i, int j) {
    if(i == j){
        return 0;
    }

    int ans = INT16_MAX;
    for(int k = i; k <= j -1; k++){
        int cost1 = matrix_chain_multiplication(arr, i, k);
        int cost2 = matrix_chain_multiplication(arr, k + 1, j);
        int cost3 = arr[i-1] * arr[k] * arr[j];
        int final = cost1 + cost2 + cost3;
        ans = min(ans, final);
    }

    return ans;
}

int main(){
    vector<int> matrix_array = {1, 2, 3, 4, 3};
    int total_cost = matrix_chain_multiplication(matrix_array, 1, matrix_array.size() - 1);
    cout << "Total : " << total_cost << endl;
}  

// Recursion + Memoization
#include <iostream>
#include <vector>
using namespace std;

int matrix_chain_multiplication(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT16_MAX;
    for(int k = i; k <= j -1; k++){
        int cost1 = matrix_chain_multiplication(arr, i, k, dp);
        int cost2 = matrix_chain_multiplication(arr, k + 1, j, dp);
        int cost3 = arr[i-1] * arr[k] * arr[j];
        int final = cost1 + cost2 + cost3;
        ans = min(ans, final);
    }

    dp[i][j] = ans;
    return ans;
}

int main(){
    vector<int> matrix_array = {1, 2, 3, 4, 3};
    vector<vector<int>> dp(matrix_array.size(), vector<int>(matrix_array.size(), -1));
    int total_cost = matrix_chain_multiplication(matrix_array, 1, matrix_array.size() - 1, dp);
    cout << "Total : " << total_cost << endl;
}  

// Tabulation
