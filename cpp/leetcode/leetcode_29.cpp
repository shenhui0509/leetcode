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

int divide(int dividend, int divisor) {
    if(divisor == 0) return INT_MAX;
    if(dividend < divisor) return 0;
    if(dividend == divisor) return 1; 
    
    int r_result = 1;
    int l_div, l_result;
    while(divisor <= dividend){
        l_div = divisor;
        l_result = r_result;
        divisor <<= 1;
        r_result <<= 1;
    }
   // cout << divisor << ' ' << l_result << ' ' << result << endl;
    if(divisor == dividend) return r_result;
    int r = divisor;
    int l = l_div;
    int mid;
    while(1){
        int mid = (r + l) >> 1;
        int m_result = (l_result + r_result) >> 1;
        if(dividend == mid) return m_result;
        if(dividend < mid){
            r = mid;
            r_result = m_result;
            continue;
        } else {
            l = mid+1;
            l_result = m_result;
            continue;
        }
    }
    
}

int main() {
    cout << divide(2147483647,2) << endl;
}