#include <PrimAlgorithm.hpp>

#include <queue>
#include <iostream>



Graph::Graph(int V) noexcept
{
    this->V = V;
    adj = new std::list<iPair> [V];
}


 
auto Graph::addEdge(int u, int v, int w) noexcept -> void
{
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
}



auto Graph::primMST() noexcept -> void
{
    std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;
 
    int src = 0;

    std::vector<int> key(V, INF);
 
    std::vector<int> parent(V, -1);
 
    std::vector<bool> inMST(V, false);
 
    pq.push(std::make_pair(0, src));
    key[src] = 0;
 
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
         
          if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true; 

        std::list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
 
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(std::make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 
    size_t total_weight = 0;
    for (int i = 1; i < V; ++i)
    {
        printf("(%d, %d, %d)\n", parent[i], i, key[i]);
        total_weight += key[i];
    }

    std::cout << "Total weight: " << total_weight << std::endl;
}