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

typedef long long ll;

#define mx 1000005
int n;
int nxt[mx];
string s,p;

void get_next()
{
    nxt[0] = -1;
    int i = 0, j = -1;
    while( i < p.size()){
        if(j == -1 || p[j] == p[i]){
            i++;
            j++;
            nxt[i] = j;
        } else {
            j = nxt[j];
        }
    }
}

int kmp()
{
    get_next();
    int i = 0, j = 0, ans = 0;
    while(i < s.size()) {
        if(j == -1 || s[i] == p[j]) {
            i++;
            j++;    
        } else {
            j == nxt[j];
        }
        if(j == p.size())
            ans++;
    }
    return ans;
}

int main()
{
    cin >> n;
    while(n--){
        cin >> p >> s;
        cout << kmp() << endl;
    }
    return 0;
}