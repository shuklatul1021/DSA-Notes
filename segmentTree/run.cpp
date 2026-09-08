#include <bits/stdc++.h>
using namespace std;

class SegementTree { 
public:
    vector<int> tree;
    int n;

    SegementTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, val);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0; // Out of range
        }
        if (l <= start && end <= r) {
            return tree[node]; // Current segment is fully within range
        }
        int mid = (start + end) / 2;
        int left_sum = query(2 * node + 1, start, mid, l, r);
        int right_sum = query(2 * node + 2, mid + 1, end, l, r);
        return left_sum + right_sum;
    }

    void printTree() {
        for (int i = 0; i < tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegementTree st(arr.size());
    st.build(arr, 0, 0, arr.size() - 1);
    cout << "Segment Tree: ";
    st.printTree();
    return 0;
}