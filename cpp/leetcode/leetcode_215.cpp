#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int left, int right)
{
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (nums[j] >= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

int findKthLargest(vector<int>& nums, int k)
{
    int left = 0, right = nums.size() - 1;
    int p;
    while (1) {
        p = partition(nums, left, right);
        if (p == k - 1) return nums[p];
        else if (p < k - 1) left = p + 1;
        else right = p - 1;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test = {1, 7, 8, 9, 5, 3, 2, 6};
    cout << findKthLargest(test, 4) << endl;
    return 0;
}