#include <bits/stdc++.h>
using namespace std;

//Solution1 : Raw DFS and backtrap
bool isPalindrome(const string& s){
    if(s.empty())
        return false;
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i++] != s[j--]){
            return false;
        }
    }
    return true;
}
void dfs(const string& s, int depth, vector<string>& cur, vector<vector<string>>&result)
{
    if(depth == s.size()){
        result.push_back(cur);
    }
    bool flag = false;
    for(int len = 1; depth + len <= s.size(); len++){
        string t = s.substr(depth, len);
        vector<string> tmp = cur;
        if(isPalindrome(t)){
            cur.push_back(t);
            flag = true;
            dfs(s, depth+len, cur, result);
        } else {
            continue;
        }
        cur = tmp;
    }
    return;
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> rst;
    vector<string> cur;
    dfs(s,0,cur,rst);
    return rst;
}

//Solution2 : DP + dfs

void dfs_2(const string& s, int depth, vector<string>& cur, vector<vector<string>>& result)
{
    if(j == s.size()){
        result.push_back(cur);
        return;
    }
    int m,n,l;
    for(m = s.size() - 1; m >= depth; m--){
        l = depth;
        n = m;
        while(l < n && s[l++] == s[n--]);
        if(l >= n){
            cur.push_back(s.substr(depth, m - depth + 1));
            dfs_2(s, m+1, cur, result);
            cur.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    string s("aabcb");
    vector<vector<string>> r = partition(s);
    for(auto vec : r){
        for(auto str : vec){
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}