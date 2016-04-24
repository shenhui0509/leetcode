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
#include <stack>
using namespace std;
typedef long long ll;

struct fun{
    string func;
    string ts;
    string act;
    ll difftime;
};
fun l[200000];


inline int time2int(string ts){
    int t[3];
    t[0] = stoi(ts.substr(0,2));
    t[1] = stoi(ts.substr(3,2));
    t[2] = stoi(ts.substr(6,2));
    ll count = t[0] * 60 * 60 + t[1] * 60 + t[2];
    return count;

}

inline ll time_cmp(string ts1, string ts2){
    return time2int(ts1) - time2int(ts2);
}

int main(){
    freopen("in", "r", stdin);
    int n;
    string wrong_msg = "Incrrect performance log\n";
    cin >> n;
    getchar();
    stack<fun> s;
    vector<fun> out;
    for(int i = 0; i < n; ++i){
        cin >> l[i].func;
        cin >> l[i].ts;
        cin >> l[i].act;
    }
    for(int i = 0; i < n; i++){
        if( i != 0 ){
            int diff_time = time_cmp(l[i].ts,l[i-1].ts);
            if(diff_time < 0){
                cout << wrong_msg;
                return 0;
            }
        }
        if(l[i].act == "START"){
            s.push(l[i]);
            out.push_back(l[i]);
        } else {
            if(s.empty() || s.top().func != l[i].func){
                cout << wrong_msg;
                return 0;
            }
            fun top = s.top();
            s.pop();
            int diff_time = time_cmp(l[i].ts, top.ts);
            if(diff_time < 0){
                cout << wrong_msg;
                return 0;
            }
            for(int j = 0; j < out.size(); ++j){
                if(out[j].func == l[i].func){
                    out[j].difftime = diff_time;
                    break;
                }
            }
        }
    }

    if(!s.empty()){
        cout << wrong_msg;
        return 0;
    }

    for(int i = 0; i < out.size(); i++){
        int diff = out[i].difftime;
        int s = diff%60;
        diff/=60;
        int m = diff % 60;
        diff /= 60;
        int h = diff;
        cout << out[i].func;
        printf(" %02d:%02d:%02d\n", h, m, s);
    }
    fclose(stdin);
    return 0;
}