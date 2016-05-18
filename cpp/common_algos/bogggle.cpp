#include <bits/stdc++.h>
#include "utils.hpp"
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    int mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (nums[mid] >= target) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int lb(vector<int>& nums, int key){
    int lo = 0, hi = nums.size() - 1;
    int mid;
    while(lo < hi){
        mid = lo + (hi - lo) / 2;
        if(key > nums[mid]) lo = mid + 1;
        else hi = mid; 
    }
    return lo;
}

int ub(vector<int>& nums, int key){
    int lo = 0, hi = nums.size() - 1;
    int mid;
    while(lo < hi){
        mid = lo + (hi - lo) / 2;
        if(key < nums[mid]) hi = mid;
        else lo = mid+1;
    }
    return hi;
}
int main()
{
    vector<int> test = {1,2,3,3,3,3,3,3,5};
    cout << lb(test,3) << " " << ub(test,3) << endl;
    test.erase(remove_if(test.begin(), test.end(),[](int x){return x==0;}),test.end());
    string s("ABCD");
    cout << (s[4] == '\0') << endl;
    print_vector(test);
    cout << (5&6&7&8) <<endl;
    return 0;
}