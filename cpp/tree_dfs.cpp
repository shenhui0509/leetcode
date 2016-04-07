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
#include <bitset>
using namespace std;
#define mx 111

int m, ok, j, order[mx], flag[mx][mx];
bitset<mx> digit[mx];//all the cities that can be reached from the city
vector<int> u[mx]; //the edges

void can_reach(int a, int v)
{
    digit[a][a] = 1;
    for(int i = 0; i < u[a].size(); i++){
        int to = u[a][i];
        if(to == v)  continue;
        can_reach(to, a);
        digit[a] |= digit[to];
    }
}

void dfs(int a, int v)
{
    if(a == order[j])
        j++;
    if(j == m){
        ok = 1;
        return;
    }
    while(j < m) {
        int p = j, c = order[j];
        for(int i = 0; i < u[a].size(); i++){
            int b = u[a][i];
            if(b == v)
                continue;
            if(digit[b][c] && flag[a][b]){
                flag[a][b] = 0;
                dfs(b,a);
                break;
            }
        }
        if(p == j) {
            break;
        }
    }
}

int main()
{
    int a,b,i,t,n;
    scanf("%d", &t);
    while(t--){
        ok = j = 0;
        memset(flag, 0, sizeof(flag));
        for(i = 0; i < mx; i++)
        {
            digit[i].reset();
            u[i].clear();
        }
        scanf("%d", &n);
        for(i = 1; i < n; i++){
            scanf("%d%d", &a,&b);
            u[a].push_back(b);
            u[b].push_back(a);
            flag[a][b] = flag[b][a] = 1;
        }
        scanf("%d", &m);
        for(i = 0; i < m; i++){
            scanf("%d", &order[i]);
        }
        can_reach(1,-1);
        dfs(1,-1);
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
}