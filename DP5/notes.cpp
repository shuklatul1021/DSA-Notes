/**
 * Wildcard matching with support for '?' and '*'.
 * '?' matches any single character.
 * Ex : "?" matches "a", "b", "c", etc.
 * '*' matches any sequence of characters (including the empty sequence).
 * Ex : "*" matches "", "a", "ab", "abc", etc.
*/
#include <iostream>
#include <vector>
using namespace std;

bool wildcard_machine(string str, string pattern, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
    dp[0][0] = true;
    for(int i = 1; i < n + 1; i++){
        dp[i][0] = false;
    }
 
    for(int j = 1; j < m + 1; j++){
        if(pattern[j-1] == '*'){
            dp[0][j] = dp[0][j-1];
        } else {
            dp[0][j] = false;
        }
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if(pattern[j-1] == str[i-1] || pattern[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            } else if(pattern[j-1] == '*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

int main() {
    string str = "abcde";
    string pattern = "a*b?c";
    if(wildcard_machine(str, pattern , str.length(), pattern.length())) {
        cout << "Pattern matches the string." << endl;
    } else {
        cout << "Pattern does not match the string." << endl;
    }
}

/**
 * Catalan's Number (10-15) Problem Came Up
 * Ex : 
 * C(0) = 1, 
 * C(1) = 1, 
 * C(2) = C(0)C(1) + C(1)C(0) = 2, 
 * C(3) = 5
 * 
 * FORMULA
 * C(n) = C(0)C(n-1) + C(1)C(n-2) + C(2)C(n-3) + ... + C(n-1)C(0)
 */


 // Recursion
#include <iostream>
#include <vector>
using namespace std;

int catalan_number_rec(int n) {
    if (n <= 1) {
        return 1;
    }
    /**
     * 
     */
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += catalan_number_rec(i) * catalan_number_rec(n - i - 1);
    }
    return result;
}

int main() {
    int result = catalan_number_rec(5);
    cout << "Catalan Number for n=5: " << result << endl;
    return 0;
}

// Recursion + Memoization
int catalan_number_rec_mem(int n, vector<int> &km) {
    if (n <= 1) {
        return 1;
    }
    if(km[n] != -1){
        return km[n];    
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += catalan_number_rec_mem(i, km) * catalan_number_rec_mem(n - i - 1, km);
    }
    km[n] = result;
    return result;
}

int main() {
    vector<int> catalan_memoization(30, -1);
    int result = catalan_number_rec_mem(30, catalan_memoization);
    cout << "Catalan Number for n=5: " << result << endl;
    return 0;
}

// Tabulation
int catalan_number_rec_tab(int n) {
    vector<int> catalan_memoization(n+1, 0);
    
    catalan_memoization[0] = 1;
    catalan_memoization[1] = 1;

    for(int i = 2; i <= n ; i++){
        for(int j = 0; j < i; j++){
            catalan_memoization[i] += catalan_memoization[j] * catalan_memoization[i-j-1];
        }
    }
    for(int i = 0; i <= n ; i++){
        cout<<catalan_memoization[i]<<" ";
    }cout<<endl;
    return catalan_memoization[n];
}

int main() {
    int result = catalan_number_rec_tab(4);
    cout << "Catalan Number for n=5: " << result << endl;
    return 0;
}


// Counting Trees
/**
 * Find Number Of All possible BST With Given N Nodes
*/ 

int counting_bst_tree(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n ; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    for(int i = 0; i <= n ; i++){
        cout<< dp[i] <<" ";
    }cout<<endl;
    return dp[n];
}

int main() {
    int result = counting_bst_tree(4);
    cout << "BST Count For n=5: " << result << endl;
    return 0;
}


/**
 * Mountain Range Problem
 * 
 * Mountains And Valleys Problem
 * at ant moment the number of down strokes should not exceed the number of up strokes
 * 
 * For Example :
 * For n=3, the valid sequences are:
 * 
 *                               /\
 *                /\            /  \            /\          /\/\
 * /\/\/\        /  \/\        /    \        /\/  \        /    \
 *   1             2              3              4           5 
 */

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