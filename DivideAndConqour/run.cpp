#include <iostream>
#include <string>
using namespace std;

int MijorityElement(int *arr , int low , int high){
    if(low >= high){
        return 0;
    }
    int mid = (low + high)/2;
    MijorityElement(arr , low , mid);
    MijorityElement(arr , mid + 1 , high);
}

int main(void){
    int arr[5] = {2,4,1,3,5};
    cout<<MijorityElement(arr, 0 , 2);
}