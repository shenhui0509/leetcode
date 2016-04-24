#include <bits/stdc++.h>
using namespace std;

void dfs(int n, int k, int cur, int num, vector<vector<int>>& ret, vector<int>& tmp){
    if(num == k){
        ret.push_back(tmp);
        return;
    }
    for(int i = cur; i < n; i++){
        tmp.push_back(i+1);
        dfs(n,k,i+1,num+1,ret,tmp);
        tmp.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ret;
    vector<int> tmp;
    if(n < k) return ret;
    dfs(n,k,0,0,ret,tmp);
    return ret;

}

int main(int argc, char const *argv[])
{
    vector<vector<int>> ret = combine(5,3);
    for(vector<int> v : ret){
        for(int u : v){
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}