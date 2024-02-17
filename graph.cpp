#include <iostream>
#include <vector>
#include <utility> // For std::pair

using namespace std;

class Graph
{
    int V;                              // Number of vertices
    vector<vector<pair<int, int>>> adj; // Vector of vectors containing pairs of (vertex, weight)

public:
    Graph(int V);                           // Constructor
    void addEdge(int v, int w, int weight); // Function to add an edge to the graph
    void printGraph();                      // Function to print the graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V); // Resize the vector to hold V elements
}

void Graph::addEdge(int v, int w, int weight)
{
    adj[v].push_back(make_pair(w, weight)); // Add w to v's list with weight
    adj[w].push_back(make_pair(v, weight)); // Add v to w's list with weight (for undirected graph)
}

void Graph::printGraph()
{
    for (int v = 0; v < V; ++v)
    {
        cout << "Adjacency list of vertex " << v << ": ";
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
            cout << "(" << it->first << "," << it->second << ") ";
        cout << endl;
    }
}

int main()
{
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges with weights
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 6);
    g.addEdge(1, 3, 15);
    g.addEdge(1, 4, 8);
    g.addEdge(2, 3, 20);
    g.addEdge(3, 4, 9);

    // Print the graph
    g.printGraph();

    return 0;
}
