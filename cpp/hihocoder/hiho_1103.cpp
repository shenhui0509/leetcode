#include <bits/stdc++.h>
using namespace std;

stack<int> s;
char str[1009];
int main() {
    freopen("in", "r", stdin);
    while (gets(str) != NULL) {
        int cnt[3] = {0, 0, 0}; //r,y,b
        int len = strlen(str);
        int i = 0;
        for (; i < len; i++) {
            if (str[i] == '<') {
                if (str[i + 1] == 'r') {i += 4; s.push(0); continue;}
                else if (str[i + 1] == 'y') {i += 7; s.push(1); continue;}
                else if (str[i + 1] == 'b') {i += 5; s.push(2); continue;}
                else if (str[i + 1] == '/') {
                    s.pop();
                    if (str[i + 2] == 'r') {i += 5; continue;}
                    else if (str[i + 2] == 'y') {i += 8; continue;}
                    else if (str[i + 2] == 'b') {i += 6; continue;}
                }
            } else {
                if (s.empty()) continue;
                else if (str[i] <= 'z' && str[i] >= 'a') cnt[s.top()]++;
            }
        }
        printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
    }

    fclose(stdin);
    return 0;
}