#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallestElement(TreeNode* root, int k)
{
    stack<TreeNode*> stk;
    TreeNode* p = root;
    while(p || !stk.empty()){
        while(p){
            stk.push(p);
            p = p->left;
        }
        p = p.top();
        if(--k == 0)
            return p->val;
        st.pop();
        p = p->right;
    }
}