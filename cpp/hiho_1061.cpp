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

struct node
{
    char ch;
    int cnt;
};

int main()
{ 
    freopen("in","r",stdin);
    int tn;
    scanf("%d",&tn);
    char ch;
    node str[100000+ 12];
    int n;
    int cur;
    bool ans;
    while(tn--){
        ans = false;
        scanf("%d",&n);
        str[0].ch = 0;
        cur = 0;
        ch = getchar();
        for(int i = 0; i < n; i++){
            ch = getchar();
            if(ch!=str[cur].ch){
                cur++;
                str[cur].ch = ch;
                str[cur].cnt = 1;
            } else {
                ++str[cur].cnt;
            }
        }
        for(int i = 1; i + 2 <= cur; ++i){
            if((str[i].ch + 1 == str[i+1].ch) && 
                (str[i+1].ch + 1 == str[i+2].ch) &&
                (str[i].cnt >= str[i+1].cnt) &&
                (str[i+2].cnt >= str[i+1].cnt)){
                ans = true;
                break;
            }
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    fclose(stdin);
}