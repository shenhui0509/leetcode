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

const int nmax = 109;
#define inf -2147483647

vector<int>edge[nmax];

int m,n,k;
int dp[nmax][nmax];
int w[nmax];

void dfs(int u, int v)
{
    dp[u][1] = w[u];
    for(int i = 0; i < edge[u].size(); i++){
        int next = edge[u][i];
        if(next == v) continue;
        dfs(next, u);
        for(int x = m; x >= 1; x--){
            if(dp[u][x] > inf)
                for(int y = 0; y <= m-x; y++)
                    if(dp[next][y]!=inf)
                        dp[u][x+y] = max(dp[u][x+y],dp[u][x]+dp[next][y]);
        }
    }
}

int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for(int i = 1; i <= k; i++)
    {
        scanf("%d",&t);
        w[t] += 20000;
    }
    for(int i = 1; i < n; i++){
        int t1,t2;
        scanf("%d %d", &t1,&t2);
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
    }
    if(k > m){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < nmax; i++)
        for(int j = 0; j < nmax; j++)
            dp[i][j] = inf;
    dfs(1,0);
    cout << dp[1][m] - 20000 * k << endl;
    fclose(stdin);
    return 0;
}