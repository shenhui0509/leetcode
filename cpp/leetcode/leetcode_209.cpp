#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    if(!n) return 0;
    int start = 0, i = 0 ,min_len = INT_MAX, sum = 0;

    for(i = 0; i < n; i++){
        sum += nums[i];
        while(sum >= s){
            min_len = min(min_len, i - start + 1);
            sum -= nums[start++];
        }
    }
    return min_len == INT_MAX ? 0 : min_len;
}

int main(int argc, char const *argv[])
{
    vector<int> test_case = {1,5,2,3,4,3,5};
    printf("%d\n", minSubArrayLen(8,test_case));
    return 0;
}