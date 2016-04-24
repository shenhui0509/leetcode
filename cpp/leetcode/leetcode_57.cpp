#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval():start(0), end(0){}
    Interval(int s, int e) : start(s), end(e){}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    vector<Interval> ret;
    auto iter = intervals.begin();
    for(;iter != intervals.end(); ++iter){
        if(newInterval.end < iter->start) break;
        else if(newInterval.start > iter->end) {
            ret.push_back(*iter);
        } else {
            newInterval.start = min(newInterval.start, iter->start);
            newInterval.end = max(newInterval.end, iter->end);
        }
    }
    ret.push_back(newInterval);
    for(;it!=intervals.end();++iter){
        ret.push_back(*iter);
    }
    return ret;
}