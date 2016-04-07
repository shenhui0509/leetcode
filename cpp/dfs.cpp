#include <map>
#include <vector>
#include <iostream>
using namespace std;

void dfs(const vector<map<int, int>>& graph, int node, vector<map<int, int>>& count)
{
    map<int,int> edges = graph[node];
    int edge_num = edges.size();
    if(edge_num == 1){
        int target = edges.begin()->first;
        count[node][target]++;
        count[target][node]++;
        return;
    } else {
        for(auto iter = edges.begin(); iter != edges.end(); ++iter){
            int target = iter->first;
            count[node][target]++;
            count[target][node]++;
            dfs(graph,target,count);
        }
    }
}

int main(){
    vector<map<int,int>> graph(5,map<int,int>());
    vector<map<int,int>> count(5,map<int,int>());
    graph[0][1] = 3;
    graph[0][2] = 4;
    graph[2][3] = 5;
    graph[2][4] = 4;
    graph[3][5] = 5;
    dfs(graph,0,count);
    for(auto i : count){
        for(auto iter = i.begin(); iter != i.end(); iter++){
            cout << iter->second << '\t';
        }
        cout << endl;
    }
}