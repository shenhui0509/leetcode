#include <unordered_set>
#include <iostream>
#include <utility>
#include <string>
#include <cstring>
using namespace std;


inline char up(char ch, int k){
    return 'A' + (ch - 'A' + k)%26;
}

char c[1111];
int main ()
{
    c[0] = 'b';
    memset(c+1, '1', 10);
    cout << c << endl;
    cout << strlen(c+1) << endl;
    cout << up('A', 26) << endl;
    int i = 1;
    while(i <= 10){
        *(c+i) += 1;
        i++;
    }
    cout << c << endl;
    cout << i;
    char s[111];
    int x,y,z;
    scanf("%5s",s);
    scanf("%d%d%d",&x,&y,&z);
    cout << s << endl;
    cout << x << y << z;
    int a[10][10];
    memset(a,0x7f,sizeof(a));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
