#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define the number of vertices in the graph
#define V 4

// Define a structure to represent a weighted edge in the graph
struct Edge
{
    int dest;
    int weight;
};

// Define a function to implement Dijkstra's algorithm
void dijkstra(vector<vector<Edge>> &graph, int source)
{
    // Create a priority queue to store (distance, vertex) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Create an array to store distances from the source vertex
    vector<int> dist(V, INT_MAX);

    // Initialize the distance of the source vertex to 0
    dist[source] = 0;

    // Push the source vertex into the priority queue
    pq.push(make_pair(0, source));

    // Iterate until the priority queue is empty
    while (!pq.empty())
    {
        // Extract the minimum distance vertex from the priority queue
        int u = pq.top().second;
        pq.pop();

        // Iterate through all adjacent vertices of the extracted vertex
        for (auto &edge : graph[u])
        {
            int v = edge.dest;
            int weight = edge.weight;

            // Update the distance of vertex v if it is shorter through u
            if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
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
    // Define the graph as an adjacency list
    vector<vector<Edge>> graph(V);

    // Add edges to the graph
    graph[0].push_back({1, 5});
    graph[0].push_back({2, 10});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 2});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});

    // Define the source vertex
    int source = 0;

    // Run Dijkstra's algorithm
    dijkstra(graph, source);

    return 0;
}
