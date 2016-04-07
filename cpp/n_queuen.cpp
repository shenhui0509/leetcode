#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n==1) return vector<vector<string>>{{"Q"}};
        vector<int> pos(n,0); //pos[i] is the location that the queuen at row (i pos[i]) col
        vector<vector<string>> result;
        int i = 0;
        while(1){
            if(pos[i] < n){
                if(!can_place(pos,i)){
                    pos[i]++;
                    continue;
                }
                if(i >= n-1){
                    result.push_back(get_string(pos));
                    pos[n-1]++;
                    continue;
                }
                i++;
                continue;
            } else {
                pos[i] = 0;
                i--;
                if( i < 0 ){
                    return result;
                }
                pos[i]++;
                continue;
            }
        }
    }
private:
    bool can_place(vector<int>& placed, int k){
        for(int i = 0; i < k; i++){
            if(placed[i] == placed[k] || placed[i] - placed[k] == k - i || placed[k] - placed[i] == k - i)
                return false;
        }
        return true;
    }
    vector<string> get_string(vector<int> &pos){
        vector<string> strs(pos.size(),string(pos.size(),'.'));
        for(int i = 0; i < strs.size(); i++){
            strs[i][pos[i]] = 'Q'; 
        }
        return strs;
    }
};

int main(){
    Solution sol;
    vector<vector<string>> v = sol.solveNQueens(4);
    for(auto i : v){
        for(auto j : i){
            cout << j << endl;
        }
        cout << "------------------" << endl;
    }
}