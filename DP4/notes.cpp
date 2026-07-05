/**
 * Longest Common Subsequence (LCS) problem is a classic computer science problem that involves finding the longest subsequence common to two sequences. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. The LCS problem has applications in various fields such as bioinformatics, text comparison, and version control systems.
 * Example:
 *  str1 = "abcd", str2 = "ace"
 * ans = 3 (The longest common subsequence is "ace")
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print_dp(vector<vector<int>>& dp){
    for(int i = 0; i < dp.size(); i++){
        for(int j=0; j < dp[0].size(); j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

int longest_common_substring(string s1, string s2, int s1_len , int s2_len){
    vector<vector<int>> dp(s1_len + 1 , vector<int>(s2_len + 1 , 0));
    int ans = 0;
    for(int i = 1; i < s1_len + 1; i++){
        for(int j = 1; j < s2_len + 1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    print_dp(dp);
    return ans;

}

int main() {
    string str1 = "ABCDE";
    string str2 = "ABGCE";
    int result = longest_common_substring(str1, str2, str1.length(), str2.length());
    cout << "Length of LCS: " << result << endl;
}


/**
 * Longest Increasing Subsequence
 * Ex : 
 * arr = {50, 10, 7, 40 , 80};
 * lis = 4;
 */
int longest_increasing_subsequence(vector<int> &arr, vector<int> &sorted_array, int n, int m){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1 , 0));
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if(arr[i-1] == sorted_array[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                int ans1 = dp[i-1][j];
                int ans2 = dp[i][j-1];
                dp[i][j] = max(ans1, ans2);
            }
        }
    }

    return dp[n][m];
}

int main() {
    vector<int> arr = {50, 3, 10, 7, 40, 80};
    vector<int> sorted_arr(arr);
    sort(sorted_arr.begin(), sorted_arr.end());
    /**
     * One More thing to add an hashset which will remove all the duplicate value 
     */
    int result = longest_increasing_subsequence(arr, sorted_arr, arr.size(), sorted_arr.size());
    cout << "Length of LIS: " << result << endl;
}

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