//                      Binary Tree
/**
 * 1. Binary Tree is a tree data structure in which each node has at most two children, referred to as the left child and the right child.
 * 2. The topmost node of the tree is called the root node, and the nodes that do not have any children are called leaf nodes.
 * 3. Binary trees are used in various applications, such as expression parsing, binary search trees, and heaps.
 */

#include <iostream>
#include <vector>
#include <queue>
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
};

int BinaryTree::idx = -1;

int main()
{
    BinaryTree tree;
    vector<int> tree_element = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = tree.build_tree(tree_element);
    cout << root->data << endl;
}

//                      Tree Traversal
/**
 * 1. Tree traversal is the process of visiting each node in a tree data structure in a specific order.
 * 2. There are three common types of tree traversal:
 *    a. Preorder Traversal: Visit the root node first, then recursively visit the left subtree, and finally the right subtree.
 *    b. Inorder Traversal: Recursively visit the left subtree first, then visit the root node, and finally the right subtree.
 *    c. Postorder Traversal: Recursively visit the left subtree first, then the right subtree, and finally visit the root node.
 * 3. Tree traversal is used in various applications, such as searching for a specific value in a tree, printing the contents of a tree, and evaluating expressions represented as trees.
 */

// Pre-Order Traversal
/**
 *          5
 *        /   \
 *       3     7   
 *     / \    / \
 *    2   4  6   8
 */
void pre_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}
// In-Order Traversal
void in_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}
// Post-Order Traversal
void post_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

// Level Order Traversal
void level_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        Node *curr_node = que.front();
        que.pop();
        if (curr_node == NULL)
        {
            cout << endl;
            if (!que.empty())
            {
                que.push(NULL);
            }
        }
        else
        {
            cout << curr_node->data << " ";
            if (curr_node->left != NULL)
            {
                que.push(curr_node->left);
            }
            if (curr_node->right != NULL)
            {
                que.push(curr_node->right);
            }
        }
    }
}

// Calculate Height Of Tree
int height_of_tree(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left_height = height_of_tree(node->left);
    int right_height = height_of_tree(node->right);
    int height = max(left_height, right_height);
    return height + 1;
}

// Count The Nodes Of The Tree

int count_node(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left_height = count_node(node->left);
    int right_height = count_node(node->right);
    return left_height + right_height + 1;
}

/**
 *          5
 *        /   \
 *       3     7   
 *     / \    / \
 *    2   4  6   8
 */

// Sum Of Nodes In Tree
int sum_node(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left_sum = sum_node(node->left);
    int right_sum = sum_node(node->right);
    return left_sum + right_sum + node->data;
}

// Diameter Of Tree