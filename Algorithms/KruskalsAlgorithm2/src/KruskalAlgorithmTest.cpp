#include <iostream>

#include <KruskalAlgorithm.hpp>



int main(int _argc, char* _argv[])
{
    std::vector<Edge> edges =
    {
        {0, 1, 6}, {1, 2, 12}, {2, 7, 1}, {7, 6, 2}, {6, 5, 5},
        {1, 3, 1}, {1, 4, 1}, {0, 3, 1}, {4, 2, 1}, {3, 4, 4},
        {5, 3, 1}, {3, 6, 7}, {6, 4, 5}, {7, 4, 8}
    };
 
    int n = 8;
 
    try 
    {
        std::vector<Edge> e = KruskalAlgorithm(edges, n);

        size_t total_weight = 0;
        for (Edge &edge: e)
        {
            std::cout << "(" << edge.src << ", " << edge.dest << ", "
                    << edge.weight << ")" << std::endl;
            total_weight += edge.weight;
        }
        std::cout << "Total weight: " << total_weight << std::endl;
    }
    catch (const std::exception& _ex)
    {
        std::cerr << "ERROR: " << _ex.what() << std::endl;
        return EXIT_FAILURE;
    }
 
    return EXIT_SUCCESS;
}