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
#include <set>
using namespace std;

typedef long long ll;

ll init_sum(int n, int m)
{
    int s = min(m, n);
    int l = max(m, n);
    ll sum = s * (s + 1) * (2 * s + 1) / 6;
    sum += (l == s ? 0 : ((l - s) * (s + 1) * s / 2));
    return sum;
}

int main()
{
    freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        set<int> rep;
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        ll sum = init_sum(n, m) % k;
        cout << sum << endl;
        int x = 1, y = 1;
        int step = 1;
        if (sum == 0)
            printf("%d %d\n", x, y);
        rep.insert(sum);
        while (true) {
            for (int left = 0; left <= step; left++) {
                int down = step - left;
                int diag = min(down, left);
                sum = (sum + m * n * down) % k;
                if (down == left) {
                    if (rep.find(sum) != rep.end()){
                        goto search_end;
                    } else{
                        if(sum%k!=0){
                            rep.insert(sum);
                            continue;                            
                        } else {
                            x = 1 + down;
                            y = 1 + left;
                            goto search_end;
                        }
                    }
                }
                if(left > down){
                    int re = left - down;
                    sum = (sum + (2 * n -1 - re) * re) % k;
                    if(sum==0){
                        x = down+1;
                        y = left+1;
                        goto search_end;    
                    } else {
                        if(rep.find(sum) != rep.end())
                            goto search_end;
                        else{
                            rep.insert(sum);
                            continue;
                        }
                    }
                } else {
                    int re = down - left;
                    sum = (sum + (2 * m -1 - re) * re) % k;
                    if(sum==0){
                        x = down+1;
                        y = left+1;
                        goto search_end;    
                    } else {
                        if(rep.find(sum) != rep.end())
                            goto search_end;
                        else{
                            rep.insert(sum);
                            continue;
                        }
                    }                    
                }
            }
            ++step;
        }
search_end:
        if(x == 1 && y == 1) printf("%d\n", -1);
        else printf("%d %d\n", x,y);
    }
    fclose(stdin);
    return 0;
}