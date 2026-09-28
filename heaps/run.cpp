#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    priority_queue<int> max_heap;
    max_heap.push(10);
    max_heap.push(30);
    max_heap.push(20);
    cout << "Top Element Of The Max Heap : " << max_heap.top() << endl;
    max_heap.pop();
    cout << "Top Element Of The Max Heap : " << max_heap.top() << endl;

    return 0;
}