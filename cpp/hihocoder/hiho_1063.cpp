#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define inf 2147483647
using namespace std;

struct edge
{
    int to,len;
    edge(int x,int y) : to(x),len(y){}
};

vector<edge>e[105];
int vv[105],n,q,dp[2][105][210];

void dfs(int u,int v)
{
    dp[0][u][vv[u]] = dp[1][u][vv[u]] = 0;
    for(int i = 0;i<e[u].size();i++)//part1
    {
        int h = e[u][i].to,f = e[u][i].len;
        if(h == v)continue;
        dfs(h,u);
        for(int x = 200;x >= 0;x--)
        {
            if(dp[0][u][x] < inf)
            for(int y = 0;y <= 200 - x;y++)
            if(dp[0][h][y] < inf)
            dp[0][u][x + y] = min(dp[0][u][x + y],dp[0][u][x] + dp[0][h][y] + 2 * f);
        }
    }
    for(int i = 0;i<e[u].size();i++)//part2
    {
        int h = e[u][i].to,f = e[u][i].len;
        if(h == v)continue;
        int temp[205];
        for(int j = 0;j<=202;j++)
        temp[j] = inf;
        temp[vv[u]] = 0;
        for(int j = 0;j<e[u].size();j++)
        {
            int t = e[u][j].to,l = e[u][j].len;
            if(t == h || t == v)continue;
            for(int x = 200;x >= 0;x--)
            {
                if(temp[x] < inf)
                for(int y = 0;y <= 200 - x;y++)
                if(dp[1][t][y] < inf)
                temp[x + y] = min(temp[x + y],temp[x] + dp[0][t][y] + 2 * l);
            }
        }
        for (int x=200;x>=0;x--)
        if (temp[x]<inf)
        for (int y=0;y<=200-x;y++)
        if (dp[1][h][y]<inf)
        dp[1][u][x+y]=min(dp[1][u][x+y],temp[x]+dp[1][h][y]+f);     
    }
}

int main()
{
    cin>>n;
    int t1,t2,t3;
    for(int i = 0;i<=100;i++)
    for(int j = 0;j<=200;j++)
    dp[0][i][j] = dp[1][i][j] = inf;
    for(int i = 1;i<=n;i++)
    cin>>vv[i];
    for(int i = 1;i<n;i++)
    {
        cin>>t1>>t2>>t3;
        e[t1].push_back(edge(t2,t3));
        e[t2].push_back(edge(t1,t3));
    }
    dfs(1,0);
    cin>>n;
    int l;
    while(n--)
    {
        int ans;
        cin>>l;
        for (ans=200;ans>=1;ans--)
        if (dp[1][1][ans]<=l) break;
        printf("%d\n",ans);
    }
    return 0;
}
