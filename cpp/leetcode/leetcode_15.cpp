#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> rst;
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        int target = -nums[i];
        int head = i + 1;
        int tail = nums.size() - 1;
        while(head < tail){
            int sum = nums[head] + nums[tail];
            if(sum < target) head++;
            else if(sum > target) tail--;
            else {
                rst.push_back(vector<int>({nums[i],nums[head],nums[tail]}));
                while(head < tail && rst.back()[1] == nums[head]) head++;
                while(head < tail && rst.back()[2] == nums[tail]) tail--;
            }
        }
        while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
    }
    return rst;

}

int main()
{
    
    return 0;
}