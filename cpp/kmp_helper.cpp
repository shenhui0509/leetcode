#include <bits/stdc++.h>
using namespace std;

vector<int> get_next(const string &p)
{
    int m = p.size();
    vector<int> next(m,0);
    next[0] = -1;
    int i = 0, j = -1;
    while(i < m){
        if(j == -1 || p[i] == p[j]){
            i++;j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
    return next;
}

vector<int> get_overlay(const string& p){
    int m = p.size();
    vector<int> overlay(m, 0);
    int i = 1;
    for(; i < m; i++){
        int j = overlay[i-1];
        while( j > 0 && p[j] != p[i]) j = overlay[j-1];
        overlay[i] = (j += p[i] == p[j]);   
    }
    return overlay;
}

int main(void)
{
    freopen("in","r",stdin);
    string pattern;
    cin >> pattern;
    vector<int> next,over;
    next = get_next(pattern);
    over = get_overlay(pattern);
    for(auto i : next){
        printf("%d\t", i);
    }
    printf("\n");
    for(auto i : over){
        printf("%d\t", i);
    }
    printf("\n");
    fclose(stdin);
    return 0;
}