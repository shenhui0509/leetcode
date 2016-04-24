#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>&nums, int target){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] < target)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return low;
}

int main(int argc, char const *argv[])
{
    vector<int> test = {1,2,3,4,5,6,7,8};
    for(int i = -1; i <= 4; i++){
        cout << i << " : " << searchInsert(test,i) << endl;
    }
    return 0;
}