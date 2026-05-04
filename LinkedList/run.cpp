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

    bool PalindromeLinkedList()
    {
        int size = 0;
        Node *itr = head;
        while (itr != NULL)
        {
            itr = itr->next;
            size += 1;
        }
        int half = (size / 2) - 1;

        int check_positioning = 0;
        Node *reverse_iterator = head;

        while (check_positioning < half)
        {
            reverse_iterator = reverse_iterator->next;
            check_positioning += 1;
        }

        Node *secondHalf = reverse_iterator->next;
        reverse_iterator->next = NULL;

        Node *prev = NULL;
        Node *curr = secondHalf;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        reverse_iterator->next = prev;

        Node *firstHalf = head;
        reverse_iterator = reverse_iterator->next;

        while (firstHalf->next != NULL && reverse_iterator->next != NULL)
        {
            if (firstHalf->data == reverse_iterator->data)
            {
                firstHalf = firstHalf->next;
                reverse_iterator = reverse_iterator->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main(void)
{
    LinkedList L1;
    L1.InsertLinkedList(10);
    L1.InsertLinkedList(20);
    L1.InsertLinkedList(30);
    L1.InsertLinkedList(30);
    L1.InsertLinkedList(20);
    L1.Display();
    cout << L1.PalindromeLinkedList() << endl;
}
