#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& g)
{
    int m = g.size();
    if(m==0) return 0;
    int n = g[0].size();
    if(n == 0) return 0;
    vector<vector<int>> dp(m,vector<int>(n,1));
    int t = INT_MAX;
    for(int i = 0; i < n; i++){
        if(i < t && g[0][i] == 1){
            t = i;
            dp[0][i] = 0;
            continue;
        }
        if(i >= t){
            dp[0][i] = 0;
        }
    }
    t = INT_MAX;
    for(int i = 0; i < m; i++){
        if(i < t && g[i][0] == 1){
            t = i;
            dp[i][0] = 0;
            continue;
        }
        if(i >= t){
            dp[i][0] = 0;
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(g[i][j] == 1) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> g = {{1,0}};
    cout << uniquePathsWithObstacles(g) << endl;
    return 0;}
