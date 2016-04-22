#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

inline void get_next(string& p, vector<int>& next)
{
    next.resize(p.size(),-1);
    for(int i = 1; i < p.size(); i++){
        int j = next[i-1];
        while(p[i] != p[j+1] && j >= 0)
            j = next[j];
        if(p[i] == p[j+1]) next[i] = j+1;
        else    next[i] = 0;
    }
}

inline int kmp(string& s, string& p)
{
    vector<int> next;
    get_next(p, next);
    int cnt = 0;
    string::size_type index, count = 0;
    for(index = 0; index < s.size(); ++index){
        int pos = 0;
        string::size_type iter = index;
        while(pos < p.size() && iter < s.size()){
            if(s[iter] == p[pos]){
                ++iter;
                ++pos;
            } else {
                if(pos == 0) ++iter;
                else pos = next[pos - 1] + 1;
            }
        }
        if(pos == p.size() && (iter - index) == p.size()) ++ cnt;

    }
    return cnt;
}

int main()
{
    int n;
    string s, p;
    cin >> n;
    while(n--){
        cin >> p;
        cin >> s;
        cout << kmp(s,p) << endl;
    }
    return 0;
}