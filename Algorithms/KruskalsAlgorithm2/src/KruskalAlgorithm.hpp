#include <vector>
#include <unordered_map>
#include <algorithm>



struct Edge {
    int src = 0;
    int dest = 0;
    int weight = 0;
};



struct compare
{
    bool operator() (Edge const &a, Edge const &b) const noexcept;
};



class DisjointSet
{
public:

    void makeSet(int n) noexcept;
 
    int Find(int k) const noexcept;
 
    void Union(int a, int b) noexcept;

private:

    std::unordered_map<int, int> m_parent;

};


 
std::vector<Edge> KruskalAlgorithm(std::vector<Edge>& edges, int n) noexcept;