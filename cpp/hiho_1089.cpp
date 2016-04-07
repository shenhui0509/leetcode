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
#define inf 0x3f3f3f3f
const int nmx = 105;
int n,m;

int g[nmx][nmx];

void floyd()
{

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if( g[j][i]+g[i][k] < g[j][k]){
                    g[j][k] = g[j][i]+g[i][k];
                }
            }
        }
    }
}

int main(void)
{
    //freopen("in","r",stdin);
    scanf("%d %d",&n,&m);
    int u,v,l;
    memset(g,inf, sizeof(g));
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &u, &v, &l);
        g[u][v] = min(g[u][v],l);
        g[v][u] = min(g[v][u],l);
    }
    for(int i = 1; i <= n; i++)
        g[i][i] = 0;
    floyd();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <n; j++){
            printf("%d ", g[i][j]);
        }
        printf("%d\n",g[i][n]);
    }
    //fclose(stdin);
    return 0;
}