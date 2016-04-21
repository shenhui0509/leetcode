#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height){
    int total = 0;
    int left = 0, right = height.size() - 1;
    int maxleft = 0, maxright = 0;
    while(left < right){
        if(height[left] <= height[right]){
            if(height[left] >= maxleft) maxleft = height[left];
            else total += maxleft - height[left];
            left++;
        } else {
            if(height[right] >= maxright) maxright = height[right];
            else total += maxright - height[right];
            right--;
        }
    }
    return total;
}

int main(int argc, char const *argv[])
{
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(test) << endl;
    return 0;
}