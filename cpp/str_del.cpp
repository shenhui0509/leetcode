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


string eliminate(string str)
{
    string::size_type l = str.size();
    if(l <= 1) return str;
    string t;
    for(size_t i = 0; i < l - 1; i++){
        if(str[i] == str[i+1]){
            while(i < l-1 && str[i] == str[i+1]) i++;
        } else {
            t += str[i];
        }
    }
    if(str[l-1] != str[l-2]) t+=str[l-1];
    return t;
}

int main()
{
    const char in[3] = {'A','B','C'};
    int t, max_;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        max_ = 0;
        for(int i = 0; i < s.length() - 1; i++){
            for(int j = 0; j < 3; j++){
                string inserted = s.substr(0,i+1) + in[j] + s.substr(i+1);
                int len = inserted.length();
                inserted = eliminate(inserted);
                while(len > inserted.length()){
                    len = inserted.length();
                    inserted = eliminate(inserted);
                }
                if(s.length() - len + 1 > max_) max_ = s.length() - len + 1;

            }
        }
        cout << max_ << endl;
    }
}