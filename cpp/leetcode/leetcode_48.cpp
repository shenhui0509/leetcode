#include <bits/stdc++.h>
using namespace std;

void show_image(const vector<vector<int>>&m)
{
    for(auto line : m){
        for(auto p : line){
            printf("%d ",p);
        }
        printf("\n");
    }
}
void rotate(vector<vector<int>>& matrix)
{
    reverse(matrix.begin(), matrix.end());
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    show_image(matrix);
    rotate(matrix);
    show_image(matrix);
    return 0;
}

