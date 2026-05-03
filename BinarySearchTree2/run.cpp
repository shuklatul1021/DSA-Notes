#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class BinarySearchTree
{
public:
    Node *root;
    BinarySearchTree()
    {
        root = NULL;
    }

    Node *BuildBSTTree(Node *root, int val) {
        Node *new_tree_node = new Node(val);
        if (root == NULL) {
        root = new_tree_node;
        return root;
        }

        if (root->data > val) {
        root->left = BuildBSTTree(root->left, val);
        }

        if (root->data < val) {
        root->right = BuildBSTTree(root->right, val);
        }

        return root;
    }

    Node *bst_to_balanced_bst(vector<int>& inorder_data, int str, int end){
        if(str > end){
            return NULL;
        }

        int mid = (str + end) / 2;
        Node *new_node = new Node(inorder_data[mid]);
        root->left = bst_to_balanced_bst(inorder_data, str, mid - 1);
        root->left = bst_to_balanced_bst(inorder_data, mid + 1 , end);
        return new_node;
    }

    void find_inorder(Node *root, vector<int>& inorder_vector){
        if(root == NULL){
            return;
        }
        find_inorder(root->left, inorder_vector);
        inorder_vector.push_back(root->data);
        find_inorder(root->right, inorder_vector);
    }
};

int main() {
  BinarySearchTree bst_tree;
  vector<int> bst_array = {8, 5, 3, 6, 10, 11, 14};
  vector<int> inorder_array;
  Node *root = NULL;
  int n = bst_array.size();
  for (int i = 0; i < n ; i++) {
    root = bst_tree.BuildBSTTree(root, bst_array[i]);
  }
  bst_tree.find_inorder(root, inorder_array);
  for(int i = 0 ; i< inorder_array.size() ; i++){
    cout<<inorder_array[i]<<" ";
  }cout<<endl;
  
}