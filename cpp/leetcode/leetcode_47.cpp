#include <bits/stdc++.h>
using namespace std;

void permute_re(vector<int>&nums, int start, int end, vector<vector<int>>& result)
{
    if(start == end-1){
        result.push_back(nums);
        return;
    }
    for(int i = start; i < end; i++){
        if(i != start && nums[i] == nums[start]) continue;
        swap(nums[start],nums[i]);
        permute_re(nums,i+1,end,result);
        swap(nums[start],nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> r;
    permute_re(num,0,nums.size() - 1, r);
    return r;
}