#include <bits/stdc++.h>
using namespace std;

vector<int> majorElement(vector<int>& nums) {
    int m1, m2, cnt1 = 0, cnt2 = 0;
    size_t len = nums.size();
    for (size_t i = 0; i < len; i++) {
        if (nums[i] == m1) cnt1++;
        else if (nums[i] == m2) cnt2++;
        else if (cnt1 == 0) {
            m1 = nums[i];
            cnt1++;
        }
        else if (cnt2 == 0) {
            m2 = nums[i];
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0; cnt2 = 0;
    for (int n : nums) {
        if (n == m1) cnt1++;
        if (n == m2) cnt2++;
    }
    if (cnt1 > (len / 3)) ret.push_back(m1);
    if (cnt2 > (len / 3)) ret.push_back(m2);
    return ret;

}