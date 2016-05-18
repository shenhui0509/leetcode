#include <vector>
#include <algorithm> // std::min & std::max
#include <climits>

#include "utils.hpp"
using namespace std;

struct AdjWeightedMatrix
{

    vector<vector<int>> _matrix;
    size_t n_vertices;
    AdjWeightedMatrix(size_t n) : _matrix(n, vector<int>(n, INT_MAX)), n_vertices(n){}
    AdjWeightedMatrix(vector<vector<int>>&& rv) : _matrix(move(rv)), n_vertices(_matrix.size()){} 
    AdjWeightedMatrix(vector<vector<int>>& lv) : _matrix(move(lv)), n_vertices(_matrix.size()){} 
    vector<int>& operator[](size_t i){
        return _matrix[i];
    }
};

size_t find_nearest(const vector<int>& dist, const vector<bool>& visited)
{
    int min_dist = INT_MAX;
    size_t min_index;
    for(size_t i = 0; i < dist.size(); i++){
        if(!visited[i] && dist[i] < min_dist){
            min_dist = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

vector<int> dijkstra(AdjWeightedMatrix graph, int src)
{
    size_t n = graph.n_vertices;
    vector<int> result(graph.n_vertices, INT_MAX);
    vector<bool> visited(graph.n_vertices, false);
    result[src] = 0;
    for(size_t i = 0; i < n; i++){
        size_t u = find_nearest(result, visited);
        visited[u] = true;
        for(size_t v = 0; v < n; v++){
            if(!visited[v] && graph[u][v] &&
                result[u] != INT_MAX && result[u] + graph[u][v] < result[v]){
                result[v] = result[u] + graph[u][v];
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> p = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                              {4, 0, 8, 0, 0, 0, 0, 11, 0},
                              {0, 8, 0, 7, 0, 4, 0, 0, 2},
                              {0, 0, 7, 0, 9, 14, 0, 0, 0},
                              {0, 0, 0, 9, 0, 10, 0, 0, 0},
                              {0, 0, 4, 0, 10, 0, 2, 0, 0},
                              {0, 0, 0, 14, 0, 2, 0, 1, 6},
                              {8, 11, 0, 0, 0, 0, 1, 0, 7},
                              {0, 0, 2, 0, 0, 0, 6, 7, 0}
                             };
    AdjWeightedMatrix m(p);
    vector<int> res = dijkstra(m,0);
    print_vector(res);
    return 0;
}