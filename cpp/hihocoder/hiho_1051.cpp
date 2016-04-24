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
#define mx 100
int find_max(vector<int>& arr, int m)
{
    if(m >= arr.size()) return mx;

    vector<int> work(arr.size() + 1, 0 );
    work[0] = arr[0] - 1;
    for(int i = 1; i < arr.size(); i++){
        work[i] = arr[i] - arr[i-1] - 1;
    }
    work[arr.size()] = 100 - arr.back();
    int ans = 0;
    for(int i = 0; i < work.size(); i++){
        int a = 0;
        for(int j = i; j <= i + m && j < work.size(); j++)
            a += work[j];
        ans = max(a, ans);
    }
    return ans + m;
}

int main(){
    int q;
    int n,m;
    int a;
    vector<int> arr;
    cin >> q;
    arr.reserve(n);
    while(q--){
        arr.clear();
        cin >> n >> m;
        while(n--){
            cin >> a;
            arr.push_back(a);
        }
        cout << find_max(arr, m) << endl;;
    }
}