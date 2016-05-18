#include <bits/stdc++.h>
using namespace std;

// dp
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

// dp Space optimize
int maxSubArray_opt(vector<int>& n)
{
    int m = n.size();
    if(m == 0) return 0;
    int local_max = INT_MIN, global_max = INT_MIN;
    for(int i = 0; i < m; i++){
        local_max = max(local_max + n[i], n[i]);
        global_max = max(local_max, global_max);
    }
    return global_max;
}

//divide and conquer
void maxSubArray(vector<int>& num, int l, int r, int &mx, int &lmx, int &rmx, int &sum)
{
    if(l == r){
        mx = lmx = rmx = sum = num[l];
    } else {
        int m = l + (r - l) / 2;
        int mx1, lmx1, rmx1, sum1;
        int mx2, lmx2, rmx2, sum2;
        maxSubArray(num, l, m, mx1, lmx1, rmx1, sum1);
        maxSubArray(num, m+1, r, mx2, lmx2, rmx2, sum2);
        mx = max(max(mx1, mx2), rmx1 + lmx2);
        lmx = max(sum1 + lmx2, lmx1);
        rmx = max(rmx2, sum2 + rmx1);
        sum = sum1 + sum2;
    }
}

int maxSubArray_dc(vector<int>& nums){
    if(nums.size() == 0) return 0;
    int mx, lmx, rmx, sum;
    maxSubArray(nums,0,nums.size()-1,mx,lmx,rmx,sum);
    return mx;
}


int main()
{   
    vector<int> test = {-2,-2,-3,-2,-2,-2,-11,-5,-4};
    cout << maxSubArray(test) << endl;
    
    return 0;
}