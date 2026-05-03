//                          Stack Notes

//Implementation Of Stack Using Arraylist
#include <iostream>
#include <vector>
using namespace std;

class Stack{
public:
    vector<int> arratlist;
    bool isEmpty(){
        return arratlist.size() == 0;
    }

    void push(int val){
        arratlist.push_back(val);
    }
    int pop(){
        int top = arratlist.at(arratlist.size() - 1);
        arratlist.pop_back();
        return top;
    }

    int top(){
        int top = arratlist.at(arratlist.size() - 1);
    }
};

int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();
    s1.push(40);
    while(!s1.isEmpty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
}


// Using Linked List
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class StackLinkedList{
public:
    Node *head;

    StackLinkedList(){
        head = NULL;
    }

    bool isEmpty(){
        return head == NULL;
    }
   
    void push(int val){
        Node *new_node = new Node(val);
        if(head == NULL){
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void pop(){
        Node *itr = head;
        while (itr->next->next != NULL)
        {
            itr = itr->next;
        }
        itr->next = NULL;
    }

    int peak(){
        Node *itr = head;
        int size = 0;
        while (itr != NULL)
        {
            size++;
            itr = itr->next;
        }
        return (size - 1); 
    }

    void display(){
        Node *itr = head;
        while(itr != NULL){
            cout<<itr->data<<"->";
            itr = itr->next;
        }cout<<"NULL"<<endl;
    }


};

int main(){
    StackLinkedList s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.pop();
    s1.display();
    cout<<s1.peak()<<endl;
    
}


// Build In Stack
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    s.push(10);
    s.push(20); 
    s.push(30);
    s.pop();
    
}


// Button Of Stack 
#include <iostream>
#include <stack>
using namespace std;

void pushtobutton(stack<int> &tem_stack, int data){
    if(tem_stack.empty()){
      tem_stack.push(data);
      return;  
    }

    int top = tem_stack.top();
    tem_stack.pop();
    pushtobutton(tem_stack , data);
    tem_stack.push(top);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20); 
    s.push(30);

    pushtobutton(s , 0);
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
}


// Reverse of Stack

#include <iostream>
#include <stack>
using namespace std;


int main(){
    stack<char> s;
    s.push('a');
    s.push('b'); 
    s.push('c');
    
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
}


// Reverse An Stack Without Using Any Extra Space 
void push_buttom(stack <char> &s , char data){
    if(s.empty()){
        s.push(data);
        return;
    }

    char top = s.top();
    s.pop();
    push_buttom(s , data);
    s.push(top);
}

void StringReverse(stack <char> &s){
    if(s.empty()){
        return;
    }
    char top = s.top();
    s.pop();
    StringReverse(s);
    push_buttom(s , top);
}

void PrintStack(stack <char> s){
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }cout<<endl;
}

int main(){
    stack<char> s;
    s.push('a');
    s.push('b'); 
    s.push('c');

    cout<<"Before Reverse"<<endl;
    PrintStack(s);
    
    StringReverse(s);
    
    cout<<"After Reverse"<<endl;
    PrintStack(s);   
}

// Stock Span Problem

void stock_span(vector <int> &stock , vector <int> &span){
    stack <int> s;
    span[0] = 1;
    s.push(0);

    for(int i = 1 ; i < stock.size() ; i++){
        int curr_price = stock[i];
        while(!s.empty() && curr_price > stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i] = i + 1;
        }else {
            int prevhigh = s.top();
            span[i] = i - prevhigh;
        }

        s.push(i);
    }
}

int main(){
    stack<int> s;
    vector<int> stock = {100 , 80 , 60 , 70 , 60 , 85 , 100};
    int stock_s = stock.size();
    vector<int> span(stock_s);
    stock_span(stock , span);

    for(int i = 0 ; i < stock_s ; i++){
        cout<<span[i]<<" ";
    }cout<<endl;
}


// Next Greater Element

int main(){
    vector<int> arr = {6 ,8 ,0 ,1 ,3};
    int n = arr.size() - 1;
    vector<int> next_arr(arr.size());
    stack<int> s;
   
    for(int i = n ; i >= 0 ; i--){
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }
        if(s.empty()){
            next_arr[i] = -1;
        }else{
            next_arr[i] = arr[s.top()];
        }
        
        s.push(i);
        
    }

    for(int i = 0 ; i < arr.size()  ; i++){
        cout<<next_arr[i]<<" ";
    }cout<<endl;
  
}


//Valid Parenthesis
bool check_valid_parenthese(string str){
    stack<char> q;
    int n = str.length();

    for(int i = 0 ; i < n ; i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            q.push(str[i]);
        }else{
            if(q.empty()){
                return false;
            }
            int top = q.top();
            if((top == '{' && str[i] == '}') || (top == '(' && str[i] == ')') || (top == '[' && str[i] == ']')){
                q.pop();
            } else {
                return false;
            }
        }
    }

    if(q.empty()){
        return true;
    }else {
        return false;
    }
}

int main(){
    string sample_string = "{{[(]}}";
    if(!check_valid_parenthese(sample_string)){
        cout<<"Not Valid"<<endl;
    }else {
        cout<<"Valid"<<endl;
    }
}

// Duplicate Parenthesis

bool is_oprator(char oper){
    if(oper == '+' || oper == '-' || oper == '/' || oper == '%'){
        return true;
    }
    return false;
}

//Revisit This Question 
bool check_duplicate_parenthese(string str){
    stack<char> q;
    int n = str.length();

    for(int i = 0 ; i < n ; i++){
       if(str[i] == '(' || str[i] == '{' || str[i] == '[' || is_oprator(str[i]) || isdigit(str[i])){
        q.push(str[i]);
       }else{
        int count = 0;
        int top = q.top();
        while (!q.empty() && top != ')')
        {
            if((top == '(' && str[i] == ')') || (top == '{' && str[i] == '}') || (top == '[' && str[i] == ']')){
                if(count < 1){
                    return true;
                }
            }else{
                q.pop();
                count++;
            }
        }
        
       }
    }

}

int main(){
    string sample_string = "{{[(]}}";
    if(!check_duplicate_parenthese(sample_string)){
        cout<<"Not Valid"<<endl;
    }else {
        cout<<"Valid"<<endl;
    }
}