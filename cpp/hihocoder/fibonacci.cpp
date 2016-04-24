#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;
const LL mod = 100000000007;
vector<int> fib(27,1);
map<int, int>f_index;

void init()
{
    int i;
    f_index.insert(make_pair(1,2));
    for(i = 3; i <= 26; i++){
        fib[i] = fib[i-1]+fib[i-2];
        f_index.insert(make_pair(fib[i],i));
    }
}

int main()
{
    int i;
    init();
    LL dp[27];
    LL cnt = 0;
    LL ones_cnt = 0;
    memset(dp,0,sizeof(dp));
    int n;
    cin >> n;
    int x;
    for(i = 1; i <= n; i++){
        cin >> x;
        if(x == 1){
            cnt = (cnt + ones_cnt + 1) % mod;
            ones_cnt++;
            dp[2] = (ones_cnt - 1) * (ones_cnt) / 2;
        } else if(f_index.find(x) != f_index.end()){
            dp[f_index[x]] = (dp[f_index[x]] + dp[f_index[x]-1]) % mod;
            cnt = (cnt + dp[f_index[x]-1]) % mod;
        }
    }
    cout << cnt << endl;
    return 0;
}