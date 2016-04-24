#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> get_graph(int n/*num of vertex*/, const vector<pair<int,int>>& edges)
{
    vector<vector<int>> graph(n,vector<int>());
    for(auto edge : edges){
        graph[edge.first].push_back(edge.second);
    }
    return graph;
}

bool dfs(const vector<vector<int>>&g, int vertex, vector<bool>&visited, vector<bool> onpath, vector<int>& finished)
{
    if(visited[vertex]) return false;
    visited[vertex] = 1;
    onpath[vertex] = 1
    for(auto u : g[vertex]){
        if(onpath[u] || dfs(g,u,visited,onpath,finished)){
            return true;
        }
    }
    finished.push_back(vertex);
    return onpath[vertex] = false;
}

vector<int> find_order(int n, vector<pair<int,int>> pre){
    vector<vector<int>> g = get_graph(n, pre);
    vector<bool> visited(n,0), onpath(n,0);
    vector<int> finished;
    for(int i = 0; i < n; i++){
        if(!visited[i] && dfs(g,i,visited,onpath,finished))
            return {};
    }
    reverse(finished.begin(), finished.end());
    return finished;
}

int main(int argc, char const *argv[])
{
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(1,0));
    edges.push_back(make_pair(0,1));
/*    edges.push_back(make_pair(3,1));
    edges.push_back(make_pair(3,2));
    edges.push_back(make_pair(4,3));
    edges.push_back(make_pair(1,5));
    edges.push_back(make_pair(3,6));*/
    vector<vector<int>> g = get_graph(2,edges);
    dfs(g);
    return 0;
}
