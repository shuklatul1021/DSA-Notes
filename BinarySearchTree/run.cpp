#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

class BinarySearchTree {
public:
  Node *root;

  BinarySearchTree() { root = NULL; }

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

  Node *mirror_bst(Node *root){
    if(root == NULL){
      return NULL;
    }

    Node *left_mirror = mirror_bst(root->left);
    Node *right_mirror = mirror_bst(root->right);
    root->left = right_mirror;
    root->right = left_mirror;

    return root;
  } 
};

int main() {
  BinarySearchTree bst_tree;
  vector<int> bst_array = {8, 5, 3, 6, 10, 11, 14};
  vector<int> path_array;
  Node *root = NULL;
  int n = bst_array.size();
  for (int i = 0; i < n ; i++) {
    root = bst_tree.BuildBSTTree(root, bst_array[i]);
  }
}
