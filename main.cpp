#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Insert into BST
static Node* insert_node(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->val) root->left = insert_node(root->left, v);
    else if (v > root->val) root->right = insert_node(root->right, v);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> in;
    in.reserve(8);
    long long x;
    for (int i = 0; i < 8; ++i) {
        if (!(cin >> x)) return 0; // insufficient input
        in.push_back(x);
    }
    // First 7 are node values, last is cnt
    vector<int> vals;
    vals.reserve(7);
    for (int i = 0; i < 7; ++i) vals.push_back((int)in[i]);
    int cnt = (int)in[7];

    // Build BST by inserting values following BST ordering
    Node* root = nullptr;
    for (int v : vals) root = insert_node(root, v);

    // Perform reverse in-order traversal to find cnt-th largest
    int answer = -1;
    int k = cnt;
    stack<Node*> st;
    Node* cur = root;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur->right;
        }
        cur = st.top(); st.pop();
        if (--k == 0) { answer = cur->val; break; }
        cur = cur->left;
    }

    if (answer != -1)
        cout << answer;
    return 0;
}

