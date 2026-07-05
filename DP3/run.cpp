#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_dp(vector<vector<int>>& dp){
    for(int i = 0; i < dp.size(); i++){
        for(int j=0; j < dp[0].size(); j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

int longest_common_subsequence_tabulation(string str1, string str2, int str1_last_idx, int str2_last_index){
    vector<vector<int>> dp(str1_last_idx + 1, vector<int>(str2_last_index + 1, 0));
    for(int i = 1; i < str1_last_idx + 1; i++){
        for(int j = 1; j < str2_last_index + 1; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    print_dp(dp);
    return dp[str1_last_idx][str2_last_index];
}


int main() {
    string str1 = "abcde";
    string str2 = "ace";
    int result = longest_common_subsequence_tabulation(str1, str2, str1.length(), str2.length());
    cout<<"Result : "<<result<<endl;
    return 0;
}