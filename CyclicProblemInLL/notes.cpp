#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = NULL;
    }
};


class LinkedList{
public:
    Node *head;
    LinkedList(){
        head = NULL;
    }

    void InsertLinkedList(int data){
        Node *New_Node = new Node(data);
        if(head == NULL){
            head = New_Node;
            return;
        }
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = New_Node;
    }

    void Display(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }cout<<"NULL"<<endl;
    }

    int size;
    int LLSize(){
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        size = count;
    }

    void Merge(int ){

    }


    void Merge_Sort(int low , int high){
        if(){
            //Edge Case
        }
        int mid = (low + high)/2;
        Merge_Sort(low , mid);
        Merge_Sort(mid+1 , high);
        Merge();
    }
};

int main(void){
    LinkedList L1;
    L1.InsertLinkedList(10);
    L1.InsertLinkedList(20);
    L1.InsertLinkedList(30);
    L1.AddCycle();
    cout<<L1.CycleDetection()<<endl;
    L1.RemoveCycle();
    L1.Display();
}

