#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int>& cite)
{
    if(cite.empty()) return 0;
    int left = 0, len = cite.size(), right = len - 1;
    while(left <= end){
        int mid = left + (end - left) / 2;
        if(cite[mid] < len - mid){
            left = mid + 1;
        } else if(cite[mid] > len - mid){
            right = mid - 1;
        } else {
            return len - mid;
        }
    }
    return len - left;
}