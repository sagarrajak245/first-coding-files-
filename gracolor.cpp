#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isSafe(int vertex, const vector<vector<int>> &graph, const vector<int> &color, int c)
{
    for (int i = 0; i < graph[vertex].size(); ++i)
    {
        int neighbor = graph[vertex][i];
        if (color[neighbor] == c)
        {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>> &graph, vector<int> &color, int numColors, int vertex)
{
    if (vertex == graph.size())
    {
        return true; // All vertices are colored
    }

    for (int c = 0; c < numColors; ++c)
    {
        if (isSafe(vertex, graph, color, c))
        {
            color[vertex] = c; // Assign color c to the current vertex

            // Recur to assign colors to the remaining vertices
            if (graphColoringUtil(graph, color, numColors, vertex + 1))
            {
                return true;
            }

            // Backtrack: Undo the color assignment
            color[vertex] = -1;
        }
    }

    return false; // No valid color for the current vertex
}

void graphColoring(const vector<vector<int>> &graph, int numColors)
{
    int V = graph.size();
    vector<int> color(V, -1); // Initialize all vertices with no color assigned

    if (graphColoringUtil(graph, color, numColors, 0))
    {
        // Output the coloring result
        for (int i = 0; i < V; ++i)
        {
            cout << "Vertex " << i << " is assigned color " << color[i] << endl;
        }
    }
    else
    {
        cout << "No valid coloring possible with " << numColors << " colors." << endl;
    }
}

int main()
{
    // Example graph (adjacency list representation)
    vector<vector<int>> graph = {
        {1, 2},    // Vertex 0 is connected to vertices 1 and 2
        {0, 2, 3}, // Vertex 1 is connected to vertices 0, 2, and 3
        {0, 1, 3}, // Vertex 2 is connected to vertices 0, 1, and 3
        {1, 2}     // Vertex 3 is connected to vertices 1 and 2
    };

    int numColors = 3; // Number of colors available

    // Perform graph coloring using backtracking
    graphColoring(graph, numColors);

    return 0;
}
