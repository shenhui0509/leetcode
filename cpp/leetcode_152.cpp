#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums)
{
    int n = nums.size();
    int front = 1, back = 1, ans = INT_MIN;
    for(int i = 0; i < n; ++i){
        front *= nums[i];
        back *= nums[n-i-1];
        ans = max(ans, max(front, back));
        front = front == 0 ? 1 : front;
        back = back == 0 ? 1 : back;
    }
    return ans;
}

int main(void)
{
    vector<int> test = {-1,2,3,-1,5};
    cout << maxProduct(test) << endl;
    return 0;
}