#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>&n){
    int m = n.size();
    if(m == 0) return 0;
    vector<int> dp(m, 0);
    dp[0] = n[0];
    int ret = dp[0];
    for(int i = 1; i < m; ++i){
        dp[i] = (dp[i-1] < 0 ? 0 : dp[i-1]) + n[i];
        ret = max(ret, dp[i]);
    }
    return ret;
}
int main()
{   
    vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(test) << endl;
    
    return 0;
}