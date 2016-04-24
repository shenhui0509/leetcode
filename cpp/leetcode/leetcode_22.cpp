#include <bits/stdc++.h>
using namespace std;

void adder(vector<string>& res, string str, int left, int right){
    if(left == 0 && right == 0){
        res.push_back(str);
        return;
    }
    if(left > 0) adder(res, str+"(",left-1,right);
    if(right > left) adder(res, str+")",left,right-1);
}

vector<string> generateParenthesis(int n){
    vector<string> ret;
    adder(ret,"", n,n);
    return ret;
}

int main(int argc, char const *argv[])
{
    vector<string> ret = generateParenthesis(3);
    for(string str : ret){
        cout << str << endl;
    }
    return 0;
}