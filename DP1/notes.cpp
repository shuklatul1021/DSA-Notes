//                                  Dynamic Programming 1
/**
 * Dynamic Programming Algorithum`
 * Time Complexcity : O(V.E)
 * Space Complexity : O(V)
 * Dynamic Programming is a method for solving complex problems by breaking them down into simpler subproblems. 
 * It is applicable when the problem can be divided into overlapping subproblems, which can be solved independently and stored for future reference.
 * The main idea is to avoid redundant calculations by storing the results of subproblems in a table (usually an array or a matrix) and reusing them when needed.
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * Memoization
 * It is a top-down approach where we solve the problem recursively and store the results of subproblems in a data structure (like an array or a hash table) to avoid redundant calculations.
 * 
 * How to identify DP
 * a-> optimal problem structure
 * b-> some choice is given(multiple branches)
 */
int fib(int n , vector<int> f){
    if(n == 0 || n == 1){
        return n;
    }

    if(f[n] != 0){
        return f[n];
    }
    
    f[n] =  fib((n - 1), f) + fib((n - 2), f);
    return f[n];
}

int main(){
    int n  = 6;
    vector<int> f(n+1, 0);
    int result = fib(n, f);
    cout<<result<<endl;
}

// Ways OF DP
/**
 * Memorization : Top-Down Approach
 *                Reccursive Approach
 *                subproblems are stored in a data structure (like an array or a hash table) to avoid redundant calculations.
 * 
 * Tabulation : Bottom-Up Approach
 *               Iterative Approach
*/
int fib_tab(int n){
    vector<int> dp_tab(n+1 , 0);
    dp_tab[0] = 0;
    dp_tab[1] = 1;
    for(int i=2; i<=n; i++){
        dp_tab[i] = dp_tab[i - 1] + dp_tab[i - 2];
    }
    return dp_tab[n];
}

/**
 * 7 Imp Qs
 * Fibonacci
 * 0-1 Knapsack
 * Unbounded Knapsack
 * LCS(Longest Common Subsequence)
 * Kadane's Alogorithum
 * Catalan Number
 * Dp and Grind(2d Array)
*/


/**
 * Climbing Stairs
 * Count ways to nth stair.
 * The Person Can Climb 1 or 2 stairs at a time.
 */
//Recurssion Approach
int climbing_stairs_ways(int n){
   if(n == 0){
    return 1;
   }
   if(n < 0){
    return 0;
   }

   return climbing_stairs_ways(n - 1) + climbing_stairs_ways(n - 2);
}

int main(){
    int n  = 5;
    vector<int> f(n+1, 0);
    int result = climbing_stairs_ways(n);
    cout<<result<<endl;
}

//      DP-Reccursion
int climbing_stairs_ways_dp(int n, vector<int> &f){
   if(n == 0){
    return 1;
   }
   if(n < 0){
    return 0;
   }

   if(f[n] != -1){
    return f[n];
   }

   f[n] = climbing_stairs_ways_dp((n - 1), f) + climbing_stairs_ways_dp((n - 2), f);
   return f[n];
}

int main(){
    int n  = 5;
    vector<int> f(n+1, -1);
    int result = climbing_stairs_ways_dp(n,f);
    cout<<result<<endl;
}

// Tabulation Approach
int climbing_stairs_ways_Tabulation(int n){
    vector<int> f(n + 1, 0);

    f[0] = 1;
    f[1] = 1;

    for(int i=2; i<=n; i++){
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

/**
 * Variation For Climing Stairs
 * You Allow To climb 1, 2, 3
*/

int climbing_stairs_ways_Tabulation(int n){
    vector<int> f(n + 1, 0);

    f[0] = 1;
    
    for(int i=1; i<=n; i++){
        int i1 = i - 1 >= 0 ? f[i - 1] : 0;
        int i2 = i - 2 >= 0 ? f[i - 2] : 0;
        int i3 = i - 3 >= 0 ? f[i - 3] : 0;
        f[i] = i1 + i2 + i3;
    }

    return f[n];
}

int main(){
    int n  = 4;
    vector<int> f(n+1, 0);
    int result = climbing_stairs_ways_Tabulation(n);
    cout<<result<<endl;
}



//                     