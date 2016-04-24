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

const int nmax = 150;

map<string,string> g;

int main()
{
    freopen("in","r",stdin);
    int n,m;
    cin >> n;
    string father,son;
    g.clear();
    while(n--){
        cin >> father >> son;
        if(g.find(son) == g.end()){
            g.insert(make_pair(son,father));
        }
    }
    cin >> m;
    string m1,m2;
    while(m--){
        bool flag = false;
        cin >> m1 >> m2;
        vector<string> fs;
        while(g.find(m1)!=g.end()){
            fs.push_back(m1);
            m1 = g[m1];
        }
        while(g.find(m2)!=g.end()){
            for(auto s : fs){
                if(m2 == s){
                    cout << s << endl;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            else m2 = g[m2];
        }
        if(!flag) cout << "-1" << endl;

    }
    fclose(stdin);
    return 0;
}