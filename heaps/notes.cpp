//                         Heaps/Priority Queue Notes
//                         ------------------------------
// Heaps Is Also Known As Priority Queue
/**
 * Priority Queue :
 * A priority queue is an abstract data type that operates similarly to a regular queue or stack data structure, but where each element has a "priority" associated with it.
 * In a priority queue, an element with high priority is served before an element with low priority. If two elements have the same priority, they are served according to their order in the queue.
 */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    /**
     * Queue Structure
     *  [10, 20, 30]
     */
    /**
     * Insertion In Max Heap : O(log n)
     * Deletion In Max Heap : O(log n)
     * Accessing Top Element In Max Heap : O(1)
     */
    // Ascending Order Max Heap
    priority_queue<int> max_heap;
    max_heap.push(10);
    max_heap.push(30);
    max_heap.push(20);
    cout << "Top Element Of The Max Heap : " << max_heap.top() << endl;
    max_heap.pop();
    cout << "Top Element Of The Max Heap : " << max_heap.top() << endl;
    // Descending Order Max Heap
    priority_queue<int, vector<int>, greater<int>> max_heap2;
    max_heap2.push(10);
    max_heap2.push(30);
    max_heap2.push(20);
    cout << "Top Element Of The Max Heap : " << max_heap2.top() << endl;
    max_heap2.pop();
    cout << "Top Element Of The Max Heap : " << max_heap2.top() << endl;
}

//                              Heap
/**
 * CBT : Complete Binary Tree
 *        10
 *       /  \
 *      20   30
 *      Complete Binary Tree Is A Binary Tree In Which Every Level, Except Possibly The Last, Is Completely Filled, And All Nodes Are As Far Left As Possible.
 * Heap Is A Complete Binary Tree Which Satisfies The Heap Property
 * Max Heap : A Binary Tree In Which Every Node Is Greater Than Or Equal To Its Children
 *              Children >= Parent
 * Min Heap : A Binary Tree In Which Every Node Is Less Than Or Equal To Its Children
 *              Children <= Parent
 */
/**
 * IMPORTANT NOTE :
 * Why Heap Is Not Implemented Using Class And Object?
 * Ans : Because Heap Is A Data Structure Which Is Used To Implement Priority Queue And It Is Used In Many Algorithms Like Dijkstra's Algorithm, Prim's Algorithm, Huffman Coding, etc. And It Is Not A Data Structure Which Is Used To Store Data Like Linked List, Stack, Queue, etc. So It Is Not Implemented Using Class And Object.
 *          It Is Implemented Using Array Because It Is A Complete Binary Tree And It Can Be Easily Represented Using Array. And It Is Also Easy To Implement The Heap Operations Like Insertion, Deletion, etc. Using Array.
 *          It Is Also Used To Implement The Heap Sort Algorithm Which Is A Comparison Based Sorting Algorithm And It Is Not A Stable Sorting Algorithm. And It Is Also Used To Implement The Priority Queue Data Structure Which Is Used In Many Algorithms Like Dijkstra's Algorithm, Prim's Algorithm, Huffman Coding, etc.
 */

/**
 * Heap As an ArrayList
 *          2
 *        /   \
 *      3       4
 *    /   \
 *   5       6
 *
 * Array Representation Of The Above Heap : [2, 3, 4, 5, 6]
 *
 * Property Of The Heap :
 *        (node) idx = i
 *        left child idx = 2*i + 1
 *        right child idx = 2*i + 2
 *
 * Last Position Of The Non-Leaf Node : (n/2) - 1
 */
/**
 * Insertion In Heap
 *        2                     arr = [2, 3, 4, 5, 10]
 *      /   \
 *    3       4
 *   /  \
 *  5    10
 *
 * Assuming Inserted Element Is  : 1
 * Step 1 : Insert The Element At The End Of The Heap
 *           arr = [2, 3, 4, 5, 10, 1]
 *
 * Step 2 : Compare The Inserted Element With Its Parent And Swap If The Inserted Element Is Greater Than Its Parent (For Max Heap) Or Less Than Its Parent (For Min Heap)
 *          arr = [2, 3, 4, 5, 10, 1] -> Compare 1 With Its Parent 4 -> Swap -> arr = [2, 3, 1, 5, 10, 4] -> Compare 1 With Its Parent 3 -> Swap -> arr = [2, 1, 3, 5, 10, 4] -> Compare 1 With Its Parent 2 -> Swap -> arr = [1, 2, 3, 5, 10, 4]
 *          Find The Parent Index : (i-1)/2
 *          And Compare And If Smaller Than Parent Then Swap
 *
 */
