#include <PrimAlgorithm.hpp>



int main(int _argc, char* _argv[])
{
    int V = 8;
    Graph g(V);
 
    g.addEdge(0, 1, 6);
    g.addEdge(2, 7, 1);
    g.addEdge(1, 2, 12);
    g.addEdge(6, 7, 2);
    g.addEdge(6, 5, 5);
    g.addEdge(5, 0, 10);
    g.addEdge(0, 3, 1);
    g.addEdge(3, 1, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 7, 8);
    g.addEdge(4, 6, 5);
    g.addEdge(3, 6, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, 4);
 
    g.primMST();
 
    return 0;
}