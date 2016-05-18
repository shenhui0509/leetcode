#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void print_vector(const vector<int>& vec)
{
    for(int i : vec)
        printf("%d ", i);
    printf("\n");
    return;
}