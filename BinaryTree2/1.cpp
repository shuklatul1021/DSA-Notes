#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
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

    
    vector<int> bottomView(Node *root) {
        map<int, int> m;
        queue<Info> q;
        vector<int> result;
        q.push({root, 0});
        while(!q.empty()){
            Info curr = q.front();
            q.pop();
            if(m.find(curr.hd) == m.end()){
                m.insert({curr.hd , curr.n->data});
            }
            if(m.find(curr.hd) != m.end()){
                m[curr.hd] = curr.n->data;
            } 
            if(curr.n->left != NULL){
                q.push({curr.n->left, curr.hd - 1});
            }
            if(curr.n->right != NULL){
                q.push({curr.n->right, curr.hd + 1});
            }
        }

        for(auto& d : m){
            result.push_back(d.second);
        }

        return result;
    }
};

int BinaryTree::idx = -1;
int BinaryTree::tree_height = -1;

int main()
{
    BinaryTree tree;
    vector<int> tree_element = {1, 2, 3, 4, 5, -1, 6};
    Node *root = tree.build_tree(tree_element);
    vector<int> bottom_view = tree.bottomView(root);
    for(int n : bottom_view){
        cout << n << " ";
    }cout << endl;
}