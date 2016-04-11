#include <bits/stdc++.h>
using namespace std;
const int nmax = 105;
int dp[nmax][nmax][2];
int m[nmax][nmax];
int N,M;

void update(int &val, int a)
{
    val = min(val, a);
}
int solve(){
    memset(dp, 0x7f7f7f7f, sizeof(dp));
    dp[1][0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(m[i+1][j]) dp[i][j][0] = min(dp[i][j-1][0],dp[i-1][j][1]);
            else dp[i][j][0] = min(dp[i][j-1][0], dp[i-1][j][1] + 1);
            if(m[i][j+1]) dp[i][j][1] = min(dp[i][j-1][0],dp[i-1][j][1]);
            else dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][0] + 1);
            if(m[i][j]){
                dp[i][j][0]++;
                dp[i][j][1]++;
            }
            cout << dp[i][j][0] << " " << dp[i][j][1] << "  ";
        }
        cout << endl;
    }
    return min(dp[N][M][0],dp[N][M][1]);
}

int main(void)
{
    freopen("in", "r", stdin);
    scanf("%d %d", &N,&M);
    char buf[111];
    memset(m,0x01,sizeof(m));
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