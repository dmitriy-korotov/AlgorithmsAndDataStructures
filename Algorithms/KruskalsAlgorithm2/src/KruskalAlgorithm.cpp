#include <KruskalAlgorithm.hpp>

#include <iostream>


auto compare::operator() (Edge const &a, Edge const &b) const noexcept -> bool
{
    return a.weight > b.weight;
}



auto DisjointSet::makeSet(int n) noexcept -> void
{
    for (int i = 0; i < n; i++) 
        m_parent.emplace(i, i);
}
 


auto DisjointSet::Find(int k) const noexcept -> int
{
    if (m_parent.at(k) == k) 
        return k;
    return Find(m_parent.at(k));
}
 


auto DisjointSet::Union(int a, int b) noexcept -> void
{
    int x = Find(a);
    int y = Find(b);

    m_parent[x] = y;
}



auto KruskalAlgorithm(std::vector<Edge>& edges, int n) noexcept -> std::vector<Edge>
{
    std::vector<Edge> MST;
 
    DisjointSet ds;
 
    ds.makeSet(n);
 
    std::sort(edges.begin(), edges.end(), compare());
 
    while (MST.size() != n - 1)
    {
        Edge next_edge = edges.back();
        edges.pop_back();
 
        int x = ds.Find(next_edge.src);
        int y = ds.Find(next_edge.dest);

        if (x != y)
        {
            MST.push_back(next_edge);
            ds.Union(x, y);
        }
    }
    return MST;
}