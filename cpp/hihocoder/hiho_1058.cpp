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
#define REOPEN freopen("in","r",stdin)

#define N 50001
#define M 50001
int n,m;
char str[N];
char tmp[N];
char cmd[10];
char num[20];
int offset = 0;

inline void up(char* c, int k){

    *c = ((*c - 'A') + k)%26 + 'A';
}

inline void cmd_1(int i, int j, char c){
    if(j + offset <= n){
        memset(str + i + offset, c, j - i + 1);
        return;
    }
    if(i + offset > n){
        i = i + offset - n;
        j = j + offset - n;
        memset(str + i, c, j-i+1);
        return;
    }
    if(i + offset <= n && j + offset > n){
        memset(str+offset+i,c,n-offset - i + 1);
        j = j + offset -n;
        memset(str+1, c, j);
        return;
    }
}

inline void cmd_2(int i, int j, int k){
    int index;
    while(i <= j){
        index = i+offset;
        index = index > n ? (index - n) : index;
        cout << index << endl;
        up(str+index, k);
        i++;
    }
}

inline void cmd_3(int k){
    offset = (offset + k) % n;
}

inline void cmd_4(int i, int j){
    if(i > j)
        return;
    else 
    {
        cmd_4(i+1, j);
        cmd_2(i,j,1);
    }
}

inline void recover()
{
    if(offset){
        memcpy(tmp, str+1+offset, (n-offset));
        memcpy(str+n-offset+1,str+1,offset);
        memcpy(str+1,tmp,(n-offset));
        offset = 0;
    }
    return;
}

int main(){
    REOPEN;
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    int act = -1;
    int i,j,k;
    char c;
    while(m--){
        scanf("%s", cmd);
        scanf("%d", &act);
        cout << cmd << ' ' << act << endl;;
        if(act == 1){
            scanf("%d%d %c",&i,&j,&c);
            cmd_1(i,j,c);
        } else if(act == 2){
            scanf("%d %d %d",&i,&j,&k);
            cmd_2(i,j,k);
        } else if(act == 3){
            scanf("%d", &k);
            cmd_3(k);
        } else {
            scanf("%d %d", &i,&j);
            cmd_4(i,j);
        }
    }
    recover();
    printf("%s\n", str+1);
    fclose(stdin);
}