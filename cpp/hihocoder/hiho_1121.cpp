#include <bits/stdc++.h>
using namespace std;

const int nmax = 10010;
const int mmax = 40010;

vector<int> e[nmax];
int color[nmax];
int N,M;

bool valid()
{
    int start = 1;
    memset(color, 0, sizeof(color));
    color[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i = 0; i < e[s].size();i++){
            int to = e[s][i];
            if(color[to] == 0){
                color[to] = -color[s];
                //printf("set node %d to %d\n", to, color[to]);
                q.push(to);
                continue;
            }
            if(color[s]!=0 && color[to] == color[s])
                return false;
        }
    }
    return true;
}

int main(void)
{
    // freopen("in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i = 0; i <= N; i++){
            e[i].clear();
        }
        int u,v;
        for(int i = 1; i <= M; i++){
            scanf("%d %d", &u,&v);
            e[u].push_back(v);e[v].push_back(u);
        }     
        if(valid()) printf("Correct\n");
        else    printf("Wrong\n");   
    }

    // fclose(stdin);
    return 0;
}