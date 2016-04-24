#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    for(int i = 0; i < nums.size(); i++){
        int remain = target - nums[i];
        for(int j = i+1; j < nums.size(); j++){
            if(remain == nums[j]) return vector<int>{i,j};
        }
    }
    return vet
}

int main()
{
    
    return 0;
}