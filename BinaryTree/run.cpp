#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
public:
    Node *root;
    static int idx;
    static int tree_height;

    BinaryTree(){
        root = NULL;
    }
    
    Node *build_tree(vector<int>& ele){
        idx++;
        if(ele[idx] == -1){
            return NULL;
        }
        Node *new_node = new Node(ele[idx]);
        new_node->left = build_tree(ele);
        new_node->right = build_tree(ele);

        return new_node;

    }

     void in_order_function(vector<int> &vec , Node* root){
        if(root == NULL){
            return;
        }
        in_order_function(vec , root->left);
        vec.push_back(root->data);
        in_order_function(vec , root->right);
    }

    vector<int> inorderTraversal(Node* root) {
        vector<int> result;
        in_order_function(result, root);
        return result;
    }

    

};

int BinaryTree::idx = -1;
int BinaryTree::tree_height = -1;

int main(){
    BinaryTree tree;
    vector<int> tree_element = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = tree.build_tree(tree_element);
    vector<int> in_order_result = tree.inorderTraversal(root);
    for(int i = 0; i < in_order_result.size(); i++){
        cout<<in_order_result[i]<<" ";
    }
}