#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int n = prices.size(), k = 2;
    if(n <= 1) return 0;
    vector<vector<int>> dp(k+1, vector<int>(n,0));
    for(int j = 1; j <= k; j++){
        int tmp = dp[j-1][0] - prices[0];
        for(int i = 1; i < n; i++){
            dp[j][i] = max(dp[j][i-1], prices[i] + tmp);
            tmp = max(tmp, dp[j-1][i]-prices[i]);
        }
    }
    return dp[k][n-1];
}