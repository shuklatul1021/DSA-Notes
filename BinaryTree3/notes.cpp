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

    /**
     * Lowest Common Ancestor
     * Ancestor of a node is the node which is present in the path from root to that node.
     * Lowest common ancestor of two nodes is the node which is present in the path from root to both nodes and is farthest from the root.
     */
    // Approach 1
    bool getPath(Node *root, int node, vector<int> &path)
    {
        if (root == NULL)
            return false;
        path.push_back(root->data);

        if (root->data == node)
        {
            return true;
        }
        bool foundleft = getPath(root->left, node, path);
        bool foundright = getPath(root->right, node, path);

        if (foundleft || foundright)
        {
            return true;
        }
        path.pop_back();
        return false;
    }

    int lowest_common_ancestor(Node *root, int n1, int n2)
    {
        vector<int> path1, path2;
        getPath(root, n1, path1);
        getPath(root, n2, path2);
        int i;
        for (i = 0; i < path1.size() && path2.size(); i++)
        {
            if (path1[i] != path2[i])
            {
                break;
            }
        }
        return path1[i - 1];
    }

    // Approach 2
    int lowest_common_ancestor_approach2(Node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root->data;
        }

        int left_lca = lowest_common_ancestor_approach2(root->left, n1, n2);
        int right_lca = lowest_common_ancestor_approach2(root->right, n1, n2);

        if (left_lca == -1)
        {
            return right_lca;
        }
        if (right_lca == -1)
        {
            return left_lca;
        }
        return root->data;
    }

    // Min Distance Between Two Nodes

    Node *Node_lowest_common_ancestor_approach2(Node *root, int n1, int n2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == n1 || root->data == n2)
        {
            return root;
        }

        Node *left_lca = Node_lowest_common_ancestor_approach2(root->left, n1, n2);
        Node *right_lca = Node_lowest_common_ancestor_approach2(root->right, n1, n2);

        if (left_lca == NULL)
        {
            return right_lca;
        }
        if (right_lca == NULL)
        {
            return left_lca;
        }
        return root;
    }
    int lcaDist(Node *root, int n)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->data == n)
        {
            return 0;
        }

        int leftDis = lcaDist(root->left, n);
        int rightDis = lcaDist(root->right, n);

        if (leftDis == -1 && rightDis == -1)
        {
            return -1;
        }
        else if (leftDis == -1)
        {
            return rightDis + 1;
        }
        else
        {
            return leftDis + 1;
        }
    }

    int min_distance_between_node(Node *root, int n1, int n2)
    {
        Node *lca = Node_lowest_common_ancestor_approach2(root, n1, n2);
        int dis1 = lcaDist(lca, n1);
        int dis2 = lcaDist(lca, n2);

        return dis1 + dis2;
    }

    // Kth - Ancestor Of Node
    int Kth_ancestor_node(Node *root, int n, int k)
    {
        if (root == NULL)
        {
            return -1;
        }

        if (root->data == n)
        {
            return 0;
        }

        int dis_lef = Kth_ancestor_node(root->left, n, k);
        int dis_rig = Kth_ancestor_node(root->right, n, k);
        if (dis_lef == -1 && dis_rig == -1)
        {
            return -1;
        }

        int result_max = max(dis_lef, dis_rig);
        if (result_max + 1 == k)
        {
            cout << "Node" << root->data << endl;
        }
        return result_max + 1;
    }

    // Transform to Sum tree
    /*                    1                                                                    24
                        /   \              Transform To Sum Tree                             /    \
                       2     3             ---------------------->                          9      13
                     /  \   /  \                                                          /   \   /   \
                    4    5 6    7                                                        0     0  0    0
    */
    int sum_tree(Node *root)
    {
        if (root == NULL)
        {
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
    vector<int> result = tree.kth_level_tree_recursion(root, 2, 1);
    cout << result.size() << endl;
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}