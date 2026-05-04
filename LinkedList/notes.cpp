//                          Initializing A Linked List
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void InsertLinkedList(int data)
    {
        Node *New_Node = new Node(data);
        if (head == NULL)
        {
            head = New_Node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = New_Node;
    }

    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(void)
{
    LinkedList L1;
    L1.InsertLinkedList(10);
    L1.InsertLinkedList(20);
    L1.InsertLinkedList(30);
    L1.InsertLinkedList(40);
    L1.Display();
}

//          Operation On The Linked List

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void InsertLinkedList(int data)
    {
        Node *New_Node = new Node(data);
        if (head == NULL)
        {
            head = New_Node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = New_Node;
    }

    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Insertion
    void InsertHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void InsertingAtTail(int val)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    void InsertingKPosition(int val, int k)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        int count = 1;
        while (count != k)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Deletion
    void DeletionAtHead()
    {
        Node *temp = head;
        head = temp->next;
    }

    void DeletionAtTail()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void DeletionKPosition(int pos)
    {
        Node *prev = head;
        int currPos = 1;
        while (currPos != pos)
        {
            prev = prev->next;
            currPos++;
        }
        Node *temp = prev->next;
        prev->next = prev->next->next;
        free(temp);
    }
};

// Reverse Linked List
void ReverseLinkedList()
{
    Node *prv = NULL;
    Node *curr = head;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prv;
        prv = curr;
        curr = next;
    }
    head = prv;
}

// Remove Nth Node From Back End
void FindAndRemoveNthNodeLinkedList(int n)
{
    int size = 1;
    Node *itr = head;
    Node *position = head;
    while (itr->next != NULL)
    {
        itr = itr->next;
        size += 1;
    }
    int front_position = size - n + 1;
    int counter = 0;

    cout << "Counter " << counter << endl;
    cout << "Front Position " << front_position - 1 << endl;

    if (front_position - 1 == counter)
    {
        head = head->next;
        return;
    }

    while (counter != front_position - 2)
    {
        position = position->next;
        counter++;
    }
    Node *temp = position->next;
    position->next = position->next->next;
    free(temp);
}
