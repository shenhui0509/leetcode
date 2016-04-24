#include <bits/stdc++.h>
using namespace std;


int calculateMinHP(vector<vector<int>>& d)
{
    size_t m = d.size(), n = d[0].size();
    vector<vector<int>> hp(m+1, vector<int>(n+1,INT_MAX));
    hp[m-1][n] = 1;
    hp[m][n-1] = 1;
    for(int i = m-1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            int need = min(hp[i+1][j],hp[i][j+1]) - d[i][j];
            hp[i][j] = need <= 1 ? 1 : need;
        }
    }
    return hp[0][0];
}
int main()
{
    vector<vector<int>> d = {{1,-3,3},{0,-2,0},{-3,-3,-3}};
    cout <<  calculateMinHP(d) << endl;;
    return 0;
}