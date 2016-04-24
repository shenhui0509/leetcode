#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int>& heights){
    heights.push_back(0);
    int len = heights.size(), res = 0, cur = 1;
    vector<int> s(len + 1, 0);
    s[0] = -1;
    for(int i = 1; i < len; i++){
        while(cur && heights[i] < heights[s[cur]]){
            res = max(res, heights[s[cur]] * (i - s[--cur] - 1));
        }
        s[++cur] = 1;
    }
    return res;
}

int main()
{
    vector<int> heights = {1,2,3,4,5,6,7,8};
    cout << largestRectangle(heights) << endl;
    return 0;
}