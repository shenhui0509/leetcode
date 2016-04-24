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

typedef unsigned long long ull;
const ull mod= 1e9+7;

ull ans;
int m,n;
void dfs(int sum, int remain, ull product){
    if(remain == 0){
        if(product % m == 0){
            ans++;
            ans = ans % mod;
        }
    }

    for(int i = sum; i <= remain;i++){
        dfs(1 + i, remain - i, product * i);
    }
}

int main(int argc, char const *argv[])
{
    ans = 0;
    scanf("%d %d", &n, &m);
    dfs(1,n,1);
    cout << ans << endl;
    return 0;
}