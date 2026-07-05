#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
/**
 * String conversion:
 *  Given Two String word1 and word2 , retun the minimum number of operation require to convert word1 to word2
 * you have following three opration permitted on a word 
 * 1 - insert a char
 * 2 - Delete a char
 */
int edit_distance(string s1, string s2 , int s1_len , int s2_len){
    vector<vector<int>> dp(s1_len + 1 , vector<int>(s2_len + 1 , 0));
    for(int i = 0; i < s1_len + 1; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j < s2_len + 1; j++){
        dp[0][j] = j;
    }
    for(int i = 1; i < s1_len + 1; i++){
        for(int j = 1; j < s2_len + 1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                int insert_op = dp[i][j-1];
                int delete_op = dp[i-1][j];
                dp[i][j] = min(insert_op, delete_op) + 1;
            }
        }
    }
    return dp[s1_len][s2_len];
    
}

int main() {
    string str1 = "intention";
    string str2 = "execution";
    int result = edit_distance(str1, str2 , str1.length(), str2.length());
    cout << "Minimum Edit Distance: " << result << endl;
}