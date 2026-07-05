#include <iostream>
#include <vector>
#include <string>
using namespace std;

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


int main() {
    string str1 = "abcde";
    string str2 = "ace";
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, -1));
    int result = longest_common_subsequence(str1, str2, str1.length(), str2.length(), dp);
    cout<<"Result : "<<result<<endl;
    return 0;
}
