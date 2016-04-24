#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3){
    if(s3.size() != s1.size() + s2.size()){
        return false;
    }

    int m = s1.size(), n = s2.size();
    bool dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i==0 && j ==0){
                dp[i][j] = true;
            } else if(i == 0){
                dp[i][j] = dp[i][j-1] && (s3[i+j-1] == s2[j-1]);
            } else if(j == 0){
                dp[i][j] = dp[i-1][j] && (s3[i+j-1] == s1[i-1]);
            } else {
                dp[i][j] = (dp[i-1][j] && (s3[i+j-1] == s1[i-1]))
                         ||(dp[i][j-1] && (s3[j+i-1] == s2[j-1]));
            }
        }
    }
    return dp[m][n];
}

int main()
{
    cout << isInterleave("aabcc","dbbca","aadbbcbcac") << endl;
    cout << isInterleave("aabcc","dbbca","aadbbbaccc") << endl;
    return 0;
}