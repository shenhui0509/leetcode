#include <bits/stdc++.h>
using namespace std;

int findFirstMissingPositive(vector<int>& n)
{
    for(int i = 0; i < n.size(); i++){
        if(i+1 == n[i]) continue;
        int x = n[i];
        while(x>=1 && x <= n.size() && x != n[x-1])
            swap(x,n[x-1]);

    }
    for(int i = 0; i <= n.size(); i++){
        if(i+1!=n[i]) return i+1;
    }
    return n.size()+1;
}