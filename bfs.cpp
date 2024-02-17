#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class graph
{
public:
    int V;
    vector<vector<pair<int, int>>> adjList;

    // Constructor
    graph(int V)
    {
        this->V = V;
        adjList.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int firstnode, int secondnode, int weight)
    {
        // Undirected graph
        adjList[firstnode].push_back(make_pair(secondnode, weight));
        adjList[secondnode].push_back(make_pair(firstnode, weight));
    }

    // Print the graph
    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Adjacency list of vertex " << i << ": ";
            for (auto it = adjList[i].begin(); it != adjList[i].end(); ++it)
                cout << "(" << it->first << "," << it->second << ") ";
            cout << endl;
        }
    }

    void bfs(int startnode)
    {

        vector<bool> visited(V, false);
        queue<int> q;

        visited[startnode] = true;
        q.push(startnode);
        while (!q.empty())
        {

            int temp = q.front();

            q.pop();
            int size = adjList[temp].size();
            for (int i = 0; i < size; i++)
            {
                if (!visited[adjList[temp][i].first])
                {
                    visited[adjList[temp][i].first] = true;
                    q.push(adjList[temp][i].first);
                    cout << "the visited node is " << adjList[temp][i].first << endl;
                }
            }
        }
    }
};

int main()
{
    // Create a graph with 5 vertices
    graph g(5);

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
    g.bfs(0);

    return 0;
}
