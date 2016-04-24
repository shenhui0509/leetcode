#include <bits/stdc++.h>
using namespace std;

vector<int> f = {1,2,3,5,8,13,21};

bool is_lucky(string& s)
{
    int len = s.size();
    int cnt=0;
    vector<bool> e(26,false);
    for(int i = 0; i < len; i++){
        int id = s[i] - 'a';
        if(e[id]) continue;
        else{
            cnt++;
            e[id] = true;
        }
    }
    for(auto i : f){
        if(i == cnt)
            return true;
    }
    return false;
}

int main(){
    set<string> result;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        for(int len = 1; len <= s.size() - i; len++){
            string ss = s.substr(i,len);
            if(is_lucky(ss))
                result.insert(ss);
        }
    }
    for(auto ss : result){
        cout << ss << endl;
    }

}