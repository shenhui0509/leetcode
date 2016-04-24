#include <bits/stdc++.h>
using namespace std;

//Backtracking
void dfs(vector<int>& nums, vector<int>& cur, int index, vector<vector<int>>& ret){
    ret.push_back(cur);
    for (int i = index; i < nums.size(); i++) {
        cur.push_back(nums[i]);
        dfs(nums, cur, i + 1, ret);
        cur.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    vector<int> cur;
    dfs(nums, cur, 0, ret);
    return ret;
}

//Iterative
vector<vector<int>> subsets_iter(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret(1,vector<int>());
    for(int i = 0; i < nums.size(); i++){
        int n = ret.size();
        for(int j = 0; j < n; j++){
            ret.push_back(ret[j]);
            ret.back().push_back(nums[i]);
        }
    }
    return ret;
}

//bit
vector<vector<int>> subsets_bit(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int num_subset = pow(2, nums.size());
    vector<vector<int>> ret(num_subset, vector<int>());
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < num_subset; j++){
            if((j>>i)&1)
                ret[j].push_back(nums[i]);
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    vector<int> test = {1, 2, 3};
    vector<vector<int>> ret = subsets(test);
    for (auto vec : ret) {
        for (auto i : vec) {
            printf("%d ", i);
        }
        printf("\n");
    }
    ret = subsets_iter(test);
    for (auto vec : ret) {
        for (auto i : vec) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}