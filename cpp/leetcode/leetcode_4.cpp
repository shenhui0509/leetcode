#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double find_median(vector<int>& nums1, vector<int>& nums2)
{
    size_t n = nums1.size(), m = nums2.size();
    if(n > m) return find_median(nums2, nums1);
    int l_max, r_min;
    size_t imin = 0, imax = n, half_len = (m + n + 1) / 2;
    size_t i,j;
    while(imin <= imax){
        i = (imin + imax) >> 1;
        j = half_len - i;
        cout << i << "  " << j << "\n";
        if(i < n && j > 0 && nums2[j-1] > nums1[i]) imin = i + 1;
        else if(i > 0 && j < m && nums1[i-1] > nums2[j]) imax = i - 1;
        else{
            if(i == 0) l_max = nums2[j-1];
            else if( j == 0) l_max = nums1[i-1];
            else l_max = max(nums1[i-1],nums2[j-1]);
            cout << l_max << endl;
            break;
        }
    }

    if((m+n)&1) return 1.0 * l_max;
    if(i == n) r_min = nums2[j];
    else if(j == m) r_min = nums1[i];
    else r_min = min(nums1[i], nums2[j]);
    return (r_min + l_max) / 2.0;
}

int main(void)
{
    vector<int> nums1 = {1,3,5,7,9,11};
    vector<int> nums2 = {6,8,10,12,14,16,18};
    cout << find_median(nums1,nums2) << endl;
    return 0;
}