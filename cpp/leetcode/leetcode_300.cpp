#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int LIS(vector<int>&nums)
{
    if(nums.size() <= 1)
        return nums.size();
    vector<int> f(nums.size(),1);
    int ans = 1;
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    return ans;
}

int main(void)
{
    freopen("in","r",stdin);
    int n;
    cin >> n;
    while(n--){
        vector<int> nums;
        int m,a;
        cin >> m;
        for(int i = 1; i <= m; i++){
            cin >> a;
            nums.push_back(a);
        }
        cout << LIS(nums) << endl;

    }
    fclose(stdin);
    return 0;
}