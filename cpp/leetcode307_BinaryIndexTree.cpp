#include <bits/stdc++.h>
using namespace std;

class BinaryIndexTree
{
public:
    BinaryIndexTree(vector<int>& _nums):nums(_nums){
        vec.resize(_nums.size() + 1);
        pre_processing(_nums);
    }
    void update(int i, int val){
        int diff = val - nums[i];
        nums[i] = val;
        i=i+1;
        int n = vec.size();
        while(i < n){
            vec[i] += diff;
            i += lowbit(i);
        }
    }
    int sum(int n){
        n = n+1;
        int sum = 0;
        while(n > 0){
            sum+=vec[n];
            n-=lowbit(n);
        }
        return sum;
    }
private:
    int lowbit(int a){
        return a & (-a);
    }
    void pre_processing(const vector<int>& num){
        int n = vec.size();
        for(int i = 0; i < nums.size(); ++i){
            int m = i+1;
            while(m < n){
                vec[m] += nums[i];
                m += lowbit(m);
            }
        }
    }
    vector<int> vec;
    vector<int> &nums;  
};

class NumArray
{
public:
    NumArray(vector<int>& nums) : bit(nums){};
    void update(int i, int val){
        bit.update(i,val);
    }
    int sumRange(int i, int j){
        return bit.sum(j) - bit.sum(i-1);
    }
private:
    BinaryIndexTree bit;
    
};

int main(int argc, char const *argv[])
{
    vector<int> test = {1,2,34,45,6,4,6,3,2,3,56,54};
    NumArray arr(test);
    cout << arr.sumRange(1,3) << endl;
    return 0;
}