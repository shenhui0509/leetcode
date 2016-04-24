#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path)
{
    string res,tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss, tmp, '/')){
        if(tmp == "" || tmp == ".") continue;
        if(tmp == ".." && !stk.empty()) stk.pop_back();
        else if(tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/" + str;
    return res.empty() ? "/" : res;
}

int main(int argc, char const *argv[])
{
    string path = "/usr/var/../../fuck/././././../ribi";
    cout << simplifyPath(path) << endl;
    return 0;
}