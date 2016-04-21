#include <bits/stdc++.h>
using namespace std;

void dfs(const int k, const int n, vector<int>& cur, int cur_sum, int start, vector<vector<int>>& ret)
{
    if(cur.size() == k && cur_sum == n){
        ret.push_back(cur);
        return;
    }
    if(cur_sum + start > n)
        return;
    
    for(int i = start; i <= 9; i++){
        cur.push_back(i);
        dfs(k,n,cur,cur_sum+i,i+1,ret);
        cur.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ret;
    vector<int> cur;
    dfs(k,n,cur,0,1,ret);
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> ret = combinationSum3(2,18);
    for(auto v : ret){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}