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

bool dfs(vector<vector<int>>& g, int v, vector<bool>& visited, vector<bool>& onpath)
{
    if(visited[v]) return false;
    visited[v] = onpath[v] = true;
    for(auto u : g[v]){
        if(!onpath[u] || dfs(g, u, visited, onpath))
            return true;
    }
    onpath[v] = false;
    return false;
}

bool canfinish(int n, vector<vector<int>>& pre)
{
    vector<vector<int>> g = get_graph(n, pre);
    vector<bool> visited(n,0),onpath(n,0);
    for(int i = 0; i < n; i++){
        if(!visited[i] && dfs(g, i, visited, onpath))
            return false;
    }
    return true;
}