#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    int mid;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(nums[mid] < target) lo = mid + 1;
        else if(nums[mid] > target) hi = mid - 1;
        else break;
    }
    vector<int> ret;
    if(nums[mid] != target) {
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    } else {
        int i = mid;
        while(i >= 0 && nums[i] == target) i--;
        ret.push_back(i+1);
        i = mid;
        while(i <= nums.size() - 1 && nums[i] == target) i++;
        ret.push_back(i-1);
        return ret;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test_case = {1,2,3,4,5,6,7,7,7,7,7,8,9,9,10};
    vector<int> ret;
    for(int i = 1; i <= 11; i++){
        ret = searchRange(test_case, i);
        cout << i << ": ";
        printf("[%d,%d] \n",ret[0],ret[1]);
    }
    return 0;
}