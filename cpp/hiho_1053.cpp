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

struct town
{
    int x;
    int y;
};
#define mx 100020
town t[mx];
town max_t[mx];

int main()
{
    int m;
    scanf("%d", &m);
    while(m--){
        int n,r;
        scanf("%d %d", &n, &r);
        int i;
        int x,y;
        int max_num = 0;
        int max_pop = 0;
        for(i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            t[i].x = x;
            t[i].y = y;
            if(y >= max_pop){
                max_pop = y;
                max_t[max_num].x = x;
                max_t[max_num].y = y;
                max_num++;
            } 
        }
        int ans = 0;
        for(i = 0; i < max_num; i++){
            int sum = max_t[i].y;
            int num = 1;
            for(int j = 0; j < n; j++){
                if(abs(t[j].x-max_t[i]) <= r){
                    ++num;
                    sum+=t[j].y;
                }
            }
            
        }
    }
}