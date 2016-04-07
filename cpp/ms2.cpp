#include <bits/stdc++.h>
using namespace std;
const int nmax = 1000005;

struct ip{
    int addr,mask;
};

vector<ip> a_table;
vector<ip> d_table;
int allow_set = 0;
int mask = 0xffffffff << 12;

int ip_string_to_int(char* c){
    int a[4];
    sscanf(c,"%d.%d.%d.%d", &a[0],&a[1],&a[2],&a[3]);
    int result = 0x00;
    for(int i = 0; i <= 3; i++){
        result |= (a[i] << (8*(3-i)));
    }
    return result;
}

void check(int ip){
    if(!((ip&mask) ^ (mask & allow_set))) printf("%x is allowed\n",ip);
    else printf("%x is not allowed\n",ip);
}

int main()
{
    freopen("in","r",stdin);
    int n,m;
    scanf("%d %d\n",&n,&m);
    char buf[123];
    for(int i = 1; i <= n; i++){
        gets(buf);
        int len = strlen(buf);
        printf("%s\n", buf);
        if(/*buf[0] == 'a'*/true){
            int addr = ip_string_to_int(buf+6);
            int k = len-1;
            for(; k>0&&buf[k]!='/';k--);
            //printf("%d\n", k);
            int mask;
            if(k == 0) mask = 0xffffffff;
            else{
                mask = 0xffffffff << (32 - atoi(buf+(k+1)));
            }
            printf("%x\n", mask);
        }
    }
    printf("%x\n",0xffffffff << 32);
    check(ip_string_to_int("1.2.3.4"));
    check(ip_string_to_int("1.2.3.0"));
    check(ip_string_to_int("2.3.4.5"));
    check(ip_string_to_int("10.3.4.2"));
    fclose(stdin);
}