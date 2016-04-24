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
#include <set>
using namespace std;

vector<bool> vis[10] = {{1,0,0,0,0,0,0,0,0,0},
                        {1,1,1,1,1,1,1,1,1,1},
                        {1,0,1,1,0,1,1,0,1,1},
                        {0,0,0,1,0,0,1,0,0,1},
                        {1,0,0,0,1,1,1,1,1,1},
                        {1,0,0,0,0,1,1,0,1,1},
                        {0,0,0,0,0,0,1,0,0,1},
                        {1,0,0,0,0,0,0,1,1,1},
                        {1,0,0,0,0,0,0,0,1,1},
                        {0,0,0,0,0,0,0,0,0,1}};
char buf[555];
int main(void)
{
    freopen("in","r",stdin);
    string k;
    int m;
    scanf("%d", &m);
    while(m--){
        scanf("%s",buf);
        int len = strlen(buf);
        char result[555];
        int i = 1;
        result[0] = buf[0];
        bool tag = false;
        while(i < len){
            int prev = result[i-1];
            int cur = buf[i] - '0';
            int start = tag ? cur : 9;
            int j;
            for(j = start; j>=0; j--)
                if(vis[prev][j])
                    break;
            if(j >= 0){
                result[i] = j + '0';
                i++;
                tag = false;
            }

        }
        printf("%s\n",result);
    }
    fclose(stdin);
    return 0;
}