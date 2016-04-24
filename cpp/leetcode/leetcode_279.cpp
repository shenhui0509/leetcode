#include <bits/stdc++.h>
using namespace std;

int num_square_dp(int n)
{
    if(n <= 0) return 0;
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j*j <= i; j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    return dp[n];
}

int num_square_static_dp(int n){
    if(n <= 0) return 0;
    static vector<int> dp(1,0);
    while(dp.size() <= n){
        int m = dp.size();
        int cnt = INT_MAX;
        for(int i = 1; i * i <= m; i++){
            cnt = min(cnt, dp[m-i*i] + 1);
        }
        dp.push_back(cnt);
    }
    return dp[n];
}

int num_square_math(int n){
    auto is_sqrt = [](int n){int sqrt_n = static_cast<int>(sqrt(n)); return (sqrt_n * sqrt_n == n);};
    if(n <= 0) return 0;
    if(is_sqrt(n)) return 1;
    while((n&3) == 0){
        n >>= 2;
    }
    if((n&7) == 7){
        return 4;
    }
    int sqrt_n = int(sqrt(n));
    for(int i = 1; i <= sqrt_n; i++){
        if(is_sqrt(n-i*i)){
            return 2;
        }
    }
    return 3;
}

int num_square_bfs(int n){
    if(n <= 0) return 0;
    vector<int> perfect_squares;
    vector<bool> visited(n,false);
    for(int i = 1; i*i <= n; i++){
        perfect_squares.push_back(i*i);
        visited[i*i-1] = true;
    }
    if(perfect_squares.back() == n){
        return 1;
    }
    queue<int> q;
    for(auto& i : perfect_squares){
        q.push(i);
    }
    int curcnt = 1;
    while(!q.empty()){
        curcnt++;
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            int tmp = q.front();
            for(auto& j : perfect_squares){
                if(tmp+j==n){
                     return curcnt;
                 }
                else if(tmp + j < n && !visited[tmp+j-1]){
                    visited[tmp+j-1] = true;
                    q.push(tmp+j);
                }
                else if(tmp + j > n){
                    break;
                }
            }
            q.pop();
        }
    }
    return 0;
}

int main()
{
    for(int i = 1; i < 3; i++){
        printf("%d %d %d %d %d\n", i, num_square_dp(i), num_square_static_dp(i), num_square_math(i), num_square_bfs(i));
    }
}