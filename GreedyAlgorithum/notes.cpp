//              Introduction To Greedy Algorithm
/**
 * Optimization -> min , max
 * No Fixed Rule
 * Not Realize
 *
 *** Greedy Algorithm Is the problem solving technique where we make the locally optimum choice at each stage and hope to achieve a global optimum
 */

// Activity Selection
#include <iostream>
#include <vector>
using namespace std;

/**
 * Point Observed
 * 1 - Make Sure End Time is Sorted
 * 2 - Select [A0](first activity Select)
 *      not - overlapping
 *      |
 *       ----->Start time >= last chosen Time
 *             cout++
 *
 */

int activity_selection(vector<int> &s, vector<int> &e)
{
    int activity_time = 1;
    int prev_activity = e[0];
    int n = s.size();
    vector<char> res(n);
    res.push_back('A' + 0);
    for (int i = 1; i < n; i++)
    {
        if (s[i] >= prev_activity)
        {
            prev_activity = e[i];
            activity_time++;
            res.push_back('A' + i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return activity_time;
}

/**
 * Dry Run
 * ->Initial Condition
 * activity_time = 1;
 * prev_activity = 20
 *
 * Iteration - 1
 * cmp(12 >= 20) false => not change
 *
 *  Iteration - 2
 * cmp(20 >= 20) true => change
 * activity_time = 2;
 * prev_activity = 30
 *
 * //End Of Loop
 */

int main()
{
    vector<int> start = {10, 12, 20};
    vector<int> end = {20, 25, 30};
    int result = activity_selection(start, end);
    cout << "The Answer Is : " << result << endl;
}

//                      Fractional Knapsack Problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/**
 * Fractional Knapsack Problem
 * Given The Weight and Values of the items and the capacity of the knapsack, find the maximum value that can be put in a knapsack of given capacity.
 * value[] = {60, 100, 120}
 * weight[] = {10, 20, 30}
 * capacity = 50
 * Output: 240
 */

int fraction_knapsack(vector<int> &val, vector<int> &wei, int cap)
{
    vector<vector<double>> ratio;
    int result;
    int n = val.size();
    for (int i = 0; i < n; i++)
    {
        ratio[i][0] = i;
        ratio[i][1] = val[i] / (double)wei[i];
    }
    sort(ratio.begin(), ratio.end());
    for (int i = ratio.size() - 1; i >= 0; i++)
    {
        int idx = (int)ratio[i][0];
        if (cap >= wei[idx])
        {
            result += val[idx];
            cap -= wei[idx];
        }
        else
        {
            result += (ratio[i][1] * cap);
            cap = 0;
            break;
        }
    }
    return result;
}

int main()
{
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    int result = fraction_knapsack(value, weight, capacity);
    cout << "Result : " << result << endl;
}

//      Minimum Absolute Difference Pair
/**
 * Min Absolute Difference Pair
 * Given two arrays A and B of size N and M respectively(both N and M are same size), find the pair (a, b) such that a belongs to A and b belongs to B and the absolute difference between a and b is minimum.
 * Input: A = {1, 3, 15, 11, 2} , B = {23, 127, 235, 19, 8}
 * Output: 3
 */

int min_abs_diff_pair(vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int result = 0;
    for (int i = 0; i < A.size(); i++)
    {
        result += abs(A[i] - B[i]);
    }
    return result;
}

int main()
{
    vector<int> A = {4, 1, 8, 7};
    vector<int> B = {2, 3, 6, 5};
    int result = min_abs_diff_pair(A, B);
    cout << "Minimum absolute difference: " << result << endl;
}

// Max Length Chain Of Pair
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/**
 * Max Length Chain Of Pair
 * You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
 * A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion.
 * Find the length of the longest chain which can be formed from a given set of pairs.
 * Input: pairs = [[5,24],[39,60],[15,28],[27,40],[50,90]]
 * Output: 3
 *
 */

int max_len_chain_pair(vector<pair<int, int>> &p)
{
    int result = 1;
    int n = p.size();
    sort(p.begin(), p.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right)
         { return left.second < right.second; });
    for (int i = 0; i < n; i++)
    {
        cout << "Pair" << i + 1 << "(" << p[i].first << "," << p[i].second << ")" << endl;
    }
    int last_selected = p[0].second;
    for (int i = 0; i < n; i++)
    {
        if (last_selected <= p[i].first)
        {
            result++;
            last_selected = p[i].second;
        }
        else
        {
            continue;
        }
    }
    return result;
}

int main()
{
    vector<pair<int, int>> pair = {{5, 24}, {39, 60}, {5, 28}, {27, 40}, {50, 90}};
    int result = max_len_chain_pair(pair);
    cout << "The Max Length Of N Pair Of Number Is : " << result << endl;
}

/**
 * Indian Coin Change Problem
 * You are given an infinite supply of coins of given denominations and a total amount of money.
 * Find the minimum number of coins required to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 *
 */

int ind_coins(vector<int> &p, int v)
{
    int result = 0;
    sort(p.begin(), p.end(), greater<int>());
    int n = p.size();
    int volume = v;
    for (int i = 0; i < n; i++)
    {
        if (p[i] <= volume)
        {
            while (p[i] <= volume)
            {
                result++;
                volume -= p[i];
            }
        }
    }
    return result;
}

int main()
{
    vector<int> ind_curr = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int val = 590;
    int result = ind_coins(ind_curr, val);
    cout << "The Min Number : " << result << endl;
}

//                  Job Scheduling Problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/**
 * Job Scheduling Problem
 * Given a set of N jobs where each job i has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.
 * Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
 * Output: 2 60
 */

class Job
{
public:
    char Id;
    int deadline;
    int profit;
    Job(char i, int d, int p)
    {
        this->Id = i;
        this->deadline = d;
        this->profit = p;
    }
};
// Still Need to fix it
void job_scheduling(vector<pair<int, int>> &job)
{
    int n = job.size();
    vector<Job> temp_entry;
    for (int i = 0; i < n; i++)
    {
        Job j((char)(i + 65), job[i].first, job[i].second);
        temp_entry.push_back(j);
    }

    sort(job.begin(), job.end(), [](const pair<int, int> &left, const pair<int, int> &right)
         { return left.second < right.second; });
    vector<char> ans;
    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (job[i].first < time)
        {
            time++;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<pair<int, int>> job_sch = {{4, 20}, {1, 10}, {1, 40}, {1, 30}};
    job_scheduling(job_sch);
}