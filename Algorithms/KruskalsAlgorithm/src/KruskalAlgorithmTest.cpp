#include <iostream>

#include <KruskalAlgorithm.hpp>



int main(int _argc, char* _argv[])
{
    Graph graph;

    size_t n = 0;
    std::cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int a = 0, b = 0, w = 0;
        std::cin >> a >> b >> w;
        graph.AddEdge(a, b, w);
    }

    auto res = graph.KruskalAlgorithm();

    int total_weight = 0;
    for (auto [weight, vertexes] : res.GetEdges())
    {
        std::cout << "V1: " << vertexes.second << " V2: " << vertexes.second << " Weight: " << weight << std::endl;
        total_weight += weight;
    }

    std::cout << "Total weight: " << total_weight << std::endl;
    
    return 0;
}