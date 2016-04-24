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

const int kmax = 25;
const int nmax = 105;
const int mmax = 10005;
int k;
int N,M;
int h,w;
struct con
{
    int h,w;
    char m[nmax][nmax];
};

con cons[kmax];
char sky[nmax][mmax];

bool __check(int i, int x, int y)
{
    for(int k = 0; k < cons[i].h; k++){
        for(int j = 0; j < cons[i].w; j++){
            if(cons[i].m[k][j]^sky[x+k][y+j])
                return false;
        }
    }
    return true;
}

bool check(int i)
{
    for(int x = 0; x + cons[i].h <= M; x++){
        for(int y = 0; y + cons[i].w <= N; y++){
            if(__check(i,x,y))
                return true;;
        }
    }
    return false;
}

int main(void)
{
    freopen("in","r",stdin);
    scanf("%d", &k);
    char buf[1005];
    for(int i = 1; i <= k; i++){
        scanf("%d %d",&cons[i].h,&cons[i].w);
        for(int j = 0; j < cons[i].h; j++){
            scanf("%s",buf);
            strcpy(cons[i].m[j],buf);
        }
    }
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%s",buf);
        strcpy(sky[i],buf);
    }
    for(int i = 1; i <= k; i++){
        if(check(i)) printf("YES\n");
        else printf("NO\n");
    }
    fclose(stdin);
    return 0;
}