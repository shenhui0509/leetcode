#include <bits/stdc++.h>
using namespace std;

void gameOfLife(vector<vector<int>>& board){
    int m = board.size(), n = m ? board[0].size() : 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int I = max(i-1,0); I < min(i+2,m); I++){
                for(int J = max(j-1,0); J < min(j+2,n); J++){
                    cnt += board[I][J] & 1;
                }
            }
            if(cnt == 3 || cnt - board[i][j] == 3){
                board[i][j] |= 2;
            }
        }
    }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; ++j){
            board[i][j] >>= 1;
        }
}