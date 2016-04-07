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
typedef long long ll;

ll dp[21][21];

inline bool able(int i, int j, int x, int y){
    if(i == x && j == y)
        return false;
    if(abs(i-x)==2 && abs(j-y) == 1)
        return false;
    if(abs(i-x)==1 && abs(j-y) == 2)
        return false;
    return true;

}
int main(){

    int m,n,x,y;
    cin >> m >> n >> x >> y;
    for(int i = 0; i <= max(m,n); i++)
    {
        dp[i][0] = able(i,0,x,y) ? 1 : 0;
        dp[0][i] = able(0,i,x,y) ? 1 : 0;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(able(i,j,x,y)) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];

            }
            else {

                dp[i][j]=0;
            }
        }
    }
    cout << dp[m][n] << endl;

    return 0;
}