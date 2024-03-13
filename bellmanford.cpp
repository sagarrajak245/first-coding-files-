
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Define the number of vertices in the graph
#define V 5
#define INF INT_MAX

// Define a structure to represent a weighted edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Define a function to implement Bellman-Ford algorithm
void bellmanFord(vector<Edge> &edges, int source)
{
    // Create an array to store distances from the source vertex
    vector<int> dist(V, INF);
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; ++i)
    {
        for (auto &edge : edges)
        {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto &edge : edges)
    {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;
        if (dist[u] != INF && dist[u] + weight < dist[v])
        {
            cout << "Graph contains negative-weight cycle!" << endl;
            return;
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < V; ++i)
    {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    // Define the graph as a vector of edges
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    // Define the source vertex
    int source = 0;

    // Run Bellman-Ford algorithm
    bellmanFord(edges, source);

    return 0;
}
