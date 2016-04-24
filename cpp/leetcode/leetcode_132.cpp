#include <bits/stdc++.h>
using namespace std;
//reverse
int minCut(string s)
{
    int len = static_cast<int>(s.size());
    if(len <= 1) return 0;
    vector<vector<bool>> p(len, vector<bool>(len,true));
    vector<int> dp(len,len-1);
    for(int i = len - 1; i >= 0; i--){
        for(int j = i; i <= len - 1; j++){
            if(j > i){
                p[i][j] = (s[i] == s[j]) && (p[i+1][j-1]);
            }
            if(p[i][j]){
                if(j == len - 1){
                    dp[i] = 0;
                } else {
                    dp[i] = min(1 + dp[j+1], dp[i]);
                }
            }
        }
    }
    return dp[0];
}

int __minCut(string s){
    int len = static_cast<int>(s.size());
    vector<int> dp(len+1, len-1);
    vector<vector<bool>> p(len+1,vector<bool>(len+1,true));
    for(int i = 1; i <= len; i++){
        dp[i] = i;
        for(int j = 1; j <= i; j++){
            if(s[i-1] == s[j-1]){
                if(i - j < 2 || p[j+1][i-1]){
                    p[j][i] = true;
                    if(j == 1) dp[i] = 0;
                    else dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        }
    }
    return dp[len];
}