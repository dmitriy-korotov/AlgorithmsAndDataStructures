#pragma once

#include <map>
#include <unordered_set>



class Graph
{
public:

    using vertex_id_t = std::uint64_t;
    using edge_weight_t = std::int64_t;
    using edge_t = std::pair<vertex_id_t, vertex_id_t>;
    using edges_set_t = std::multimap<edge_weight_t, edge_t>;
    using vertexes_set_t = std::unordered_set<vertex_id_t>;

    Graph() = default;

    bool AddEdge(vertex_id_t _start, vertex_id_t _end,
                 edge_weight_t _weight) noexcept;

    bool AddVertex(vertex_id_t _vertex) noexcept;

    Graph KruskalAlgorithm() const noexcept; 

    const edges_set_t& GetEdges() const & noexcept; 
    edges_set_t&& GetEdges() && noexcept;

    const vertexes_set_t& GetVertexes() const & noexcept; 
    vertexes_set_t&& GetVertexes() && noexcept;

private:

    Graph(edges_set_t _edges, vertexes_set_t _vertexes) noexcept;

private:

    vertexes_set_t m_vertexes;
    edges_set_t m_edges;

};