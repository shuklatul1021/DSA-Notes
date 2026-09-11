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



};

int main() {
  BinarySearchTree bst_tree;
  vector<int> bst_array = {8, 5, 3, 6, 10, 11, 14};
  
  
}