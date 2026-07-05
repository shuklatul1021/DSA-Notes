//                          Types Of Knapsack Problem
/**
 * Fractional Knapsack(Gredy Approach)
 * 0-1 Knapsack
 * Unbounded Knapsack
*/

#include <iostream>
#include <vector>
using namespace std;

int knapsack_0_1( vector<int> &i, vector<int> &w, int total_weight, int idx){
    if(total_weight == 0 || idx == i.size()){
        return 0;
    }
    if(w[idx] <= total_weight){
        // Include 
        int ans1 = i[idx] + knapsack_0_1(i, w, total_weight - w[idx], idx + 1);
        //Exclude
        int ans2 = knapsack_0_1(i, w, total_weight, idx + 1);

        return max(ans1, ans2);
    } else {
        return knapsack_0_1(i, w, total_weight, idx + 1);
    }
}

int knapsack_0_1_memorization( vector<int> &i, vector<int> &w, int total_weight, int idx, vector<vector<int>> &dp){
    if(total_weight == 0 || idx == i.size()){
        return 0;
    }

    if(dp[idx][total_weight] != -1){
        return dp[idx][total_weight];
    }
    if(w[idx] <= total_weight){
        // Include 
        int ans1 = i[idx] + knapsack_0_1_memorization(i, w, total_weight - w[idx], idx + 1, dp);
        //Exclude
        int ans2 = knapsack_0_1_memorization(i, w, total_weight, idx + 1, dp);

        dp[idx][total_weight] = max(ans1, ans2);
        return dp[idx][total_weight];
    } else {
        dp[idx][total_weight] =  knapsack_0_1_memorization(i, w, total_weight, idx + 1, dp);
        return dp[idx][total_weight];
    }
}


int main() {
    vector<int> item = {15, 14, 10, 45, 30};
    vector<int> weight = {2, 5, 1, 3, 4};
    int allowed_weight = 7;
    int result = knapsack_0_1(item, weight, allowed_weight, 0);
    cout<<"Result : "<<result<<endl;
    return 0;
}


// Knapsack 0-1 Tabulation Approach

int knapsack_0_1_tabulation(vector<int> &it, vector<int> &we, int total_weight, int idx, vector<vector<int>> &dp){
    /**
     * i = item  (maximum number of items)
     * j = weight(knapsack weight)
    */

    for(int i=1; i < it.size() + 1; i++){
        for(int j = 1; j < total_weight + 1; j++){
            int v = it[i-1];
            int w = we[i-1];
            if(w <= j){
                dp[i][j] = max(dp[i-1][j], v + dp[i-1][j - w]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[it.size()][total_weight];
}


int main() {
    vector<int> item = {15, 14, 10, 45, 30};
    vector<int> weight = {2, 5, 1, 3, 4};
    int allowed_weight = 7;
    vector<vector<int>> dp(item.size() + 1, vector<int>(allowed_weight + 1 , 0));
    int result = knapsack_0_1_tabulation(item, weight, allowed_weight, 0, dp);
    cout<<"Result : "<<result<<endl;
    return 0;
}


/**
 * Unbounded Knapsack Problem
 * In this problem we can take the same item multiple times.
 */