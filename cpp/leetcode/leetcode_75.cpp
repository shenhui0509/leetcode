#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums)
{
    int r = nums.size() - 1, l = 0;
    int i = 0;
    while(i <= r){
        if(nums[i] == 0){
            swap(nums[i], nums[l]);
            l++;
            i++;
        } else if(nums[i] == 1){
            i++;
        } else {
            swap(nums[i],nums[r]);
            r--;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    vector<int> test = {0,0,0,2,2,2,1,1,1,0,1,2,0,1,2,0,0,1};
    sortColors(test);
    for(auto i : test){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}