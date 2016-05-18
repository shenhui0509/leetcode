#include <bits/stdc++.h>
using namespace std;

int numTrees(int n)
{
    vector<int> dp(n+1,0);
    d[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i] += dp[j-1]*dp[i-j];
    return dp[n];
}

/*    
Hope it will help you to understand :

    n = 0;     null   

    count[0] = 1


    n = 1;      1       

    count[1] = 1 


    n = 2;    1__                    __2     
                  \                 /                 
                 count[1]       count[1]    

    count[2] = 1 + 1 = 2



    n = 3;    1__                     __2__                    __3
                  \                 /       \                 /     
              count[2]        count[1]    count[1]      count[2]

    count[3] = 2 + 1 + 2  = 5



    n = 4;    1__                   __2__                      ___3___                  
                  \              /        \                   /       \         
              count[3]       count[1]    count[2]         count[2]   count[1]

                 __4                
               /
           count[3]   

    count[4] = 5 + 2 + 2 + 5 = 14     


And  so on...
*/