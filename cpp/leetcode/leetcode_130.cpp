#include <bits/stdc++.h>
using namespace std;

void bfs_boundary(vector<vector<char>>& board, int w, int l){
    int width = board.size();
    int length = board[0].size();
    deque<pair<int,int>> q;
    q.push_back(make_pair(w,l));
    board[w][l] = 'B';
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop_front();
        pair<int,int> adjs[4] = {{cur.first-1,cur.second},
                                {cur.first+1,cur.second},
                                {cur.first,cur.second-1},
                                {cur.first,cur.second+1}};
        for(int i = 0; i < 4; i++){
            int adjW = adjs[i].first;
            int adjL = adjs[i].second;
            if(adjW >= 0 && adjW < width && adjL >= 0 && adjL < length && board[adjW][adj:] == 'O'){
                q.push_back(make_pair(adjW,adjL));
                board[adjW][adjL] = 'B';
            }
        }
    }
}

void solve(vector<vector<char>>& board)
{
    int width = board.size();
    if(!width) return;
    int length = board[0].size();
    if(!length) return;
    for(int i = 0; i < length; i++){
        if(board[0][i] == 'O')
            bfs_boundary(board,0,i);
        if(board[width-1][i] == 'O')
            bfs_boundary(board,width-1,i);
    }
    for(int i = 0; i < width; i++){
        if(board[i][0] == 'O')
            bfs_boundary(board,i,0);
        if(board[i][length-1] == 'O')
            bfs_boundary(board,i,length-1);
    }
    for(int i = 0; i < width; ++i){
        for(int j = 0; j < length; j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            else if(board[i][j] == 'B')
                board[i][j] = 'O';
        }
    }
}