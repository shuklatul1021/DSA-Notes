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
    Node *node;
    int hd;
} info;

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

    vector<int> kth_level_tree_iterative(Node *root, int k)
    {
        if (root == NULL)
        {
            return {};
        }

        vector<int> k_level_element;
        queue<Node *> track_queue;
        track_queue.push(root);
        track_queue.push(NULL);
        int curr_level = 1;
        while (!track_queue.empty())
        {
            Node *curr = track_queue.front();
            track_queue.pop();
            if (curr == NULL)
            {
                curr_level++;
                if (!track_queue.empty())
                {
                    track_queue.push(NULL);
                }
            }
            else
            {
                if (curr_level == k)
                {
                    k_level_element.push_back(curr->data);
                }
                if (curr->left != NULL)
                {
                    track_queue.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    track_queue.push(curr->right);
                }
            }
        }
        return k_level_element;
    }

    vector<int> kth_level_tree_recursion(Node *root, int k, int level)
    {
        if (root == NULL)
            return {};
        if (k == level)
            return {root->data};

        vector<int> result;
        vector<int> left_result = kth_level_tree_recursion(root->left, k, level + 1);
        vector<int> right_result = kth_level_tree_recursion(root->right, k, level + 1);

        result.insert(result.end(), left_result.begin(), left_result.end());
        result.insert(result.end(), right_result.begin(), right_result.end());

        return result;
    }
};

int BinaryTree::idx = -1;
int BinaryTree::tree_height = -1;

int main()
{
    BinaryTree tree;
    vector<int> tree_element = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = tree.build_tree(tree_element);
    vector<int> result = tree.kth_level_tree_recursion(root, 2, 1);
    cout << result.size() << endl;
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}