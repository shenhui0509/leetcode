#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct adj_link
{
    size_t num_vertices;
    vector<unordered_set<int>> adjs;
    adj_link(int n) : num_vertices(n){
        adjs.resize(num_vertices, unordered_set<int>());
    }
    unordered_set<int>& operator[](size_t i){
        return adjs[i];
    }
};
class Graph
{
public:
    Graph(){};
    virtual ~Graph(){}
    virtual void addEdge(int u, int v) = 0;
    virtual vector<int> bfs(int source) = 0;
    virtual vector<int> dfs(int v) = 0;
    virtual vector<int> topo_sort() = 0;
};


class DirectedGraph : public Graph
{
private:
    adj_link adjs;
    size_t num_vertices;
    void topo_sort(int u, vector<bool>& visited, vector<int>& ret);
    virtual void _dfs_internal(int v, vector<bool>& visited, vector<int>& ret);
public:
    DirectedGraph(size_t _num_vertices) : adjs(_num_vertices), num_vertices(_num_vertices){}
    ~DirectedGraph(){}
    virtual void addEdge(int u, int v) override;
    virtual vector<int> bfs(int source) override;
    virtual vector<int> dfs(int v) override;
    virtual vector<int> topo_sort();
};

void DirectedGraph::addEdge(int u, int v)
{
    adjs[u].insert(v);
    return;
}

vector<int> DirectedGraph::bfs(int source)
{
    vector<bool> visited(num_vertices, false);
    queue<int> q;
    q.push(source);
    int s;
    vector<int> ret;
    ret.reserve(num_vertices);
    while(!q.empty()){
        s = q.front();
        q.pop();
        ret.push_back(s);
        visited[s] = true;
        for(auto iter = adjs[s].begin(); iter != adjs[s].end(); ++iter){
            if(!visited[*iter]){
                visited[*iter] = true;
                q.push(*iter);
            }
        }
    }
    return ret;
}

vector<int> DirectedGraph::dfs(int v)
{
    vector<bool> visited(num_vertices, false);
    vector<int> ret;
    ret.reserve(num_vertices);
    _dfs_internal(v, visited, ret);
    return move(ret);
}

void DirectedGraph::_dfs_internal(int v, vector<bool>& visited, vector<int>& ret)
{
    visited[v] = true;
    ret.push_back(v);
    for(auto iter = adjs[v].begin(); iter != adjs[v].end(); ++iter){
        if(!visited[*iter]){
            _dfs_internal(*iter,visited,ret);
        }
    }
    return;
}
void DirectedGraph::topo_sort(int u, vector<bool>& visited, vector<int>& ret)
{
    visited[u] = true;
    for(auto iter = adjs[u].begin(); iter != adjs[u].end(); ++iter){
        if(!visited[*iter]){
            topo_sort(*iter, visited, ret);
        }
    }
    printf("%d\n",u);
    ret.push_back(u);
}
vector<int> DirectedGraph::topo_sort()
{
    vector<int> result;
    result.reserve(num_vertices);
    vector<bool> visited(num_vertices, false);
    for(size_t u = 0; u < num_vertices; ++u){
        if(!visited[u]){
            topo_sort(u, visited, result);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

class UndirectedGraph : public Graph
{
private:
    adj_link adjs;
    size_t num_vertices;

    virtual void _dfs_internal(int v, vector<bool>& visited, vector<int>& ret);
public:
    UndirectedGraph(size_t _num_vertices) : adjs(_num_vertices), num_vertices(_num_vertices){}
    ~UndirectedGraph(){}
    virtual void addEdge(int u, int v) override;
    virtual vector<int> bfs(int source) override;
    virtual vector<int> dfs(int v) override;
};

void UndirectedGraph::addEdge(int u, int v)
{
    adjs[u].insert(v);
    adjs[v].insert(u);
    return;
}

vector<int> UndirectedGraph::bfs(int source)
{
    vector<bool> visited(num_vertices, false);
    queue<int> q;
    q.push(source);
    int s;
    vector<int> ret;
    ret.reserve(num_vertices);
    while(!q.empty()){
        s = q.front();
        q.pop();
        ret.push_back(s);
        visited[s] = true;
        for(auto iter = adjs[s].begin(); iter != adjs[s].end(); ++iter){
            if(!visited[*iter]){
                visited[*iter] = true;
                q.push(*iter);
            }
        }
    }
    return ret;
}

vector<int> UndirectedGraph::dfs(int v)
{
    vector<bool> visited(num_vertices, false);
    vector<int> ret;
    ret.reserve(num_vertices);
    _dfs_internal(v, visited, ret);
    return ret;
}

void UndirectedGraph::_dfs_internal(int v, vector<bool>& visited, vector<int>& ret)
{
    visited[v] = true;
    ret.push_back(v);
    for(auto iter = adjs[v].begin(); iter != adjs[v].end(); ++iter){
        if(!visited[*iter]){
            _dfs_internal(*iter,visited,ret);
        }
    }
    return;
}
