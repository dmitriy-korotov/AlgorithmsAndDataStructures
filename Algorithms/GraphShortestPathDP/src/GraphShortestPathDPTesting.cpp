#include <iostream>
#include <vector>
#include <climits>
#include <chrono>

#include <GraphShortestPathDP.hpp>



template <typename Func, typename ...Args>
auto Bench(Func&& function, Args&&... args) {
    auto start = std::chrono::steady_clock::now();
    auto result = std::forward<Func>(function)(std::forward<Args>(args)...);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start) << std::endl;
    return result;
}

void Solve(std::vector<std::vector<int>>& graph, int start, int end) {
    std::vector<int> path;
    int shortest = Bench(GraphShortestPath, graph, start, end, path);
    std::cout << "The shortest path from node " << start << " to node " << end << " is: " << shortest << std::endl;
    std::cout << "Path: ";
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i] << " -> ";
    }
    std::cout << "finish" << std::endl;
}



int main() {
    std::vector<std::vector<int>> graph1 = {{0, 0, 1, 2, 0, 0, 3},
                                            {0, 0, 4, 0, 5, 0, 0},
                                            {1, 4, 0, 0, 6, 7, 0},
                                            {2, 0, 0, 0, 0, 8, 9},
                                            {0, 5, 6, 0, 0, 0, 10},
                                            {0, 0, 7, 8, 0, 0, 0},
                                            {3, 0, 0, 9, 10, 0, 0}};
    std::cout << "Graph 1:" << std::endl;                                            
    Solve(graph1, 0, 6);

    std::vector<std::vector<int>> graph2 = {{0, 11, 0, 12, 13, 0, 14},
                                            {11, 0, 15, 16, 0, 0, 0},
                                            {0, 15, 0, 17, 0, 18, 19},
                                            {12, 16, 17, 0, 20, 21, 0},
                                            {13, 0, 0, 20, 0, 22, 0},
                                            {0, 0, 18, 21, 22, 0, 23},
                                            {14, 0, 19, 0, 0, 23, 0}};
    std::cout << "Graph 2:" << std::endl;
    Solve(graph2, 0, 6);

    std::vector<std::vector<int>> graph3 = {{0, 24, 25, 0, 0, 26, 0},
                                            {24, 0, 27, 28, 29, 0 ,0},
                                            {25 ,27 ,0 ,0 ,30 ,31 ,32},
                                            {0 ,28 ,0 ,0 ,33 ,0 ,0},
                                            {0 ,29 ,30 ,33 ,0 ,0 ,34},
                                            {26 ,0 ,31 ,0 ,0 ,0 ,35},
                                            {0 ,0 ,32 ,0 ,34 ,35 ,0}};
    std::cout << "Graph 3:" << std::endl;
    Solve(graph3, 0, 6);

    return 0;
}
