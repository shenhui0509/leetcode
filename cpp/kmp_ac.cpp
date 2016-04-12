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
    while( i < s.size()){
        if(j == -1 || p[j] == s[i]){
            i++;
            j++;
            nxt[i] = j;
        } else {
            j = nxt[j];
        }
    }
    for(i = 0; i < p.size(); i++){
        cout << p[i] << " ";
        cout << nxt[i] << "  ";
    }
    cout << endl;
}

int kmp()
{
    get_next();
    int i = 0, j = 0, ans = 0;
    while(i < s.size()) {
        // /cout << j << endl;
        if(j == 0 || s[i] == p[j]) {
            cout << "j = " << j << " i = " << i << endl; 
            cout << "p[j] = " << p[j] << " s[i] = " << s[i] << endl; 
            i++;
            j++;    
        } else {
            cout << "j = " << j << " i = " << i << endl; 
            j = nxt[j];
        }
        if(j == p.size() - 1){
            ans++;
            j = 0;
        }
    }
    return ans;
}

int main()
{
    freopen("in","r",stdin);
    cin >> n;
    while(n--){
        cin >> p >> s;
        cout << kmp() << endl;
    }
    fclose(stdin);
    return 0;
}