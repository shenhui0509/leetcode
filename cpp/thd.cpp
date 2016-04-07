#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>
using namespace std;

typedef vector<map<int,int>> edge_t;
typedef vector<map<int,int>> count_t;

count_t init(edge_t edges)
{
    auto size = edge_t.size()
    vector<int> degrees(size,0);
    count_t count;
    vector<bool> visited(size,false);
    int nums = dfs(0,count,visited);
    return count;
}

int dfs(int root, count_t &count)
{

}

int main()
{
    int n, m;
    cin >> n >> m;
    int i,j,len;
    vector<vector<int>> graph = construct(n);
    count_t counter;
    while(n > 1){
        cin >> i >> j >> len;
        if(i < j)
            swap(i,j);
        graph[i-1][j-1] = len;
        counter.insert(make_pair(make_pair(i,j),make_pair(len,1)));
        n--;
    }
    process(graph, counter);
    int THD = 0;
    auto iter = counter.begin();
    for(; iter != counter.end(); iter++){
        THD += (iter->second.first) * (iter->second.second);
    }
    string instruct;
    while(m > 0){
        cin >> instruct;
        if(instruct.substr(0,5).compare("QUERY") == 0){
            cout << THD << endl;
        }
        if(instruct.substr(0.compare("EDIT") == 0){
            cin >> i >> j >> len;
            update(THD, counter, i, j, len);
        }
        m--;
    }
}
