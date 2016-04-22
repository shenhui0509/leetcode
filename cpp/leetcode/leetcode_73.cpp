#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    int first_row = 0, first_col = 0;
    int m = matrix.size(), n = m ? matrix[0].size() : 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j]==0){
                if(i==0) first_row = 1;
                if(j==0) first_col = 1;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }
    if(first_row)
        for(int i = 0; i < n; ++i){
            matrix[0][i] = 0;
        }

    if(first_col)
        for(int i = 0; i < m; ++i){
            matrix[i][0] = 0;
        }
}