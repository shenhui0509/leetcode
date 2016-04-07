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
#include <queue>
using namespace std;
#define N 100000+5

int n,eee;
bool vis[N];
int fa[N];
vector<int> q[N];

void bfs_root(int s)
{
    int i,j;
    int len;
    queue<int> p;
    while(!p.empty())
        p.pop();
    p.push(s);
    vis[s] = true;
    while(!p.empty()){
        int front = p.front();
        p.pop();
        vis[front]=true;
        len = q[front].size();
        for(i = 0; i < len; i++){
            if(vis[q[front][i]] == false){
                fa[q[front][i]] = fa[front] + 1;
                vis[q[front][i]] = true;
                p.push(q[front][i]);
            }
        }
    }

    eee = 1;
    int ff = fa[1];
    for(j = 2; j <= n; j++){
        if(fa[j] > ff){
            eee = j;
            ff =fa[j];
        }
    }
}

void bfs_eee(int e)
{
    int i,j,len;
    queue<int>p;
    while(!p.empty())
        p.pop();
    vis[e] = true;
    p.push(e);
    while(!p.empty()){
        int front = p.front();
        p.pop();
        vis[front] = true;
        len = q[front].size();
        for(i=0;i<len;i++){
            if(vis[q[front][i]] == false){
                fa[q[front][i]] = fa[front]+1;
                vis[q[front][i]] = true;
                p.push(q[front][i]);
            }
        }
    }
    int ans = fa[e];
    for(j=1;j<=n;j++){
        if(fa[j] > ans){
            ans = fa[j];
        }
    }
    cout << ans << endl;
}

int main(){
    //freopen("in","r",stdin);
    scanf("%d",&n);
    int i,j;
    int u,v;
    for(i = 0; i <= n; i++){
        q[i].clear();
    }
    for(i = 0; i < n-1; i++){
        scanf("%d %d", &u, &v);
        q[u].push_back(v);
        q[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    memset(fa,0,sizeof(fa));
    bfs_root(1);
    memset(vis,false,sizeof(vis));
    memset(fa,0,sizeof(fa));
    bfs_eee(eee);
    //fclose(stdin);
    return 0;
}
