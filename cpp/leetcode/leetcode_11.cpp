#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height){
    int maxA = 0;
    int i = 0, j = height.size() - 1;
    while(i < j){
        int h = min(height[i],height[j]);
        maxA = max(maxA,h*(j-i));
        while(height[i] <= h && i < j) i++;
        while(height[j] <= h && j > i) j--;
    }
    return maxA;
}