#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

int dfs(const vector<vector<int>>& matrix, int x, int y, const int& m, const int& n, vector<vector<int>>& dp)
{
    if(dp[x][y]) return dp[x][y];
    for(auto &dir : directions){
        int xx = x + dir[0], yy = y + dir[1];
        if(xx < 0 || yy < 0 || xx >= m || yy>=n) continue;
        if(matrix[xx][yy] <= matrix[x][y]) continue;
        dp[x][y] = max(dp[x][y],dfs(matrix,xx,yy,m,n,dp));
    }
    return ++dp[x][y];
}

int longestIncreasingPath(vector<vector<int>>& matrix){
    int m = matrix.size();
    if(!m) return 0;
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    int ret = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ret = max(ret,dfs(matrix,i,j,m,n,dp));
        }
    }
    return ret;

}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << longestIncreasingPath(matrix) << endl;
    return 0;
}