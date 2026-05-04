#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Sliding Window Maximum
 * Detail About Problem:
 *   Maximum of all subarrays of size k.
 *   Input: arr[] = {1, 3, -1, -3, 5, 3, 6, 7}, k = 3
 *   Output: 3 3 5 5 6 7
 *  -- Brute Force
 *          vector<int> sample_vector = {1, 3, -1, -3, 5, 3, 6, 7};
            vector <int> result_vector;
            int k = 3;
            for(int i = 0 ; i < sample_vector.size(); i++){
                int first = sample_vector[i];
                int second = sample_vector[i+1];
                int third = sample_vector[i+2];
                int max_val = max(first , max(second, third));
                result_vector.push_back(max_val);
            }

            for(int i = 0; i < result_vector.size(); i++){
                cout<<result_vector[i]<<" ";
            }cout<<endl;
*/

class Pair
{
public:
    int val;
    int idx;
    Pair(int val, int idx)
    {
        this->val = val;
        this->idx = idx;
    }

    bool operator<(const Pair &c) const
    {
        return this->val < c.val;
    }
};

int main()
{
    /**
     * Max Size Of Resultant Array Size:
     * (n - k + 1)
     * Where:
     *  n = size of Given Array
     *  k = Window Size
     */
    /**
     * Algo Step:
     *  1. add k nums to pq
     *  2.   a-> pq.peek() -> wind[0];
     *       b-> while(pq.top().idx <= (i-k)){
     *               pq.pop();
     *           }
     *           pq.add(curr);
     *           wind[] = pq.peek();
     */

    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    priority_queue<Pair> pq;
    int n = arr.size();
    vector<int> result(n - k + 1);
    for (int i = 0; i < k; i++)
    {
        Pair curr_pair(arr[i], i);
        pq.push(curr_pair);
    }

    result[0] = pq.top().val;
    for (int i = k; i < n; i++)
    {
        while (pq.top().idx <= (i - k))
        {
            pq.pop();
        }
        Pair curr_pair(arr[i], i);
        pq.push(curr_pair);
        result[i - k + 1] = pq.top().val;
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}