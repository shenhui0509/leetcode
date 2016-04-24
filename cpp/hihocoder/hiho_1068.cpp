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

const int nmx = 1e6+5;
const int mmx = 20;
int st[nmx][mmx];

int main(void)
{
    freopen("in","r",stdin);
    int n,m;
    cin >> n;
    int wt;
    memset(st,0x00,sizeof(st));
    for(int i = 1; i <= n; i++){
        cin >> wt;
        st[i][0] = wt;
    }
    int j_max = int(log(n)/log(2.0));
    for(int j = 1; j <= j_max; j++){
        for(int i = 1; i + (1<<j) - 1 <= n; i++){
            st[i][j] = min(st[i][j-1], st[i + (1<<(j-1))][j-1]);
        }
    }
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        int t = int(log(r-l+1)/log(2.0));
        cout << min(st[l][t],st[r-(1<<t)+1][t])<<endl;

    }
    fclose(stdin);
    return 0;
}