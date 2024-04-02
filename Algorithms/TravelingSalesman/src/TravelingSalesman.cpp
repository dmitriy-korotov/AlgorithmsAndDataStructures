#include <TravelingSalesman.hpp>

#include <algorithm>
#include <climits>



int tsp(std::vector<std::vector<int>>& graph, int start, std::vector<int>& path) noexcept {
    int n = graph.size();
    std::vector<int> vertex;
    for (int i = 0; i < n; ++i) {
        if (i != start) {
            vertex.push_back(i);
        }
    }

    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = start;
        for (int i = 0; i < vertex.size(); ++i) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][start];
        if (current_pathweight < min_path) {
            min_path = current_pathweight;
            path.clear();
            path.push_back(start);
            for (int i = 0; i < vertex.size(); ++i) {
                path.push_back(vertex[i]);
            }
            path.push_back(start);
        }
    } while (next_permutation(vertex.begin(), vertex.end()));
    return min_path;
}