#include <bits/stdc++.h>
using namespace std;

struct SegmentTreeNode
{
    int s, e, sum;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int _s, int _e):s(_s), e(_e),sum(0),left(NULL),right(NULL){}    
};

class SegmentTree
{
public:
    SegmentTree(vector<int>& nums){
        int n = nums.size();
        root = build_segment_tree(nums,0,n-1);
    }
    void update(int i, int val){
        update(root, i, val);
    }

    int sumRange(int i, int j){
        return sumRange(root,i,j);
    }
    ~SegmentTree();
private:
    SegmentTreeNode* root;
    SegmentTreeNode* build_segment_tree(vector<int>& nums, int s, int e){
        if(s > e) return NULL;
        else {
            SegmentTreeNode* res = new SegmentTreeNode(s,e);
            if(s == e) res->sum = nums[s];
            else{
                int m = s + (e - s) / 2;
                res->left = build_segment_tree(nums, s, m);
                res->right = build_segment_tree(nums, m+1, e);
                res->sum = res->left->sum + res->right->sum;
            }
            return res;
        }
    }

    void update(SegmentTreeNode* root, int i, int val){
        if(root->s == root->e) root->sum = val;
        else{
            int m = root->s + (root->e - root->s) / 2;
            if(i <= m) update(root->left,i,val);
            else update(root->right, i, val);
            root->sum = root->left->sum + root->right->sum;
        }
    }

    int sumRange(SegmentTreeNode* root, int s, int e){
        if(root  == NULL)  return 0;
        if(root->s == s && root->e == e) return root->sum;
        else{
            int m = root->s + (root->e - root->s) / 2;
            if(e <= m) return sumRange(root->left,s,e);
            else if(s >= m+1) return sumRange(root->right,s,e);
            else return sumRange(root->left,s,m) + sumRange(root->right,m+1,e);
        }
    }   
};

class NumArray
{
public:
    NumArray(vector<int>& nums){
        st = new SegmentTree(nums);
    }
    void update(int i, int val){
        st->update(i,val);
    }
    int sumRange(int i, int j){
        return st->sumRange(i,j);
    }
private:
    SegmentTree *st;
};

int main(int argc, char const *argv[])
{
    vector<int> test = {1,2,34,45,6,4,6,3,2,3,56,54};
    NumArray arr(test);
    cout << arr.sumRange(1,3) << endl;
    return 0;
}