#include <bits/stdc++.h>
using namespace std;

void solveSudoku(vector<vector<char>>& board)
{
    __solveSudoku(board,0);
}

bool can_place(vector<vector<char>>& board, int i, int j, char c)
{
    for(int k = 0; k < 9; k++){
        if(board[i][k] == c) return false;
        if(board[k][j] == c) return false;
        int r = i/3*3+j/3;
        if(board[r/3*3+k/3][r%3*3+k%3] == c) return false;
    }
    return true;
}
bool __solveSudoku(vector<vector<char>>& board, int cur)
{
    if(cur == 81) return true;
    int i = cur / 9, j = cur % 9;
    if(board[i][j] != '.'){
        return __solveSudoku(board, cur+1);
    } else {
        for(char c = '1'; c <= '9'; c++){
            if(can_place(board,i,j,c)){
                board[i][j] = c;
                if(__solveSudoku(board,cur+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
}