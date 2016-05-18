#include "Graphs.hpp"
#include "utils.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Graph* p = new DirectedGraph(6);
    p->addEdge(0,1);
    p->addEdge(0,2);
    p->addEdge(0,3);
    p->addEdge(1,3);
    p->addEdge(1,4);
    p->addEdge(2,5);
    p->addEdge(3,5);
    vector<int> ret = p->topo_sort();
    print_vector(ret);
    return 0;
}