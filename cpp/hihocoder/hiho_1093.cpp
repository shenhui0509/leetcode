#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
const int mx = 100000+1000;

struct edge
{
    int to,cost;
}e;

vector<edge> g[mx];
int m,n,s,t,d[mx];

vector<bool> vis(mx,false);

void add_edge(int u, int v, int cost)
{
    e.to = v;e.cost = cost;
    g[u].push_back(e);
    e.to = u;
    g[v].push_back(e);
}

void spfa(int s)
{
    fill(d,d+n+10,INF);
    vis[s] = true;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = 0; i < g[u].size();i++){
            int v = g[u][i].to;
            if(d[v] > d[u] + g[u][i].cost){
                d[v] = d[u] + g[u][i].cost;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            } 

        }
    }
}

int main(void)
{
    freopen("in","r",stdin);
    scanf("%d %d %d %d", &n, &m, &s, &t);
    int u,v,cost;
    for(int i =0; i < m;i++){
        scanf("%d %d %d", &u,&v,&cost);
        add_edge(u,v,cost);
    }
    spfa(s);
    printf("%d\n",d[t]);
    fclose(stdin);
    return 0;
}