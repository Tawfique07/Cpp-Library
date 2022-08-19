#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Dijkstra {
   private:
    int vertices, edges;
    long long *dist;
    bool *isVisited;
    std::vector<std::pair<int, int>> *adj;
    long long INF;
    int *via;

    void dijktraSink(int source) {
        int i;
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;

        isVisited = new bool[vertices + 1];

        for (i = 0; i <= vertices; ++i) {
            dist[i] = this->INF;
            isVisited[i] = false;
        }

        dist[source] = 0;
        pq.push({0, source});
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            if (isVisited[current.second]) {
                continue;
            }

            isVisited[current.second] = true;
            dist[current.second] = current.first;

            for (auto edge : adj[current.second]) {
                int cost = edge.first;
                pq.push({current.first + edge.first, edge.second});
            }
        }
    }

    void dijkstraPath(int source) {
        int i;
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;

        via = new int[vertices + 1];

        isVisited = new bool[vertices + 1];

        for (i = 0; i <= vertices; ++i) {
            dist[i] = this->INF;
            via[i] = -1;
            isVisited[i] = false;
        }

        dist[source] = 0;
        via[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto current = pq.top().second;
            pq.pop();

            if (isVisited[current]) {
                continue;
            }

            isVisited[current] = true;

            for (auto edge : adj[current]) {
                if (dist[current] + edge.first < dist[edge.second]) {
                    dist[edge.second] = edge.first + dist[current];
                    pq.push({dist[edge.second], edge.second});
                    via[edge.second] = current;
                }
            }
        }
    }

   public:
    Dijkstra(int vertices, int edges) {
        this->vertices = vertices;
        this->edges = edges;
        this->INF = 1e18;
        dist = new long long[vertices + 1];

        adj = new std::vector<std::pair<int, int>>[vertices + 1];
    }
    void addEdge(int u, int v, int w) {
        this->adj[u].push_back({w, v});
        this->adj[v].push_back({w, u});
    }

    long long shortestPath(int src, int sink) {
        dijktraSink(src);
        if (dist[sink] != INF) {
            return dist[sink];
        } else {
            return -1;
        }
    }
    int *pathOfShortestPath(int src) {
        dijkstraPath(src);
        return via;
    }
};
