#include <GraphShortestPathDP.hpp>



int GraphShortestPath(std::vector<std::vector<int>>& graph, int start, int end, std::vector<int>& path) noexcept {
    int n = graph.size();
    std::vector<int> dist(n, INT_MAX);
    std::vector<int> prev(n, -1);
    dist[start] = 0;

    for (int k = 0; k < n - 1; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] != 0 && dist[i] != INT_MAX && dist[i] + graph[i][j] < dist[j]) {
                    dist[j] = dist[i] + graph[i][j];
                    prev[j] = i;
                }
            }
        }
    }
    int current = end;
    while (current != -1) {
        path.push_back(current);
        current = prev[current];
    }
    std::reverse(path.begin(), path.end());
    return dist[end];
}