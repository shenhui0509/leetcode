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

void post_order(string prev, string in)
{
    if(prev.size() == 0 || in.size() == 0)  return;
    char root = prev[0];
    string::size_type index = in.find(root);

    string pre_l = prev.substr(1, index);
    string in_l = in.substr(0,index);
    string pre_r = prev.substr(index + 1, prev.length() - index - 1);
    string in_r = in.substr(index + 1, in.length() - index - 1);

    post_order(pre_l, in_l);
    post_order(pre_r, in_r);
    cout << root;
}

int main()
{
    string pre, in;
    cin >> pre >> in;
    post_order(pre, in);
    cout << endl;
    return 0;
}