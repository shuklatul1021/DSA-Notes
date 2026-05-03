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

class BinaryTree
{
public:
    Node *root;
    static int idx;
    static int tree_height;

    BinaryTree()
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
    //1 - build balance bst with given sorted array
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

    //2 : converting to the sorted array with using inorder
    void find_inorder(Node *root, vector<int>& inorder_vector){
        if(root == NULL){
            return;
        }
        find_inorder(root->left, inorder_vector);
        inorder_vector.push_back(root->data);
        find_inorder(root->right, inorder_vector);
    }

};

int BinaryTree::idx = -1;
int BinaryTree::tree_height = -1;

int main()
{
    BinaryTree tree;
    vector<int> tree_element =  {3, 5, 6, 8, 10, 11, 12};
   
}