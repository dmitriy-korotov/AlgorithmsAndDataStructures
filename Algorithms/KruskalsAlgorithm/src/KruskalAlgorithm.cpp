#include <KruskalAlgorithm.hpp>

#include <vector>



Graph::Graph(edges_set_t _edges, vertexes_set_t _vertexes) noexcept
        : m_edges(std::move(_edges))
        , m_vertexes(std::move(_vertexes))
{ }



bool Graph::AddEdge(vertex_id_t _start, vertex_id_t _end,
                    edge_weight_t _weight) noexcept
{
    m_vertexes.emplace(_start);
    m_vertexes.emplace(_end);
    auto it = m_edges.emplace(_weight, std::make_pair(_start, _end));
    return (it != m_edges.end());
}



auto Graph::AddVertex(vertex_id_t _vertex) noexcept -> bool
{
    return m_vertexes.emplace(_vertex).second;
}



auto Graph::GetVertexes() const & noexcept -> const vertexes_set_t&
{
    return m_vertexes;
}



auto Graph::GetVertexes() && noexcept -> vertexes_set_t&&
{
    return std::move(m_vertexes);
}



 auto Graph::GetEdges() const & noexcept -> const edges_set_t&
 {
    return m_edges;
 }



 auto Graph::GetEdges() && noexcept -> edges_set_t&&
 {
    return std::move(m_edges);
 }



auto Graph::KruskalAlgorithm() const noexcept -> Graph
{
    edges_set_t edges;
    std::vector<std::unordered_set<vertex_id_t>> linck_components;

    auto curr = m_edges.begin();
    while (not linck_components.empty() and linck_components.back().size() != m_vertexes.size())
    {
        bool is_valid = true;

        int first_vertex_component_idx = -1;
        int second_vertex_component_idx = -1;

        int index = 0;
        for (const auto& linck_component : linck_components)
        {
            bool contains_first = linck_component.contains(curr->second.first);
            bool contains_second = linck_component.contains(curr->second.second);
            if (contains_first and contains_second)
            {
                is_valid = false;
                break;
            }

            if (contains_first)
                first_vertex_component_idx = index;
            
            if (contains_second)
                second_vertex_component_idx = index;

            index++;
        }

        if (is_valid)
        {
            if (first_vertex_component_idx == -1 && second_vertex_component_idx == -1)
            {
                std::unordered_set<vertex_id_t> tmp = { curr->second.first, curr->second.second };
                linck_components.push_back(std::move(tmp));
            }

            if (first_vertex_component_idx == -1)
                linck_components[second_vertex_component_idx].emplace(curr->second.first);
            else if (second_vertex_component_idx == -1)
                linck_components[first_vertex_component_idx].emplace(curr->second.second);
            else
            {
                auto& tmp = linck_components[second_vertex_component_idx];
                for (auto el : tmp)
                    linck_components[first_vertex_component_idx].emplace(el);
                linck_components.erase(linck_components.begin() + second_vertex_component_idx);
            }

            edges.emplace(curr->first, std::make_pair(curr->second.first, curr->second.second));
        }

        curr++;
    }

    return Graph(std::move(edges), m_vertexes);
}