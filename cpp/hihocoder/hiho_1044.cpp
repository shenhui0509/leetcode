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

const int mmax = 15;
const int nmax = 10000+5;
int w[nmax];
int n,q,m;
int ans;
int dp[nmax][2000];

int count_bit(int s){
    int cnt = 0;
    while(s){
        cnt += (s&1);
        s >>= 1;
    }
    return cnt;
}
int max_w(){
    memset(dp,0,sizeof(dp));
    int a,b;
    for(int i = 0; i <= n-1; i++){
        for(int j = 0; j < (1 << (m-1)); j++){
            a = j >> 1;
            b = (j >> 1) + (1 << (m-2)); 
            if(count_bit(j) < q){
                if(dp[i][j]+w[i+1] > dp[i+1][b])
                    dp[i+1][b] = dp[i][j]+w[i+1];
                if(dp[i][j] > dp[i+1][a])
                    dp[i+1][a] = dp[i][j];        

            } else if(count_bit(j) == q){
                dp[i+1][a] = max(dp[i+1][a],dp[i][j]);
            }
        }

    }

    for(int j = 0; j < (1<<(m-1));j++){
        ans = max(ans,dp[n][j]);
    }
    return ans;
}

int main(void)
{
    freopen("in","r",stdin);
    int ww;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    printf("%d\n", max_w());
    fclose(stdin);
    return 0;
}