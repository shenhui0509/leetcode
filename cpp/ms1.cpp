#include <bits/stdc++.h>
using namespace std;
const int nmax = 1005;
const int mmax = 1000005;
int T;
int N,P,W,H;
int a[nmax];

int init_value(){
    int total = 0;
    for(int i = 1; i <= N; i++){
        total += a[i];
    }
    long long pixes = P * W * H;
    int max_font = sqrt(pixes / total);
    return max_font;
}

bool check(int fs){
    long long haha = P*H;
    int total_lines = P * (H / fs);
    int cost_lines = 0;
    int num_per_line = W / fs;
    for(int i = 1; i <= N; i++){
        int tmp = a[i] / num_per_line;
        tmp+= a[i]%num_per_line == 0? 0 : 1;
        cost_lines += tmp;
    }
    return cost_lines <= total_lines;
}


int main(void)
{
    freopen("in", "r", stdin);
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d %d %d", &N, &P, &W, &H);
        memset(a,0,sizeof(a));
        for(int j = 1; j <= N; j++){
            scanf("%d", &a[j]);
        }
        int start = init_value();
        int k = 0;
        for(k = start+1; k > 0; k--){
            if(check(k))
                break;
        }
        printf("%d\n", k);
    }
    fclose(stdin);
    return 0;
}