// Insertion in Heap
void insert_heap(vector<int> &heap_array, int insert)
{
    int position = heap_array.size() - 1;
    int parent_index = (position - 1) / 2;
    while (heap_array[position] < heap_array[parent_index])
    {
        swap(heap_array[position], heap_array[parent_index]);
    }
}

// Get Min In Heap
int min_heap(vector<int> &heap_array)
{
    return heap_array[0];
}

/**
 * Heapify
 *
 */
void Heapify(int i, vector<int> &heap_array)
{
    // Heapify Function
    /**
     * root = i
     * left = 2 * i + 1
     * right = 2 * i + 2
     * min(root, left, right) = smallest
     * if smallest != root then swap and heapify the smallest index
     * Time Complexity : O(log n) because in worst case we have to heapify the entire height of the heap which is log n
     * Space Complexity : O(1) because we are not using any extra space
     */
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int minidx = i;
    if (left < heap_array.size() && heap_array[minidx] > heap_array[right])
    {
        minidx = right;
    }

    if (minidx != i)
    {
        swap(heap_array[i], heap_array[minidx]);
    }
}

void delete_heap(vector<int> &heap_array)
{
    //  three-step process
    // First and last node swap
    int n = heap_array.size() - 1;
    swap(heap_array[0], heap_array[n]);
    // Second Remove Last Index
    heap_array.pop_back();
    // Heapify Function
    Heapify(0, heap_array);
}

// Heap Sort
#include <iostream>
#include <vector>
using namespace std;

void Heapify(int i, vector<int> &heap_array, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxidx = i;
    if (left < n && heap_array[left] > heap_array[maxidx])
    {
        maxidx = left;
    }

    if (right < n && heap_array[right] > heap_array[maxidx])
    {
        maxidx = right;
    }

    if (maxidx != i)
    {
        swap(heap_array[i], heap_array[maxidx]);
        Heapify(maxidx, heap_array, n);
    }
}

void heap_sort(vector<int> &arr_vec)
{
    /**
     * For Ascending Order Max Heap
     *  For Descending Order Min Heap
     * Getting Non leaf Node
     *                  1
     *                /   \
     *               2     4
     *             /   \
     *            5     3
     * Non-Leaf Node = [2 , 1];
     */
    // Step 1 : Convert Array To Build Max heap
    int n = arr_vec.size();
    for (int i = n / 2; i >= 0; i--)
    {
        Heapify(i, arr_vec, n);
    }
    // Step 2 : Push Largest At end
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr_vec[0], arr_vec[i]);
        Heapify(0, arr_vec, i);
    }
}

// Nearby cars
class Points
{
public:
    int x;
    int y;
    int dist_sqrt;
    int index;
    Points(int u_x, int u_y, int u_index)
    {
        this->x = u_x;
        this->y = u_y;
        this->dist_sqrt = (u_x * u_x) + (u_y * u_y);
        this->index = u_index;
    }

    bool operator<(const Points &p) const
    {
        return this->dist_sqrt < p.dist_sqrt;
    }
};

int main()
{
    vector<vector<int>> pts = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;
    priority_queue<Points> point_pts;
    for (int i = 0; i < pts.size(); i++)
    {
        Points p(pts[i][0], pts[i][1], i);
        point_pts.push(p);
    }

    for (int i = 0; i < k; i++)
    {
        Points p = point_pts.top();
        cout << "Point " << p.index << " : (" << p.x << ", " << p.y << ")" << endl;
        point_pts.pop();
    }
}

// Connect N Ropes With Minimum Cost
class Cost
{
public:
    int cost;
    Cost(int u_cost)
    {
        this->cost = u_cost;
    }

    bool operator<(const Cost &c) const
    {
        return this->cost > c.cost;
    }
};

int main()
{
    vector<int> ropes = {2, 3, 3, 4, 6};

    priority_queue<Cost> pq;
    for (int i = 0; i < ropes.size(); i++)
    {
        Cost c(ropes[i]);
        pq.push(c);
    }

    int cost = 0;
    while (pq.size() > 1)
    {
        Cost min = pq.top();
        pq.pop();
        Cost max = pq.top();
        pq.pop();
        cost += min.cost + max.cost;
        pq.push(Cost(min.cost + max.cost));
    }

    cout << "Cost : " << cost << endl;
}

// Weakest Soldier
/**
 *
 * TODO
 */

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