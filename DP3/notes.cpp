#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * Rod Cutting Problem
 * Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
 * 
 */


void dp_print(vector<vector<int>>& dp){
    for(int i = 0; i < dp.size(); i++){
        for(int j=0; j < dp[0].size(); j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

int rod_cutting(const vector<int>& length, const vector<int>& price, vector<vector<int>>& dp, int rod_length) {
    for(int i = 1; i < length.size() + 1; i++){
        for(int j = 1; j < rod_length + 1; j++){
            if(length[i-1] <= j){
                //             1          + 0
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]] , dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    dp_print(dp);
    return dp[length.size()][rod_length];
}

int main(){
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int rod_length = 8;
    vector<vector<int>> dp(length.size() + 1, vector<int>(rod_length + 1, 0));
    int result = rod_cutting(length, price, dp, rod_length);
    cout<<"Result : "<<result<<endl;

}


/**
 * IMP(10-15)
 * Longest Common Subsequence(LCS) 
 * An subsequence of a string is a new string generation from the original string with some char delete withoit chnaging the relative order of the  remaining char
 * Ex : 
 *  str1 = "abcd", str2 = "ace"
 *  ans = 3
 * 
 * Ex:
 *  str1= "abcdge" , str2 = "abedg"
 */

//      All Three Aproaches are same as LCS
/**
 * Reccursion
 */


int longest_common_subsequence(string str1, string str2, int str1_last_idx, int str2_last_index){
    if(str1_last_idx == 0 || str2_last_index == 0 ){
        return 0;
    }

    if(str1[str1_last_idx] == str2[str2_last_index]){
        return longest_common_subsequence(str1, str2, str1_last_idx - 1, str2_last_index -1) + 1;
    } else {
        // Decrementing the Index of first String
        int ans1 = longest_common_subsequence(str1, str2, str1_last_idx - 1, str2_last_index);
        // Decrementing The Index of Second String
        int ans2 = longest_common_subsequence(str1, str2, str1_last_idx, str2_last_index - 1);
        // Returning Max 
        return max(ans1, ans2);
    }

}


int main() {
    string str1 = "abcde";
    string str2 = "ace";
    int ans = 0;
    int result = longest_common_subsequence(str1, str2, str1.length(), str2.length());
    cout<<"Result : "<<result<<endl;
    return 0;
}



/**
 * Recursion + Memoization
 */
int longest_common_subsequence(string str1, string str2, int str1_last_idx, int str2_last_index, vector<vector<int>>& dp){
    if(str1_last_idx == 0 || str2_last_index == 0 ){
        return 0;
    }

     if(dp[str1_last_idx][str2_last_index] != -1){
        return dp[str1_last_idx][str2_last_index];
    }

    if(str1[str1_last_idx] == str2[str2_last_index]){
        dp[str1_last_idx][str2_last_index] = longest_common_subsequence(str1, str2, str1_last_idx - 1, str2_last_index -1, dp) + 1;
        return dp[str1_last_idx][str2_last_index];
    } else {
        // Decrementing the Index of first String
        int ans1 = longest_common_subsequence(str1, str2, str1_last_idx - 1, str2_last_index, dp);
        // Decrementing The Index of Second String
        int ans2 = longest_common_subsequence(str1, str2, str1_last_idx, str2_last_index - 1, dp);
        // Returning Max 
        dp[str1_last_idx][str2_last_index] = max(ans1, ans2);
        return dp[str1_last_idx][str2_last_index];
    }
}


 /**
  * Tabulation
  */