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

bool isUgly(int num) {
    while(num % 2 == 0){
        num = num / 2;
    }
    while(num % 3 == 0){
        num = num / 3;
    }
    while(num % 5 == 0){
        num = num / 5;
    }
    return num == 1;
}

int main(void)
{
    freopen("in","r",stdin);
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        cout << a ;
        if(isUgly(a))
            cout << " is ugly" << endl;
        else 
            cout << " is beautiful" << endl;
    }
    fclose(stdin);
    return 0;
}