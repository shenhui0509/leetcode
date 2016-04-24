#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    istringstream in('+' + s + '+');
    long long sum = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' || op == '-') {
            sum += term;
            in >> term;
            term *= (op == '+') ? 1 : -1;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}