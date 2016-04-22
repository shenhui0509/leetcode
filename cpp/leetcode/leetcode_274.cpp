#include <bits/stdc++.h>
using namespace std;

int hIndex__sort(vector<int> cite)
{
    if (citations.empty()) return 0;
    if (citations.size() == 1) {
        if (citations[0] >= 1) return 1;
        else return 0;
    }

    sort(citations.begin(), citations.end());
    size_t n = citations.size();
    int h = 0;
    for (size_t i = n - 1; i >= 0; --i) {
        int tmp = h + 1;
        if (citations[i] >= tmp) {
            h = tmp;
            continue;
        } else {
            break;
        }
    }
    return h;
}

int hIndex(vector<int>& cite)
{
    size_t len = cite.size();
    vector<int> cnt(len+1,0);
    for(int i : cite){
        if(i > len)
            cnt[len]++;
        else
            cnt[i]++;
    }
    int total = 0;
    for(int i = len; i >= 0; --i){
        total += cnt[i];
        if(total >= i)
            return i;
    }
    return 0;
}