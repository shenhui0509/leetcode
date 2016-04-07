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

typedef pair<int, int> vec_t;

inline bool is_parallel(const vec_t& a, const vec_t& b){
    return a.first * b.second == a.second * b.first;
}

inline bool is_vertical(const vec_t& a, const vec_t&b){
    return a.first * b.first + a.second * b.second == 0;
}

inline bool is_same_len(const vec_t& a, const vec_t& b)
{
    return a.first * a.first + a.second * a.second == b.first * b.first + b.second * b.second;
}

inline bool is_zero_len(const vec_t &a){
    return a.first * a.first + a.second * a.second == 0;
}

inline bool is_rect(vector<vec_t>& vecs)
{
    if(vecs.size() != 4)
        return false;
    vec_t vec_1 = vecs.back();
    vecs.pop_back();
    vec_t para_vec;
    bool have_parallel = false;
    for(auto i = vecs.begin(); i != vecs.end(); i++){
        if(is_parallel(vec_1, *i)){
            have_parallel = true;
            para_vec = *i;
            vecs.erase(i);
            break;
        }
    }
    if(!have_parallel) return false;
    if(!is_parallel(vecs[0], vecs[1])) return false;
    if(!is_same_len(vec_1, para_vec) || !is_same_len(vecs[0], vecs[1])) return false;
    if(!is_vertical(vec_1,vecs[0])) return false;
    if(is_zero_len(vec_1) || is_zero_len(vecs[0])) return false;
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<vec_t> vecs;
    int m;
    while(n--){
        m = 4;
        int a,b,c,d;
        while(m--){
            cin >> a >> b >> c >> d;
            vecs.push_back(make_pair(c-a,d-b));
        }
        if(is_rect(vecs)) cout << "YES" << endl;
        else cout << "NO" << endl;
        vecs.clear();
    }
    return 0;
}