#include <bits/stdc++.h>
using namespace std;

bool gt(vector<int>& n1, int i, vector<int>& n2, int j){
    while(i < n1.size() && j < n2.size() && n1[i] == n2[j]){
        i++;
        j++;
    }
    return j == n2.size() || (i < n1.size() && (n1[i] > n2[j]));
}

vector<int> max_number(vector<int>& n, int k)
{
    int len = n.size();
    vector<int> result(k,INT_MIN);
    for(int i = 0, j = 0; i < len; i++){
        while(len-i+j > k && j > 0 && result[j-1] < n[i]) j--;
        if( j < k ) result[j++] = n[i];
    }
    return result;
}

vector<int> merge(vector<int> n1, vector<int> n2, int k)
{
    vector<int> ans(k,0);
    for(int i = 0, j = 0, r = 0; r < k; r++){
        ans[r] = gt(n1,i,n2,j) ? n1[i++] : n2[j++];
    }
    return ans;
}

vector<int> maxNumber(vector<int>& n1, vector<int>& n2, int k)
{
    int n = n1.size();
    int m = n2.size();
    vector<int> result(k,0);
    for(int i = max(0, k - m); i <= k && i <= n; ++i){
        vector<int> candidate = merge(max_number(n1, i), max_number(n2,k-i), k);
        if(gt(candidate, 0, result, 0)) result = candidate;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> a = {8,4,2,1,6,3,2}, b = {5,6,1,2,3,7,7};
    vector<int> r = max_number(a,4);
    vector<int> l = max_number(b,4);
    for(int i : r){
        cout << i << " ";
    }
    cout << endl;
    for(int j : l){
        cout << j << " ";
    }
    cout << endl;
    vector<int> res = maxNumber(a,b,6);
    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}