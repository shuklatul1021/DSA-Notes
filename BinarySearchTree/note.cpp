//              Binary Search Tree
/*
 * Binary Search Tree Is simply Binary Tree But With The criteria
 *      a. Left Subtree Node < Root
 *      b. Right Subtree Nodes > Root
 *      c. Left and Right Subtree are also BST with no duplicate
 **/
/*
 * Special Property of BST
 * Inorder Traversal of BST given a sorted Sequence
 *
 */

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

  // Build The Binary Search Tree
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

  void inOrder(Node *root) {
    if (root == NULL) {
      return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }

  // Search A Element In The BST
  bool searchElement(Node *root, int key) {
    if (root == NULL) {
      return false;
    }
    if (root->data == key) {
      return true;
    }

    if (root->data > key) {
      return searchElement(root->left, key);
    }

    if (root->data < key) {
      return searchElement(root->right, key);
    }

    return false;
  }

  // Delete Element From Tree
   Node *find_inorder_successor(Node *right_node){
    while(right_node->left != NULL){
      right_node = right_node->left;
    }

    return right_node;
  }

  Node *delete_node(Node *root, int data){
    if(root == NULL){
      return NULL;
    }
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } 
    else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else{
      // Checking All The cases
      // Case 1 : Leaf Node 
      if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
      }

      // Case 2 - single child
      if(root->left == NULL){
        Node *temp = root->right;
        delete root;
        return temp;
      }else if(root->right == NULL){
         Node *temp = root->left;
        delete root;
        return temp;
      }

      //Case 3 - Both Children
      // Find Closest Inorder Successor
      Node *is = find_inorder_successor(root->right);
      root->data = is->data;
      root->right = delete_node(root->right, is->data);
    }

    return root;
  }

  // Print In range
  void print_range(Node *tree, int k1,  int k2){
    if(tree == NULL){
      return;
    }

    if(tree->data >= k1 && tree->data <= k2){
      cout<<tree->data<<" ";
    }
    print_range(tree->left , k1, k2);
    print_range(tree->right , k1, k2);
  }

  // Print Path Root To Leaf
  void print_path(vector<int>& path){
    for(int i = 0 ; i < path.size(); i++){
      cout<<path[i]<<"->";
    }cout<<endl;
  }

  void root_to_leaf_path(Node *root, vector<int>& path_array){
    if(root == NULL){
      return;
    }

    path_array.push_back(root->data);
    if(root->left == NULL && root->right == NULL){
      print_path(path_array);
    }
    root_to_leaf_path(root->left, path_array);
    root_to_leaf_path(root->right, path_array);
    path_array.pop_back();
  }

  // Validate BST
    /**
   * Approch To Find The Valid BST
   * 1 -> Inorder Traversal : if the inorder traversal is sorted then it is valid bst    
   * 2-> Inorder Predecessor and inorder successer: 
   *              Condition : check if max value in left subtree < node and min in right subtree > node
  */
  bool is_valid_bst(Node *root, Node *min , Node *max){
    if(root == NULL){
      return true;
    }
    if(min != NULL && root->data <= min->data){
      return false;
    }

    else if(max != NULL && root->data >= max->data){
      return false;
    }

    return is_valid_bst(root->left , min, root) && is_valid_bst(root->right , root, max);

  }

  // Mirror Of An BST
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
  vector<int> bst_array = {5, 1, 3, 4, 2, 7};
  Node *root = NULL;

  for (int i = 0; i < bst_array.size(); i++) {
    root = bst_tree.BuildBSTTree(root, bst_array[i]);
  }

  bst_tree.inOrder(root);
  cout << endl;

  if (!bst_tree.searchElement(root, 10)) {
    cout << "Element Not Found" << endl;
  } else {
    cout << "Element Found" << endl;
  }
}
