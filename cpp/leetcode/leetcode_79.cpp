#include <bits/stdc++.h>
using namespace std;

bool match(vector<vector<char>>& board, int i, int j, int m, int n,
           string& word, int k)
{
    if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '\0' || board[i][j] != word[k]){
        printf("searched or mismatch or run out of edge %d %d \n",i,j);
        return false;
    }
    if(k == word.size()-1) return true;
    printf("%c\n", board[i][j]);
    char t = board[i][j];
    board[i][j] = '\0';
    k++;
    if(match(board,i,j-1,m,n,word,k) ||
       match(board,i,j+1,m,n,word,k) ||
       match(board,i-1,j,m,n,word,k) ||
       match(board,i+1,j,m,n,word,k))
        return true;
    board[i][j] = t;
    return false;
}

bool exist(vector<vector<char>>& board, string word){
    size_t i = 0, j = 0;
    size_t m = board.size(), n = board[0].size();
    for(i=0; i < m; i++){
        for(j=0; j < n; j++){
            if(match(board,i,j,m,n,word,0))
                return true;
        }
    }
    return false;
}


int main()
{
    vector<vector<char>> board = {{'A','B','C','D'},
                                  {'S','F','C','S'},
                                  {'S','C','E','G'}};
    string word = "SCEGSCFSABCD";
    if(exist(board,word)) printf("%s\n", word.c_str());
    return 0;
}