#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    if(s.empty() || t.empty()){
        return "";
    }
    int cnt = t.size();
    int cnter[128];
    memset(cnter, 0,sizeof(cnter));
    bool asc[128];
    memset(asc, 0, sizeof(asc));
    for(int i = 0; i < 128; i++){
        cnter[t[i]]++;
        asc[t[i]] = true;
    }
    int i = -1, j = 0, min_len = INT_MAX, min_idx = 0;
    while(i < (int)s.size() && j < (int)s.size()){
        if(cnt){
            i++;
            cnter[s[i]]--;
            if(asc[s[i]] && cnter[s[i]] >= 0){
                cnt--;
            }
        } else {
            if(min_len > i - j + 1){
                min_len = i - j + 1;
                min_idx = j;
            }
            cnter[s[j]]++;
            if(asc[s[j]] && cnter[s[j]] > 0){
                cnt++;
            }
            j++;
        }
    }
    if(min_len == INT_MAX)
        return "";
    return s.substr(min_idx,min_len);
}

int main(int argc, char const *argv[])
{

    string s("a");
    string t("a");
    cout << minWindow(s,t) << endl;
    return 0;
}