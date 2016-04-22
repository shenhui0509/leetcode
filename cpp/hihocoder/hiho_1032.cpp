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
#define REOPEN freopen("in","r",stdin)
#define cl fclose(stdin)
using namespace std;

const int mx = 1e6+5;
char str[mx];
char p_str[2*mx+5];
int  p[mx];
int n;

void pre_process()
{
    int len = strlen(str);
    p_str[0] = '@';
    p_str[1] = '#';
    for(int i = 0; i < len;i++){
        p_str[2*i+2] = str[i];
        p_str[2*i+3] = '#';
    }
    p_str[2 * len + 2] = '\0';
}

int get_max_pali()
{
    pre_process();
    int m = 0, pi = 1;
    int len = strlen(p_str);
    memset(p,0,sizeof(p));
    for(int i = 1; i < len; i++){
        if(m > i){
            p[i] = min(m - i, p[2*pi - 1]);
        } else {
            p[i] = 1;
        }
        while( i-p[i] > 0 && i + p[i] < len && p_str[i-p[i]] == p_str[i+p[i]]) {
            p[i]++;
        }
        if(i + p[i] > m){
            m = p[i] + i;
            pi = i;
        }
    }
    int ans = 0;
    for(int i = 0; i < len; i++){
        ans = max(p[i],ans);
    }
    cout << ans - 1 << endl;
}

int main()
{
    //REOPEN;
    cin >> n;
    while(n--){
        scanf("%s", str);
        get_max_pali();
    }
    //cl;
}