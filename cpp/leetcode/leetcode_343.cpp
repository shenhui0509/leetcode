#include <bits/stdc++.h>
using namespace std;

int integerBreak(int n)
{
    static const vector<int> refer = {1,1,1,2,4};
    if(n <= 4) return refer[n];
    if(n % 3 == 0) return pow(3, n/3);
    if(n % 3 == 1) return 4 * pow(3, n / 3 - 1);
    if(n % 3 == 2) return 2 * pow(3, n / 3);
}