#include <iostream>
#include <string>
using namespace std;

int MajorityElement(int *arr, int low, int high)
{
    if (low >= high)
    {
        return 0;
    }
    int mid = (low + high) / 2;
    MajorityElement(arr, low, mid);
    MajorityElement(arr, mid + 1, high);
}

int main(void)
{
    int arr[5] = {2, 4, 1, 3, 5};
    cout << MajorityElement(arr, 0, 2);
}