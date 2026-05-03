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

    Node *build_tree(vector<int> &ele)
    {
        idx++;
        if (ele[idx] == -1)
        {
            return NULL;
        }
        Node *new_node = new Node(ele[idx]);
        new_node->left = build_tree(ele);
        new_node->right = build_tree(ele);

        return new_node;
    }

    int sum_tree(Node *root){
        if(root == NULL){
            return 0;
        }

        int left_subtree_sum = sum_tree(root->left);
        int right_subtree_sum = sum_tree(root->right);

        int data = root->data;
        root->data = root->left->data + left_subtree_sum + root->right->data + right_subtree_sum;
        return data;
    }
};

int BinaryTree::idx = -1;
int BinaryTree::tree_height = -1;

int main()
{
    BinaryTree tree;
    vector<int> tree_element = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = tree.build_tree(tree_element); 

}