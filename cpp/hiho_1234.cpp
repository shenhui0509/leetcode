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

int main(){
    vector<double> r;
    r.reserve(1000+10);
    r.push_back(0);
    for(int i = 1; i <= 1000; i++){
        double a = r.back();
        r.push_back((a+0.5) / 2.);
    }
    int T;
    cin >> T;
    while(T--){
        double f;
        cin >> f;
        if(find(r.begin(), r.end(), f) != r.end()){
            cout << "-1" << endl;
        } else{
            auto it = upper_bound(r.begin(),r.end(),f);
            cout << 4 * (it-r.begin()) << endl;
        }
    }
    return 0;
}