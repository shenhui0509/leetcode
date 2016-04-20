#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> countSmaller(vector<int>& nums){
        vector<int> ret = nums;
        int len = (int) nums.size();
        unordered_map<int,int> reflect;
        array.resize(len+1);
        sort(ret.begin(), ret.end());
        for(int i = 0; i < len; ++i){
            reflect[ret[i]] = i+1;
        }
        for(int i = len - 1; i >= 0; --i){
            ret[i] = query(reflect[nums[i]] - 1);
            add(reflect[nums[i]],1);
        }
        return ret;
    }
private:
    vector<int> array;
    inline int lowbit(int pos){
        return pos & (-pos);
    }
    void add(int pos, int val){
        long len = array.size();
        while(pos < len){
            array[pos] += val;
            pos += lowbit(pos);
        }
    }
    int query(int pos){
        int ret = 0;
        while(pos > 0){
            ret += array[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
}