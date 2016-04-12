#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome(const string &s){
    string rev_s = string(s.rbegin(), s.rend());
    string l = s + "#" + rev_s;

    vector<int> o(l.size(), 0);
    for(int i = 1; i < l.size(); i++){
        int j = o[i-1];
        while(j > 0 && l[i] != l[j]) j = o[j-1];
        o[i] = (j += l[i] == l[j]);
    }
    for(auto i : o){
        cout << i << " ";
    }
    cout << "\n";
    string to_attach = rev_s.substr(0, s.size() - o[l.size() - 1]);
    cout << to_attach << endl;
    return rev_s.substr(0, s.size() - o[l.size()-1]) + s;
}

int main(void)
{
    cout << shortestPalindrome("aba") << endl;
    return 0;
}