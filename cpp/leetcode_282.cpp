#include <bits/stdc++.h>
using namespace std;
const int nmax = 10000000;
const int mmax = 10000000;

void dfs(vector<string>& result, const string& num, const int target, 
        string cur, int pos, const long cv, const long pv, const char op){
    if(pos == num.size() && cv == target){
        result.push_back(cur);
    } else {
        for(int i = pos+1; i <= num.size(); i++){
            string t = num.substr(pos, i - pos);
            long now = stol(t);
            if(to_string(now).size() != t.size()) continue;
            dfs(result, num, target, cur + '+' + t, i, cv + now, now, '+');
            dfs(result, num, target, cur + '-' + t, i, cv - now, now, '-');
            dfs(result, num, target, cur + '*' + t, i, (op == '-') ? cv + pv - pv * now: ((op == '+') ? cv - pv + pv * now : pv * now), pv * now, op);
        }
    }
}
vector<string> add_operators(string num, int target)
{
    vector<string> rst;
    if(num.empty()) return rst;
    for(int i = 1; i <= num.size(); i++){
        string s = num.substr(0,i);
        long cur = stol(s);
        if(to_string(cur).size() != s.size()) continue;
        dfs(rst,num,target,s,i,cur,cur,'#');
    }
    return rst;
}



int main(void)
{
    freopen("in", "r", stdin);
    int n;
    int target;
    string test_case;
    cin >> n;
    while(n--){
        cin >> test_case;
        cin >> target;

        vector<string> rst = add_operators(test_case, target);
        for(auto s : rst){
            cout << s << "=" << target << endl;
        }
    }
    vector<string> ss = add_operators("12345", 15);
    for(auto s : ss){
        cout << s << "=" << target << endl;
    }
    fclose(stdin);
    return 0;
}