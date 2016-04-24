#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int num){
    return (num & 0x55555555) && (!(num & (num-1)));
}

int main(int argc, char const *argv[])
{
    for(int i = 0; i < 256; i++){
        printf("%d\n",isPowerOfFour(i) );
    }
    return 0;
}