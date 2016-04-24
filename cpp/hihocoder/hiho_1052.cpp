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
const char* c = "ATCG";

int solute(const string& s, int k)
{
    int ans = 0;
    int cnt[4];
    int maxi;
    int rep= s.length() - k;
    for(int i = 0; i < rep; i++){
        memset(cnt, 0, sizeof(cnt));
        for(int j = i; j < s.length(); j+=rep){
            for(int k = 0; k < 4; k++){
                if(s[j] == c[k]){
                    cnt[k]++;
                    break;
                }
            }
        }
        maxi = 0;
        for (int k = 0; k < 4; k++) {
            maxi = max(maxi, cnt[k]);
            ans += cnt[k];
        }
        ans -= maxi;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n,k;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        cin >> k;
        cout << solute(s,k) << endl;
    }
    return 0;
}