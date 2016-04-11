#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x; 
    int y;
    point():x(0),y(0){}
    point(int a, int b):x(a),y(b){}
};

int gcd(int a, int b){
    int r;
    if(a < b) swap(a,b);
    while(b > 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
};
struct line
{
    int x;
    int y;
    int d;
    operator==(const line& rhs){
        return x==rhs.x && y == rhs.y && d == rhs.d;
    }
    line(point a, point b){
        int delta_y = b.y - a.y;
        int delta_x = b.x - a.x;
        if(delta_x == 0){
            x = 0; y = 1; d = b.x;
            return;
        }
        if(delta_y == 0){
            x = 1; y = 0; d = b.x;
            return;
        }
        int sign = (delta_x ^ delta_y) >> 31;
        delta_x = abs(delta_x); delta_y = abs(delta_y);
        int divisor = gcd(delta_x, delta_y);
        x = delta_x / divisor; y = divisor ? (-delta_y / divisor) : (delta_y/divisor);
        d = a.y * x - y * a.x;
        return;

    }
};

int max_points(vector<point>& points)
{
    unordered_map<line,unordered_set<point>> recorder;
    if(points.size() <= 2) return points.size();
    for(int i = 0; i < points.size(); i++){
        for(int j = i; j < points.size(); j++){
            line l(points[i], points[j]);
            if(counter.find(l) != counter.end()){
                recorder[l].insert(points[i]);
                recorder[l].insert(points[j]);
            } else {
                recorder.insert(make_pair(l, unordered_set<point>{points[i],points[j]}));
            }
        }
    }
    auto iter = recorder.begin();
    int m = 0;
    for(;iter!=recorder.end(); iter++){
        m = max(m,iter->second.size());
    }
    return m;
}