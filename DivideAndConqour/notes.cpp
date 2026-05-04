//                  Divide And Conquer
// Merge Sort
#include <iostream>
using namespace std;

void Merge(int *arr, int low, int mid, int high)
{
    int an = mid - low + 1;
    int bn = high - mid;
    int A[an], B[bn];
    for (int i = 0; i < an; i++)
    {
        A[i] = arr[i + low];
    }
    for (int j = 0; j < bn; j++)
    {
        B[j] = arr[j + mid + 1];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i < an && j < bn)
    {
        if (A[i] < B[j])
        {
            arr[k++] = A[i++];
        }
        else
        {
            arr[k++] = B[j++];
        }
    }
    while (i < an)
    {
        arr[k++] = A[i++];
    }
    while (i < bn)
    {
        arr[k++] = B[j++];
    }
}

void MergeSort(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2; // l+(r-l)/2
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, r);
    Merge(arr, l, mid, r);
}

//          Quick Sort
int Pivot(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int pi = Pivot(arr, l, r);
    QuickSort(arr, l, pi - 1);
    QuickSort(arr, pi + 1, r);
}

//      Modified Binary Search
// Rotated Sorted Array With Distinct Ascending Order
int RotatedSortedArray(int *arr, int target, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    // To Find Out Mid ;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    // Lie In Line L1
    if (arr[left] <= arr[mid])
    {
        if (arr[left] <= target && target <= arr[mid])
        {
            return RotatedSortedArray(arr, target, left, mid);
        }
        else
        {
            return RotatedSortedArray(arr, target, mid + 1, right);
        }
    }
    // Lie In Line S2
    else
    {
        if (arr[mid] <= target && target <= arr[left])
        {
            return RotatedSortedArray(arr, target, mid + 1, right);
        }
        else
        {
            return RotatedSortedArray(arr, target, left, mid - 1);
        }
    }
}