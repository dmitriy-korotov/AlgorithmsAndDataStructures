#include <iostream>

#include <TravelingSalesman.hpp>



void Solve(std::vector<std::vector<int>>& graph, int start) {
    std::vector<int> path;
    int min_path = tsp(graph, start, path);
    std::cout << "Minimal path length: " << min_path << std::endl;
    std::cout << "Path: ";
    for (int i = 0; i < path.size(); ++i) {
        std::cout << path[i] << " -> ";
    }
    std::cout << "Final" << std::endl;
}



int main() {
    std::vector<std::vector<int>> graph1 = {
        {0, 7, 12, 25, 10},
        {10, 0, 9, 5, 11},
        {13, 8, 0, 6, 4},
        {6, 11, 15, 0, 15},
        {5, 9, 12, 17, 0}
    };
    std::cout << "Graph 1:" << std::endl;
    Solve(graph1, 0);
    
    std::vector<std::vector<int>> graph2 = {
        {0, 7, 12, 25, 10, 45},
        {10, 0, 9, 5, 11, 23},
        {13, 8, 0, 6, 4, 21},
        {6, 11, 15, 0, 15, 45},
        {5, 9, 12, 17, 0, 12},
        {15, 7, 2, 12, 34, 0}
    };
    std::cout << "Graph 2:" << std::endl;
    Solve(graph2, 0);

    return 0;
}
