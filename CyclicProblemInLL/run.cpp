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

    void AddCycle(){
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = head;
    }

    //Floyd Cycle Finding 
    bool CycleDetection(){
        Node *slow = head;
        Node *fast = head;
        int i = 0;
        while (slow->next != NULL && fast->next != NULL)
        {

            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
            i++;
        }
        return false;     
    }

    void RemoveCycle(){
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
              break;
            }
        }   

        slow = head;
        while (slow != fast)
        {  
            slow = slow->next;
            fast = fast->next;
        }
        
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
    }

};

int main(void){
    LinkedList L1;
    int size = 0;
    L1.InsertLinkedList(20);
    L1.InsertLinkedList(10);
    L1.InsertLinkedList(30);
    L1.InsertLinkedList(50);
    L1.InsertLinkedList(40);
}

