#include <bits/stdc++.h>
using namespace std;

void permute_(vector<int>& nums, int begin, vector<vector<int>>& ret)
{
    if(begin == nums.size()){
        ret.push_back(nums);
        return;
    }
    for(int i = begin; i < nums.size(); i++){
        swap(nums[begin], nums[i]);
        permute_(nums, begin+1, ret);
        swap(nums[begin],nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ret;
    permute_(nums, 0, ret);
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {1,2,3};
    vector<vector<int>> ret = permute(vec);
    for(auto v : ret){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}