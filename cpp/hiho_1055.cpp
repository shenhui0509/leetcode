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

#define N 111

int n,m,val[N], dp[N][N];
vector<int> g[N];

void dfs(int u, int p)
{
    memset(dp[u], 0, sizeof(dp[u]));
    dp[u][1] = val[u];
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v == p) continue;
        dfs(v,u);
        for(int j = m; j >= 2; j--)
            for(int k = 1; k < j; k++)
                dp[u][j] = max(dp[u][j], dp[u][j-k] + dp[v][k]);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m))
    for(int i = 1; i <= n; i++){
        scanf("%d",&val[i]);
        g[i].clear();
    }
    int u,v;
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n", dp[1][m]);
    return 0;
}