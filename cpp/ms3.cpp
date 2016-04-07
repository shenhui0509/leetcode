#include <bits/stdc++.h>
using namespace std;
const int nmax = 105;
int dp[nmax][nmax];
int m[nmax][nmax];
int N,M;

void init(){
    memset(dp,0,sizeof(dp));
    int cnt = 0;
    for(int i = 1; i<=M;i++){
        if(m[1][i] == 0)
            dp[1][i] = cnt;
        else{
            cnt++;
            dp[1][i] = cnt;
        }
    }
    cnt = 0;
    for(int i = 1; i<=N;i++){
        if(m[i][1] == 0)
            dp[i][1] = cnt;
        else{
            cnt++;
            dp[i][1] = cnt;
        }

    }
}

int solve(){
    init();
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= M; j++){
            if(m[i][j-1] == 1 && m[i-1][j] == 1){
                dp[i][j] == min(dp[i][j-1],dp[i-1][j]);
            }
            dp[i][j] += m[i][j]==1?1:0;
        }
    }
    return dp[N][M];
}

int main(void)
{
    freopen("in", "r", stdin);
    scanf("%d %d", &N,&M);
    char buf[111];
    memset(m,0,sizeof(m));
    for(int i = 1; i <= N; i++){
        scanf("%s",buf);
        for(int j = 1; j <= M; j++){
            if(buf[j-1] == '.') m[i][j] = 0;
            if(buf[j-1] == 'b') m[i][j] = 1;
        }
    }
    printf("%d",solve());
    fclose(stdin);
    return 0;
}