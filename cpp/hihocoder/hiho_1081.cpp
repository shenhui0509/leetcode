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

#define mx 1000+10

int g[mx][mx];
vector<bool> vis;
int ans;
int M,N,S,T;

void get_min(int s)
{
    vis[s] = true;
    while(!vis[T]){
        int min_len = INT_MAX;
        int next;
        for(int i = 1; i <= N; i++){
            if(!vis[i] && g[s][i] != 0 && g[s][i] < min_len){
                min_len = g[s][i];
                next = i;
            }
        }
        vis[next] = true;
        for(int i = 1; i <= N; i++){
            if(!vis[i] && g[next][i] != 0){
                if(g[s][i] == 0)
                    g[s][i] = g[next][i] + min_len;
                else{
                    g[s][i] = min(g[next][i]+min_len, g[s][i]);
                }
            }
        }   
    }
}

int main(int argc, char const *argv[])
{
    freopen("in","r",stdin);
    scanf("%d %d %d %d", &N, &M, &S, &T);
    vis.resize(N+1,false);
    for(int i = 1; i <= N; i++){
        memset(g[i], 0, N+1);
    }
    while(M--){
        int i,j,w;
        scanf("%d %d %d", &i, &j, &w);
        if(g[i][j] == 0)
            g[i][j] = g[j][i] = w;
        else{
            g[i][j] = g[j][i] = min(g[i][j],w);
        }
    }
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= N; j++){
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
    get_min(S);
    cout << g[S][T] << endl;
    fclose(stdin);
    return 0;
}