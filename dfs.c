#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t
{

    // No. of vertices
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph *Graph_create(int V)
{
    Graph *g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            g->adj[i][j] = false;
        }
    }

    return g;
}

// Destructor
void Graph_destroy(Graph *g) { free(g); }

// Function to add an edge to graph
void Graph_addEdge(Graph *g, int v, int w)
{
    // Add w to v’s list.
    g->adj[v][w] = true;
}

// Prints dfs traversal from a given source s

void Graph_DFS(Graph *g, int s)
{
    // Mark all the vertices as not visited
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++)
    {
        visited[i] = false;
    }

    // Create a stack for DFS
    int stack[MAX_VERTICES];
    int top = -1;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    stack[++top] = s;

    while (top != -1)
    {
        // Dequeue a vertex from stack and print it
        s = stack[top--];
        printf("%d ", s);

        for (int i = 0; i < g->V; i++)
        {
            if (g->adj[s][i] && !visited[i])
            {
                visited[i] = true;
                stack[++top] = i;
            }
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph *g = Graph_create(4);
    Graph_addEdge(g, 0, 1);
    Graph_addEdge(g, 0, 2);
    Graph_addEdge(g, 1, 2);
    Graph_addEdge(g, 2, 0);
    Graph_addEdge(g, 2, 3);
    Graph_addEdge(g, 3, 3);

    printf("Following is Depth First Traversal "
           "(starting from vertex 2) \n");
    Graph_DFS(g, 2);

    Graph_destroy(g);

    return 0;
}