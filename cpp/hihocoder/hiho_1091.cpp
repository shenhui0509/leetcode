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

const int nmax = 35;
const int mmax = 20000+5;
int N,M;
int a[nmax],b[nmax];
int dp[nmax][mmax];

int cost(int i,int k)
{
    int result = 0;
    int current = b[i];
    for(int i = 1; i <= k; i++){
        result += current;
        current = static_cast<int>(1.07 * current);
    }
    return result;
}

int total_damage()
{
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= M; j++){
            for(int k = 0; cost(i,k) <= j; k++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-cost(i,k)] + k * a[i]);
            }
        }
    }
    return dp[N][M];
}

int main(void)
{
    // freopen("in","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 1; i<=N;i++){
        scanf("%d %d", &a[i], &b[i]);
    }
    printf("%d", total_damage());
    // fclose(stdin);
    return 0;
}