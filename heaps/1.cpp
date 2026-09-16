#include <iostream>
#include <vector>
using namespace std;

class Heap {  
public:
    vector<int> arr;
    Heap(){
    }

    void add(int data){
        arr.push_back(data);

        int postion = arr.size() - 1;
        int parentIndex = (postion - 1) / 2;
        cout << postion << " " << parentIndex << endl;
        while(arr[postion] < arr[parentIndex]){
            swap(arr[postion], arr[parentIndex]);

            postion = parentIndex;
            parentIndex = (postion - 1) / 2;
        }
    
    }

    int getTop(){
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }cout << endl;
        return arr[0];
    }
};

int main(){
    Heap h;
    h.add(2);
    h.add(3);
    h.add(4);
    h.add(5);
    h.add(10);
    cout << "After Insertion of the 1 " << endl;
    h.add(1);
    cout << h.getTop() << endl;

}