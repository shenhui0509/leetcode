#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    int res = 0;
    int sign = 1, num = 0;
    stack<int> nums, signs;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + c - '0';
        } else {
            res += sign * num;
            num = 0;
            if (c == '+') sign = 1;
            if (c == '-') sign = -1;
            if (c == '(') {
                nums.push(res);
                signs.push(sign);
                res = 0;
                sign = 1;
            }
            if (c == ')' && signs.size()) {
                res = signs.top() * res + nums.top();
                signs.pop(); nums.pop();
            }
        }
    }
    res += sign * num;
    return res;
}

