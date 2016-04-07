#include <map>
#include <vector>
#include <iotream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define N 1111
int dp[N][N];
int m,n,s,t,num,a[N];
int main()
{
    int q;
    scanf("%d", &q);
    while(q--){
        memset(dp, INT_MAX, sizeof(dp));
        scanf("%d%d%d",&n,&m,&s);
        for(int j = 0; j <= m; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            num = ceil(a[i]/s);
            for(int k = 0; k <= num; k++){
                int x = a[i] - k * s;
                x = x > 0 ? ceil(x) : 0;
                for(int j = 0; j <= m; j++){
                    if(j+k+m <= m){
                        dp[i][j+i+k] = min(dp[i][j+k+x],dp[i-1][j]+k);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j <= m; j++){
            ans = min(ans,dp[n][j]);
        }
        if(ans > m) cout << "No" << "\n";
        else cout << ans << "\n";
    }
    return 0;
}