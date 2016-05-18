#include <bits/stdc++.h>
using namespace std;

int dfs(TreeNode* root, int &res)
{
    if(!root) return 0;
    int l_max = dfs(root->left, res), r_max = dfs(root->right, res);
    res = max(res, a+b+root->val);
    return max(0, max(a,b) + root->val);
}

int maxPathSum(TreeNode* root)
{
    if(!root) return 0;
    int res = root->val;
    dfs(root, res);
    return res;
}