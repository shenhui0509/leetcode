#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_max(const vector<int> need, const vector<int> value, int m)
{
    vector<int>::size_type size = need.size();
    vector<vector<int>> dp(size+1,vector<int>(m+1,0));
    for(int i = 1; i <= size; i++){
        for(int j = 0; j <= m; j++){
            if(j < need[i-1])
                dp[i][j] = dp[i-1][j];
            else{
                for(int k = 1; k <= j/need[i-1];k++)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-k*need[i-1]]+k*value[i-1]);
            }
        }
    }
    return dp[size][m];
}

int get_max_1d(const vector<int> need, const vector<int> value, int m)
{
    vector<int> dp(m+1,0);
    for(int i = 0; i < need.size();i++){
        for(int j = need[i]; j <= m; j++)
            dp[j] = max(dp[j],dp[j-need[i]] + value[i]);
    }
    return dp[m];
}

int main()
{
    vector<int> need;
    vector<int> value;
    int m;
    int n;
    cin >> m >> n;
    while(m--){
        int a,b;
        cin >> a >> b;
        need.push_back(a);
        value.push_back(b);
    }
    cout << get_max(need, value, n) << endl;
    cout << get_max_1d(need,value,n) << endl;
}