#include <bits/stdc++.h>
using namespace std;

int test(int a, int b, int c){
    return (a&c)^(b&c);
}

int main(int argc, char const *argv[])
{
    vector<int> a = {0,1};
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++){
                // printf("(%d and %d) xor (%d and %d) = %d\n",
                    // a[j],a[i],a[k],a[i],test(a[j],a[k],a[i]));
                // printf("(%d | %d) & %d = %d\n", a[j],a[k],a[i],(a[j]^a[k])&a[i]);
                // printf("%d ^ (%d & %d) = %d\n", a[j],a[k],a[i],a[j]^(a[k]&a[i]));
                printf("(%d ^ %d) | (%d ^ %d) = %d\n",a[i],a[j],a[i],a[k],(a[i]^a[j])|(a[i]^a[k]));
                printf("%d ^ %d ^ %d = %d\n",a[i],a[j],a[k],a[i]^a[j]^a[k]);
            }
    return 0;
}