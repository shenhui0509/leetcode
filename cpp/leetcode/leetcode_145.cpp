#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    static string serialize(TreeNode* root) {
        string ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            if (cur == NULL) {
                str = str + "#,";
            } else {
                q.push(cur->left);
                q.push(cur->right);
                str = str + to_string(cur->val) + ",";
            }
            q.pop();
        }
        return str;
    }

    static TreeNode* desrialize(string data) {
        TreeNode* root = NULL;
        queue<TreeNode**> q;
        q.push(&root);
        auto first = data.begin();
        while (first != data.end()) {
            TreeNode** pp = q.front();
            if (*first == '#') {
                advance(first, 2);
            } else {
                auto last = find(first, data.end(), ',');
                int val = stoi(string(first, last));
                *pp = new TreeNode(val);
                q.push(&((*pp)->left));
                q.push(&((*pp)->right));
                first = next(last);
            }
            q.pop();
        }
        return root;
    }
};

//recursive
vector<int> post_order_recursive(TreeNode* root)
{
    vector<int> ret;
    std::function<void(TreeNode*)> __post_order = [&ret，__post_order](TreeNode * root) {if (!root) return; __post_order(root->left); __post_order(root->right); ret.push_back(root->val);};
    __post_order(root);
    return ret;
}

//stack
vector<int> post_order_stack(TreeNode* root)
{
    vector<int> ret;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* last = NULL;
    while (cur || !st.empty()) {
        if (cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            TreeNode* node = st.top();
            if (node->right && last != node->right) {
                cur = cur->right;
            } else {
                ret.push_back(node->val);
                last = node;
                st.pop();
            }
        }
    }
    return ret;
}

//morris travel
void reverse(TreeNode* start, TreeNode* end) {
    if (start == end) return;
    TreeNode* x = start;
    TreeNode* y = start->right;
    TreeNode* z;
    while (x != end) {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
    }
}

void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& ret) {
    reverse(start, end);
    TreeNode* node = end;
    while (1) {
        ret.push_back(node->val);
        if (node == start) break;
        node = node->right;
    }
    reverse(end, start);
}
vector<int> post_order_morris(TreeNode* root)
{
    vector<int> ret;
    TreeNode dump = new TreeNode(0);
    dump->left = root;
    TreeNode* cur = dump;
    while (cur) {
        if (cur->left) {
            TreeNode* pre = cur->left;
            while (pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if (!(pre->right)) {
                pre->right = cur;
                cur = cur->left;
            } else {
                reverseAddNodes(cur->left, pre, ret);
                pre->right = NULL;
                cur = cur->right;
            }
        } else {
            cur = cur->right;
        }
    }
    return ret;
}