#include <iostream>
#include <fstream>
#include <queue>
#include <limits>

using namespace std;

const int MAX_V = 1000;

struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

struct Vertex {
    int id;
    int dist;
    bool operator<(const Vertex& other) const {
        return dist > other.dist;
    }
};

void dijkstra(int source, const vector<vector<Edge>>& graph, vector<int>& dist) {
    priority_queue<Vertex> pq;
    pq.push({source, 0});
    dist[source] = 0;

    while (!pq.empty()) {
        Vertex u = pq.top();
        pq.pop();

        if (u.dist > dist[u.id]) 
            continue;

        for (const Edge& e : graph[u.id]) {
            int v = e.to;
            int weight = e.weight;
            if (dist[u.id] + weight < dist[v]) {
                dist[v] = dist[u.id] + weight;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    int n, m; 
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(MAX_V); 

    cout << "Enter edges (from to weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(Edge(to, weight));
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    vector<int> shortest_paths(MAX_V, numeric_limits<int>::max()); // Initialize distances to infinity

    dijkstra(source, graph, shortest_paths);

    // Write data to CSV file
    ofstream outFile("shortest_paths.csv");
    outFile << "Vertex,Distance\n";
    for (int i = 0; i < n; ++i) {
        outFile << i << "," << shortest_paths[i] << "\n";
    }
    outFile.close();

    cout << "Shortest paths have been written to shortest_paths.csv\n";

    return 0;
}
