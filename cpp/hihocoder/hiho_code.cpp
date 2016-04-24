#include <climits>
#include <iostream>
#include <cstring>
#define N 1001
using namespace std;
int nums[N];
int main()
{
    int n;
    memset(nums,-1,sizeof(nums));
    cin >> n;
    int last;
    for(int i = 1; i <= n;i++){
        cin >> nums[i];
    }
    int flag = 1;
    for(int i = n-1; i >= 1; i--){
        if(nums[i] >= nums[i+1]){
            flag = i;
            break;
        }
    }
    for(int i = 1; i < flag; i++)
        cout << nums[i] << ' ';
    cout << endl;
    return 0;
}