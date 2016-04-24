#include <bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int> nums){
    vector<string> rst;
    int i = 0;
    while(i < nums.size()){
        int j = i + 1;
        while(j < nums.size() && ((nums[j-1]+1) == nums[j])) j++;
        if((j-1) > i){
            rst.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
        } else {
            rst.push_back(to_string(nums[i]));
        }
        i = j;
    }
    return rst;
}

int main(){
    vector<vector<int>> test_cases = {{1,2,3,5,6,7,9,11},
                                      {1,3,5,7,9},
                                      {1,3},
                                      {1},
                                      {1,2}};
    for(auto test : test_cases){
        vector<string> result = summaryRanges(test);
        for(string s : result){
            cout << s << "  ";
        }
        cout << endl;
    }
}