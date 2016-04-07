#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> ss = {1,2,3,4,5,6,7,8};
    cout << accumulate(ss.begin(), ss.end(), 0, plus<int>());
    scanf("%d %d %d", &m, &n, &q);
}