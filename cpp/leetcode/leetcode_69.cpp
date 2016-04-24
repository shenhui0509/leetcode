#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if (x <= 0) return 0;
    int low = 1, high = x;
    while (1) {
        int mid = low + (high - low) / 2;
        if (mid * mid <= x && (mid + 1) * (mid + 1) > x) return mid;
        else if (mid * mid > x) high = mid - 1;
        else low = mid + 1;
    }
}

int main()
{
    for(int i = 0; i <= 256; i++){
        printf("%d ", mySqrt(i));
        if(!(i%16)) printf("\n");
    }
}