#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct bst_node
    {
        int val;
        int less; // count of members less than val
        int cnt; // count of members equals val
        bst_node *left,*right;
        bst_node(int x):val(x),less(0),cnt(1),left(nullptr),right(nullptr){}
    };

    void insert(bst_node* root, const int& val, int& num_less){
        if(val < root->val){ // insert to the left sub-tree
            root->less++;
            if(root->left == nullptr){
                root->left = new bst_node(val);
            } else {
                insert(root->left, val, num_less);
            }
        } else if(val > root->val){ // insert to the right sub-tree
            num_less += root->less + root->cnt;
            if(root->right == nullptr)
                root->right = new bst_node(val);
            else 
                insert(root->right, val, num_less);
        } else{ // val == root->val
            num_less += root->less;
            root->cnt++;
            return;
        }
    }

    vector<int> countSmaller(vector<int>& nums){
        size_t n = nums.size();
        vector<int> count(n);
        if(n == 0) return count;
        bst_node root(nums[n-1]);
        for(int i = n - 2; i >= 0; --i){
            int numless = 0;
            insert(&root,nums[i],numless);
            count[i] = numless;
        }
        return count;
    }   
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> t = {2,4,5,4,5,4,5,6,7,3,2,1};
    vector<int> cnt = sol.countSmaller(t);
    for(auto c : cnt){
        cout << c << " ";
    }
    cout << endl;
    return 0;
}