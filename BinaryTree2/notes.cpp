//              Diameter Of Tree
// Approach 1 (Brute Force 1) (n^2);
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

typedef struct
{
    int diameter;
    int height;
} info;

typedef struct
{
    Node *node;
    int hd;
} info2;

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
    /**
     * Diameter Approach 1
     */
    int height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int left_height = height(node->left);
        int right_height = height(node->right);
        int height = max(left_height, right_height);
        return height + 1;
    }
    // No of Nodes In the longest path between in two leaves
    int diameter_of_tree(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_diameter = diameter_of_tree(root->left);
        int leftHt = height(root->left);

        int right_diameter = diameter_of_tree(root->right);
        int rightHt = height(root->right);

        int self_dia = leftHt + rightHt + 1;

        return max(self_dia, max(right_diameter, left_diameter));
    }
    //******************************************************************************************************/
    /**
     * Diameter Approach 2
     */
    info diameter_of_tree_2(Node *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }
        info left_diameter = diameter_of_tree_2(root->left);
        info right_diameter = diameter_of_tree_2(root->right);
        int final_diameter = max(max(left_diameter.diameter, right_diameter.diameter), left_diameter.height + right_diameter.height + 1);
        int ht = max(left_diameter.height, right_diameter.height) + 1;
        return {final_diameter, ht};
    }

    // Question : 2 -> Find Subtree of another Tree
    bool isIdentical(Node *root, Node *sub_tree)
    {
        if (root == NULL && sub_tree == NULL)
            return true;
        else if (root == NULL || sub_tree == NULL || root->data != sub_tree->data)
            return false;

        if (!isIdentical(root->left, sub_tree->left))
            return false;
        if (!isIdentical(root->right, sub_tree->right))
            return false;
        return true;
    }

    bool issubtree(Node *root, Node *sub_tree)
    {
        if (sub_tree == NULL)
            return true;
        if (root == NULL)
            return false;
        if (root->data == sub_tree->data)
            return isIdentical(root, sub_tree);
        return issubtree(root->left, sub_tree) || issubtree(root->right, sub_tree);
    }

    // Question(imp) : Top View Of Binary Tree
    /**
     * Horizontal Distance Of Tree
     * 1. The horizontal distance of the root node is 0.
     * 2. For any node, the horizontal distance of its left child is the horizontal
     *    distance of the node minus 1, and the horizontal distance of its right child is the horizontal distance of the node plus 1.
     * 3. Nodes that have the same horizontal distance are considered to be in the same
     *     vertical line when viewed from the top.
     * 4. The top view of a binary tree consists of the nodes that are visible
     *    when the tree is viewed from above, which means that for each horizontal distance, only the first node encountered at that distance is included in the top view.
     * 5. The top view of a binary tree can be useful for understanding the structure
     *    of the tree and for solving problems related to vertical order traversal, where nodes are grouped based on their horizontal distance from the root.
     */
    /**
     * Count Horizontal Distance Of Tree
     *                  (x)
     *                  node
     *                 /     \
     *               node      node
     *              (x - 1)   (x + 1)
     */
    /**
     * Approach For Top View Of Tree
     */
    void top_view_of_tree(Node *root)
    {
        if (root == NULL)
            return;
        queue<info2> que;
        map<int, int> top_nodes;
        que.push({root, 0});
        while (!que.empty())
        {
            info2 curr = que.front();
            que.pop();
            if (top_nodes.find(curr.hd) == top_nodes.end())
            {
                top_nodes[curr.hd] = curr.node->data;
            }
            if (curr.node->left != NULL)
            {
                que.push({curr.node->left, curr.hd - 1});
            }
            if (curr.node->right != NULL)
            {
                que.push({curr.node->right, curr.hd + 1});
            }
        }

        for (auto &entry : top_nodes)
        {
            cout << "Index : " << entry.first << " - " << entry.second << endl;
        }
        cout << endl;
    }
};

int BinaryTree::idx = -1;
int BinaryTree::tree_height = -1;

int main()
{
    BinaryTree tree;
    vector<int> tree_element = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = tree.build_tree(tree_element);
    cout << "The Diameter Of Tree Approach 1 : " << tree.diameter_of_tree(root) << endl;

    cout << "The Diameter Of Tree Approach 2 : " << tree.diameter_of_tree_2(root).diameter << endl;
}