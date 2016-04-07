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

struct person
{
    string name;
    string rep;
    person(string n):name(n),rep(n){}
};


string find_rep(string rep)
{
    if(p.name == rep)
        return p;
    else{
        p.rep = find_rep(p.rep);
        return p->rep;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        string n1,n2;
        int op;
        cin >> op >> n1 >> n2;
        if(op == 0){
            person
        }
    }
}