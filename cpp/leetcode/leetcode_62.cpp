#include <bits/stdc++.h>
using namespace std;

int uniquepath(int m, int n)
{
    int dp[m+1][n+1];
    memset(dp, 0,sizeof(dp));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(i==1 || j == 1) dp[i][j] = 1;
            else 
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            cout << dp[i][j] << endl;
        }
    }
    return dp[m][n];
}

int main()
{
    cout << uniquepath(3,3) << endl;
    return 0;
}