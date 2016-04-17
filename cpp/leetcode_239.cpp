#include <bits/stdc++.h>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k){
    deque<int> q;
    vector<int> win;
    if(nums.empty() || k <=0) return win;

    for(int i = 0; i < nums.size(); i++){
        while(!q.empty() && nums[q.back()] <= nums[i]){
            printf("current queue tail: (%d, %d)\n", q.back(), nums[q.back()]);
            q.pop_back(); 
        }
        q.push_back(i);
        if(q.front() <= i - k){
            printf("current queue head: (%d, %d)\n", q.front(), nums[q.front()]);
            q.pop_front();
        }
        if(i >= k-1){
            printf("push current queue head: (%d, %d)\n", q.front(), nums[q.front()]);
            win.push_back(nums[q.front()]);
        }   
    }
    return win; 
}

int main(int argc, char const *argv[])
{
    vector<int> tests = {3,3,5,5,6,7};
    vector<int> win = maxSlidingWindow(tests, 3);
    cout << win.size() << endl;
    return 0;
}