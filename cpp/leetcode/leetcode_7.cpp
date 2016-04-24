#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int ans = 0; 
    int sign = x & 0x80000000;
    x = abs(x);
    while(x){
        ans = ans * 10 + x % 10;
        x /= 10;

        if(ans < 0)
            return 0;
    }
    return sign ? -ans : ans;
}

int main(void)
{
    cout << reverse(1000000003) << endl;
    return 0;
}