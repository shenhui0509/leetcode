#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<int>& candidate, int begin, int target, vector<vector<int>>& res, vector<int>& comb)
{
    if(!target){
        res.push_back(comb);
        return;
    }
    for(int i = begin; i < candidate.size() && target >= candidate[i]; ++i){
        if(i && candidate[i] == candidate[i-1]&&i>begin) continue;
        comb.push_back(candidate[i]);
        dfs(candidate, i+1, target - candidate[i], res, comb);
        comb.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidate, int target)
{
    std::sort(candidate.begin(), candidate.end());
    vector<vector<int>> ret;
    vector<int> comb;
    dfs(candidate,0,target,ret,comb);
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {2,1,1,3,4,5,7};
    vector<vector<int>> res = combinationSum(vec, 7);
    for(vector<int> v : res){
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}