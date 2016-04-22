#include <bits/stdc++.h>
using namespace std;

//This is O(n^3)..............................
//Stupid
int dfs_min_height(const vector<vector<int>> g, const int n, int root)
{
    vector<int> h(n,1);
    queue<int> q;
    int max_h = 1;
    q.push(root);
    while(!q.empty()){
        int w = q.front();
        q.pop();
        for(auto u : g[w]){
            if(h[u] == 1 && u != root){
                h[u] = h[w]+1;
                max_h = max(h[u],max_h);
                q.push(u);
            }
        }
    }
    return max_h;

}
vector<int> findMinHeightTrees_fuck(int n, vector<pair<int,int>>& edges)
{
    vector<vector<int>> g(n,vector<int>());
    for(auto edge : edges){
        g[edge.first].push_back(edge.second);
        g[edge.second].push_back(edge.first);
    } 
    vector<int> h(n,0);
    for(int i = 0; i < n; i++)
        h[i] =  dfs_min_height(g,n,i);
    vector<int> ret;
    for(int i = 0; i < n; i++){
        if(ret.empty()) ret.push_back(i);
        else{
            if(h[ret.back()] < h[i]) continue;
            else if(h[ret.back()] == h[i]) ret.push_back(i);
            else{
                while(!ret.empty()) ret.pop_back();
                ret.push_back(i);
            }
        }
    }
    return ret;
}

//Right Solution, cut the leaves,until no leave left
vector<int> findMinHeightTrees(int n, vector<pair<int,int>>& edges)
{
    vector<unordered_set<int>> graph(n);
    for(auto edge : edges){
        graph[edge.first].insert(edge.second);
        graph[edge.second].insert(edge.first);
    }
    vector<int> cur;
    if( n== 1){
        cur.push_back(0);
        return cur;
    }
    for(int i = 0; i < graph.size(); i++){
        if(graph[i].size() == 1) cur.push_back(i);
    }
    while(true){
        vector<int> nxt;
        for(int node : cur){
            for(int neighbor : graph[node]){
                graph[neighbor].erase(node);
                if(graph[neighbor].size()==1) nxt.push_back(neighbor);
            }
        }
        if(nxt.empty()) return cur;
        cur.swap(nxt);
    }
}
int main(int argc, char const *argv[])
{
    vector<pair<int,int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    vector<int> res = findMinHeightTrees(6,edges);
    for(auto a : res)
        cout << a << "   ";
    return 0;
}