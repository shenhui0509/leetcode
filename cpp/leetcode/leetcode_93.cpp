#include <bits/stdc++.h>
using namespace std;

void dfs(const string& s, int pos, string cur, int cnt,vector<string>& rst)
{
    if(pos == s.size() && cnt == 4){
        cur.erase(cur.end() - 1);
        rst.push_back(cur);
        return;
    }
    if(s.size() - pos  > (4-cnt) * 3) return;
    if(s.size() - pos < (4-cnt)) return;
    int num = 0;

    for(int i = pos; i < pos+3; i++){
        num = num*10 + (s[i]-'0');
        if(num <= 255 ){
            cur+=s[i];
            dfs(s,i+1,cur+'.',cnt+1,rst);
        }
        if(num == 0) break;
    }
}
vector<string> restoreIpAddress(string s)
{
    vector<string> rst;
    string ip;
    dfs(s,0,ip,0,rst);
    return rst;
}

int main()
{
    freopen("in","r",stdin);
    int n;
    cin >> n;
    string ip;
    while(n--){
        cin >> ip;
        cout << ip << "=>>>  ";
        vector<string> rst = restoreIpAddress(ip);
        for(string s : rst)
            cout << s << " ";
        cout << endl;
    }
    fclose(stdin);
    return 0;
}