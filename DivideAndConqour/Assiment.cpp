//Sort The Sring Array In The Accending Order
#include <iostream>
using namespace std;

void Merge(string *arr, int low , int mid , int high){
    int an = mid-low+1;
    int bn = high - mid ;
    string A[an] , B[bn];

    for(int i=0; i<an; i++){
        A[i] = arr[i+low];
    }
    for(int j=0; j<bn; j++){
        B[j] = arr[j+mid+1];
    }
    int i=0 , j = 0 , k = low;
    while(i<an && j<bn){
        if(min(A[i] , B[j]) == A[i]){
            arr[k++] = A[i++];
        }else{
            arr[k++] = B[j++];
        }
    }
    while(i<an){
        arr[k++] = A[i++];   
    }
    while(i<bn){
        arr[k++] = B[j++];
    }
}

void AlphabateMergeSort(string *arr ,int left , int right ){
    if(left >= right){
        return;
    }
    int mid = (left + right)/2;
    AlphabateMergeSort(arr, left , mid);
    AlphabateMergeSort(arr, mid + 1 , right);
    Merge(arr , left , mid , right);
}

int main(void){
    string arr[4] = {"sun" , "earth" , "mars" , "mercury"};
    AlphabateMergeSort(arr , 0 , 3);
    for(int i=0; i<4; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

//Mijority Element 
//Not Completed
int MijorityElement(int *arr , int low , int high){
    if(low >= high){
        return 0;
    }
    int mid = (low + high)/2;
    MijorityElement(arr , low , mid);
    MijorityElement(arr , mid + 1 , high);
}

int main(void){
    int arr[3] = {3,2,3};
    cout<<MijorityElement(arr, 0 , 2);
}
