#include <list>
#include <vector>



# define INF 0x3f3f3f3f
 
using iPair = std::pair<int, int>;
 


class Graph
{
public:

    Graph(int V) noexcept; 
 
    void addEdge(int u, int v, int w) noexcept;
 
    void primMST() noexcept;

private:

    int V = 0;
    std::list<iPair> *adj = nullptr;

};